#include <SPI.h>

SPISettings settings = SPISettings(4000, MSBFIRST, SPI_MODE0);

#define CC1120_CS 12
#define CC1120_MOSI 11
#define CC1120_MISO 10
#define CC1120_SCLK 13

void setup() {
  pinMode(CC1120_CS, OUTPUT);
  pinMode(CC1120_MOSI, OUTPUT);
  pinMode(CC1120_SCLK, OUTPUT);
  pinMode(CC1120_MISO, INPUT);
  SPI.begin();
  //SPI.beginTransaction(settings);
  SPI.setClockDivider(SPI_CLOCK_DIV128);

  digitalWrite(CC1120_CS, HIGH);
  digitalWrite(CC1120_MOSI, HIGH);
  digitalWrite(CC1120_SCLK, LOW);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  /*digitalWrite(CC1120_CS, LOW);
  delayMicroseconds(200);
  send((uint8_t) 0b01010101);
  digitalWrite(CC1120_CS, HIGH);
  delayMicroseconds(2000);
  */
  digitalWrite(CC1120_CS,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(CC1120_CS,LOW);
  digitalWrite(9,LOW);
}

//void send(uint8_t dat){
//
// int j;
// char so=0;
// 
// delay(14);
// Serial.println("\n\n");
// digitalWrite(CC1120_SCLK,0);
// 
// for (j=0; j<8; j++){
//   digitalWrite(CC1120_MOSI,(dat>>j)&1);
//   delay(1);
//   digitalWrite(CC1120_SCLK,1);
//   delay(1);
//   digitalWrite(CC1120_SCLK,0);
//   delay(1);
//   so+=digitalRead(CC1120_MISO)<<j;
//   delay(14);
// }
//
//}
