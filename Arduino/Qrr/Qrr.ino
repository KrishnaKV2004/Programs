#include <Adafruit_SSD1306.h>
#include <qrcode.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define QR_SIZE 2// Set the size of the QR code (3-10)
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64

void setup() {
  // Initialize the display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Generate the QR code
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(QR_SIZE)];
  qrcode_initText(&qrcode, qrcodeData, QR_SIZE, ECC_LOW, "Hello, World!");

  // Calculate starting pixel coordinates for the x and y axes to center the QR code
  int startX = (DISPLAY_WIDTH - (qrcode.size + 2) * QR_SIZE) / 2;
  int startY = (DISPLAY_HEIGHT - (qrcode.size + 2) * QR_SIZE) / 2;

  // Display the QR code
  for (uint8_t y = 0; y < qrcode.size; y++) {
    for (uint8_t x = 0; x < qrcode.size; x++) {
      if (qrcode_getModule(&qrcode, x, y)) {
        display.drawPixel(x * QR_SIZE + startX, y * QR_SIZE + startY, WHITE);
        for (int i = 1; i < QR_SIZE; i++) {
          display.drawPixel(x * QR_SIZE + startX + i, y * QR_SIZE + startY, WHITE);
          display.drawPixel(x * QR_SIZE + startX, y * QR_SIZE + startY + i, WHITE);
          display.drawPixel(x * QR_SIZE + startX + i, y * QR_SIZE + startY + i, WHITE);
        }
      } else {
        display.fillRect(x * QR_SIZE + startX, y * QR_SIZE + startY, QR_SIZE, QR_SIZE, BLACK);
      }
    }
  }
  
  display.display();
}

void loop() {
  // Nothing to do here
}
