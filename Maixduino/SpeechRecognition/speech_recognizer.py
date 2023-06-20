# Copyright (c) sipeed.com
#
# Licensed under the MIT license:
#   http://www.opensource.org/licenses/mit-license.php
#

import time
from Maix import GPIO, I2S
from fpioa_manager import fm
import lcd
from speech_recognizer import isolated_word


# user setting
NUM_VOICE_DATA = 5 #39 is the max tested up to 30
SAMPLE_RATE   = 16000

#register pin configurations for i2s (audio device)
fm.register(20,fm.fpioa.I2S0_IN_D0, force=True)
fm.register(18,fm.fpioa.I2S0_SCLK, force=True)
fm.register(19,fm.fpioa.I2S0_WS, force=True)

#initialize i2s
rx = I2S(I2S.DEVICE_0)
rx.channel_config(rx.CHANNEL_0, rx.RECEIVER, align_mode=I2S.STANDARD_MODE)
rx.set_sample_rate(SAMPLE_RATE)
#print(rx)

#initialize lcd
lcd.init()

#initialize speech recognizer
# default: maix dock / maix duino set shift=0
# maix bit set shift=1
sr = isolated_word(dmac=2, i2s=I2S.DEVICE_0, size=NUM_VOICE_DATA, shift=0)
#print(sr.size())
#print(sr)

#set speech recognizer threshold
#first 2 params are not used,
#the last param is the noise threshold default 10000
sr.set_threshold(0, 0, 20000)

#function prompts speech recognizer status
def print_sr_state(state):
    state_strings={
        0: "none",
        1: "record_wait_speeking",
        2: "record_success",
        3: "recog_wait_speeking",
        4: "recog_sucess",
        5: "got_noise"}
    print(state_strings.get(state,"none"))

#-----------------------------------------------
#starting speech recognition logic
#it will record voice command for a given num of times and save it to the speech recognizer.
#then, it will listne for the voice command and display the result.
#------------------------------------------------
lcd.draw_string(60, 100, "Voice Command Demo", lcd.RED, lcd.BLACK)

index = 0
#Record and save the voice command data for the given times.
while True:
    time.sleep_ms(100)
    #print(sr.state())
    print_sr_state(sr.state())
    #redords and save the data to 0
    if sr.Done == sr.record(index):
        #data = sr.get(index)
        #print(data)
        index = index + 1
        if index == NUM_VOICE_DATA:
            break

    if sr.Speak == sr.state():
        lcd.draw_string(60, 100, "recording voice command: %d" % index, lcd.RED, lcd.BLACK)
        print('recording voice command: #', index)

#other speech recognizer methods
#sr.set(3, data)
#sr.stop()
#sr.run()

print('start recognizing')
while True:
    time.sleep_ms(200)
    #print(sr.state())
    #print(sr.dtw(data))
    if sr.Done == sr.recognize():
        res = sr.result()
        lcd.clear()
        lcd.draw_string(60, 100, "Result %s" % (res,), lcd.RED, lcd.BLACK)
        print(res)
