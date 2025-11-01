/**
 * Project:     MAZUINO | Maze Solving Robot, and more!
 * File:        MAZUNIO - Light Show.ino
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
  for(int i = 2; i < 10; i++)
  {
    pinMode(i, OUTPUT);
  }
}
void loop()
{
  togother();
  togotherR();
  oneAfterAnother();
  togotherR();
  togother();
  oneAfterAnotherR();
  fromCenter();
  fromCenter();
  fromCenter();
  fromCenterS();
  fromCenterS();
  all();
  all();
  all();
  all();
  all();
  all();
  all();
  all();
  all();
  all();
}
void togother()
{
  for(int i = 2; i < 10; i++)
  {
    digitalWrite(i, HIGH);
    delay(100);;
  }
  for(int i = 2; i < 10; i++)
  {
    digitalWrite(i, LOW);
    delay(100);;
  }
}
void togotherR()
{
  for(int i = 9; i > 1; i--)
  {
    digitalWrite(i, HIGH);
    delay(100);;
  }
  for(int i = 9; i > 1; i--)
  {
    digitalWrite(i, LOW);
    delay(100);;
  }
}
void oneAfterAnother()
{
  for(int i = 2; i < 10; i++)
  {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
    delay(100);
  }
  for(int i = 8; i > 2; i--)
  {
    digitalWrite(i, HIGH);
    delay(100);;
    digitalWrite(i, LOW);
    delay(100);
  }
}
void oneAfterAnotherR()
{
  for(int i = 9; i > 1; i--)
  {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
    delay(100);
  }
  for(int i = 3; i < 9; i++)
  {
    digitalWrite(i, HIGH);
    delay(100);;
    digitalWrite(i, LOW);
    delay(100);
  }
}
void fromCenter()
{
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  delay(100);
  digitalWrite(3, HIGH);
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(2, HIGH);
  digitalWrite(9, HIGH);
  delay(100);
  
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(100);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  delay(100);
  digitalWrite(3, LOW);
  digitalWrite(8, LOW);
  delay(100);
  digitalWrite(2, LOW);
  digitalWrite(9, LOW);
  delay(100);
}

void fromCenterS()
{
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(4, HIGH);
  digitalWrite(7, HIGH);
  delay(500);
  digitalWrite(3, HIGH);
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(2, HIGH);
  digitalWrite(9, HIGH);
  delay(500);
  
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(500);
  digitalWrite(4, LOW);
  digitalWrite(7, LOW);
  delay(500);
  digitalWrite(3, LOW);
  digitalWrite(8, LOW);
  delay(500);
  digitalWrite(2, LOW);
  digitalWrite(9, LOW);
  delay(500);
}

void all()
{
  for(int i = 2; i < 10; i++)
  {
    digitalWrite(i, HIGH);
  }
  delay(100);
  for(int i = 2; i < 10; i++)
  {
    digitalWrite(i, LOW);
  }
  delay(100);
}
