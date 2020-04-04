//menu functions for game selection

void read_buttons() {
  //REQUIRES: existing static [4][4] int array, row 0 is button #, row 1 is toggle, row2
  //          is current state, row3 is buttonpressed
  //PROMISES: Reads button pressed, and will set buttonPressed (row 3 in arr_array)
  //          to 1 (if buttons in columns are pressed) for one clock cycle

  //reset button pressed to 0
  for (int i = 0; i < 4; i++) {
    button_arr[3][i] = 0;
  }

  //read button state
  for (int i = 0; i < 4; i++) {
    button_arr [2][i] = digitalRead (button_arr [0][i]);
  }

  //read single press
  for (int i = 0; i < 4; i++) {
    if (button_arr[2][i] == 1) {          //if pressed
      button_arr[1][i] = 1;               //set toggle to 1
    }
    else if (button_arr[1][i] == 1) {     //once released
      button_arr[1][i] = 0;               //set toggle to 0;
      button_arr[3][i] = 1;               //set buttonpressed to 1
    }
  }
}

void print_msg() {
  lcd.setCursor(0, 0);
  lcd.print(msg[0]);
  lcd.setCursor(0, 1);
  lcd.print(msg[1]);
}

void to_select() {
  if (pos[0] == 0) {
    if (button_arr [3][0] == 1 || button_arr [3][1] == 1 || button_arr [3][2] == 1 || button_arr [3][3] == 1) {
      msg[0] = "Math    Spelling";
      msg[1] = "Other Game??????";
      pos[0] = 1;
      for (int i = 0; i < 4; i++) {
        button_arr[3][i] = 0;
      }
    }
  }
}

void pick_game() {
  if (pos[0] == 1) {
    if (button_arr[3][0] == 1) {    //goto math
      msg[0] = "  Press any to  ";
      msg[1] = "   Play Again   ";
      pos[0] = 2;                  //pos for math game
      pos[1] = 0;
    }
    if (button_arr[3][1] == 1) {    //goto spelling
      msg[0] = "  Press any to  ";
      msg[1] = "   Play Again   ";
      pos[0] = 2;                   //pos for spelling game
      pos[1] = 1;
    }
  }
}
