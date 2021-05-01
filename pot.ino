#define POT_1_R_PIN A0 // - PIN 14
#define POT_2_R_PIN A1 // - PIN 15
#define POT_3_R_PIN A2 // - PIN 16
#define POT_4_R_PIN A3 // - PIN 17
#define POT_5_R_PIN A6 // - PIN 20
#define POT_6_R_PIN A7 // - PIN 21

// value fields - holds the current value of each potentiometer
int _valPot1 = 0;
int _valPot2 = 0;
int _valPot3 = 0;
int _valPot4 = 0;
int _valPot5 = 0;
int _valPot6 = 0;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  readPot(POT_1_R_PIN, &_valPot1);
  readPot(POT_2_R_PIN, &_valPot2);
  readPot(POT_3_R_PIN, &_valPot3);
  readPot(POT_4_R_PIN, &_valPot4);
  readPot(POT_5_R_PIN, &_valPot5);
  readPot(POT_6_R_PIN, &_valPot6);
  delay(250);
}

// reads the current pot value and serial.prints it 
// when it has changed from the fields value
// arguments:
//  pin
//    the pin address
//  *field
//    reference to the pin value-field
void readPot(int pin, int *field)
{
  int sensorValue = map(analogRead(pin), 0, 1023, 0, 100);
  if(isEqual(*field, sensorValue) == false)
  {
    *field = sensorValue;
    Serial.println(String(pin) + ":" + String(*field)); // PIN:VALUE
  }
}

// compares the two given values with a tolerance of +/- 1
// returns: 
//   true 
//     if the values are equal (tolerance included)
//   false
//     if the value is not equal (tolerance included)
bool isEqual(int currentValue, int newValue)
{
  if((newValue == currentValue) == false)
  {
    int newValuePlusOne = newValue + 1;
    int newValueMinusOne = newValue - 1;
    
    if((newValuePlusOne == currentValue) || (newValueMinusOne == newValue))
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  
  return true;
}
