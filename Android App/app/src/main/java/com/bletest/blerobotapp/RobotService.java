package com.bletest.blerobotapp;

import android.app.Service;
import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothGatt;
import android.bluetooth.BluetoothGattCallback;
import android.bluetooth.BluetoothGattCharacteristic;
import android.bluetooth.BluetoothGattDescriptor;
import android.bluetooth.BluetoothGattService;
import android.bluetooth.BluetoothManager;
import android.bluetooth.BluetoothProfile;
import android.content.Context;
import android.content.Intent;
import android.os.Binder;
import android.os.IBinder;
import android.util.Log;
import java.util.LinkedList;
import java.util.Queue;
import java.util.UUID;

/**
 * Service for managing connection and data communication with the BLE car
 */
public class RobotService extends Service {

    private final static String TAG = RobotService.class.getSimpleName();

    public enum Motor { LEFT_WHEEL, RIGHT_WHEEL }

    private static BluetoothManager mBluetoothManager;
    private static BluetoothAdapter mBluetoothAdapter;
    private static String mBluetoothDeviceAddress;
    private static BluetoothGatt mBluetoothGatt;

    //  Queue for BLE events
    //  This is needed so that rapid BLE events don't get dropped
    private static final Queue<Object> BleQueue = new LinkedList<>();

    // UUID for the custom motor characteristics
    private static final String baseUUID =           "BD19D460-CCB7-4BE6-A46F-D2A3A6BB05A";
    private static final String motorServiceUUID =   baseUUID + "0";
    private static final String speedLeftCharUUID =  baseUUID + "1";
    private static final String speedRightCharUUID = baseUUID + "2";

    // Bluetooth Characteristics that we need to read/write
    private static BluetoothGattCharacteristic mSpeedLeftCharacteristic;
    private static BluetoothGattCharacteristic mSpeedRightCharacteristic;

    // State (on/off), speed of the motors
    //private static boolean motorLeftState;
    //private static boolean motorRightState;
    private static int motorLeftSpeed;
    private static int motorRightSpeed;
    // Actions used during broadcasts to the activity
    public static final String ACTION_CONNECTED =
            "com.bletest.blerobotapp.ACTION_GATT_CONNECTED";
    public static final String ACTION_DISCONNECTED =
            "com.bletest.blerobotapp.ACTION_GATT_DISCONNECTED";
    public static final String ACTION_DATA_AVAILABLE =
            "com.bletest.blerobotapp.ACTION_DATA_AVAILABLE";

    /**
     * This is a binder for the BluetoothLeService
     */
    public class LocalBinder extends Binder {
        RobotService getService() {
            return RobotService.this;
        }
    }

    @Override
    public IBinder onBind(Intent intent) {
        return mBinder;
    }

    @Override
    public boolean onUnbind(Intent intent) {
        // Disconnect from the GATT database and close the connection
        disconnect();
        close();
        return super.onUnbind(intent);
    }

    private final IBinder mBinder = new LocalBinder();

    /**
     * Implements callback methods for GATT events.
     */
    private final BluetoothGattCallback mGattCallback = new BluetoothGattCallback() {

        @Override
        public void onConnectionStateChange(BluetoothGatt gatt, int status, int newState) {
            if (newState == BluetoothProfile.STATE_CONNECTED) {
                broadcastUpdate(ACTION_CONNECTED);
                Log.i(TAG, "Connected to GATT server.");
                // Attempts to discover services after successful connection.
                Log.i(TAG, "Attempting to start service discovery:" +
                        mBluetoothGatt.discoverServices());

            } else if (newState == BluetoothProfile.STATE_DISCONNECTED) {
                Log.i(TAG, "Disconnected from GATT server.");
                broadcastUpdate(ACTION_DISCONNECTED);
            }
        }

        /**
         * This is called when service discovery has completed.
         *
         * It broadcasts an update to the main activity.
         *
         * @param gatt The GATT database object
         * @param status Status of whether the discovery was successful.
         */
        @Override
        public void onServicesDiscovered(BluetoothGatt gatt, int status) {
            if (status == BluetoothGatt.GATT_SUCCESS) {

                // Get the characteristics for the motor service
                BluetoothGattService gattService = mBluetoothGatt.getService(UUID.fromString(motorServiceUUID));
                if (gattService == null) return; // return if the motor service is not supported
                mSpeedLeftCharacteristic = gattService.getCharacteristic(UUID.fromString(speedLeftCharUUID));
                mSpeedRightCharacteristic = gattService.getCharacteristic(UUID.fromString(speedRightCharUUID));


            } else {
                Log.w(TAG, "onServicesDiscovered received: " + status);
            }
        }

        /**
         * This handles the BLE Queue. If the queue is not empty, it starts the next event.
         */
        private void handleBleQueue() {
            if(BleQueue.size() > 0) {
                // Determine which type of event is next and fire it off
                if (BleQueue.element() instanceof BluetoothGattDescriptor) {
                    mBluetoothGatt.writeDescriptor((BluetoothGattDescriptor) BleQueue.element());
                } else if (BleQueue.element() instanceof BluetoothGattCharacteristic) {
                    mBluetoothGatt.writeCharacteristic((BluetoothGattCharacteristic) BleQueue.element());
                }
            }
        }


        @Override
        public void onCharacteristicWrite(BluetoothGatt gatt,
                                          BluetoothGattCharacteristic characteristic,
                                          int status) {
            // Pop the item that was written from the queue
            BleQueue.remove();
            // See if there are more items in the BLE queues
            handleBleQueue();
        }

        @Override
        public void onDescriptorWrite(BluetoothGatt gatt, BluetoothGattDescriptor descriptor,
                                      int status) {
            // Pop the item that was written from the queue
            BleQueue.remove();
            // See if there are more items in the BLE queues
            handleBleQueue();
        }
    };

    private void broadcastUpdate(final String action) {
        final Intent intent = new Intent(action);
        sendBroadcast(intent);
    }
    public boolean initialize() {
        // For API level 18 and above, get a reference to BluetoothAdapter through
        // BluetoothManager.
        if (mBluetoothManager == null) {
            mBluetoothManager = (BluetoothManager) getSystemService(Context.BLUETOOTH_SERVICE);
            if (mBluetoothManager == null) {
                Log.e(TAG, "Unable to initialize BluetoothManager.");
                return false;
            }
        }

        mBluetoothAdapter = mBluetoothManager.getAdapter();
        if (mBluetoothAdapter == null) {
            Log.e(TAG, "Unable to obtain a BluetoothAdapter.");
            return false;
        }

        // Initialize car state variables
        //motorLeftState = false;
        //motorRightState = false;
        motorLeftSpeed = 0;
        motorRightSpeed = 0;

        return true;
    }

    public boolean connect(final String address) {
        if (mBluetoothAdapter == null || address == null) {
            Log.w(TAG, "BluetoothAdapter not initialized or unspecified address.");
            return false;
        }

        // Previously connected device.  Try to reconnect.
        if (mBluetoothDeviceAddress != null && address.equals(mBluetoothDeviceAddress)
                && mBluetoothGatt != null) {
            Log.i(TAG, "Trying to use an existing mBluetoothGatt for connection.");
            return mBluetoothGatt.connect();
        }

        final BluetoothDevice device = mBluetoothAdapter.getRemoteDevice(address);
        if (device == null) {
            Log.w(TAG, "Device not found.  Unable to connect.");
            return false;
        }
        // We want to directly connect to the device, so we are setting the autoConnect
        // parameter to false.
        mBluetoothGatt = device.connectGatt(this, false, mGattCallback);
        Log.i(TAG, "Trying to create a new connection.");
        mBluetoothDeviceAddress = address;
        return true;
    }

    public void disconnect() {
        if (mBluetoothAdapter == null || mBluetoothGatt == null) {
            Log.w(TAG, "BluetoothAdapter not initialized");
            return;
        }
        mBluetoothGatt.disconnect();
    }

    /**
     * After using a given BLE device, the app must call this method to ensure resources are
     * released properly.
     */
    public void close() {
        if (mBluetoothGatt == null) {
            return;
        }
        mBluetoothGatt.close();
        mBluetoothGatt = null;
    }

    private void updateGattSpeed(Motor motor)
    {
        if(motor == Motor.LEFT_WHEEL) {
            if (mSpeedLeftCharacteristic != null)
                //if(state)
                    mSpeedLeftCharacteristic.setValue(motorLeftSpeed, BluetoothGattCharacteristic.FORMAT_SINT8, 0);
                //} else {
                //    mSpeedLeftCharacteristic.setValue(0, BluetoothGattCharacteristic.FORMAT_SINT8, 0);

                writeCharacteristic(mSpeedLeftCharacteristic);

        } else { // Motor == RIGHT
            if (mSpeedRightCharacteristic != null) //{
                //if(state) {
                    mSpeedRightCharacteristic.setValue(motorRightSpeed, BluetoothGattCharacteristic.FORMAT_SINT8, 0);
                //} else {
                //    mSpeedRightCharacteristic.setValue(0, BluetoothGattCharacteristic.FORMAT_SINT8, 0);
                //}
                writeCharacteristic(mSpeedRightCharacteristic);
           // }
        }
    }


    private void writeCharacteristic(BluetoothGattCharacteristic characteristic) {
        if (mBluetoothAdapter == null || mBluetoothGatt == null) {
            Log.w(TAG, "BluetoothAdapter not initialized");
            return;
        }
        BleQueue.add(characteristic);
        if (BleQueue.size() == 1) {
            mBluetoothGatt.writeCharacteristic(characteristic);
            Log.i(TAG, "Writing Characteristic");
        }
    }
    /*public void setMotorState(Motor motor, boolean state) {
        // Update the motor state variable
        if(motor == Motor.LEFT_WHEEL)
        {
            motorLeftState = state;
        } else { // Motor == RIGHT
            motorRightState = state;
        }
        // Update the Speed in the Gatt Database
        updateGattSpeed(motor, state);
    }*/

    public void setMotorSpeed(Motor motor, int speed) {
       // boolean state;
        if(motor == Motor.LEFT_WHEEL)
        {
            motorLeftSpeed = speed;
            //state = motorLeftState;
        } else  { // Motor == RIGHT
            motorRightSpeed = speed;
            //state = motorRightState;
        }
        // Update the Speed in the Gatt Database
        updateGattSpeed(motor);
    }


    /**
     * This function returns the UUID of the motor service
     */
    public static UUID getMotorServiceUUID() {
        return UUID.fromString(RobotService.motorServiceUUID);
    }
}
