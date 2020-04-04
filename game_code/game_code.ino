//including LCD library
//format: Button[0]           Button[1]
//                 LCD SCREEN
//        Button[2]           Button[4]
#include <LiquidCrystal.h>
//initializing library with numbers of interface pins
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);



int button_arr[4][4] = {
  {11, 10, 9, 8},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0}
};
String msg[] = {"Alphabyte Games ", " Press to Start "};
int pos[] = {0 , 0};

void setup() {
  // set up of the LCD's number of columns and rows
  lcd.begin(16, 2);

  //initalize all button pins
  for (int i = 0; i < 4; i++) {
    pinMode(button_arr[0][i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  read_buttons();
  print_msg();
  to_select();
  pick_game();
  ask_math_question();
  ask_spelling_question();
  Serial.println((String)pos[0] + (String)pos[1]);
}
