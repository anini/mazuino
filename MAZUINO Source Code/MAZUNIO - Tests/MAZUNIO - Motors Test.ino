/**
 * Project:     MAZUINO | Maze Solving Robot, and more!
 * File:        MAZUNIO - Motors Test.ino
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

void setup()
{
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);
}
void loop()
{
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(13, HIGH);
  delay(2000);
  
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(13, LOW);
  delay(1000);
  
  digitalWrite(0, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(13, HIGH);
  delay(2000);
  
  digitalWrite(0, LOW);
  digitalWrite(4, LOW);
  digitalWrite(13, LOW);
  delay(1000);
  
  digitalWrite(1, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(13, HIGH);
  delay(3000);
  
  digitalWrite(1, LOW);
  digitalWrite(4, LOW);
  digitalWrite(13, LOW);
  delay(1000);
}