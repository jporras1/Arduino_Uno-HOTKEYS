# Arduino_Uno-HOTKEYS

This is based on the work done by this [source](https://www.youtube.com/watch?v=wTbjmulNSlw).

___

How it works, you will need to first change the firmware on the 16u2 chip on arduino Uno board. It requires a genuine arduino uno with this chip and not one with a different FTDI chip.

First you will need to modify the ATmega328p firmware by adding in your hotkeys. In the new state, it should be fairly easy to follow the way the file is set up.

Next the keyboard firmware and the original firmware can be found HERE, but the methods to change the firmware can easily be found [here](https://www.arduino.cc/en/Hacking/DFUProgramming8U2).

___
Tips:
The best way I found to do this was to keep the 16u2 chip, and then upload the changes to the ATmega328p using a USBTinyisp programmer.
