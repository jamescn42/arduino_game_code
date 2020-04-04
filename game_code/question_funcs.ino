//format: Button[0]           Button[1]
//                 LCD SCREEN
//        Button[2]           Button[4]
typedef struct {
  //lines 1/2 are to display on the lcd
  //answer is between 0-3. that button is the correct answer
  //question_audio_code refers to the index of a seperate array
  //with the question in audio format
  String line1;
  String line2;
  int answer;
  int question_audio_code;
} Question;


//MATH questions*************************************************************
//Question: "What does three plus five equal?" (3+5=8)
Question math_addition = {"4             19", "8              7", 2, 0};

//Question: "What does ten minus seven equal?" (10-7=3)
Question math_subtract = {"3             17", "7              4", 0, 1};

//Question: "What does six multiplied by 7 equal?" (6*7=42)
Question math_multiply = {"20            67", "32            42", 3, 2};

//Question: "What does fifty four divided by 6 equal?" (54/6 = 9)
Question math_divide = {"13             9", "14            07", 1, 3};

Question math_questions[] = {math_addition, math_subtract, math_multiply, math_divide};

//Spelling Questions********************************************************
//Question: "How do you spell 'green'?
Question spell_0 = {"gren       green", "grane       jean", 1, 4};

//Question: How do you spell 'animal'?
Question spell_1 = {"animal    animel", "anemal  aneimall", 0, 5};

//Question: How do you spell 'believe'?
Question spell_2 = {"bellive   believ", "belive   believe", 3, 6};

//Question: How do you spell 'remain'?
Question spell_3 = {"reemane   ravine", "remain    remane", 2, 7};

Question spelling_questions[] = {spell_0, spell_1, spell_2, spell_3};


//FUNCTIONS
void ask_math_question() {
  if (pos[0] == 2 && pos[1] == 0) {       //in math games mode

    //pick random math question
    int question_number = random(4);

    while (1) {
      read_buttons();
      //display math question
      lcd.setCursor(0, 0);
      lcd.print(math_questions[question_number].line1);
      lcd.setCursor(0, 1);
      lcd.print(math_questions[question_number].line2);

      //check for correct answer
      if (button_arr[3][math_questions[question_number].answer] == 1) {
        lcd.setCursor(0, 0);
        lcd.print("   Correct!!!   ");
        lcd.setCursor(0, 1);
        lcd.print("   Correct!!!   ");
        delay(2000);
        pos[0] = 0;
        pos[1] = 0;
        break;
      } else if(button_arr[3][0] == 1 || button_arr[3][1] == 1 || button_arr[3][2] == 1 || button_arr[3][3] == 1){
        lcd.setCursor(0, 0);
        lcd.print("    Incorrect   ");
        lcd.setCursor(0, 1);
        lcd.print("Please Try Again");
        delay(2000);
      }
    }
  }
}

void ask_spelling_question() {
  if (pos[0] == 2 && pos[1] == 1) {       //in spelling games mode

    //pick random math question
    randomSeed(analogRead(0));
    int question_number = random(4);

    while (1) {
      read_buttons();
      //display math question
      lcd.setCursor(0, 0);
      lcd.print(spelling_questions[question_number].line1);
      lcd.setCursor(0, 1);
      lcd.print(spelling_questions[question_number].line2);

      //check for correct answer
      if (button_arr[3][spelling_questions[question_number].answer] == 1) {
        lcd.setCursor(0, 0);
        lcd.print("   Correct!!!   ");
        lcd.setCursor(0, 1);
        lcd.print("   Correct!!!   ");
        delay(2000);
        pos[0] = 0;
        pos[1] = 0;
        break;
      } else if(button_arr[3][0] == 1 || button_arr[3][1] == 1 || button_arr[3][2] == 1 || button_arr[3][3] == 1){
        lcd.setCursor(0, 0);
        lcd.print("    Incorrect   ");
        lcd.setCursor(0, 1);
        lcd.print("Please Try Again");
        delay(2000);
      }
    }
  }
}
