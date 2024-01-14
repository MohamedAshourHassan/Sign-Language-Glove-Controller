
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#define NUMBER_OF_SERVO   (5)
#define ARRAY_OF_ANGLES   (6)
#define FINGER_STATUS     NUMBER_OF_SERVO
/******************************* Functions Prototypes ******************************/
/********** This function check the value stauts variable and then display the words corrsponding to it ***/
void WORDS_ofSignLanguage(uint8_t object);
/******* This function use to set the all servo's angles according to sensor's data ***/
void SERVO_setTheAngleForEachOne(uint8_t * ArrayOfAngles);
/********** This function use to setup the servo pins connections ***/
void SERVO_init(void);

uint8_t Map_AS(char data);

void ReceivedDataOfstring(String data,uint8_t *arr);
/********Enum of Servo's names to make the code readable *********/
enum{
  SERVO_1 = 0, SERVO_2, SERVO_3, SERVO_4, SERVO_5
}SERVOS_ID;
/********Enum of PIN_Servo's names to make the code readable *********/
enum{
  PIN_OF_SERVO_1 = 3, PIN_OF_SERVO_2 = 5, PIN_OF_SERVO_3 = 6, PIN_OF_SERVO_4 = 9, PIN_OF_SERVO_5 = 10, PIN_OF_SERVO_6 = 11
}PINOFSERVOS;
/*** Create lcd Object of LiquidCrystal_I2C ***/
LiquidCrystal_I2C lcd(0x27,16,2);
/**** Array  to store the servo's angles of Servo_class of library  ***/
Servo ArrayOfServos[NUMBER_OF_SERVO];
/*** This array used to store the Received array of servo's angle from MCU ***/ 
String receivedData;
 uint8_t ArrayOfDataToServos[ARRAY_OF_ANGLES] = {LOW};
 
void setup() {
  /*** init to all servo pins *****/
  SERVO_init();
  /**** init the lcd  ***/
    lcd.init();
  /*** Enable the backlight to the LCD. ****/
  lcd.backlight();
  /*** Display the 5 LSB , binary of variable as the 5 status of fingers ****/
  lcd.setCursor(0,1);
  lcd.print("Binary:  ");
  /*** initialize serial communication at 9600 bits per second: ***/
  Serial.begin(9600);
}

void loop() {
    if (Serial.available() > 0) { 
        receivedData = Serial.readString();
        Serial.print("Received Data: ");
        Serial.println(receivedData);
        ReceivedDataOfstring(receivedData,ArrayOfDataToServos);
    }
    SERVO_setTheAngleForEachOne(ArrayOfDataToServos);
    
    WORDS_ofSignLanguage(ArrayOfDataToServos[NUMBER_OF_SERVO]);
    delay(100);
}
/********** This function use to setup the servo pins connections ***/
void SERVO_init(void){

  ArrayOfServos[SERVO_1].attach(PIN_OF_SERVO_1);
  ArrayOfServos[SERVO_2].attach(PIN_OF_SERVO_2);
  ArrayOfServos[SERVO_3].attach(PIN_OF_SERVO_3);
  ArrayOfServos[SERVO_4].attach(PIN_OF_SERVO_4);
  ArrayOfServos[SERVO_5].attach(PIN_OF_SERVO_5);
}
/******* This function use to set the all servo's angles according to sensor's data ***/
void SERVO_setTheAngleForEachOne(uint8_t* ArrayOfAngles){
  uint8_t ServoIndex;
  for(ServoIndex = SERVO_1; ServoIndex <= SERVO_5; ServoIndex ++)
  {
    if( (ArrayOfAngles[ ServoIndex] >= 0 ) && (ArrayOfAngles[ ServoIndex] <= 180 ))
    {
       Serial.print("Angle of Servo ");
       Serial.print( ServoIndex + 1);
       Serial.print(": ");
       Serial.println(ArrayOfAngles[ServoIndex]);
       ArrayOfServos[ServoIndex].write((ArrayOfAngles[ServoIndex]));
       //delay(10);
    }
  }
  
}
/********** This function check the value stauts variable and then display the words corrsponding to it ***/
void WORDS_ofSignLanguage(uint8_t object)
{

/*** Display the 5 LSB , binary of variable as the 5 status of fingers ****/
  lcd.setCursor(10,1);
  lcd.print((object));
  lcd.print("   ");
  Serial.println();
  Serial.print("The Value of object: ");
  Serial.println(object);
  switch(object)
  {
  case 0:
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Helle                            ");
  break;
  case 8:
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hate you                         ");
  break;
  case 12:
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("I Love You                        ");
  break;
  case 13:
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Rock On                          ");
  break;
  case 14:
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("BYE                              ");
  break;
  case 24:
  ///lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("It's Good                        ");
  break;
  case 29:
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("YOU                               ");
  break;
  default:  
  lcd.setCursor(0,0);
  lcd.print("Another Words                         ");
  }
}
uint8_t Map_AS(char data)
{
  return (((data + 80) * 180) / (159.0));
}
void ReceivedDataOfstring(String data,uint8_t *arr)
{
  uint8_t ObjectIndex;
  /************* This variable use as indicator for all sensor's ststus in every cycle of main loop ***/
  uint8_t FormatOfSignLangugeObject = LOW;
  for(ObjectIndex = LOW; ObjectIndex < NUMBER_OF_SERVO; ObjectIndex ++)
  {
    arr[ObjectIndex] = Map_AS((data[ObjectIndex] - '0'));
              /**** Set each bit corrsponding to counter value and value of each sensor ***********/
    if(arr[ObjectIndex] > 100 )
    {
     /********* This the certain bit according to counter value ****/
      FormatOfSignLangugeObject |= (1 << ObjectIndex);
    }
    Serial.println(arr[ObjectIndex]);
    //delay(10);
  }
  arr[ObjectIndex] = ((FormatOfSignLangugeObject & 0x1F));
  Serial.println(arr[ObjectIndex]);
  delay(10);
  Serial.println("*****************************************");
}
