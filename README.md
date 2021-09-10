# Raspberry Pi - SD Card SMART Query
Get S.M.A.R.T Information for Transcend SDXC430T and SDXC450I.

-------------------------
The various statuses of MicroSD products are located in the SMART block of the device. 
By reading and analyzing the SMART block, you can grasp the product name, serial number,
firmware version, Erase count, health, etc. of the device, so as to monitor and find the 
device early potential problems. This document provides a way to read and print SMART 
block to enable SMART command via the MicroSD port on Raspberry Pi.

Hardware requirements
-------------------------
* Raspberry Pi 3 Model B+ with Micro SD port
* Transcend SDXC430T and SDXC450I

Usage
-------------------------

- Download mmc-utils package and modify it to support SMART DUMP function. Please download the source code and modify it step by step.

1. Download the code by following command with terminal.
```
$ git clone https://kernel.googlesource.com/pub/scm/linux/kernel/git/cjb/mmc-utils-old
```

2. Update the files in [folder](https://github.com/WBJisMyName/READMETest/tree/main/mmc-utils-old) to the corresponding files.

3. Use the Make command to compile the updated source code.
```
$ make
```
4. After build success, check the availability of the mmc tool by -h
```
$ ./mmc –h
``` 
5. Get SMART buffer by following command.
```
$ ./mmc smtbuffer /dev/mmcblk0
``` 
6. Get SMART information by following command.
```
$ ./mmc smart /dev/mmcblk0
``` 
7. Get Card life by following command.
```
$ ./mmc health /dev/mmcblk0
``` 

Command Execution
-------------------------
1. To dump SMART raw data</br></br>
![Buffer](https://github.com/transcend-information/RaspberryPi-SDcard-SMARTQuery/blob/main/smtbuffer.png)

2. To show SMART info</br></br>
![SMART](https://github.com/transcend-information/RaspberryPi-SDcard-SMARTQuery/blob/main/smart.png)

3. To show card life(Heath)</br></br>
![Heath](https://github.com/transcend-information/RaspberryPi-SDcard-SMARTQuery/blob/main/health.png)


