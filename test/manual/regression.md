# Setting up the test scenario

1. Build and flash the project using the instructions [here](https://github.com/uofu-emb/rtos/blob/main/CMAKE.md)

2. Unplug and replug the USB

# Exercise the system

1. Observe the onboard LED. 

2. Open a serial terminal.

### Linux
`sudo minicom -D /dev/ttyACM0 -b 115200`

3.  Type a lowercase letter.

4. Type an uppercase letter. 

5. Input a non-letter character.

# Expected result

1. The LED should blink about every second

2. Lowercase letters should be printed out as uppercase

3. Uppercase letters should be printed out as lowercase

4. Other characters will be returned as-is
