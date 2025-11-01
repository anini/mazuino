/**
 * Project:     MAZUINO | Maze Solving Robot, and more!
 * File:        MAZUNIO - Dancing.ino
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

int ds = 250;
int df = 150;
int RF, RB, LF, LB;

void setup()
{
  LF = 5;
  LB = 6;
  RF = 9;
  RB = 10;

  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);

  analogWrite(RF, 0);
  analogWrite(LF, 0);
  analogWrite(RB, 0);
  analogWrite(LB, 0);
}

void loop()
{
  analogWrite(RF, 0);
  analogWrite(LF, 100);
  analogWrite(RB, 0);
  analogWrite(LB, 0);
  delay(ds);
  analogWrite(RF, 0);
  analogWrite(LF, 0);
  analogWrite(RB, 0);
  analogWrite(LB, 100);
  delay(ds);
  analogWrite(RF, 0);
  analogWrite(LF, 100);
  analogWrite(RB, 0);
  analogWrite(LB, 0);
  delay(ds);
  analogWrite(RF, 0);
  analogWrite(LF, 0);
  analogWrite(RB, 0);
  analogWrite(LB, 100);
  delay(ds);
  analogWrite(RF, 100);
  analogWrite(LF, 0);
  analogWrite(RB, 0);
  analogWrite(LB, 0);
  delay(ds);
  analogWrite(RF, 0);
  analogWrite(LF, 0);
  analogWrite(RB, 100);
  analogWrite(LB, 0);
  delay(ds);
}
