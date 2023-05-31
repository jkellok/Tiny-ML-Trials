### VoiceControlExample
Example code to test voice control. Use get_voice_model.ino first to record your commands. Run the code in Arduino, open serial monitor, press reset on the board and talk to the microphone. 

You will get number of frames and an array for numbers. Copy these to the voice_model.h. You can press reset again when you want to record another command. In this example, there are four recordings each for "red", "green", "blue" and "turn off". 

Save voice_model.h and run voice_control_led_en.ino to test your voice to change the led color. Each model can have up to four recordings keyed to it and the SpeechRecognizer can have 20 models registered.
