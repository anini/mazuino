/**
 * Project:     MAZUINO | Maze Solving Robot, and more!
 * File:        MAZUNIO - Maze Solving.ino
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

//Declare sensors pins
int left_left_sensor, left_right_sensor, center_left_sensor, center_right_sensor, right_left_sensor, right_right_sensor;

//Declare sensors values
int left_left_value, left_right_value, center_left_value, center_right_value, right_left_value, right_right_value;

//Declare motors pins
int right_forward, right_backward, left_forward, left_backward;

//Declare maximum speed of motors (0-255)
int max_speed;

//Declare threshold which wiqll be the dividing line between black and white
int threshold;

//Declare black and white
int black, white;

//Declare maximum time which if exceeded while turning means an error is occurred
int max_time;

//Declare boolean value will be true if an error is occurred
boolean error;

//Declare a string to store the token path in
String path;

//Declare temporarily string to be used when process the path
String temp;

//Declare status of the maze
boolean solved;

//Declare delay time to check if maze solved
int delay_time;

void setup()
{ 
  //Define sensors pins
  left_left_sensor = 14;
  left_right_sensor = 15;
  center_left_sensor = 16;
  center_right_sensor = 17;
  right_left_sensor = 18;
  right_right_sensor = 19;
  
  //Define motors pins
  right_forward = 10;
  right_backward = 9;
  left_forward = 5;
  left_backward = 6;
  
  //Define maximum speed, maximum time and delay time
  max_speed = 150;
  max_time = 3000;
  delay_time = 100;
  
  //Define black and white
  black = 1;
  white = 0;
  
  //Initialize solved, error and path
  solved = false;
  error = false;
  path = "";
  
  setInputsAndOutputs();
  calibrateSensors();
  
  delay(3000);
}

void loop()
{
  //Traverse maze for first time
  if (traverseMaze())
  {
    //processPath();
    //if (solveMaze())
    //{
      celebrate();
    //}
  }
  //If traverseMaze() or solveMaze return false, this means an error is occured 
  alertError();
}

/* 
 * Setting input and output pins
 */
void setInputsAndOutputs()
{
  //Set motors pins as outputs
  pinMode(right_forward, OUTPUT);
  pinMode(right_backward, OUTPUT);
  pinMode(left_forward, OUTPUT);
  pinMode(left_backward, OUTPUT);

  //Set sensors pins as inputs:
  //First we set them as output, then charge them for 100 milliseconds, then set them as inputs
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
}

/* 
 * This function will read all sensors 1000 times to determine the threshold
 */
void calibrateSensors()
{
  int minimum = 1024;
  int maximum = 0;
  for (int i = 0; i < 1000; i++)
  {
    left_left_value = analogRead(left_left_sensor);
    left_right_value = analogRead(left_right_sensor);
    center_left_value = analogRead(center_left_sensor);
    center_right_value = analogRead(center_right_sensor);
    right_left_value = analogRead(right_left_sensor);
    right_right_value = analogRead(right_right_sensor);
    maximum = max(maximum, max(left_left_value, max(left_right_value, max(center_left_value, max(center_right_value, max(right_left_value, right_right_value))))));
    minimum = min(minimum, min(left_left_value, min(left_right_value, min(center_left_value, min(center_right_value, min(right_left_value, right_right_value))))));
    delay(5);
  }
  threshold = (maximum + minimum) / 2;
}

/* 
 * This function will traverse the maze and return true if the maze is solved for the first time without errors
 */
boolean traverseMaze()
{
  while(true)
  {
    readSensors();
    if (!checkDeadEnd())
    {
      if (checkCrossIntersection())
        {
          if(checkMazeSolved())
          {
            solved = true;
          }
          else
          {
            turnLeft();
          }
        }
      else if (checkLeft() && !(solved || error))
      {
        turnLeft();
      }
      else if (checkForward() && !(solved || error))
      {
        moveForward();
      }
      else if (checkRight() && !(solved || error))
      {
        turnRight();
      }
      else if (!(solved || error))
      {
        error = true;
      }
    }
    else if (checkDeadEnd() && !(solved || error))
    {
      revolve();
    }
    else if (solved)
    {
      return true;
    }
    else
    {
     return false;
    }
  }
return false;
}

/* 
 * This function will read all sensors values
 */
void readSensors()
{
  left_left_value = (analogRead(left_left_sensor) > threshold) ? black : white;
  left_right_value = (analogRead(left_right_sensor) > threshold) ? black : white;
  center_left_value = (analogRead(center_left_sensor) > threshold) ? black : white;
  center_right_value = (analogRead(center_right_sensor) > threshold) ? black : white;
  right_left_value = (analogRead(right_left_sensor) > threshold) ? black : white;
  right_right_value = (analogRead(right_right_sensor) > threshold) ? black : white;
}

/* 
 * This function will return true if all sensors values are white
 */
boolean checkDeadEnd()
{
  return (left_left_value == white && left_right_value == white && center_left_value == white && center_right_value == white && right_left_value == white && right_right_value == white) ? true : false;
}

/* 
 * This function will return true if all sensors values are black
 */
boolean checkCrossIntersection()
{
  return (left_left_value == black && left_right_value == black && center_left_value == black && center_right_value == black && right_left_value == black && right_right_value == black) ? true : false;
}

/* 
 * This function will return true if the maze is solved
 * Mazuino will move forward a little bit, then check if all sensors values are black
 */
boolean checkMazeSolved()
{
  moveForward(delay_time);
  readSensors();
  return checkCrossIntersection();
}

/* 
 * This function will return true if both center sensors values are black
 * Which means Mazuino is standing on the line
 */
boolean checkOnLine()
{
  return (center_left_value == black && center_right_value == black) ? true : false;
}

void moveForward()
{
  if (checkOnLine)
  {
    analogWrite(right_backward, 0);
    analogWrite(left_backward, 0);
    analogWrite(right_forward, max_speed);
    analogWrite(left_forward, max_speed);
  }
  else if (right_left_value == black && center_left_value == black)
  {
    analogWrite(right_backward, 0);
    analogWrite(left_backward, 0);
    analogWrite(right_forward, max_speed);
    analogWrite(left_forward, max_speed / 2);
  }
  else if (center_left_value == black)
  {
    analogWrite(right_backward, 0);
    analogWrite(left_backward, 0);
    analogWrite(right_forward, max_speed);
    analogWrite(left_forward, max_speed / 4);
  }
  else if (left_right_value == black && center_right_value == black)
  {
    analogWrite(right_backward, 0);
    analogWrite(left_backward, 0);
    analogWrite(right_forward, max_speed / 2);
    analogWrite(left_forward, max_speed);
  }
  else if (center_right_value == black)
  {
    analogWrite(right_backward, 0);
    analogWrite(left_backward, 0);
    analogWrite(right_forward, max_speed / 4);
    analogWrite(left_forward, max_speed);
  }
  else
  {
    stopMoving();
    error = true;
  }
}

void moveForward(int delay_time)
{
  stopMoving();
  analogWrite(right_forward, max_speed);
  analogWrite(left_forward, max_speed);
  delay(delay_time);
  stopMoving();
}

void stopMoving()
{
  analogWrite(right_backward, 0);
  analogWrite(left_backward, 0);
  analogWrite(right_forward, 0);
  analogWrite(left_forward, 0);
}

void turnLeft()
{
  int time = millis();
  while(!checkDeadEnd())
  {
    if (millis() - time > max_time)
    {
      error = true;
      break;
    }
    moveForward();
    readSensors();
  }
  stopMoving();
  while(!checkOnLine())
  {
    if (millis() - time > max_time)
    {
      error = true;
      break;
    }
    analogWrite(left_backward, max_speed);
    analogWrite(right_forward, max_speed);
    readSensors();
  }
  stopMoving();
}

void turnRight()
{
  int time = millis();
  while(!checkDeadEnd())
  {
    if (millis() - time > max_time)
    {
      error = true;
      break;
    }
    moveForward();
    readSensors();
  }
  stopMoving();
  while(!checkOnLine())
  {
    if (millis() - time > max_time)
    {
      error = true;
      break;
    }
    analogWrite(right_backward, max_speed);
    analogWrite(left_forward, max_speed);
    readSensors();
  }
  stopMoving();
}

void revolve()
{
  delay_time *= 2;
  turnLeft();
  delay_time /= 2;
}

boolean checkLeft()
{
  return (left_left_value == black && left_right_value == black) ? true : false;
}

boolean checkForward()
{
  moveForward(delay_time);
  readSensors();
  return (center_left_value == black || center_right_value == black) ? true : false;
}

boolean checkRight()
{
  return (left_right_value == black && right_right_value == black) ? true : false;
}

void celebrate()
{
  stopMoving();
  delay(10000);
}

void alertError()
{
  stopMoving();
  delay(10000);
}
