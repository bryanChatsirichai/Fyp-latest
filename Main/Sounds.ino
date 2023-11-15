
//using jp8900-16p to play the speaker

uint8_t checkSum(uint8_t data[] , int dataSize) {
  uint8_t sum = 0 ;
  for (int i=0;i<dataSize;i++) {
    sum += data[i] ;
  }
  return sum ;
}

// ボリューム設定 vol:0x00-0x1E
void volume( unsigned char vol) {
  unsigned char commands[5] = {0xAA,0x13,0x01,0x00,0x00};
  commands[3] = vol ; 
  commands[4] = checkSum(commands,4) ; 
  SoftwareSerial.write(commands,5);
}

//The specified track number (track number) will be the order copied to the flash memory (copy sequence).
void play(int Track) {
  uint8_t commands[6] = {0xAA,0x07,0x02,0x00,0x00,0x00};
  // Serial.print("HBYTE-");
  // Serial.println(commands[3]);
  // Serial.print("LBYTE-");
  // Serial.println(commands[4]);
  // Serial.print("checkSum-");
  // Serial.println(commands[5]);
  commands[3] = HBYTE(Track) ; 
  commands[4] = LBYTE(Track) ; 
  commands[5] = checkSum(commands,5) ; 
  SoftwareSerial.write(commands,6);
  // while(digitalRead(BUSY_PIN) != LOW){
  //   Serial.println("analogRead(BUSY_PIN)");
  // }
  // delay(500);
}


void play_sound_1(){
  play(1);
  delay(3000);
}

void play_sound_2(){
  play(2);
  delay(3000);
}

void play_sound_3(){
  play(3);
  delay(3000);
}
void play_sound_4(){
  play(4);
  delay(15000);
}
// void play_stop_sound(){}