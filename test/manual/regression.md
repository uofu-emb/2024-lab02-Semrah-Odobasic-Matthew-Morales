# Setting up the test scenario

1. Build and flash the project using the instructions [here](https://github.com/uofu-emb/rtos/blob/main/CMAKE.md)

2. Unplug and replug the USB

# Running the Test

1. Observe the onboard LED. It should blink every 1 second or so

2. Open a serial terminal.

### Linux
`sudo minicom -D /dev/ttyACM0 -b 115200`

3.  Type a lowercase letter. It should show up on the screen as an uppercase letter.

4. Type an uppercase letter. 
