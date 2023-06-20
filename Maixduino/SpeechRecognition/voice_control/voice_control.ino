#include "Maix_Speech_Recognition.h"
#include "voice_model.h"
#include <Sipeed_ST7789.h>

#define LABEL_TEXT_SIZE     2 // 2x font size
#define BG_COLOR            COLOR_RED

// pins for Maixduino RGB
#define LED_GREEN 10
#define LED_RED 9
#define LED_BLUE 8

SPIClass spi_(SPI0); // MUST be SPI0 for Maix series on board LCD
Sipeed_ST7789 lcd(320, 240, spi_, SIPEED_ST7789_DCX_PIN, SIPEED_ST7789_RST_PIN, DMAC_CHANNEL2);

SpeechRecognizer rec;

void printCenterOnLCD(Sipeed_ST7789 &lcd_, const char *msg, uint8_t textSize = LABEL_TEXT_SIZE) 
{
    lcd_.setCursor((lcd_.width() - (6 * textSize * strlen(msg))) / 2, (lcd_.height() - (8*textSize)) / 2);
    lcd_.print(msg);
}

void setup()
{
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    rec.begin();
    Serial.begin(115200);
    if (!lcd.begin(15000000, BG_COLOR)) {
      Serial.println("init lcd...");
    }

    lcd.setTextSize(LABEL_TEXT_SIZE);
    lcd.setTextColor(COLOR_WHITE);
    
    Serial.println("init model...");
    printCenterOnLCD(lcd, "Init model...");
    rec.addVoiceModel(0, 0, hey_maix_0, fram_num_hey_maix_0); // said "hey maix"
    rec.addVoiceModel(0, 1, hey_maix_1, fram_num_hey_maix_1); 
    rec.addVoiceModel(0, 2, hey_maix_2, fram_num_hey_maix_2); 
    rec.addVoiceModel(0, 3, hey_maix_3, fram_num_hey_maix_3); 
    rec.addVoiceModel(1, 0, shut_down_0, fram_num_shut_down_0); // said "shut down"
    rec.addVoiceModel(1, 1, shut_down_1, fram_num_shut_down_1);     
    rec.addVoiceModel(1, 2, shut_down_2, fram_num_shut_down_2);     
    rec.addVoiceModel(1, 3, shut_down_3, fram_num_shut_down_3);     
    rec.addVoiceModel(2, 0, clap_0, fram_num_clap_0); // clapped hands twice quickly
    rec.addVoiceModel(2, 1, clap_1, fram_num_clap_1);   
    rec.addVoiceModel(2, 2, clap_2, fram_num_clap_2);   
    rec.addVoiceModel(2, 3, clap_3, fram_num_clap_3);   
    rec.addVoiceModel(3, 0, whistle_0, fram_num_whistle_0); // whistled
    rec.addVoiceModel(3, 1, whistle_1, fram_num_whistle_1);  
    rec.addVoiceModel(3, 2, whistle_2, fram_num_whistle_2);  
    rec.addVoiceModel(3, 3, whistle_3, fram_num_whistle_3);  
    rec.addVoiceModel(4, 0, blink_0, fram_num_blink_0); // said "blink"
    rec.addVoiceModel(4, 1, blink_1, fram_num_blink_1);
    rec.addVoiceModel(4, 2, blink_2, fram_num_blink_2);
    rec.addVoiceModel(4, 3, blink_3, fram_num_blink_3);
    Serial.println("init model ok!");
    lcd.fillScreen(BG_COLOR);
    printCenterOnLCD(lcd, "Model ok");
    delay(500);
}
void loop()
{
    int res;
    lcd.fillScreen(BG_COLOR);
    printCenterOnLCD(lcd, "Waiting for Wake Word...");
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_BLUE, HIGH);
    
    res = rec.recognize();
    Serial.printf("res : %d ", res);
    lcd.fillScreen(BG_COLOR);
    
    if (res > 0){
        switch (res)
        {
        case 1:
            digitalWrite(LED_RED, LOW); //power on red led
            digitalWrite(LED_GREEN, HIGH);
            digitalWrite(LED_BLUE, HIGH);
            Serial.println("rec : hey maix ");
            printCenterOnLCD(lcd, "I heard 'hey maix'");
            break;
        case 2:
            digitalWrite(LED_GREEN, LOW); //power on green led
            digitalWrite(LED_RED, HIGH);
            digitalWrite(LED_BLUE, HIGH);
            Serial.println("rec : shut down ");
            printCenterOnLCD(lcd, "I heard 'shut down'");
            break;
        case 3:
            digitalWrite(LED_BLUE, LOW); //power on blue led
            digitalWrite(LED_RED, HIGH);
            digitalWrite(LED_GREEN, HIGH);
            Serial.println("rec : clap ");
            printCenterOnLCD(lcd, "I heard 'clap'");
            break;
        case 4:
            digitalWrite(LED_RED, LOW);
            digitalWrite(LED_GREEN, LOW);
            digitalWrite(LED_BLUE, HIGH);
            Serial.println("rec : whistle ");
            printCenterOnLCD(lcd, "I heard 'whistle'");
            break;
        case 5:
            digitalWrite(LED_RED, LOW);
            digitalWrite(LED_GREEN, HIGH);
            digitalWrite(LED_BLUE, LOW);
            Serial.println("rec : blink ");
            printCenterOnLCD(lcd, "I heard 'blink'");
            break;
        default:
            break;
        }
    }else
    {
        Serial.println("recognize failed.");
        printCenterOnLCD(lcd, "Recognizing failed");
    }
    delay(1000);
}
