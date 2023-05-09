// Record voice first, open serial monitor, press reset and say something
// Copy fram_num and array to voice_model.h file
#include "Maix_Speech_Recognition.h"

SpeechRecognizer rec;

void setup()
{ 
    rec.begin();
    Serial.begin(115200);
    Serial.println("start rec...");
    if( rec.record(0, 0) == 0) //keyword_num, model_num 
    {    
      rec.print_model(0, 0);
    }
    else 
        Serial.println("rec failed");
}

void loop()
{
}
