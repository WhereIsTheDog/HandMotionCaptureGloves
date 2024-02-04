#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN  9
#define CSN_PIN 10

const byte thisSlaveAddress[5] = {'R','x','A','A','A'}; //LEFT HAND ADDRESS

RF24 radio(CE_PIN, CSN_PIN);

char dataReceived[10]; // this must match dataToSend in the TX
char ackData[] = {0, 0, 0, 0, 0, 0, 0, 0};
bool newData = false;

//==============
// Setup function
void setup() {
    // Set analog pins as input
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);  
    pinMode(A4, INPUT);
        
    // Initialize the radio
    radio.begin();
    radio.setDataRate( RF24_1MBPS );
    radio.setPALevel(RF24_PA_HIGH);
    
    // Open the reading pipe with the specified address
    radio.openReadingPipe(1, thisSlaveAddress);

    // Enable acknowledgement payload
    radio.enableAckPayload();
    radio.writeAckPayload(1, &ackData, sizeof(ackData)); // pre-load data

    // Start listening for incoming data
    radio.startListening();
}

//==========
// Loop function
void loop() {
    getData();
}

//============
// Function to get data from radio
void getData() {
    if ( radio.available() ) {
        // Read the data received from the radio
        radio.read( &dataReceived, sizeof(dataReceived) );
        // Update the reply data
        updateReplyData();
        newData = true;
    }
}
//================

// Function to update the reply data
void updateReplyData() {
    //For Boneduino must write all pins low

    // Read analog values from pins A0 to A4
    int _A0 = analogRead(A0);  
    int _A1 = analogRead(A1);  
    int _A2 = analogRead(A2);  
    int _A3 = analogRead(A3);
    int _A4 = analogRead(A4);
    
    // Store the analog values in the acknowledgement data array
    ackData[0] = _A0 & 0b0000000011111111;
    ackData[1] = ((_A0 & 0b0000111100000000) >> 8) + ((_A1 & 0b0000000000001111) << 4);
    ackData[2] = ((_A1 & 0b0000111111110000) >> 4);
    ackData[3] = _A2 & 0b0000000011111111;
    ackData[4] = ((_A2 & 0b0000111100000000) >> 8) + ((_A3 & 0b0000000000001111) << 4);
    ackData[5] = ((_A3 & 0b0000111111110000) >> 4);
    ackData[6] = _A4 & 0b0000000011111111;
    ackData[7] = ((_A4 & 0b0000111100000000) >> 8) ;

    // Load the payload for the next time
    radio.writeAckPayload(1, &ackData, sizeof(ackData));
}
