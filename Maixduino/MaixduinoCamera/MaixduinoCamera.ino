#include <Maixduino_GC0328.h>   // replaced Sipeed_OV2640.h with https://github.com/fukuen/Maixduino_GC0328
#include <Sipeed_ST7789.h>

SPIClass spi_(SPI0); // MUST be SPI0 for Maix series on board LCD
Sipeed_ST7789 lcd(320, 240, spi_);

Maixduino_GC0328 camera(FRAMESIZE_QVGA, PIXFORMAT_RGB565);


void setup()
{
    Serial.begin(115200);
    lcd.begin(15000000, COLOR_RED);
    if(!camera.begin())
      Serial.printf("camera init fail\n");
    else
      Serial.printf("camera init success\n");
    camera.run(true);
}

void loop()
{
  uint8_t*img = camera.snapshot();
  if(img == nullptr || img==0)
    Serial.printf("snap fail\n");
  else
    lcd.drawImage(0, 0, camera.width(), camera.height(), (uint16_t*)img);
}
