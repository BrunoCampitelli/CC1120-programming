#define WRSR  1        //write protection command ??
#define WRITE 2        //write command
#define READ  3        //read command
#define WRDI  4        //write disable command ??
#define RDSR  5        //buffer command ??
#define WREN  6        //write enable command

#define CC1120_FIFOC 0x3E
#define CC1120_SCAL 0x33
#define CC1120_SRX 0x34
#define CC1120_SRES 0x30
/*
#define IOCFG3 0x00    //define configuration registers
#define IOCFG2 0x01
#define IOCFG1 0x02
#define IOCFG0 0x03
#define SYNC3 0x04
#define SYNC2 0x05
#define SYNC1 0x06
#define SYNC0 0x07
#define SYNC_CFG1 0x08
#define SYNC_CFG0 0x09
#define DEVIATION_M 0x0A
#define MODCFG_DEV_E 0x0B
#define DCFILT_CFG 0x0C
#define PREAMBLE_CFG1 0x0D
#define PREAMBLE_CFG0 0x0E
#define FREQ_IF_CFG 0x0F
#define IQIC 0x10
#define CHAN_BW 0x11
#define MDMCFG1 0x12
#define MDMCFG0 0x13
#define SYMBOL_RATE2 0x14
#define SYMBOL_RATE1 0x15
#define SYMBOL_RATE0 0x16
#define AGC_REF 0x17
#define AGC_CS_THR 0x18
#define AGC_GAIN_ADJUST 0x19
#define AGC_CFG3 0x1A
#define AGC_CFG2 0x1B
#define AGC_CFG1 0x1C
#define AGC_CFG0 0x1D
#define FIFO_CFG 0x1E
#define DEV_ADDR 0x1F
#define SETTLING_CFG 0x20
#define FS_CFG 0x21
#define WOR_CFG1 0x22
#define WOR_CFG0 0x23
#define WOR_EVENT0_MSB 0x24
#define WOR_EVENT0_LSB 0x25
#define PKT_CFG2 0x26
#define PKT_CFG1 0x27
#define PKT_CFG0 0x28
#define RFEND_CFG1 0x29
#define RFEND_CFG0 0x2A
#define PA_CFG2 0x2B
#define PA_CFG1 0x2C
#define PA_CFG0 0x2D
#define PKT_LEN 0x2E
#define EXTENDED ADDRESS 0x2F

#define IF_MIX_CFG 0x00    //define extended registers
#define FREQOFF_CFG 0x01
#define TOC_CFG 0x02
#define MARC_SPARE 0x03
#define ECG_CFG 0x04
#define CFM_DATA_CFG 0x05
#define EXT_CTRL 0x06
#define RCCAL_FINE 0x07
#define RCCAL_COARSE 0x08
#define RCCAL_OFFSET 0x09
#define FREQOFF1 0x0A
#define FREQOFF0 0x0B
#define FREQ2 0x0C
#define FREQ1 0x0D
#define FREQ0 0x0E
#define IF_ADC2 0x0F
#define IF_ADC1 0x10
#define IF_ADC0 0x11
#define FS_DIG1 0x12
#define FS_DIG0 0x13
#define FS_CAL3 0x14
#define FS_CAL2 0x15
#define FS_CAL1 0x16
#define FS_CAL0 0x17
#define FS_CHP 0x18
#define FS_DIVTWO 0x19
#define FS_DSM1 0x1A
#define FS_DSM0 0x1B
#define FS_DVC1 0x1C
#define FS_DVC0 0x1D
#define FS_LBI 0x1E
#define FS_PFD 0x1F
#define FS_PRE 0x20
#define FS_REG_DIV_CML 0x21
#define FS_SPARE 0x22
#define FS_VCO4 0x23
#define FS_VCO3 0x24
#define FS_VCO2 0x25
#define FS_VCO1 0x26
#define FS_VCO0 0x27
#define GBIAS6 0x28
#define GBIAS5 0x29
#define GBIAS4 0x2A
#define GBIAS3 0x2B
#define GBIAS2 0x2C
#define GBIAS1 0x2D
#define GBIAS0 0x2E
#define IFAMP 0x2F
#define LNA 0x30
#define RXMIX 0x31
#define XOSC5 0x32
#define XOSC4 0x33
#define XOSC3 0x34
#define XOSC2 0x35
#define XOSC1 0x36
#define XOSC0 0x37
#define ANALOG_SPARE 0x38
#define PA_CFG3 0x39
#define WOR_TIME1 0x64
#define WOR_TIME0 0x65
#define WOR_CAPTURE1 0x66
#define WOR_CAPTURE0 0x67
#define BIST 0x68
#define DCFILTOFFSET_I1 0x69
#define DCFILTOFFSET_I0 0x6A
#define DCFILTOFFSET_Q1 0x6B
#define DCFILTOFFSET_Q0 0x6C
#define IQIE_I1 0x6D
#define IQIE_I0 0x6E
#define IQIE_Q1 0x6F
#define IQIE_Q0 0x70
#define RSSI1 0x71
#define RSSI0 0x72
#define MARCSTATE 0x73
#define LQI_VAL 0x74
#define PQT_SYNC_ERR 0x75
#define DEM_STATUS 0x76
#define FREQOFF_EST1 0x77
#define FREQOFF_EST0 0x78
#define AGC_GAIN3 0x79
#define AGC_GAIN2 0x7A
#define AGC_GAIN1 0x7B
#define AGC_GAIN0 0x7C
#define CFM_RX_DATA_OUT 0x7D
#define CFM_TX_DATA_IN 0x7E
#define ASK_SOFT_RX_DATA 0x7F
#define RNDGEN 0x80
#define MAGN2 0x81
#define MAGN1 0x82
#define MAGN0 0x83
#define ANG1 0x84
#define ANG0 0x85
#define CHFILT_I2 0x86
#define CHFILT_I1 0x87
#define CHFILT_I0 0x88
#define CHFILT_Q2 0x89
#define CHFILT_Q1 0x8A
#define CHFILT_Q0 0x8B
#define GPIO_STATUS 0x8C
#define FSCAL_CTRL 0x8D
#define PHASE_ADJUST 0x8E
#define PARTNUMBER 0x8F
#define PARTVERSION 0x90
#define SERIAL_STATUS 0x91
#define MODEM_STATUS1 0x92
#define MODEM_STATUS0 0x93
#define MARC_STATUS1 0x94
#define MARC_STATUS0 0x95
#define PA_IFAMP_TEST 0x96
#define FSRF_TEST 0x97
#define PRE_TEST 0x98
#define PRE_OVR 0x99
#define ADC_TEST 0x9A
#define DVC_TEST 0x9B
#define ATEST 0x9C
#define ATEST_LVDS 0x9D
#define ATEST_MODE 0x9E
#define XOSC_TEST1 0x9F
#define XOSC_TEST0 0xA0
#define RXFIRST 0xD2
#define TXFIRST 0xD3
#define RXLAST 0xD4
#define TXLAST 0xD5
#define NUM_TXBYTES 0xD6
#define NUM_RXBYTES 0xD7
#define FIFO_NUM_TXBYTES 0xD8
#define FIFO_NUM_RXBYTES 0xD9 
*/

/* configuration registers */
#define CC112X_IOCFG3                   0x0000
#define CC112X_IOCFG2                   0x0001
#define CC112X_IOCFG1                   0x0002
#define CC112X_IOCFG0                   0x0003
#define CC112X_SYNC3                    0x0004
#define CC112X_SYNC2                    0x0005
#define CC112X_SYNC1                    0x0006
#define CC112X_SYNC0                    0x0007
#define CC112X_SYNC_CFG1                0x0008
#define CC112X_SYNC_CFG0                0x0009
#define CC112X_DEVIATION_M              0x000A
#define CC112X_MODCFG_DEV_E             0x000B
#define CC112X_DCFILT_CFG               0x000C
#define CC112X_PREAMBLE_CFG1            0x000D
#define CC112X_PREAMBLE_CFG0            0x000E
#define CC112X_FREQ_IF_CFG              0x000F
#define CC112X_IQIC                     0x0010
#define CC112X_CHAN_BW                  0x0011
#define CC112X_MDMCFG1                  0x0012
#define CC112X_MDMCFG0                  0x0013
#define CC112X_SYMBOL_RATE2             0x0014
#define CC112X_SYMBOL_RATE1             0x0015
#define CC112X_SYMBOL_RATE0             0x0016
#define CC112X_AGC_REF                  0x0017
#define CC112X_AGC_CS_THR               0x0018
#define CC112X_AGC_GAIN_ADJUST          0x0019
#define CC112X_AGC_CFG3                 0x001A
#define CC112X_AGC_CFG2                 0x001B
#define CC112X_AGC_CFG1                 0x001C
#define CC112X_AGC_CFG0                 0x001D
#define CC112X_FIFO_CFG                 0x001E
#define CC112X_DEV_ADDR                 0x001F
#define CC112X_SETTLING_CFG             0x0020
#define CC112X_FS_CFG                   0x0021
#define CC112X_WOR_CFG1                 0x0022
#define CC112X_WOR_CFG0                 0x0023
#define CC112X_WOR_EVENT0_MSB           0x0024
#define CC112X_WOR_EVENT0_LSB           0x0025
#define CC112X_PKT_CFG2                 0x0026
#define CC112X_PKT_CFG1                 0x0027
#define CC112X_PKT_CFG0                 0x0028
#define CC112X_RFEND_CFG1               0x0029
#define CC112X_RFEND_CFG0               0x002A
#define CC112X_PA_CFG2                  0x002B
#define CC112X_PA_CFG1                  0x002C
#define CC112X_PA_CFG0                  0x002D
#define CC112X_PKT_LEN                  0x002E

/* Extended Configuration Registers */
#define CC112X_IF_MIX_CFG               0x2F00
#define CC112X_FREQOFF_CFG              0x2F01
#define CC112X_TOC_CFG                  0x2F02
#define CC112X_MARC_SPARE               0x2F03
#define CC112X_ECG_CFG                  0x2F04
#define CC112X_CFM_DATA_CFG             0x2F05
#define CC112X_EXT_CTRL                 0x2F06
#define CC112X_RCCAL_FINE               0x2F07
#define CC112X_RCCAL_COARSE             0x2F08
#define CC112X_RCCAL_OFFSET             0x2F09
#define CC112X_FREQOFF1                 0x2F0A
#define CC112X_FREQOFF0                 0x2F0B
#define CC112X_FREQ2                    0x2F0C
#define CC112X_FREQ1                    0x2F0D
#define CC112X_FREQ0                    0x2F0E
#define CC112X_IF_ADC2                  0x2F0F
#define CC112X_IF_ADC1                  0x2F10
#define CC112X_IF_ADC0                  0x2F11
#define CC112X_FS_DIG1                  0x2F12
#define CC112X_FS_DIG0                  0x2F13
#define CC112X_FS_CAL3                  0x2F14
#define CC112X_FS_CAL2                  0x2F15
#define CC112X_FS_CAL1                  0x2F16
#define CC112X_FS_CAL0                  0x2F17
#define CC112X_FS_CHP                   0x2F18
#define CC112X_FS_DIVTWO                0x2F19
#define CC112X_FS_DSM1                  0x2F1A
#define CC112X_FS_DSM0                  0x2F1B
#define CC112X_FS_DVC1                  0x2F1C
#define CC112X_FS_DVC0                  0x2F1D
#define CC112X_FS_LBI                   0x2F1E
#define CC112X_FS_PFD                   0x2F1F
#define CC112X_FS_PRE                   0x2F20
#define CC112X_FS_REG_DIV_CML           0x2F21
#define CC112X_FS_SPARE                 0x2F22
#define CC112X_FS_VCO4                  0x2F23
#define CC112X_FS_VCO3                  0x2F24
#define CC112X_FS_VCO2                  0x2F25
#define CC112X_FS_VCO1                  0x2F26
#define CC112X_FS_VCO0                  0x2F27
#define CC112X_GBIAS6                   0x2F28
#define CC112X_GBIAS5                   0x2F29
#define CC112X_GBIAS4                   0x2F2A
#define CC112X_GBIAS3                   0x2F2B
#define CC112X_GBIAS2                   0x2F2C
#define CC112X_GBIAS1                   0x2F2D
#define CC112X_GBIAS0                   0x2F2E
#define CC112X_IFAMP                    0x2F2F
#define CC112X_LNA                      0x2F30
#define CC112X_RXMIX                    0x2F31
#define CC112X_XOSC5                    0x2F32
#define CC112X_XOSC4                    0x2F33
#define CC112X_XOSC3                    0x2F34
#define CC112X_XOSC2                    0x2F35
#define CC112X_XOSC1                    0x2F36
#define CC112X_XOSC0                    0x2F37
#define CC112X_ANALOG_SPARE             0x2F38
#define CC112X_PA_CFG3                  0x2F39
#define CC112X_IRQ0M                    0x2F3F
#define CC112X_IRQ0F                    0x2F40 

/* Status Registers */
#define CC112X_WOR_TIME1                0x2F64
#define CC112X_WOR_TIME0                0x2F65
#define CC112X_WOR_CAPTURE1             0x2F66
#define CC112X_WOR_CAPTURE0             0x2F67
#define CC112X_BIST                     0x2F68
#define CC112X_DCFILTOFFSET_I1          0x2F69
#define CC112X_DCFILTOFFSET_I0          0x2F6A
#define CC112X_DCFILTOFFSET_Q1          0x2F6B
#define CC112X_DCFILTOFFSET_Q0          0x2F6C
#define CC112X_IQIE_I1                  0x2F6D
#define CC112X_IQIE_I0                  0x2F6E
#define CC112X_IQIE_Q1                  0x2F6F
#define CC112X_IQIE_Q0                  0x2F70
#define CC112X_RSSI1                    0x2F71
#define CC112X_RSSI0                    0x2F72
#define CC112X_MARCSTATE                0x2F73
#define CC112X_LQI_VAL                  0x2F74
#define CC112X_PQT_SYNC_ERR             0x2F75
#define CC112X_DEM_STATUS               0x2F76
#define CC112X_FREQOFF_EST1             0x2F77
#define CC112X_FREQOFF_EST0             0x2F78
#define CC112X_AGC_GAIN3                0x2F79
#define CC112X_AGC_GAIN2                0x2F7A
#define CC112X_AGC_GAIN1                0x2F7B
#define CC112X_AGC_GAIN0                0x2F7C
#define CC112X_CFM_RX_DATA_OUT          0x2F7D
#define CC112X_CFM_TX_DATA_IN           0x2F7E
#define CC112X_ASK_SOFT_RX_DATA         0x2F7F
#define CC112X_RNDGEN                   0x2F80
#define CC112X_MAGN2                    0x2F81
#define CC112X_MAGN1                    0x2F82
#define CC112X_MAGN0                    0x2F83
#define CC112X_ANG1                     0x2F84
#define CC112X_ANG0                     0x2F85
#define CC112X_CHFILT_I2                0x2F86
#define CC112X_CHFILT_I1                0x2F87
#define CC112X_CHFILT_I0                0x2F88
#define CC112X_CHFILT_Q2                0x2F89
#define CC112X_CHFILT_Q1                0x2F8A
#define CC112X_CHFILT_Q0                0x2F8B
#define CC112X_GPIO_STATUS              0x2F8C
#define CC112X_FSCAL_CTRL               0x2F8D
#define CC112X_PHASE_ADJUST             0x2F8E
#define CC112X_PARTNUMBER               0x2F8F
#define CC112X_PARTVERSION              0x2F90
#define CC112X_SERIAL_STATUS            0x2F91
#define CC112X_MODEM_STATUS1            0x2F92
#define CC112X_MODEM_STATUS0            0x2F93
#define CC112X_MARC_STATUS1             0x2F94
#define CC112X_MARC_STATUS0             0x2F95
#define CC112X_PA_IFAMP_TEST            0x2F96
#define CC112X_FSRF_TEST                0x2F97
#define CC112X_PRE_TEST                 0x2F98
#define CC112X_PRE_OVR                  0x2F99
#define CC112X_ADC_TEST                 0x2F9A
#define CC112X_DVC_TEST                 0x2F9B
#define CC112X_ATEST                    0x2F9C
#define CC112X_ATEST_LVDS               0x2F9D
#define CC112X_ATEST_MODE               0x2F9E
#define CC112X_XOSC_TEST1               0x2F9F
#define CC112X_XOSC_TEST0               0x2FA0  
                                        
#define CC112X_RXFIRST                  0x2FD2   
#define CC112X_TXFIRST                  0x2FD3   
#define CC112X_RXLAST                   0x2FD4 
#define CC112X_TXLAST                   0x2FD5 
#define CC112X_NUM_TXBYTES              0x2FD6  /* Number of bytes in TXFIFO */ 
#define CC112X_NUM_RXBYTES              0x2FD7  /* Number of bytes in RXFIFO */
#define CC112X_FIFO_NUM_TXBYTES         0x2FD8  
#define CC112X_FIFO_NUM_RXBYTES         0x2FD9  

                                                                                                                                                
/* DATA FIFO Access */
#define CC112X_SINGLE_TXFIFO            0x003F      /*  TXFIFO  - Single accecss to Transmit FIFO */
#define CC112X_BURST_TXFIFO             0x007F      /*  TXFIFO  - Burst accecss to Transmit FIFO  */
#define CC112X_SINGLE_RXFIFO            0x00BF      /*  RXFIFO  - Single accecss to Receive FIFO  */
#define CC112X_BURST_RXFIFO             0x00FF      /*  RXFIFO  - Busrrst ccecss to Receive FIFO  */

#define CC112X_LQI_CRC_OK_BM            0x80
#define CC112X_LQI_EST_BM               0x7F



/* Command strobe registers */
#define CC112X_SRES                     0x30      /*  SRES    - Reset chip. */
#define CC112X_SFSTXON                  0x31      /*  SFSTXON - Enable and calibrate frequency synthesizer. */
#define CC112X_SXOFF                    0x32      /*  SXOFF   - Turn off crystal oscillator. */
#define CC112X_SCAL                     0x33      /*  SCAL    - Calibrate frequency synthesizer and turn it off. */
#define CC112X_SRX                      0x34      /*  SRX     - Enable RX. Perform calibration if enabled. */
#define CC112X_STX                      0x35      /*  STX     - Enable TX. If in RX state, only enable TX if CCA passes. */
#define CC112X_SIDLE                    0x36      /*  SIDLE   - Exit RX / TX, turn off frequency synthesizer. */
#define CC112X_SWOR                     0x38      /*  SWOR    - Start automatic RX polling sequence (Wake-on-Radio) */
#define CC112X_SPWD                     0x39      /*  SPWD    - Enter power down mode when CSn goes high. */
#define CC112X_SFRX                     0x3A      /*  SFRX    - Flush the RX FIFO buffer. */
#define CC112X_SFTX                     0x3B      /*  SFTX    - Flush the TX FIFO buffer. */
#define CC112X_SWORRST                  0x3C      /*  SWORRST - Reset real time clock. */
#define CC112X_SNOP                     0x3D      /*  SNOP    - No operation. Returns status byte. */
#define CC112X_AFC                      0x37      /*  AFC     - Automatic Frequency Correction */

/* Chip states returned in status byte */
#define CC112X_STATE_IDLE               0x00
#define CC112X_STATE_RX                 0x10
#define CC112X_STATE_TX                 0x20
#define CC112X_STATE_FSTXON             0x30
#define CC112X_STATE_CALIBRATE          0x40
#define CC112X_STATE_SETTLING           0x50
#define CC112X_STATE_RXFIFO_ERROR       0x60
#define CC112X_STATE_TXFIFO_ERROR       0x70

/******************************************************************************
 * VARIABLES
 */  
// Carrier frequency = 868.000000 
// Symbol rate = 1.2 
// Bit rate = 1.2 
// Deviation = 3.997803 
// Manchester enable = false 
// Bit rate = 1.2 
// Modulation format = 2-FSK 
// Bit rate = 1.2 
// RX filter BW = 25.000000 
// TX power = -6 
// PA ramping = true 
// Packet length mode = Variable 
// Whitening = false 
// Address config = No address check. 
// Packet length = 255 
// Device address = 0 
typedef struct registerSetting_t{

  char addr;
  uint8_t data;
  
};

static const registerSetting_t preferredSettings[] = {
    {CC112X_IOCFG3,         0xB0},
    {CC112X_IOCFG2,         0x06},
    {CC112X_IOCFG1,         0xB0},
    {CC112X_IOCFG0,         0xB0},
    {CC112X_SYNC_CFG1,      0x0B},//4
    {CC112X_DCFILT_CFG,     0x1C},
    {CC112X_IQIC,           0xC6},
    {CC112X_CHAN_BW,        0x08},
    {CC112X_MDMCFG0,        0x05},
    {CC112X_AGC_REF,        0x20},//9
    {CC112X_AGC_CS_THR,     0x19},
    {CC112X_AGC_CFG1,       0xA9},
    {CC112X_AGC_CFG0,       0xCF},
    {CC112X_FIFO_CFG,       0x00},
    {CC112X_SETTLING_CFG,   0x03},//14
    {CC112X_FS_CFG,         0x12},
    {CC112X_PKT_CFG1,       0x05},  
    {CC112X_PKT_CFG0,       0x20},
    {CC112X_PA_CFG2,        0x4F},
    {CC112X_PA_CFG1,        0x56},//19
    {CC112X_PA_CFG0,        0x1C},
    {CC112X_PKT_LEN,        0xFF},
    {CC112X_IF_MIX_CFG,     0x00},
    {CC112X_FREQOFF_CFG,    0x22},
    {CC112X_FREQ2,          0x6C},//24
    {CC112X_FREQ1,          0x80},
    {CC112X_FREQ0,          0x00},
    {CC112X_FS_DIG1,        0x00},
    {CC112X_FS_DIG0,        0x5F},
    {CC112X_FS_CAL0,        0x0E},//29
    {CC112X_FS_DIVTWO,      0x03},
    {CC112X_FS_DSM0,        0x33},
    {CC112X_FS_DVC0,        0x17},
    {CC112X_FS_PFD,         0x50},
    {CC112X_FS_PRE,         0x6E},
    {CC112X_FS_REG_DIV_CML, 0x14},
    {CC112X_FS_SPARE,       0xAC},
    {CC112X_XOSC5,          0x0E},
    {CC112X_XOSC3,          0xC7},
    {CC112X_XOSC1,          0x07},
};

void config() {

}
