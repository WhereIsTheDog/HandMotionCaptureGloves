// Initialize an array of 16 bytes with all elements set to 0
char data[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//==============

void setup() {
    Serial.begin(115200);

    // Initialize LEFT HAND pins
    pinMode(A0, INPUT);
    pinMode(A1, INPUT);
    pinMode(A2, INPUT);
    pinMode(A3, INPUT);  
    pinMode(A4, INPUT);

    // Initialize RIGHT HAND pins
    // pinMode(A8, INPUT);
    // pinMode(A9, INPUT);
    // pinMode(A10, INPUT);
    // pinMode(A11, INPUT);  
    // pinMode(A12, INPUT);
}

//==========

void loop() {
    // Now do the LEFT HAND
    int _A0 = analogRead(A0);  
    // int _A1 = analogRead(A1);  
    // int _A2 = analogRead(A2);  
    // int _A3 = analogRead(A3);
    // int _A4 = analogRead(A4);  
    // data[0] = _A0 & 0b0000000011111111;
    // data[1] = ((_A0 & 0b0000111100000000) >> 8) + ((_A1 & 0b0000000000001111) << 4);
    // data[2] = ((_A1 & 0b0000111111110000) >> 4);
    // data[3] = _A2 & 0b0000000011111111;
    // data[4] = ((_A2 & 0b0000111100000000) >> 8) + ((_A3 & 0b0000000000001111) << 4);
    // data[5] = ((_A3 & 0b0000111111110000) >> 4);
    // data[6] = _A4 & 0b0000000011111111;
    // data[7] = ((_A4 & 0b0000111100000000) >> 8) ;
    // Serial.write(data, 8); //data_left

    // Now do the RIGHT HAND
    // int _B0 = analogRead(A8);  
    // int _B1 = analogRead(A9);  
    // int _B2 = analogRead(A10);  
    // int _B3 = analogRead(A11);
    // int _B4 = analogRead(A12);  
    // data[0] = _B0 & 0b0000000011111111;
    // data[1] = ((_B0 & 0b0000111100000000) >> 8) + ((_B1 & 0b0000000000001111) << 4);
    // data[2] = ((_B1 & 0b0000111111110000) >> 4);
    // data[3] = _B2 & 0b0000000011111111;
    // data[4] = ((_B2 & 0b0000111100000000) >> 8) + ((_B3 & 0b0000000000001111) << 4);
    // data[5] = ((_B3 & 0b0000111111110000) >> 4);
    // data[6] = _B4 & 0b0000000011111111;
    // data[7] = ((_B4 & 0b0000111100000000) >> 8) ;
    // Serial.write(data, 8); //data_right

    // Print the analog readings of the LEFT HAND pins
    Serial.print("A0:");
    Serial.println(_A0);
    Serial.print("A1:");
    Serial.println(analogRead(A1));
    Serial.print("A2:");
    Serial.println(analogRead(A2));
    Serial.print("A3:");
    Serial.println(analogRead(A3));
    Serial.print("A4:");
    Serial.println(analogRead(A4));
    Serial.print("A5:");
    Serial.println(analogRead(A5));
    Serial.println();
    delay(1000);
}
