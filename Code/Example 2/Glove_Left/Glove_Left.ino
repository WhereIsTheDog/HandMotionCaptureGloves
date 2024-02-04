#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);

void setup() {
  Serial.begin(9600);

  // Initialize the radio module
  radio.begin();

  // Set the reading pipe address
  radio.openReadingPipe(1, 0xF0F0F0F0E1LL);

  // Set the power amplifier level
  radio.setPALevel(RF24_PA_HIGH);

  // Start listening for incoming data
  radio.startListening();
}

void loop() {
  // Check if there is available data to receive
  if (radio.available()) {
    char receivedText[32] = "";

    // Read the received data into the buffer
    radio.read(&receivedText, sizeof(receivedText));

    // Print the received data to the serial monitor
    Serial.println(receivedText);
  }
}
