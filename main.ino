#include <LiquidCrystal.h>
#include "LedControl.h"
#include "Board.h"

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
LedControl lc=LedControl(5,3,4,1);
Board board = Board(8,8);


void printBoard() {
  byte state = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board.getCoordinate(i,j) != 0) {
        state = 1;
      }
      else {
        state = 0;
      }
      lc.setLed(0,i,j,state); 
    }
  }
}

void setup() {
  lcd.begin(16, 2);
  // Joystick setup
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);

  // Matrix setup 
  lc.shutdown(0,false);
  lc.setIntensity(0,1);
  lc.clearDisplay(0);

  printBoard();
}

void loop() {
  int input = analogRead(Y_pin);

  if (input < 250) {
    input = 1;
  }
  else if (input > 750) {
    input = -1;
  }
  else {
    input = 0;
  }

  // Could read a second joystick as the second player
  int result = board.update(input, input);

  if (result != 0) {
    board.reset(false);
  }
  
  printBoard();

  String scP1 = "Player 1: ";
  scP1 = scP1 + board.getPlayer1().getScore();
  String scP2 = "Player 2: ";
  scP2 = scP2 + board.getPlayer2().getScore();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(scP1);
  lcd.setCursor(0, 1);
  lcd.print(scP2);
    
  delay(500);
}
