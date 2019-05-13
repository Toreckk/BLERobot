package com.bletest.blerobotapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.TextView;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.content.ServiceConnection;
import android.os.Bundle;
import android.os.IBinder;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;


public class ControlActivity extends AppCompatActivity {

    private SeekBar seekbar;
    private SeekBar seekbar2;
    private TextView textView;
    private TextView textView2;

    private Button button;

    // This tag is used for debug messages
    private static final String TAG = ControlActivity.class.getSimpleName();

    private static String mDeviceAddress;
    private static RobotService mRobotService;


    /**
     * This manages the lifecycle of the BLE service.
     * When the service starts we get the service object, initialize the service, and connect.
     */
    private final ServiceConnection mServiceConnection = new ServiceConnection() {

        @Override
        public void onServiceConnected(ComponentName componentName, IBinder service) {
            Log.i(TAG, "onServiceConnected");
            mRobotService = ((RobotService.LocalBinder) service).getService();
            if (!mRobotService.initialize()) {
                Log.e(TAG, "Unable to initialize Bluetooth");
                finish();
            }
            // Automatically connects to the car database upon successful start-up initialization.
            mRobotService.connect(mDeviceAddress);
        }

        @Override
        public void onServiceDisconnected(ComponentName componentName) {

            mRobotService = null;
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_control);

        textView = (TextView) findViewById(R.id.textView);
        textView2 = (TextView) findViewById(R.id.textView2);
        seekbar = (SeekBar) findViewById(R.id.seekBar);
        seekbar2 = (SeekBar) findViewById(R.id.seekBar2);

        seekbar.setProgress(100);
        seekbar2.setProgress(100);
        final Intent intent = getIntent();
        mDeviceAddress = intent.getStringExtra(BLEScanActivity.EXTRAS_BLE_ADDRESS);

        //Bind to the BLE Service
        Log.i(TAG, "Binding Service");
        Intent RobotServiceIntent = new Intent(this, RobotService.class);
        bindService(RobotServiceIntent, mServiceConnection, BIND_AUTO_CREATE);

        seekbar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                int newprogress = progress-100;
                mRobotService.setMotorSpeed(RobotService.Motor.LEFT_WHEEL, newprogress);
                textView.setText("" + newprogress + "%");
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

        seekbar2.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override

            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                int newprogress = progress-100;
                mRobotService.setMotorSpeed(RobotService.Motor.RIGHT_WHEEL, newprogress);
                textView2.setText("" + newprogress + "%");
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });

        button = (Button) findViewById(R.id.ButtonStop);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                seekbar.setProgress(100);
                seekbar2.setProgress(100);
            }
        });
    }

    @Override
    protected void onResume(){
        super.onResume();
        registerReceiver(mRobotUpdateReceiver, makeRobotUpdateIntentFilter());
        if(mRobotService != null)
        {
            final boolean result = mRobotService.connect(mDeviceAddress);
            Log.i(TAG, "Connect request result = "+ result);
        }
    }

    @Override
    protected void onPause(){
        super.onPause();
        unregisterReceiver(mRobotUpdateReceiver);
    }

    @Override
    protected void onDestroy(){
        super.onDestroy();
        unbindService(mServiceConnection);
        mRobotService = null;
    }

    /**
     * Handle broadcasts from the Car service object. The events are:
     * ACTION_CONNECTED: connected to the car.
     * ACTION_DISCONNECTED: disconnected from the car.
     */
    private final BroadcastReceiver mRobotUpdateReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            final String action = intent.getAction();
            switch (action) {
                case RobotService.ACTION_CONNECTED:
                    // No need to do anything here. Service discovery is started by the service.
                    break;
                case RobotService.ACTION_DISCONNECTED:
                    mRobotService.close();
                    break;
            }
        }
    };

    private static IntentFilter makeRobotUpdateIntentFilter() {
        final IntentFilter intentFilter = new IntentFilter();
        intentFilter.addAction(RobotService.ACTION_CONNECTED);
        intentFilter.addAction(RobotService.ACTION_DISCONNECTED);
        intentFilter.addAction(RobotService.ACTION_DATA_AVAILABLE);
        return intentFilter;
    }
}
