#include <Adafruit_SSD1306.h>
#include <qrcode.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define QR_SIZE 3 // Set the size of the QR code (3-10)

void setup() {
  // Initialize the display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Generate the QR code
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(QR_SIZE)];
  qrcode_initText(&qrcode, qrcodeData, QR_SIZE, ECC_LOW, "Hello, World!");

  // Display the QR code
  for (uint8_t y = 0; y < qrcode.size; y++) {
    for (uint8_t x = 0; x < qrcode.size; x++) {
      if (qrcode_getModule(&qrcode, x, y)) {
        display.drawPixel(x + 28, y + 20, WHITE);
      } else {
        display.drawPixel(x + 28, y + 20, BLACK);
      }
    }
  }
  
  display.display();
}

void loop() {
  // Nothing to do here
}
