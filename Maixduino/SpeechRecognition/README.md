# Speech Recognition

Working with sound was done with Arduino since it has Maix Speech Recognizer library available for Maixduino.

If you want to use the Speech Recognizer in Maixpy, you have to use firmware "minimum speech with ide support". You could possibly also build a custom firmware with https://github.com/sipeed/MaixPy/blob/master/build.md (use maixpy_k210, change settings to enable Speech Recognizer)

Arduino Maixduino library has Maix_Speech_Recognition, which includes get_voice_model.ino and voice_control_led_en.ino that you can use as a base. First you need to run get_voice_model on the board. Open the serial monitor, press reset and speak close to the MEMS microphone on the board. If the recording succeeds, you get a frame number and an array of numbers. These are MFCC (Mel Frequency Cepstral Coefficient) features of the recording. Copy the number of frames and the array to the voice_model.h. You can also modify the strings to represent your commands.

There are 2628 elements in each array and there are many zeros if your recordings are short. The time limit specified in the library is 2.2 seconds. You can change the limit in ../libraries/Maix_Speech_Recognition/src/util/MFCC.h line 15

```c
#define vv_tim_max 2200
```

After changing, for example to 1000 ms, if you compile your program, you will see an error like

```c
src/voice_model.h:91:1: error: too many initializers for 'const int16_t [1188]' {aka 'const short int [1188]'}
```

this means your array has to be 1188 in length so you need to make sure your array matches the length.

After recording, save your voice_model.h. Then you can use voice_control_led_en.ino as a base to create your own program and add your own functionality. First you can just make the program print text to see if it's able to recognize your commands correctly.

In this code I said "Hey Maix", "Shut down" and "Blink" and clapped hands twice and whistled. It might not work as well for other people if they don't make their own voice model but maybe whistling and clapping hands could be easier for it to recognize.

## How it works
The Speech Recognizer works best for isolated word cases like Wake Words. Vocabulary is recorded and it is made into a recognizable template with algorithms. If the algorithm module is loaded with a vocabulary template, then when it receives input data through recording, it will perform internal matching and output the most likely recognition result. 

The identification process of the Speech Recognizer module includes pre-filtering, ADC, framing, endpoint detection, pre-emphasis, windowing, feature extraction and feature matching. Endpoint detection (VAD, voice activity detection) uses short-term amplitude and short-term zero-crossing rate. When speech is detected, MFCC of each frame is calculated. After that, dynamic time warping (DTW) algorithm matches the feature template and the result is output.

More information:
- Speech Recognizer, wiki: https://wiki.sipeed.com/soft/maixpy/en/course/speech/recognizer_mfcc.html 
	- sample code for Maixpy, also API here: https://wiki.sipeed.com/soft/maixpy/en/api_reference/machine_vision/isolated_word.html
- Maix asr, automatic speech recognition for acoustic model, wiki: https://wiki.sipeed.com/soft/maixpy/en/course/speech/recognizer_cnn.html
	- API: https://wiki.sipeed.com/soft/maixpy/en/api_reference/machine_vision/maix_asr.html 
- More about MFCC's: https://medium.com/@tanveer9812/mfccs-made-easy-7ef383006040 
- More about DTW: https://towardsdatascience.com/dynamic-time-warping-3933f25fcdd 

## speech_recognizer.py

I wanted to include this sample code here, because it was actually hard to find. I found it from here: https://robopara.co.jp/voice_command_recognition_with_maixduino_using_maixpy/. Maybe at one point it was available in Sipeed's Github but not anymore for some reason. So you might be better off using these instead: https://github.com/sipeed/MaixPy_scripts/tree/master/multimedia/speech_recognizer

In this code, the program records 5 voice commands. After recording, it starts recognizing. The recorded command and the registered voice are compared and the output result is the closest match. It will also try to match unregistered commands to the registered ones. It can also return "None" when it doesn't recognize something. When the program recognizes a command, it prints out a recognition matrix. The first number is the index of the registered command. There was no information available what the next three numbers mean but the second number could have something to do with the confidence level.
