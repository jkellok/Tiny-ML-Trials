# Tiny ML Trials
## Maixduino
### Installation and documentation

https://wiki.sipeed.com/hardware/en/maix/maixpy_develop_kit_board/maix_duino.html

#### Arduino
https://maixduino.sipeed.com/en/

#### MaixPy
Use MaixPy with Python (.py files)

https://wiki.sipeed.com/soft/maixpy/en/get_started/install_driver/duino.html

Install USB Driver: https://dl.sipeed.com/MAIX/tools/driver

Update MaixPy Firmware: 
https://wiki.sipeed.com/soft/maixpy/en/get_started/upgrade_maixpy_firmware.html

Download kflash_gui tool: https://github.com/sipeed/kflash_gui/releases

Download firmware and upload to Maixduino with kflash_gui

http://www.86x.org/cn-maixpy/cn.maixpy.sipeed.com/en/get_started/maixpyide.html

You can download MaixPy IDE: https://dl.sipeed.com/shareURL/MAIX/MaixPy/ide/_/v0.2.5

You can also use a serial terminal tool, like putty: 

http://www.86x.org/cn-maixpy/cn.maixpy.sipeed.com/en/get_started/power_on.html

#### Notes
The camera on the board is GC0328. You may need to download Maixduino_GC0328 library: 	https://github.com/fukuen/Maixduino_GC0328

If you have error with the lcd screen (like in display.ino example code in Arduino) you can remove Adafruit_GFX library from Arduino/libraries folder.

## Code
### BlinkExample
A basic Blink example to test the board.

### MaixduinoCamera
Example code to test the camera and the lcd screen.
You need GC0328 library.

### VoiceControlExample
Example code to test voice control. Use get_voice_model.ino first to record your commands. Run the code, open serial monitor, press reset on the board and talk to the microphone. You will get number of frames and an array for numbers. Copy these to the voice_model.h. You can press reset again when you want to record another command. In this example, there are four recordings each for "red", "green", "blue" and "turn off". Save voice_model.h and run voice_control_led_en.ino to test your voice to change the led color. Each model can have up to four recordings keyed to it and the SpeechRecognizer can have 20 models registered.

### ObjectRecognitionYolo
Example code to test object recognition. For this, klash_gui and MaixPy IDE was used. You could use an SD card instead of klash_gui.

You can follow along this tutorial: https://www.edgemicrotech.com/maixpy-9-maixduino-object-detection-ai-micropython/

YOLOv2 is a pre-trained object detection system: https://pjreddie.com/darknet/yolov2/

Flash the .kmodel to Maixduino with kflash_gui to the 0x500000 address. You can use baudrate 115200. Then do the same with .kfpkg file. Then connect and run the python file.