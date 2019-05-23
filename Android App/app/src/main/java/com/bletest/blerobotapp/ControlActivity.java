package com.bletest.blerobotapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.SwitchCompat;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.CompoundButton;
import android.widget.SeekBar;
import android.widget.Switch;
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
import android.widget.ToggleButton;


public class ControlActivity extends AppCompatActivity {

    private SeekBar seekbar;
    private SeekBar seekbar2;
    private TextView textView;
    private TextView textView2;

    private ToggleButton toggleButton;

    private Button button;

    // This tag is used for debug messages
    private static final String TAG = ControlActivity.class.getSimpleName();

    private static String mDeviceAddress;
    private static RobotService mRobotService;

    int oldProgressLeft = -200;
    int oldProgressRight = -200;


    /**
     * This manages the lifecycle of the BLE service.
     * When the service starts we get the service object, initialize the service, and connect.
     */
    private final ServiceConnection mServiceConnection = new ServiceConnection() {

        @Override
        public void onServiceConnected(ComponentName componentName, IBinder service) {
            //Log.i(TAG, "onServiceConnected");
            mRobotService = ((RobotService.LocalBinder) service).getService();
            if (!mRobotService.initialize()) {
                //Log.e(TAG, "Unable to initialize Bluetooth");
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
        textView.setEnabled(false);
        textView.setAlpha(.3f);
        textView2 = (TextView) findViewById(R.id.textView2);
        textView2.setEnabled(false);
        textView2.setAlpha(.3f);
        seekbar = (SeekBar) findViewById(R.id.seekBar);
        seekbar.setEnabled(false);
        seekbar.setAlpha(.3f);
        seekbar2 = (SeekBar) findViewById(R.id.seekBar2);
        seekbar2.setEnabled(false);
        seekbar2.setAlpha(.3f);
        button = (Button) findViewById(R.id.ButtonStop);
        button.setEnabled(false);
        button.setAlpha(.3f);
        final ToggleButton toggleButton1 = (ToggleButton) findViewById(R.id.ToggleButton1);
        toggleButton1.setEnabled(false);
        toggleButton1.setAlpha(1f);
        final SwitchCompat PowerSwitch = findViewById(R.id.PWswitch);



        final TextView plainText =  findViewById(R.id.ModeValue);

        seekbar.setProgress(100);
        seekbar2.setProgress(100);
        PowerSwitch.setShowText(true);

        final Intent intent = getIntent();
        mDeviceAddress = intent.getStringExtra(BLEScanActivity.EXTRAS_BLE_ADDRESS);

        //Bind to the BLE Service
        //Log.i(TAG, "Binding Service");
        Intent RobotServiceIntent = new Intent(this, RobotService.class);
        bindService(RobotServiceIntent, mServiceConnection, BIND_AUTO_CREATE);

        seekbar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                int newprogress = progress-100;
                if(newprogress!= oldProgressLeft){
                    mRobotService.setMotorSpeed(RobotService.Motor.RIGHT_WHEEL, newprogress);
                    oldProgressLeft = newprogress;
                }

                //Log.d(TAG, "Left Speed Change to:" + newprogress);
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
                if(newprogress != oldProgressRight){

                    mRobotService.setMotorSpeed(RobotService.Motor.LEFT_WHEEL, newprogress);
                    oldProgressRight = newprogress;
                }

                //Log.d(TAG, "Right Speed Change to:" + newprogress);
                textView2.setText("" + newprogress + "%");
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });


        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                seekbar.setProgress(100);
                seekbar2.setProgress(100);
            }
        });


        toggleButton1.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if(isChecked){
                    seekbar.setProgress(100);
                    seekbar2.setProgress(100);
                    seekbar.setEnabled(false);
                    seekbar.setAlpha(.3f);
                    seekbar2.setEnabled(false);
                    seekbar2.setAlpha(.3f);
                    button.setEnabled(false);
                    button.setAlpha(.3f);
                    plainText.setText("Auto mode ON");


                    //Set robot to roomba mode
                    mRobotService.emptyBleQueue();
                    mRobotService.setRobotMode(1);
                }
                else{
                    seekbar.setEnabled(true);
                    seekbar.setAlpha(1f);
                    seekbar2.setEnabled(true);
                    seekbar2.setAlpha(1f);
                    button.setEnabled(true);
                    button.setAlpha(1f);
                    plainText.setText("Auto mode OFF");
                    //Turn manual control on
                    mRobotService.setRobotMode(0);
                    //Stop Robot
                    mRobotService.setMotorSpeed(RobotService.Motor.RIGHT_WHEEL, 0);
                    mRobotService.setMotorSpeed(RobotService.Motor.LEFT_WHEEL, 0);


                }
            }
        });

        PowerSwitch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(PowerSwitch.isChecked()){
                    seekbar.setEnabled(true);
                    seekbar.setAlpha(1f);
                    seekbar2.setEnabled(true);
                    seekbar2.setAlpha(1f);
                    button.setEnabled(true);
                    button.setAlpha(1f);
                    toggleButton1.setEnabled(true);
                    toggleButton1.setAlpha(1f);

                }
                else{
                    seekbar.setProgress(100);
                    seekbar2.setProgress(100);
                    seekbar.setEnabled(false);
                    seekbar.setAlpha(.3f);
                    seekbar2.setEnabled(false);
                    seekbar2.setAlpha(.3f);
                    button.setEnabled(false);
                    button.setAlpha(.3f);
                    toggleButton1.setEnabled(false);
                    toggleButton1.setAlpha(.3f);
                    mRobotService.emptyBleQueue();
                    mRobotService.setRobotMode(0);//Auto mode
                    mRobotService.setMotorSpeed(RobotService.Motor.RIGHT_WHEEL, 0);//Stop wheels
                    mRobotService.setMotorSpeed(RobotService.Motor.LEFT_WHEEL, 0);


                }
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
            //Log.i(TAG, "Connect request result = "+ result);
        }
    }

    @Override
    protected void onPause(){
        super.onPause();
        unregisterReceiver(mRobotUpdateReceiver);
        mRobotService.close();
    }

    @Override
    protected void onDestroy(){
        mRobotService.emptyBleQueue();
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
                    mRobotService.disconnect();
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
