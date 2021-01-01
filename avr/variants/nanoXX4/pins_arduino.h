/***************************************************|
|           NANOXX4PX PINOUT for MightyCore         |
|               based on MightyCore work            |
|       https://github.com/MCUdude/MightyCore       |
|    https://github.com/tomaskovacik/MightyCore     |
|       pinout for the board designed by me         |
https://www.tindie.com/products/tomaskovacik/nanoxx4px/                                                   |
| An Arduino core for:                              |
| ATmega1284/P                                      |
| ATmega644/A/P/PA                                  |
| ATmega324A/P/PA/PB                                |
| ATmega164A/P/PA                                   |
| ATmega32/A                                        |
| ATmega16/A                                        |
| ATmega8535                                        |
|                                                   |
|***************************************************/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>

#if defined(__AVR_ATmega644A__)
  #define __AVR_ATmega644__
#endif


// We're using the Bobuino pinout
#define NANOXX4_PINOUT


// Digital pins
  #define NUM_DIGITAL_PINS          (41)

// PWM pins
#if defined(__AVR_ATmega8535__) || defined(__AVR_ATmega16__) || defined(__AVR_ATmega32__)
  #define digitalPinHasPWM(p)       ((p) == 7 || (p) == 8 || (p) == 30 || (p) == 31)
#elif defined(__AVR_ATmega164A__) || defined(__AVR_ATmega164P__) || defined(__AVR_ATmega324A__) || \
defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__)
  #define digitalPinHasPWM(p)       ((p) == 9 || (p) == 5 || (p) == 8 || (p) == 10 || (p) == 4 || (p) == 7)
#elif defined(__AVR_ATmega324PB__)
  #define digitalPinHasPWM(p)       ((p) == 9 || (p) == 5 || (p) == 8 || (p) == 10 || (p) == 12 || (p) == 13 || (p) == 17 || (p) == 4 || (p) == 7)
#elif defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)
  #define digitalPinHasPWM(p)       ((p) == 9 || (p) == 5 || (p) == 8 || (p) == 10 || (p) == 12 || (p) == 13 || (p) == 4 || (p) == 7)
#endif

// Builtin LED
#define LED_BUILTIN   (13)
static const uint8_t LED = LED_BUILTIN;

// Analog pins
#define PIN_A0 (54)
#define PIN_A1 (55)
#define PIN_A2 (56)
#define PIN_A3 (57)
#define PIN_A4 (58)
#define PIN_A5 (59)
#define PIN_A6 (60)
#define PIN_A7 (61)
static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;
#define NUM_ANALOG_INPUTS           (8)
#define analogInputToDigitalPin(p)  ((p < NUM_ANALOG_INPUTS) ? (p) + 54 : -1)
#define analogPinToChannel(p)       ((p) < NUM_ANALOG_INPUTS) ? (7 - (p)) : ((p)  >=  54 && (p) <= 61) ? (61 - (p)) : -1

// SPI
#define PIN_SPI_SS    (10)
#define PIN_SPI_MOSI  (11)
#define PIN_SPI_MISO  (12)
#define PIN_SPI_SCK   (13)
static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;
#if defined(__AVR_ATmega324PB__)
  #define PIN_SPI_SS0   PIN_SPI_SS
  #define PIN_SPI_MOSI0 PIN_SPI_MOSI
  #define PIN_SPI_MISO0 PIN_SPI_MISO
  #define PIN_SPI_SCK0  PIN_SPI_SCK
  #define PIN_SPI_SS1   (8)
  #define PIN_SPI_MOSI1 (37)
  #define PIN_SPI_MISO1 (36)
  #define PIN_SPI_SCK1  (7)
  static const uint8_t SS0   = PIN_SPI_SS0;
  static const uint8_t MOSI0 = PIN_SPI_MOSI0;
  static const uint8_t MISO0 = PIN_SPI_MISO0;
  static const uint8_t SCK0  = PIN_SPI_SCK0;
  static const uint8_t SS1   = PIN_SPI_SS1;
  static const uint8_t MOSI1 = PIN_SPI_MOSI1;
  static const uint8_t MISO1 = PIN_SPI_MISO1;
  static const uint8_t SCK1  = PIN_SPI_SCK1;
#endif  

// i2c
#define PIN_WIRE_SDA  (20)
#define PIN_WIRE_SCL  (21)
static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;
#if defined(__AVR_ATmega324PB__)
  #define PIN_WIRE_SDA0 PIN_WIRE_SDA
  #define PIN_WIRE_SCL0 PIN_WIRE_SCL
  #define PIN_WIRE_SDA1 (37)
  #define PIN_WIRE_SCL1 (38)
  static const uint8_t SDA0  = PIN_WIRE_SDA0;
  static const uint8_t SCL0  = PIN_WIRE_SCL0;
  static const uint8_t SDA1  = PIN_WIRE_SDA1;
  static const uint8_t SCL1  = PIN_WIRE_SCL1;
#endif

// Interrupts
#define EXTERNAL_NUM_INTERRUPTS     (3)
#define digitalPinToInterrupt(p)    ((p) == 2 ? 0 : ((p) == 3 ? 1 : ((p) == 6 ? 2 : NOT_AN_INTERRUPT)))

// PCINT
#if defined(__AVR_ATmega164A__) || defined(__AVR_ATmega164P__) || defined(__AVR_ATmega324A__) || \
defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega324PB__) || \
defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega1284__) || \
defined(__AVR_ATmega1284P__)
#if defined(__AVR_ATmega324PB__)
#define PORT_NDX_TO_PCMSK(x) ((x) == 0 ? &PCMSK0 : ((x) == 1 ? &PCMSK1 : ((x) == 2 ? &PCMSK2 : ((x) == 3 ? &PCMSK3 : ((x) == 4 ? &PCMSK4 : (uint8_t *)0)))))
#define ifpin(p,what,ifnot)         ((((p) >= 0 && (p) < 23) || ((p) >= 32 && (p) < 40) || ((p) >= 54 && (p) < 61)) ? (what) : (ifnot))
#else
#define PORT_NDX_TO_PCMSK(x) ((x) == 0 ? &PCMSK0 : ((x) == 1 ? &PCMSK1 : ((x) == 2 ? &PCMSK2 : ((x) == 3 ? &PCMSK3 : (uint8_t *)0))))
#define ifpin(p,what,ifnot)         ((((p) >= 0 && (p) < 23) || ((p) >= 32 && (p) < 33) || ((p) >= 54 && (p) < 61)) ? (what) : (ifnot))
#endif
#define digitalPinToPCICR(p)    ifpin(p,&PCICR,(uint8_t *)0)
#define digitalPinToPCICRbit(p) ifpin(p,digital_pin_to_pcint[p] >> 3,0)
#define digitalPinToPCMSK(p)    ifpin(p,(uint8_t *)PORT_NDX_TO_PCMSK(digital_pin_to_pcint[p] >> 3),(uint8_t *)0)
#define digitalPinToPCMSKbit(p) ifpin(p,digital_pin_to_pcint[p] & 0x7,0)


#ifndef ARDUINO_MAIN
extern const uint8_t digital_pin_to_pcint[];
#else
const uint8_t digital_pin_to_pcint[NUM_DIGITAL_PINS] =
{
24,//D0,PD0,RX0,0
25,//D1,PD1,TX0,1
26,//D2,PD2,INT0,2
27,//D3,PD3,INT1,3
28,//D4,PD4,,4
29,//D5,PD5,,5
10,//D6,PB2,INT2,6
31,//D7,PD7,SCK1,7
30,//D8,PD6,SS1,8
11,//D9,PB3,,9
12,//D10,PB4,SS0,10
13,//D11,PB5,MOSI0,11
14,//D12,PB6,MISO0,12
15,//D13,PB7,SCK0,13
 8,//D14,PB0,,14
 9,//D15,PB1,,15
19,//D16,PC3,,16
20,//D17,PC4,,17
27,//D18,PD3,RX1,18
26,//D19,PD2,TX1,19
17,//D20,PC1,SDA0,20
16,//D21,PC0,SCL0,21
22,//D22,PC6,,22
23,//D23,PC7,,23
NULL,//24
NULL,//25
NULL,//26
NULL,//27
NULL,//28
NULL,//9
NULL,//30
NULL,//31
18,//D32,PC2,,32
21,//D33,PC5,,33
#if defined(__AVR_ATmega324PB__)
32,//D34,PE0,,34
33,//D35,PE1,,35
34,//D36,PE2,MISO1,36
35,//D37,PE3,MOSI1,37
36,//D38,PE4,AREF,38
37,//D39,PE5,SDA1,39
38,//D40,PE6,SCL1,40
#else
NULL,//34
NULL,//35
NULL,//36
NULL,//37
NULL,//38
NULL,//39
NULL,//40
#endif
NULL,//41
NULL,//42
NULL,//43
NULL,//44
NULL,//45
NULL,//46
NULL,//47
NULL,//48
NULL,//49
NULL,//50
NULL,//51
NULL,//52
NULL,//53
 0,//A0/D54,PA0,ADC0,54
 1,//A1/D55,PA1,ADC1,55
 2,//A2/D56,PA2,ADC2,56
 3,//A3/D57,PA3,ADC3,57
 4,//A4/D58,PA4,ADC4,58
 5,//A5/D59,PA5,ADC5,59
 6,//A6/D60,PA6,ADC6,60
 7,//A7/D61,PA7,ADC7,61
};
#endif

#endif


#ifdef ARDUINO_MAIN

#define PA 1
#define PB 2
#define PC 3
#define PD 4
#if defined(__AVR_ATmega324PB__)
  #define PE 5
#endif

// these arrays map port names (e.g. port B) to the
// appropriate addresses for various functions (e.g. reading
// and writing)
const uint16_t PROGMEM port_to_mode_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &DDRA,
  (uint16_t) &DDRB,
  (uint16_t) &DDRC,
  (uint16_t) &DDRD,
#if defined(__AVR_ATmega324PB__)
  (uint16_t) &DDRE,
#endif
};

const uint16_t PROGMEM port_to_output_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &PORTA,
  (uint16_t) &PORTB,
  (uint16_t) &PORTC,
  (uint16_t) &PORTD,
#if defined(__AVR_ATmega324PB__)
  (uint16_t) &PORTE,
#endif
};

const uint16_t PROGMEM port_to_input_PGM[] =
{
  NOT_A_PORT,
  (uint16_t) &PINA,
  (uint16_t) &PINB,
  (uint16_t) &PINC,
  (uint16_t) &PIND,
#if defined(__AVR_ATmega324PB__)
  (uint16_t) &PINE,
#endif
};

const uint8_t PROGMEM digital_pin_to_port_PGM[] =
{
PD,//D24,D0,PD0,RX0,0
PD,//D25,D1,PD1,TX0,1
PD,//D26,D2,PD2,INT0,2
PD,//D27,D3,PD3,INT1,3
PD,//D28,D4,PD4,,4
PD,//D29,D5,PD5,,5
PB,//D10,D6,PB2,INT2,6
PD,//D31,D7,PD7,SCK1,7
PD,//D30,D8,PD6,SS1,8
PB,//D11,D9,PB3,,9
PB,//D12,D10,PB4,SS0,10
PB,//D13,D11,PB5,MOSI0,11
PB,//D14,D12,PB6,MISO0,12
PB,//D15,D13,PB7,SCK0,13
PB,//D8,D14,PB0,,14
PB,//D9,D15,PB1,,15
PC,//D19,D16,PC3,,16
PC,//D20,D17,PC4,,17
PD,//D27,D18,PD3,RX1,18
PD,//D26,D19,PD2,TX1,19
PC,//D17,D20,PC1,SDA0,20
PC,//D16,D21,PC0,SCL0,21
PC,//D22,D22,PC6,,22
PC,//D23,D23,PC7,,23
PC,//D18,D32,PC2,,32
PC,//D21,D33,PC5,,33
NULL,//24
NULL,//25
NULL,//26
NULL,//27
NULL,//28
NULL,//9
NULL,//30
NULL,//31
#if defined(__AVR_ATmega324PB__)
PE,//D32,D34,PE0,,34
PE,//D33,D35,PE1,,35
PE,//D34,D36,PE2,MISO1,36
PE,//D35,D37,PE3,MOSI1,37
PE,//D36,D38,PE4,AREF,38
PE,//D37,D39,PE5,SDA1,39
PE,//D38,D40,PE6,SCL1,40
#else
NULL,//34
NULL,//35
NULL,//36
NULL,//37
NULL,//38
NULL,//39
NULL,//40
#endif
NULL,//41
NULL,//42
NULL,//43
NULL,//44
NULL,//45
NULL,//46
NULL,//47
NULL,//48
NULL,//49
NULL,//50
NULL,//51
NULL,//52
NULL,//53
PA,//D0,A0/D54,PA0,ADC0,54
PA,//D1,A1/D55,PA1,ADC1,55
PA,//D2,A2/D56,PA2,ADC2,56
PA,//D3,A3/D57,PA3,ADC3,57
PA,//D4,A4/D58,PA4,ADC4,58
PA,//D5,A5/D59,PA5,ADC5,59
PA,//D6,A6/D60,PA6,ADC6,60
PA,//D7,A7/D61,PA7,ADC7,61
};

const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] =
{
_BV(0),//PD,24,D0,PD0,RX0,0
_BV(1),//PD,25,D1,PD1,TX0,1
_BV(2),//PD,26,D2,PD2,INT0,2
_BV(3),//PD,27,D3,PD3,INT1,3
_BV(4),//PD,28,D4,PD4,,4
_BV(5),//PD,29,D5,PD5,,5
_BV(2),//PB,10,D6,PB2,INT2,6
_BV(7),//PD,31,D7,PD7,SCK1,7
_BV(6),//PD,30,D8,PD6,SS1,8
_BV(3),//PB,11,D9,PB3,,9
_BV(4),//PB,12,D10,PB4,SS0,10
_BV(5),//PB,13,D11,PB5,MOSI0,11
_BV(6),//PB,14,D12,PB6,MISO0,12
_BV(7),//PB,15,D13,PB7,SCK0,13
_BV(0),//PB,8,D14,PB0,,14
_BV(1),//PB,9,D15,PB1,,15
_BV(3),//PC,19,D16,PC3,,16
_BV(4),//PC,20,D17,PC4,,17
_BV(3),//PD,27,D18,PD3,RX1,18
_BV(2),//PD,26,D19,PD2,TX1,19
_BV(1),//PC,17,D20,PC1,SDA0,20
_BV(0),//PC,16,D21,PC0,SCL0,21
_BV(6),//PC,22,D22,PC6,,22
_BV(7),//PC,23,D23,PC7,,23
_BV(2),//PC,18,D32,PC2,,32
_BV(5),//PC,21,D33,PC5,,33
NULL,//24
NULL,//25
NULL,//26
NULL,//27
NULL,//28
NULL,//29
NULL,//30
NULL,//31
#if defined(__AVR_ATmega324PB__)
_BV(0),//PE,32,D34,PE0,,34
_BV(1),//PE,33,D35,PE1,,35
_BV(2),//PE,34,D36,PE2,MISO1,36
_BV(3),//PE,35,D37,PE3,MOSI1,37
_BV(4),//PE,36,D38,PE4,AREF,38
_BV(5),//PE,37,D39,PE5,SDA1,39
_BV(6),//PE,38,D40,PE6,SCL1,40
#else
NULL,//34
NULL,//35
NULL,//36
NULL,//37
NULL,//38
NULL,//39
NULL,//40
#endif
NULL,//41
NULL,//42
NULL,//43
NULL,//44
NULL,//45
NULL,//46
NULL,//47
NULL,//48
NULL,//49
NULL,//50
NULL,//51
NULL,//52
NULL,//53
_BV(0),//PA,0,A0/D54,PA0,ADC0,54
_BV(1),//PA,1,A1/D55,PA1,ADC1,55
_BV(2),//PA,2,A2/D56,PA2,ADC2,56
_BV(3),//PA,3,A3/D57,PA3,ADC3,57
_BV(4),//PA,4,A4/D58,PA4,ADC4,58
_BV(5),//PA,5,A5/D59,PA5,ADC5,59
_BV(6),//PA,6,A6/D60,PA6,ADC6,60
_BV(7),//PA,7,A7/D61,PA7,ADC7,61
};

#if defined(__AVR_ATmega8535__) || defined(__AVR_ATmega16__) || defined(__AVR_ATmega32__)
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
  NOT_ON_TIMER, // D0 - PD0
  NOT_ON_TIMER, // D1 - PD1
  NOT_ON_TIMER, // D2 - PD2
  NOT_ON_TIMER, // D3 - PD3
  NOT_ON_TIMER, // D4 - PB0
  NOT_ON_TIMER, // D5 - PB1
  NOT_ON_TIMER, // D6 - PB2
  TIMER0A,      // D7 - PB3
  TIMER1A,      // D8 - PD5
  NOT_ON_TIMER, // D9 - PD6
  NOT_ON_TIMER, // D10 - PB4
  NOT_ON_TIMER, // D11 - PB5
  NOT_ON_TIMER, // D12 - PB6
  NOT_ON_TIMER, // D13 - PB7
  NOT_ON_TIMER, // D14 - PA7
  NOT_ON_TIMER, // D15 - PA6
  NOT_ON_TIMER, // D16 - PA5
  NOT_ON_TIMER, // D17 - PA4
  NOT_ON_TIMER, // D18 - PA3
  NOT_ON_TIMER, // D19 - PA2
  NOT_ON_TIMER, // D20 - PA1
  NOT_ON_TIMER, // D21 - PA0
  NOT_ON_TIMER, // D22 - PC0
  NOT_ON_TIMER, // D23 - PC1
  NOT_ON_TIMER, // D24 - PC2
  NOT_ON_TIMER, // D25 - PC3
  NOT_ON_TIMER, // D26 - PC4
  NOT_ON_TIMER, // D27 - PC5
  NOT_ON_TIMER, // D28 - PC6
  NOT_ON_TIMER, // D29 - PC7
  TIMER1B,      // D30 - PD4
  TIMER2,       // D31 - PD7
};

#elif defined(__AVR_ATmega164A__) || defined(__AVR_ATmega164P__) || defined(__AVR_ATmega324A__) || \
defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega644A__) || \
defined(__AVR_ATmega644P__)
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
NOT_ON_TIMER,//D0,PD0,_BV(0),PD,24,RX0,0,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D1,PD1,_BV(1),PD,25,TX0,1,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D2,PD2,_BV(2),PD,26,INT0,2,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D3,PD3,_BV(3),PD,27,INT1,3,,NOT_ON_TIMER,NOT_ON_TIMER
TIMER1B,//D4,PD4,_BV(4),PD,28,,4,,TIMER1B,TIMER1B
TIMER1A,//D5,PD5,_BV(5),PD,29,,5,,TIMER1A,TIMER1A
NOT_ON_TIMER,//D6,PB2,_BV(2),PB,10,INT2,6,,NOT_ON_TIMER,NOT_ON_TIMER
TIMER2A,//D7,PD7,_BV(7),PD,31,SCK1,7,,TIMER2A,TIMER2A
TIMER2B,//D8,PD6,_BV(6),PD,30,SS1,8,,TIMER2B,TIMER2B
TIMER0A,//D9,PB3,_BV(3),PB,11,,9,,TIMER0A,TIMER0A
TIMER0B,//D10,PB4,_BV(4),PB,12,SS0,10,,TIMER0B,TIMER0B
NOT_ON_TIMER,//D11,PB5,_BV(5),PB,13,MOSI0,11,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D12,PB6,_BV(6),PB,14,MISO0,12,,TIMER3A,TIMER3A
NOT_ON_TIMER,//D13,PB7,_BV(7),PB,15,SCK0,13,,TIMER3B,TIMER3B
NOT_ON_TIMER,//D14,PB0,_BV(0),PB,8,,14,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D15,PB1,_BV(1),PB,9,,15,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D16,PC3,_BV(3),PC,19,,16,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D17,PC4,_BV(4),PC,20,,17,,NOT_ON_TIMER,TIMER4A
NOT_ON_TIMER,//D18,PD3,_BV(3),PD,27,RX1,18,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D19,PD2,_BV(2),PD,26,TX1,19,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D20,PC1,_BV(1),PC,17,SDA0,20,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D21,PC0,_BV(0),PC,16,SCL0,21,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D22,PC6,_BV(6),PC,22,,22,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D23,PC7,_BV(7),PC,23,,23,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D32,PC2,_BV(2),PC,18,,32,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D33,PC5,_BV(5),PC,21,,33,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//24
NOT_ON_TIMER,//25
NOT_ON_TIMER,//26
NOT_ON_TIMER,//27
NOT_ON_TIMER,//28
NOT_ON_TIMER,//9
NOT_ON_TIMER,//30
NOT_ON_TIMER,//31
NOT_ON_TIMER,//D34,PE0,_BV(0),PE,32,,34,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D35,PE1,_BV(1),PE,33,,35,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D36,PE2,_BV(2),PE,34,MISO1,36,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D37,PE3,_BV(3),PE,35,MOSI1,37,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D38,PE4,_BV(4),PE,36,AREF,38,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D39,PE5,_BV(5),PE,37,SDA1,39,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D40,PE6,_BV(6),PE,38,SCL1,40,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//41
NOT_ON_TIMER,//42
NOT_ON_TIMER,//43
NOT_ON_TIMER,//44
NOT_ON_TIMER,//45
NOT_ON_TIMER,//46
NOT_ON_TIMER,//47
NOT_ON_TIMER,//48
NOT_ON_TIMER,//49
NOT_ON_TIMER,//50
NOT_ON_TIMER,//51
NOT_ON_TIMER,//52
NOT_ON_TIMER,//53
NOT_ON_TIMER,//A0/D54,PA0,_BV(0),PA,0,ADC0,54,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A1/D55,PA1,_BV(1),PA,1,ADC1,55,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A2/D56,PA2,_BV(2),PA,2,ADC2,56,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A3/D57,PA3,_BV(3),PA,3,ADC3,57,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A4/D58,PA4,_BV(4),PA,4,ADC4,58,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A5/D59,PA5,_BV(5),PA,5,ADC5,59,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A6/D60,PA6,_BV(6),PA,6,ADC6,60,,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A7/D61,PA7,_BV(7),PA,7,ADC7,61,,NOT_ON_TIMER,NOT_ON_TIMER
};

#elif defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__)
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
NOT_ON_TIMER,//D0,PD0,_BV(0),PD,24,RX0,0,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D1,PD1,_BV(1),PD,25,TX0,1,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D2,PD2,_BV(2),PD,26,INT0,2,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D3,PD3,_BV(3),PD,27,INT1,3,NOT_ON_TIMER,,NOT_ON_TIMER
TIMER1B,//D4,PD4,_BV(4),PD,28,,4,TIMER1B,,TIMER1B
TIMER1A,//D5,PD5,_BV(5),PD,29,,5,TIMER1A,,TIMER1A
NOT_ON_TIMER,//D6,PB2,_BV(2),PB,10,INT2,6,NOT_ON_TIMER,,NOT_ON_TIMER
TIMER2A,//D7,PD7,_BV(7),PD,31,SCK1,7,TIMER2A,,TIMER2A
TIMER2B,//D8,PD6,_BV(6),PD,30,SS1,8,TIMER2B,,TIMER2B
TIMER0A,//D9,PB3,_BV(3),PB,11,,9,TIMER0A,,TIMER0A
TIMER0B,//D10,PB4,_BV(4),PB,12,SS0,10,TIMER0B,,TIMER0B
NOT_ON_TIMER,//D11,PB5,_BV(5),PB,13,MOSI0,11,NOT_ON_TIMER,,NOT_ON_TIMER
TIMER3A,//D12,PB6,_BV(6),PB,14,MISO0,12,NOT_ON_TIMER,,TIMER3A
TIMER3B,//D13,PB7,_BV(7),PB,15,SCK0,13,NOT_ON_TIMER,,TIMER3B
NOT_ON_TIMER,//D14,PB0,_BV(0),PB,8,,14,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D15,PB1,_BV(1),PB,9,,15,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D16,PC3,_BV(3),PC,19,,16,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D17,PC4,_BV(4),PC,20,,17,NOT_ON_TIMER,,TIMER4A
NOT_ON_TIMER,//D18,PD3,_BV(3),PD,27,RX1,18,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D19,PD2,_BV(2),PD,26,TX1,19,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D20,PC1,_BV(1),PC,17,SDA0,20,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D21,PC0,_BV(0),PC,16,SCL0,21,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D22,PC6,_BV(6),PC,22,,22,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D23,PC7,_BV(7),PC,23,,23,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D32,PC2,_BV(2),PC,18,,32,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D33,PC5,_BV(5),PC,21,,33,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//24
NOT_ON_TIMER,//25
NOT_ON_TIMER,//26
NOT_ON_TIMER,//27
NOT_ON_TIMER,//28
NOT_ON_TIMER,//9
NOT_ON_TIMER,//30
NOT_ON_TIMER,//31
NOT_ON_TIMER,//D34,PE0,_BV(0),PE,32,,34,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D35,PE1,_BV(1),PE,33,,35,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D36,PE2,_BV(2),PE,34,MISO1,36,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D37,PE3,_BV(3),PE,35,MOSI1,37,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D38,PE4,_BV(4),PE,36,AREF,38,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D39,PE5,_BV(5),PE,37,SDA1,39,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//D40,PE6,_BV(6),PE,38,SCL1,40,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//41
NOT_ON_TIMER,//42
NOT_ON_TIMER,//43
NOT_ON_TIMER,//44
NOT_ON_TIMER,//45
NOT_ON_TIMER,//46
NOT_ON_TIMER,//47
NOT_ON_TIMER,//48
NOT_ON_TIMER,//49
NOT_ON_TIMER,//50
NOT_ON_TIMER,//51
NOT_ON_TIMER,//52
NOT_ON_TIMER,//53
NOT_ON_TIMER,//A0/D54,PA0,_BV(0),PA,0,ADC0,54,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//A1/D55,PA1,_BV(1),PA,1,ADC1,55,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//A2/D56,PA2,_BV(2),PA,2,ADC2,56,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//A3/D57,PA3,_BV(3),PA,3,ADC3,57,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//A4/D58,PA4,_BV(4),PA,4,ADC4,58,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//A5/D59,PA5,_BV(5),PA,5,ADC5,59,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//A6/D60,PA6,_BV(6),PA,6,ADC6,60,NOT_ON_TIMER,,NOT_ON_TIMER
NOT_ON_TIMER,//A7/D61,PA7,_BV(7),PA,7,ADC7,61,NOT_ON_TIMER,,NOT_ON_TIMER

};

#elif defined(__AVR_ATmega324PB__)
const uint8_t PROGMEM digital_pin_to_timer_PGM[] =
{
NOT_ON_TIMER,//D0,PD0,_BV(0),PD,24,RX0,0,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D1,PD1,_BV(1),PD,25,TX0,1,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D2,PD2,_BV(2),PD,26,INT0,2,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D3,PD3,_BV(3),PD,27,INT1,3,NOT_ON_TIMER,NOT_ON_TIMER
TIMER1B,//D4,PD4,_BV(4),PD,28,,4,TIMER1B,TIMER1B
TIMER1A,//D5,PD5,_BV(5),PD,29,,5,TIMER1A,TIMER1A
NOT_ON_TIMER,//D6,PB2,_BV(2),PB,10,INT2,6,NOT_ON_TIMER,NOT_ON_TIMER
TIMER2A,//D7,PD7,_BV(7),PD,31,SCK1,7,TIMER2A,TIMER2A
TIMER2B,//D8,PD6,_BV(6),PD,30,SS1,8,TIMER2B,TIMER2B
TIMER0A,//D9,PB3,_BV(3),PB,11,,9,TIMER0A,TIMER0A
TIMER0B,//D10,PB4,_BV(4),PB,12,SS0,10,TIMER0B,TIMER0B
NOT_ON_TIMER,//D11,PB5,_BV(5),PB,13,MOSI0,11,NOT_ON_TIMER,NOT_ON_TIMER
TIMER3A,//D12,PB6,_BV(6),PB,14,MISO0,12,NOT_ON_TIMER,TIMER3A
TIMER3B,//D13,PB7,_BV(7),PB,15,SCK0,13,NOT_ON_TIMER,TIMER3B
NOT_ON_TIMER,//D14,PB0,_BV(0),PB,8,,14,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D15,PB1,_BV(1),PB,9,,15,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D16,PC3,_BV(3),PC,19,,16,NOT_ON_TIMER,NOT_ON_TIMER
TIMER4A,//D17,PC4,_BV(4),PC,20,,17,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D18,PD3,_BV(3),PD,27,RX1,18,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D19,PD2,_BV(2),PD,26,TX1,19,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D20,PC1,_BV(1),PC,17,SDA0,20,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D21,PC0,_BV(0),PC,16,SCL0,21,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D22,PC6,_BV(6),PC,22,,22,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D23,PC7,_BV(7),PC,23,,23,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D32,PC2,_BV(2),PC,18,,32,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D33,PC5,_BV(5),PC,21,,33,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//24
NOT_ON_TIMER,//25
NOT_ON_TIMER,//26
NOT_ON_TIMER,//27
NOT_ON_TIMER,//28
NOT_ON_TIMER,//9
NOT_ON_TIMER,//30
NOT_ON_TIMER,//31
NOT_ON_TIMER,//D34,PE0,_BV(0),PE,32,,34,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D35,PE1,_BV(1),PE,33,,35,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D36,PE2,_BV(2),PE,34,MISO1,36,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D37,PE3,_BV(3),PE,35,MOSI1,37,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D38,PE4,_BV(4),PE,36,AREF,38,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D39,PE5,_BV(5),PE,37,SDA1,39,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//D40,PE6,_BV(6),PE,38,SCL1,40,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//41
NOT_ON_TIMER,//42
NOT_ON_TIMER,//43
NOT_ON_TIMER,//44
NOT_ON_TIMER,//45
NOT_ON_TIMER,//46
NOT_ON_TIMER,//47
NOT_ON_TIMER,//48
NOT_ON_TIMER,//49
NOT_ON_TIMER,//50
NOT_ON_TIMER,//51
NOT_ON_TIMER,//52
NOT_ON_TIMER,//53
NOT_ON_TIMER,//A0/D54,PA0,_BV(0),PA,0,ADC0,54,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A1/D55,PA1,_BV(1),PA,1,ADC1,55,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A2/D56,PA2,_BV(2),PA,2,ADC2,56,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A3/D57,PA3,_BV(3),PA,3,ADC3,57,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A4/D58,PA4,_BV(4),PA,4,ADC4,58,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A5/D59,PA5,_BV(5),PA,5,ADC5,59,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A6/D60,PA6,_BV(6),PA,6,ADC6,60,NOT_ON_TIMER,NOT_ON_TIMER
NOT_ON_TIMER,//A7/D61,PA7,_BV(7),PA,7,ADC7,61,NOT_ON_TIMER,NOT_ON_TIMER
};
#endif // Timer defs

#endif // ARDUINO_MAIN


// Missing definitions in iom164pa.h/iom324a.h/iom324p.h/iom324pa.h
#if defined(__AVR_ATmega164PA__) || defined(__AVR_ATmega324A__) || defined(__AVR_ATmega324P__)\
|| defined(__AVR_ATmega324PA__)
  #define SPSR SPSR0
  #define SPDR SPDR0
  #define SPCR SPCR0
  #define SPR0 SPR00
  #define SPR1 SPR10
  #define CPHA CPHA0
  #define CPOL CPOL0
  #define MSTR MSTR0
  #define DORD DORD0
  #define SPE  SPE0
  #define SPIE SPIE0
  #define SPI2X SPI2X0
  #define WCOL WCOL0
  #define SPIF SPIF0
#endif


// Missing definitions in iom324pb.h file + better backwards compatibility
#if defined(__AVR_ATmega324PB__)
  // USART
  #define MPCM0   MPCM
  #define U2X0    U2X
  #define UPE0    UPE
  #define DOR0    DOR
  #define FE0     FE
  #define UDRE0   UDRE
  #define TXC0    TXC
  #define RXC0    RXC
  #define TXB80   TXB8
  #define RXB80   RXB8
  #define UCSZ02  UCSZ2
  #define TXEN0   TXEN
  #define RXEN0   RXEN
  #define UDRIE0  UDRIE
  #define TXCIE0  TXCIE
  #define RXCIE0  RXCIE
  #define UCPOL0  UCPOL
  #define UCSZ00  UCSZ0
  #define UCSZ01  UCSZ1
  #define USBS0   USBS
  #define UPM00   UPM0
  #define UPM01   UPM1
  #define UMSEL00 UMSEL0
  #define UMSEL01 UMSEL1  
  #define MPCM1   MPCM
  #define U2X1    U2X
  #define UPE1    UPE
  #define DOR1    DOR
  #define FE1     FE
  #define UDRE1   UDRE
  #define TXC1    TXC
  #define RXC1    RXC
  #define TXB81   TXB8
  #define RXB81   RXB8
  #define UCSZ12  UCSZ2
  #define TXEN1   TXEN
  #define RXEN1   RXEN
  #define UDRIE1  UDRIE
  #define TXCIE1  TXCIE
  #define RXCIE1  RXCIE
  #define UCPOL1  UCPOL
  #define UCSZ10  UCSZ0
  #define UCSZ11  UCSZ1
  #define USBS1   USBS
  #define UPM10   UPM0
  #define UPM11   UPM1
  #define UMSEL10 UMSEL0
  #define UMSEL11 UMSEL1 
  #define MPCM2   MPCM
  #define U2X2    U2X
  #define UPE2    UPE
  #define DOR2    DOR
  #define FE2     FE
  #define UDRE2   UDRE
  #define TXC2    TXC
  #define RXC2    RXC
  #define TXB82   TXB8
  #define RXB82   RXB8
  #define UCSZ22  UCSZ2
  #define TXEN2   TXEN
  #define RXEN2   RXEN
  #define UDRIE2  UDRIE
  #define TXCIE2  TXCIE
  #define RXCIE2  RXCIE
  #define UCPOL2  UCPOL
  #define UCSZ20  UCSZ0
  #define UCSZ21  UCSZ1
  #define USBS2   USBS
  #define UPM20   UPM0
  #define UPM21   UPM1
  #define UMSEL20 UMSEL0
  #define UMSEL21 UMSEL1
  
  // i2c
  #define TWI_vect TWI0_vect
  #define TWI_vect_num TWI0_vect_num
  #define TWBR TWBR0
  #define TWSR TWSR0
  #define TWS3 TWS03
  #define TWS4 TWS04
  #define TWS5 TWS05
  #define TWS6 TWS06
  #define TWS7 TWS07
  #define TWAR TWAR0
  #define TWDR TWDR0
  #define TWD0 0
  #define TWD1 1
  #define TWD2 2
  #define TWD3 3
  #define TWD4 4
  #define TWD5 5
  #define TWD6 6
  #define TWD7 7
  #define TWCR  TWCR0
  #define TWAMR TWAMR0
  #define TWAM0 TWAM00
  #define TWAM1 TWAM01
  #define TWAM2 TWAM02
  #define TWAM3 TWAM03
  #define TWAM4 TWAM04
  #define TWAM5 TWAM05
  #define TWAM6 TWAM06

  // SPI
  #define SPI_STC_vect SPI0_STC_vect
  #define SPI_STC_vect_num SPI0_STC_vect_num
  #define SPCR SPCR0
  #define SPSR SPSR0
  #define SPDR SPDR0
  #define SPDRB0 0
  #define SPDRB1 1
  #define SPDRB2 2
  #define SPDRB3 3
  #define SPDRB4 4
  #define SPDRB5 5
  #define SPDRB6 6
  #define SPDRB7 7

#endif // 324PB defs

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.

#define SERIAL_PORT_MONITOR         Serial
#define SERIAL_PORT_HARDWARE        Serial
#define SERIAL_PORT_HARDWARE_OPEN   Serial

#if defined(__AVR_ATmega164A__) || defined(__AVR_ATmega164P__) || defined(__AVR_ATmega324A__) || \
defined(__AVR_ATmega324P__) || defined(__AVR_ATmega324PA__) || defined(__AVR_ATmega324PB__) ||   \
defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega1284__) ||     \
defined(__AVR_ATmega1284P__)
#define SERIAL_PORT_HARDWARE1       Serial1
#define SERIAL_PORT_HARDWARE_OPEN1  Serial1
#endif

#if defined(__AVR_ATmega324PB__)
#define SERIAL_PORT_HARDWARE2       Serial2
#define SERIAL_PORT_HARDWARE_OPEN2  Serial2
#endif

#endif // Pins_Arduino_h
