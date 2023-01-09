# STM32F429I Discovery as a NiMh Battery Charger with TouchGfx framweork

This project uses [STM32F429I Discovery board](http://www.st.com/en/evaluation-tools/32f429idiscovery.html) with some external components to charge *one* NiMh battery. \
TouchGfx graphic software framework was used to develop GUI interface. \
Maximum allowed charging current is **400mA** (and it needs to replace 3.3V LDO on Stm32F429I Disco board), if you dont want to replace 3.3V LDO on STM32F429I Disco board, maximum charging current would be **100mA** 

Run
----
To run this example with 400mA charging current, you need to replace 3.3V 150mA Voltage regulator [LD3985M33R] to 500mA Voltage regulator (for example SPX3819M5-L-3-3) \
Also some external components has to be connected to the board. 

-Shchematic is shown bellow:  \
![alt text](https://github.com/xamrex/Stm32Disco-BattCharger/blob/master/doc/schematic.png)

-Change that needs to be performed on board:  \
![alt text](https://github.com/xamrex/Stm32Disco-BattCharger/blob/master/doc/changes.png)

Get sratred
-------
-Clone project \
-Open .project form STM32CubeIDE folder \
-Flash board


Pics
----
![alt text](https://github.com/xamrex/Stm32Disco-BattCharger/blob/master/doc/mainscreen.jpg)
![alt text](https://github.com/xamrex/Stm32Disco-BattCharger/blob/master/doc/charging.jpg)
