# Tiny ML Trials
## ESP32-CAM
### Installation
Install ESP32-CAM: https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/

ESP32-CAM with ESP32-CAM-MB: https://randomnerdtutorials.com/upload-code-esp32-cam-mb-usb/ 

In our case, Board AI Thinker ESP32-CAM works. You can use ESP32 Dev Module if you're unsure of the model.

## Code
### BlinkExample
Basic Blink example to test the board. Pin 33 for internal led or pin 4 for flash.
### ESP32_CameraWebServer
Library example code to test the camera on a web server.
### ESP32_Camera_Person_recognition
Example code that determines the likelyhood that an image contains a person. Prints a number between 0 and 255(0 = not likely) to serialMonitor.
You need to install these libraries to get this piece of code working:
- EloquentTinyML
- EloquentArduino

### ESP32_Sine_wave_prediction_TensorflowLite
Example project that demonstrates mleverywhere python package. This package converts ready made Tensorflow models to source codes that can run on ESP32. 

In this case a simple sinewave prediction model has been converted and tested on ESP32 via ArduinoIDE and EloquentTinyML library.
