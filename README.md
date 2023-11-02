# Monitor SD card health and status using Raspberry Pi
Get S.M.A.R.T data for Transcend Embedded MicroSD / SD products. 

-------------------------
The various statuses of MicroSD products are located in the SMART block of the device. 
By reading and analyzing the SMART block, you can get the product name, serial number, firmware version, Erase count, health, etc. of the device, so as to monitor and find the 
device early potential problems. This document provides a way to use the MMC test tools called mmc-utils that get SMART block to enable SMART command via the native MicroSD slot on Raspberry Pi. 

**Note : The project works for Transcend Embedded MicroSD / SD products.**

Hardware requirements
-------------------------
* Raspberry Pi 1 or later model.
* Transcend Embedded MicroSD 430T / 450I / 460I / 460T or
 Transcend Embedded SD SDC460T / SDC400I / SDC240T with Raspberry Pi 1.

Install Raspberry Pi OS
-------------------------
1. Download and install Raspberry Pi OS Imager(64-bit or 32-bit) to the tartget MicroSD with an SD card reader at https://www.raspberrypi.com/software

2. Insert the MicroSD to Raspberry Pi native MicroSD or SD slot.

Usage
-------------------------

- The mmc-utils package and modify it to support SMART DUMP function. Please download the source code and modify it step by step.

1. Download the code by following command with terminal.
   
```
 git clone https://kernel.googlesource.com/pub/scm/linux/kernel/git/cjb/mmc-utils-old
```

2. Update the 4 files in mmc-utils [folder](https://github.com/transcend-information/RaspberryPi-SDcard-SMARTQuery/tree/main/mmc-utils) to the corresponding files.

3. Use the Make command to compile the updated source code.

```
 make
```

4. After build success, check the availability of the mmc tool by -h

```
 sudo ./mmc –h
``` 
5. Get SMART buffer by following command.

```
 sudo ./mmc smtbuffer /dev/mmcblk0
```
 
6. Get SMART information by following command.

```
 sudo ./mmc smart /dev/mmcblk0
```

7. Get Card life by following command.
   
```
 sudo ./mmc health /dev/mmcblk0
``` 

Command Execution
-------------------------
1. To dump SMART raw data</br></br>
![Buffer](https://github.com/transcend-information/RaspberryPi-SDcard-SMARTQuery/blob/main/smtbuffer.png)

2. To show SMART info</br></br>
![SMART](https://github.com/transcend-information/RaspberryPi-SDcard-SMARTQuery/blob/main/smart.png)

3. To show card life(Heath)</br></br>
![Heath](https://github.com/transcend-information/RaspberryPi-SDcard-SMARTQuery/blob/main/health.png)

Note: For other SMART Data Structure, please refer to Transcend Embedded MicroSD / SD datasheet.</br>
![sdsmart](https://github.com/transcend-information/RaspberryPi-SDcard-SMARTQuery/blob/main/sdsmart.PNG)
