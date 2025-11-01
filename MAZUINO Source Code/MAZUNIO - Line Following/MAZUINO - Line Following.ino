/**
 * Project:     MAZUINO | Maze Solving Robot, and more!
 * File:        MAZUNIO - Line Following.ino
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

int left_left_sensor, left_right_sensor, center_left_sensor, center_right_sensor, right_left_sensor, right_right_sensor;

int threshold = 500;

int LL, LR, CL, CR, RL, RR;

int maxSpeed = 200;

int RF, RB, LF, LB;

boolean x = true;

void readSensors()
{
  LL = (analogRead(left_left_sensor) > threshold) ? 10 : 0;
  LR = (analogRead(left_right_sensor) > threshold) ? 10 : 0;
  CL = (analogRead(center_left_sensor) > threshold) ? 10 : 0;
  CR = (analogRead(center_right_sensor) > threshold) ? 10 : 0;
  RL = (analogRead(right_left_sensor) > threshold) ? 10 : 0;
  RR = (analogRead(right_right_sensor) > threshold) ? 10 : 0;
}

void setup()
{  
  left_left_sensor = 14;
  left_right_sensor = 15;
  center_left_sensor = 16;
  center_right_sensor = 17;
  right_left_sensor = 18;
  right_right_sensor = 19;

  pinMode(left_left_sensor, OUTPUT);
  pinMode(left_right_sensor, OUTPUT);
  pinMode(center_left_sensor, OUTPUT);
  pinMode(center_right_sensor, OUTPUT);
  pinMode(right_left_sensor, OUTPUT);
  pinMode(right_right_sensor, OUTPUT);
  digitalWrite(left_left_sensor, HIGH);
  digitalWrite(left_right_sensor, HIGH);
  digitalWrite(center_left_sensor, HIGH);
  digitalWrite(center_right_sensor, HIGH);
  digitalWrite(right_left_sensor, HIGH);
  digitalWrite(right_right_sensor, HIGH);
  delay(100);
  pinMode(left_left_sensor, INPUT);
  pinMode(left_right_sensor, INPUT);
  pinMode(center_left_sensor, INPUT);
  pinMode(center_right_sensor, INPUT);
  pinMode(right_left_sensor, INPUT);
  pinMode(right_right_sensor, INPUT);
  
  
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(12, OUTPUT);
  
  digitalWrite(12, HIGH);
  
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(250);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(250);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(250);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(250);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(250);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(250);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(250);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(250);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(150);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(150);digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(150);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(150);digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(150);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(150);digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(150);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(150);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(100);
  
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  delay(50);
  
  LF = 5;
  LB = 6;
  RF = 10;
  RB = 9;
  
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(12, OUTPUT);
  
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
  readSensors();
  
  if (LL >= 5 && LR < 5)
  {
    analogWrite(RF, maxSpeed - 50);
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    analogWrite(LF, 0);
  }
  else if (RR >= 5 && RL < 5)
  {
    analogWrite(RF, 0);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(7, LOW);
    digitalWrite(4, HIGH);
    analogWrite(LF, maxSpeed - 50);
  }
  else if (LL >= 5)
  {
    analogWrite(RF, maxSpeed - 25);
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    analogWrite(LF, 0);
  }
  else if (RR >= 5)
  {
    analogWrite(RF, 0);
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(7, LOW);
    digitalWrite(4, HIGH);
    analogWrite(LF, maxSpeed - 25);
  }
  else if (LR >= 5 && CL < 5)
  {
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    analogWrite(RF, maxSpeed - 25);
    analogWrite(LF, maxSpeed / 4);
  }
  else if (RL >= 5 && CR < 5)
  {
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(4, HIGH);
    analogWrite(RF, maxSpeed / 4);
    analogWrite(LF, maxSpeed - 25);
  }
  else if (LR >= 5)
  {
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    digitalWrite(2, LOW);
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    analogWrite(RF, maxSpeed - 25);
    analogWrite(LF, maxSpeed / 3);
  }
  else if (RL >= 5)
  {
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(4, HIGH);
    analogWrite(RF, maxSpeed / 3);
    analogWrite(LF, maxSpeed - 25);
  }
  else if(CL >= 5 && CR >= 5)
  {
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    digitalWrite(2, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    analogWrite(RF, maxSpeed);
    analogWrite(LF, maxSpeed - 5);
  }
  else if (CL >= 5)
  {
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(4, LOW);
    analogWrite(RF, maxSpeed - 15);
    analogWrite(LF, maxSpeed - 50);
  }
  else if (CR >= 5)
  {
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(4, LOW);
    analogWrite(RF, maxSpeed - 50);
    analogWrite(LF, maxSpeed - 20);
  }
  else
  {
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(7, LOW);
    digitalWrite(4, HIGH);
      analogWrite(RB, 0);
      analogWrite(LB, 0);
      analogWrite(RF, 0);
      analogWrite(LF, 0);    
  }
}  
