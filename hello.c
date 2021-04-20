/**************************** Keyboard codes **********************************/

#define KEY_LEFT_CTRL 1
#define KEY_LEFT_SHIFT 2
#define KEY_F10 67

#define KEY_A     4
#define KEY_B     5
#define KEY_C     6
#define KEY_D     7
#define KEY_E     8
#define KEY_F     9
#define KEY_G     10
#define KEY_H     11
#define KEY_I     12
#define KEY_J     13
#define KEY_K     14
#define KEY_L     15
#define KEY_M     16
#define KEY_N     17
#define KEY_O     18
#define KEY_P     19
#define KEY_Q     20
#define KEY_R     21
#define KEY_S     22
#define KEY_T     23
#define KEY_U     24
#define KEY_V     25
#define KEY_W     26
#define KEY_X     27
#define KEY_Y     28
#define KEY_Z     29
#define KEY_1     30
#define KEY_2     31
#define KEY_3     32
#define KEY_4     33
#define KEY_5     34
#define KEY_6     35
#define KEY_7     36
#define KEY_8     37
#define KEY_9     38
#define KEY_0     39
#define KEY_RET   40
#define KEY_ESC   41
#define KEY_DEL   42
#define KEY_TAB   43
#define KEY_SPACE 44
#define KEY_MIN   45
#define KEY_EQU   46
#define KEY_[     47
#define KEY_]     48
#define KEY_CAP   57

/******************************************************************************/

uint8_t buf[8] = { 0 }; //Keyboard buffer bit rate
#define DELAY_SPEED   200
//Macros for buttons , PORTB and PORTD
//TODO: add PORTC
#define BTN_2 2
#define BTN_3 3
#define BTN_4 4
#define BTN_5 5
#define BTN_6 6
#define BTN_7 7
#define BTN_8 8
#define BTN_9 9
#define BTN_10 10
#define BTN_11 11
#define BTN_12 12
#define BTN_13 13

int isPressed = true; //maybe fix later to be read better.

void setup(){
  Serial.begin(9600);

  pinMode(BTN_2, INPUT);
  pinMode(BTN_3, INPUT);
  pinMode(BTN_4, INPUT);
  pinMode(BTN_5, INPUT);
  pinMode(BTN_6, INPUT);
  pinMode(BTN_7, INPUT);
  pinMode(BTN_8, INPUT);
  pinMode(BTN_9, INPUT);
  pinMode(BTN_10, INPUT);
  pinMode(BTN_11, INPUT);
  pinMode(BTN_12, INPUT);
  pinMode(BTN_13, INPUT);

  //internal pull-ups
  digitalWrite(BTN_2, 1);
  digitalWrite(BTN_3, 1);
  digitalWrite(BTN_4, 1);
  digitalWrite(BTN_5, 1);
  digitalWrite(BTN_6, 1);
  digitalWrite(BTN_7, 1);
  digitalWrite(BTN_8, 1);
  digitalWrite(BTN_9, 1);
  digitalWrite(BTN_10, 1);
  digitalWrite(BTN_11, 1);
  digitalWrite(BTN_12, 1);
  digitalWrite(BTN_13, 1);

  delay(200);
}

void loop(){
  isPressed = digitalRead(BTN_2);
  if (isPressed != true) {
    int CHAR_LEN = 5;
    int hello[CHAR_LEN] = {KEY_H, KEY_E, KEY_L, KEY_L, KEY_O};
    for(int i = 0; i < CHAR_LEN; i++){
      buf[2] = hello[i];
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }
  }
}

void releaseKey(){
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); // Release key
  delay(DELAY_SPEED);
}

//seperate releases b/c need a faster response rate to reduce sensation of lag when going thru color menu
void releaseColor(){
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8); //release
  delay(50);
}
