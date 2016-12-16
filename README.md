# TeensyUserBackdoorOSX
A backdoor script for the Teensy microcontroller to connect over netcat!

When plugged in, the Teensy will pretend to be a Human Interface Device (HID) and start a netcat daemon on the host computer.

Here's a breakdown of what happens:
1. Spotlight is opened and the Terminal application is lauched
2. A bash script called connect.sh is placed in a hidden folder inside the ~/Library directory that starts an outgoing netcat connection to the specified IP address
3. A launch daemon is configured to run every 60 seconds and attempt to run the connect.sh script
4. Terminal is quit and the built-in LED of the Teensy will flash 10 times signaling it's complete

All of this happens within seconds, increase delays if you'd like to see the results slowly.

I am not responsible for any harm caused by this code, it is simply a POC.