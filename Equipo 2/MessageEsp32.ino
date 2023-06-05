#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>    //  max7219 library

int pinCS = 5; // Attach CS to this pin, DIN to MOSI and CLK to SCK 

Max72xxPanel matrix = Max72xxPanel(pinCS, 1, 1);

const char* ssid     = "Root";
const char* password = "macaco98"; 

// Inicializa Bot Telegram
#define BOTtoken "5947289800:AAF39PkuLyEH3cbq0hoEEcDti6OweeNKO2M"  // Tu Bot Token (Obtener de Botfather)

#define CHAT_ID "@TesiEdu_bot"

WiFiClientSecure client;

UniversalTelegramBot bot(BOTtoken, client);

void handleNewMessages() {

    // Chat id of the requester
    String chat_id = String(bot.messages[0].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Usuario no autorizado", "");
    }

    String text = bot.messages[0].text;

    //Draw scrolling text
    int spacer = 1;                            // This will scroll the string
    int width = 5 + spacer;                    // The font width is 5 pixels
    for ( int i = 0 ; i < width * text.length() + width + 2; i++ ) {
      matrix.fillScreen(0);

      int letter = i / width;
      int x = (matrix.width() - 1) - i % width;
      int y = (matrix.height() - 8) / 2; // center the text vertically

      while ( x + width - spacer >= 0 && letter >= 0 ) {
        if ( letter < text.length() ) {
          matrix.drawChar(x, y, text[letter], 1, 0, 1);
        }
        letter--;
        x -= width;
      }
      matrix.write(); // Send bitmap to display

      delay(100);
    }
  
}

void setup() {
  matrix.setIntensity(4); // Set brightness between 0 and 15
  matrix.fillScreen(0);
  WiFi.begin(ssid, password);
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  bot.sendMessage(CHAT_ID, "Bot iniciado", "");
}

void loop() {
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  handleNewMessages();
  delay(200);
}
