#include <SPI.h>
#include "CC1120.h"

SPISettings s = SPISettings(4000, MSBFIRST, SPI_MODE0);
#define CC1120_CS 12
#define CC1120_MOSI 11
#define CC1120_MISO 10
#define CC1120_SCLK 13
#define CC1120_RESET 7
#define CC1120_READ 0x80
#define CC1120_EXTENDED_ADDRESS 0x2f
#define PKTLEN                  30  // 1 < PKTLEN < 126

#define CC1120_SRES 0x30
#define CC1120_SFSTXON 0x31
#define CC1120_SXOFF 0x32
#define CC1120_SRX 0x34
#define CC1120_STX 0x35
#define CC1120_SIDLE 0x36
#define CC1120_SFRX 0x3a
#define CC1120_SFTX 0x3b
#define CC1120_SNOP 0x3d

#define CC1120_FIFO 0x3F


#define PARTNUMBER 0x8f
#define PARTVERSION 0x90

void cc1120_init_pins() {
  pinMode(CC1120_CS, OUTPUT);
  digitalWrite(CC1120_CS, HIGH);
  pinMode(CC1120_MOSI, OUTPUT);
  digitalWrite(CC1120_MOSI, HIGH);
  pinMode(CC1120_MISO, OUTPUT);
  digitalWrite(CC1120_MISO, HIGH);
  pinMode(CC1120_SCLK, OUTPUT);
  digitalWrite(CC1120_SCLK, HIGH);
  
  pinMode(CC1120_RESET, OUTPUT);
  digitalWrite(CC1120_RESET, HIGH);

  //SPI.begin();
//  cc1120_write(FREQ0, 00);
//  cc1120_write(FREQ1, 0x80);
//  cc1120_write(FREQ2, 0x6C);
}

void cc1120_spi_enable() {
  //SPI.beginTransaction(s);
  digitalWrite(CC1120_CS, LOW);
}

void cc1120_spi_disable() {
  digitalWrite(CC1120_CS, HIGH);
  //SPI.endTransaction();
}

void cc1120_strobe(uint8_t command) {
  cc1120_spi_enable();
  Send_SPI(CC1120_READ | command);
  cc1120_spi_disable();
}

uint8_t cc1120_write(uint8_t address, uint8_t data) {
  uint8_t result;
  cc1120_spi_enable();
  Send_SPI(address);
  result = Send_SPI(data);
  cc1120_spi_disable();
  return result;
}

uint8_t cc1120_read(uint8_t address) {
  return cc1120_write(CC1120_READ | address, 0);
}

uint8_t cc1120_read_rx() {
  return 0;
}

/*uint8_t cc1120_tx_write(uint8_t data) {
  cc1120_spi_enable();
  SPI.transfer(CC1120_READ | CC1120_FIFO);
  SPI.transfer(data);
  cc1120_spi_disable();
}*/

uint8_t cc1120_read_extended(uint8_t address) {
  uint8_t result;
  cc1120_spi_enable();
  Send_SPI(CC1120_READ | CC1120_EXTENDED_ADDRESS);
  Send_SPI(address);
  result = Send_SPI(0xff);
  cc1120_spi_disable();
  return result;
}

void cc1120_mode_idle() {
  cc1120_strobe(CC1120_SIDLE);
  delay(20);
}

void cc1120_mode_rx() {
  cc1120_strobe(CC1120_SRX);
  delay(20);
}

uint8_t read_rx() {
uint8_t stat;
  while(stat!=0x10)
  stat = Send_SPI(0x00)&0xF0;
return Send_SPI(0xff);
}

void cc1120_mode_tx() {
  cc1120_strobe(CC1120_STX);
  delay(20);
}

void cc1120_reset() {
  cc1120_strobe(CC1120_SRES);
  delay(20);
}

char Send_SPI(char verzenden){
  uint8_t so = 0x00;
  uint8_t i = 0;
  //NSDELAY
  // data transfer
  for (i = 8; i > 0; i--) {
    // Slave Input write
    digitalWrite(CC1120_MOSI, (verzenden >> i-1) & 0x01);
    // SCLK up
    digitalWrite(CC1120_SCLK, HIGH);
    // Slave Output read
    so |= (uint8_t) digitalRead(CC1120_MISO) << i-1;
    //NSDELAY
    // SCLK down
    digitalWrite(CC1120_SCLK, LOW);
    // wait t_sd = 10 ns
    //NSDELAY
  }
        return verzenden;
}




void setup() {
  cc1120_init_pins();
  cc1120_reset(); //resets chip
  Serial.begin(9600);
  cc1120_config(); //runs through settings register
}

void cc1120_config(){
  for(uint16_t i = 0;
        i < (sizeof(preferredSettings)/sizeof(registerSetting_t)); i++) {
        cc1120_write(preferredSettings[i].addr, preferredSettings[i].data);
    }
}

uint8_t i = 0;
uint16_t packetCounter = 0;
    uint8_t txBuffer[PKTLEN+1] = {0};
void loop() {

  //cc1120_mode_idle();
  packetCounter++;
  createPacket(txBuffer);
  delay(10);
  //cc1120_write(CC1120_FIFO, (i++ & 0x1) ?   0xAA : 0xF1);
  cc1120_writetx(txBuffer);
  delay(10);
  cc1120_mode_tx();
  
      Serial.println(i);
  //wait for it to finish transmitting

  //cc1120_config();
  
  delay(1000);
  
 //cc1120_mode_idle();
// cc1120_strobe(CC1120_SFTX);
}

static void createPacket(uint8_t txBuffer[]) {

    txBuffer[0] = PKTLEN;                           // Length byte
    txBuffer[1] = (uint8_t) (packetCounter >> 8);     // MSB of packetCounter
    txBuffer[2] = (uint8_t)  packetCounter;           // LSB of packetCounter

    // Fill rest of buffer with random bytes
    for(uint8_t i = 3; i < (PKTLEN + 1); i++) {
        txBuffer[i] = (uint8_t)i;
    }
}

void cc1120_writetx(uint8_t abuffer[]){

for (uint8_t i=0; i<(uint8_t)sizeof(abuffer); i++){
  cc1120_strobe(CC1120_FIFOC);
  cc1120_strobe(i);
}
  
}

/*
void loop(){
cc1120_mode_idle();
cc1120_mode_rx();
delay(10);
Serial.Println(rx_read());
delay(10);
cc1120_mode_idle();
cc1120_strobe(CC1120_SFRX);

delay(1000);
}
 */ 
