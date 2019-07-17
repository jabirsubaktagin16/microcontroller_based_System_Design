#include <Keypad.h>
const byte ROWS =4;
const byte COLS =4;
// Define the Keymap
char keys [ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
//Connect keypad ROW0,ROW1,ROW2 and ROW3 to the arduino places
byte rowPins[ROWS]={4,5,6,7};

byte colPins[COLS]={8,9,10,11};

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

#define pinone 13

void setup()
{
  pinMode(pinone,OUTPUT);
  digitalWrite(pinone, HIGH);
  Serial.begin(9600);
}

void loop()
{
  char key=kpd.getKey();
  if(key)
  {
    switch(key)
    {
      case '*':
        digitalWrite(pinone,LOW);
        break;
      case '#':
        digitalWrite(pinone,HIGH);
        break;
       default:
        Serial.println(key);
    }
  }
}

