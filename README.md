# BLERobot

Batman is an app controlled robot with two main functions:
* Autonomous mode: The robot will self-drive avoiding any collisions, if it detects empty space in front of it, it'll also try to avoid it
* Driven mode: with the BLE app in the repository

# Requirements
![Robot Photo](https://res.cloudinary.com/toreckk/image/upload/c_scale,h_1600/v1559401467/WhatsApp_Image_2019-05-23_at_10.10.29.jpg)
## Hardware
The following items where used to build the robot:

- [Ultrasonic Ranging Module](https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf)
- [L298N Dual H-Bridge Motor Driver](http://www.handsontec.com/dataspecs/L298N%20Motor%20Driver.pdf)
- [LRE-F22 Line Follower](http://adelat.org/media/docum/ard/sensor_lref22_seguidor_luz_y_lnea.html)
- PSoC 4 w/ BLE
- 2 DC Motors + 2 Wheels
- 3D-Printed Chassis + PSoC Holder
- Batteries

## Software
The following items are needed to load the software on the PsoC4 and android phone

- Android Studio
- PSoC Creator
