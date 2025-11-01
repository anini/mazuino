/**
 * Project:     MAZUINO | Maze Solving Robot, and more!
 * File:        MAZUNIO - Sensors Test.ino
 *
 * Copyright (c) 2012, Mohammad Anini
 * The project is licensed under Waqf General Public License <https://ojuba.org/waqf:license>
 *
 * @link https://mazuino.anini.me/
 * @copyright 2012 Anini
 * @author Mohammad Anini <https://anini.me/>
 * @version 1.0.0 (2012)
 * @package MAZUINO
*/

int LL, LR, CL, CR, RL, RR;

void setup()
{
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  
  digitalWrite(14, HIGH);
  digitalWrite(15, HIGH);
  digitalWrite(16, HIGH);
  digitalWrite(17, HIGH);
  digitalWrite(18, HIGH);
  digitalWrite(19, HIGH);
  delay(10);
  pinMode(14, INPUT);
  pinMode(15, INPUT);
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  Serial.begin(9600);  
}

void loop()
{
  
  LL = analogRead(14);
  LR = analogRead(15);
  CL = analogRead(16);
  CR = analogRead(17);
  RL = analogRead(18);
  RR = analogRead(19);
  /*
  if (LL>500)  LL = 1;  else  LL = 0;
  if (LR>500)  LR = 1;  else  LR = 0;
  if (CL>500)  CL = 1;  else  CL = 0;
  if (CR>500)  CR = 1;  else  CR = 0;
  if (RL>500)  RL = 1;  else  RL = 0;
  if (RR>500)  RR = 1;  else  RR = 0;
  */
  
  Serial.print(LL);
  Serial.print(" ");
  Serial.print(LR);
  Serial.print(" ");
  Serial.print(CL);
  Serial.print(" ");
  Serial.print(CR);
  Serial.print(" ");
  Serial.print(RL);
  Serial.print(" ");
  Serial.print(RR);
  Serial.println();
  delay(700);
}  
