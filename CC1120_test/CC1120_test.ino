#include <SPI.h>
#include "CC1120.h"

//SPISettings s = SPISettings(4000, MSBFIRST, SPI_MODE0);
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
#define SS 10

#define CC1120_FIFO 0x3F


#define PARTNUMBER 0x8f
#define PARTVERSION 0x90

void cc1120_strobe(uint8_t command) {
  Send_SPI(CC1120_READ | command);
}

uint8_t cc1120_write(uint8_t address, uint8_t data) {
  uint8_t result;
  Send_SPI(address);
  result = Send_SPI(data);
  return result;
}

uint8_t cc1120_read(uint8_t address) {
  return Send_SPI_2(address);
}

uint8_t cc1120_read_EX(uint8_t address) {
  return Send_SPI_3(address);
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
  Send_SPI(CC1120_READ | CC1120_EXTENDED_ADDRESS);
  result = Send_SPI(0xff);
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
  Serial.print("SEND_PSI: ");
  Serial.print((uint8_t)verzenden);

  digitalWrite(SS,LOW);
  while(digitalRead(MISO));
  so = SPI.transfer(verzenden);
  digitalWrite(SS,HIGH);
  
  Serial.print(" --> so: ");
  Serial.println(so >> 4);
  return so;
}

char Send_SPI_2(uint8_t verzenden){
  uint16_t so = 0x00;
  uint16_t super_verzenden = 0 | (uint16_t) verzenden;
  Serial.print("SEND_SPI_2: ");
  Serial.print((uint8_t)verzenden);
  

  digitalWrite(SS,LOW);
  while(digitalRead(MISO));
  SPI.transfer((uint16_t) verzenden);
  digitalWrite(SS,HIGH);
  
  Serial.print(" --> so: ");
  Serial.print(so & 0x00FF);
  Serial.print("\t");
  Serial.println((so & 0xFF00) >> 8);
  return so >> 8;
}

char Send_SPI_3(uint16_t verzenden){
  uint8_t so = 0x00;
  Serial.print("SEND_PSI: ");
  Serial.print((uint8_t)verzenden);

  digitalWrite(SS,LOW);
  while(digitalRead(MISO));
  SPI.transfer(verzenden);
  so = SPI.transfer(0x00);
  digitalWrite(SS,HIGH);
  
  Serial.print(" --> so: ");
  Serial.println(so);
  return so;
}


void setup() {
//  cc1120_init_pins();
  Serial.begin(9600);
  pinMode(SS, OUTPUT);
  digitalWrite(SS,HIGH);
  SPI.begin();
 // SPI.beginTransaction(s);
 //SPI.setDataMode(
 SPI.setClockDivider(SPI_CLOCK_DIV128);
  delay(1000);
  cc1120_reset(); //resets chip
  cc1120_config(); //runs through settings register
  //cc1120_write(CC112X_FREQ2, 0x6C);
  //Serial.println(cc1120_read(CC112X_FREQ2));
  manualCalibration();
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
/*
  //cc1120_mode_idle();
  packetCounter++;
  createPacket(txBuffer);
  delay(10);
  //cc1120_write(CC1120_FIFO, (i++ & 0x1) ?   0xAA : 0xF1);
  cc1120_writetx(txBuffer);
  delay(10);
  cc1120_mode_tx();
  
  //    Serial.println(i);
  //wait for it to finish transmitting

  //cc1120_config();
  Serial.println("\n");
//  delay(1000);
  */
  cc1120_mode_idle();
  delay(10);/*
  cc1120_strobe(CC1120_SFTX);*/
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

/*
void cc1120_writetx(uint8_t abuffer[]){

  for (uint8_t i=0; i<(uint8_t)sizeof(abuffer); i++){
    cc1120_strobe(CC1120_FIFOC);
    cc1120_strobe(i);
  }
  
}
*/

void cc1120_writetx(uint8_t abuffer[]){

  for (uint8_t i=0; i<(uint8_t)sizeof(abuffer); i++){
    cc1120_strobe(CC1120_FIFO);
    cc1120_strobe(abuffer[i]);
  }
  
}


/////////////Some new manual calibration stuff

void cc112xSpiWriteReg(uint8_t addr, uint8_t *data, uint8_t len){
   cc1120_write(addr, *data);
}

void cc112xSpiReadReg(uint8_t addr, uint8_t *data, uint8_t len){
   *data = cc1120_read_EX(addr);
}

void trxSpiCmdStrobe(uint8_t cmd){
  cc1120_strobe(cmd);
}


#define VCDAC_START_OFFSET 2
#define FS_VCO2_INDEX 0
#define FS_VCO4_INDEX 1
#define FS_CHP_INDEX 2
static void manualCalibration(void) {
  
    uint8_t original_fs_cal2;
    uint8_t calResults_for_vcdac_start_high[3];
    uint8_t calResults_for_vcdac_start_mid[3];
    uint8_t marcstate;
    uint8_t writeByte;
    
    // 1) Set VCO cap-array to 0 (FS_VCO2 = 0x00)
    writeByte = 0x00;
    cc112xSpiWriteReg(CC112X_FS_VCO2, &writeByte, 1);
    Serial.println("1");
    
    // 2) Start with high VCDAC (original VCDAC_START + 2):
    cc112xSpiReadReg(CC112X_FS_CAL2, &original_fs_cal2, 1);
    writeByte = original_fs_cal2 + VCDAC_START_OFFSET;
    cc112xSpiWriteReg(CC112X_FS_CAL2, &writeByte, 1);
    Serial.println("2");
    
    // 3) Calibrate and wait for calibration to be done (radio back in IDLE state)
    trxSpiCmdStrobe(CC112X_SCAL);
    Serial.println("3");
     
    do 
    {
        cc112xSpiReadReg(CC112X_MARCSTATE, &marcstate, 1);
        //Serial.print("3.5 ");
        //Serial.println(marcstate);
        //delay(1000);
    } //while (!(marcstate & 0x40) && (marcstate & 0xb0));
    while (marcstate != 0x41);
    
    
    // 4) Read FS_VCO2, FS_VCO4 and FS_CHP register obtained with high VCDAC_START value
    cc112xSpiReadReg(CC112X_FS_VCO2, &calResults_for_vcdac_start_high[FS_VCO2_INDEX], 1);
    cc112xSpiReadReg(CC112X_FS_VCO4, &calResults_for_vcdac_start_high[FS_VCO4_INDEX], 1);
    cc112xSpiReadReg(CC112X_FS_CHP, &calResults_for_vcdac_start_high[FS_CHP_INDEX], 1);
    Serial.println("4");
    
    // 5) Set VCO cap-array to 0 (FS_VCO2 = 0x00)
    writeByte = 0x00;
    cc112xSpiWriteReg(CC112X_FS_VCO2, &writeByte, 1);
    Serial.println("5");
    
    // 6) Continue with mid VCDAC (original VCDAC_START):
    writeByte = original_fs_cal2;
    cc112xSpiWriteReg(CC112X_FS_CAL2, &writeByte, 1);
    Serial.println("6");
    
    // 7) Calibrate and wait for calibration to be done (radio back in IDLE state)
    trxSpiCmdStrobe(CC112X_SCAL);
    Serial.println("7");

   // delay(10000);
    
    do 
    {
        cc112xSpiReadReg(CC112X_MARCSTATE, &marcstate, 1);
        Serial.println("7.5");
        Serial.println(marcstate);
        delay(1000);
    } //while (!(marcstate & 0x40) && (marcstate & 0xb0)); 
    while (marcstate != 0x41);
    
    
    // 8) Read FS_VCO2, FS_VCO4 and FS_CHP register obtained with mid VCDAC_START value
    cc112xSpiReadReg(CC112X_FS_VCO2, &calResults_for_vcdac_start_mid[FS_VCO2_INDEX], 1);
    cc112xSpiReadReg(CC112X_FS_VCO4, &calResults_for_vcdac_start_mid[FS_VCO4_INDEX], 1);
    cc112xSpiReadReg(CC112X_FS_CHP, &calResults_for_vcdac_start_mid[FS_CHP_INDEX], 1);
    Serial.println("8");
    
    // 9) Write back highest FS_VCO2 and corresponding FS_VCO and FS_CHP result
    if (calResults_for_vcdac_start_high[FS_VCO2_INDEX] > calResults_for_vcdac_start_mid[FS_VCO2_INDEX]) 
    {
        writeByte = calResults_for_vcdac_start_high[FS_VCO2_INDEX];
        cc112xSpiWriteReg(CC112X_FS_VCO2, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_high[FS_VCO4_INDEX];
        cc112xSpiWriteReg(CC112X_FS_VCO4, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_high[FS_CHP_INDEX];
        cc112xSpiWriteReg(CC112X_FS_CHP, &writeByte, 1);
    }
    else 
    {
        writeByte = calResults_for_vcdac_start_mid[FS_VCO2_INDEX];
        cc112xSpiWriteReg(CC112X_FS_VCO2, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_mid[FS_VCO4_INDEX];
        cc112xSpiWriteReg(CC112X_FS_VCO4, &writeByte, 1);
        writeByte = calResults_for_vcdac_start_mid[FS_CHP_INDEX];
        cc112xSpiWriteReg(CC112X_FS_CHP, &writeByte, 1);
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
