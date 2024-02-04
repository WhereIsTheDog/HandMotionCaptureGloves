#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);

void setup() {
  Serial.begin(9600);

  // Initialize the radio module
  radio.begin();

  // Set the writing pipe address
  radio.openWritingPipe(0xF0F0F0F0E1LL);

  // Set the power amplifier level
  radio.setPALevel(RF24_PA_HIGH);
}

void loop() {
  // Create a character array to store the text message
  char text[] = "Hello, world!";

  // Print a message to indicate that the data is being sent
  Serial.println("Send.");

  // Send the text message through the radio
  radio.write(&text, sizeof(text));

  // Delay for 1 second before sending the next message
  delay(1000);
}
