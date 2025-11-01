/**
 * Project:     MAZUINO | Maze Solving Robot, and more!
 * File:        MAZUNIO - Maze Solving with Music & Light Show.ino
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

#include <Tone.h>

Tone tone1;

#define OCTAVE_OFFSET 0

int notes[] = { 0,
NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4,
NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5,
NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6, NOTE_B6,
NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7
};

char *song3 = "MissionImp:d=16,o=6,b=95:32d,32d#,32d,32d#,32d,32d#,32d,32d#,32d,32d,32d#,32e,32f,32f#,32g,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,g,8p,g,8p,a#,p,c7,p,g,8p,g,8p,f,p,f#,p,a#,g,2d,32p,a#,g,2c#,32p,a#,g,2c,a#5,8c,2p,32p,a#5,g5,2f#,32p,a#5,g5,2f,32p,a#5,g5,2e,d#,8d";
char *song2 = "SMBUndergr:d=16,o=6,b=100:c,c5,a5,a,a#5,a#,2p,8p,c,c5,a5,a,a#5,a#,2p,8p,f5,f,d5,d,d#5,d#,2p,8p,f5,f,d5,d,d#5,d#,2p,32d#,d,32c#,c,p,d#,p,d,p,g#5,p,g5,p,c#,p,32c,f#,32f,32e,a#,32a,g#,32p,d#,b5,32p,a#5,32p,a5,g#5";
char *song1 = "smb:d=4,o=5,b=100:16e6,16e6,32p,8e6,16c6,8e6,8g6,8p,8g,8p,8c6,16p,8g,16p,8e,16p,8a,8b,16a#,8a,16g.,16e6,16g6,8a6,16f6,8g6,8e6,16c6,16d6,8b,16p,8c6,16p,8g,16p,8e,16p,8a,8b,16a#,8a,16g.,16e6,16g6,8a6,16f6,8g6,8e6,16c6,16d6,8b,8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16g#,16a,16c6,16p,16a,16c6,16d6,8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16c7,16p,16c7,16c7,p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16g#,16a,16c6,16p,16a,16c6,16d6,8p,16d#6,8p,16d6,8p,16c6";
char *timer = "Tot:32d";
char *turnTone = "turn:d=4,o=5,b=100:16e6,16e6";
char *DeadEndTone = "death:d=4,o=5,b=90:16b,16f6,16p,16f6,16f.6,16e.6,16d6,16c6,16p,16e,16p,16c";


int left_left_sensor, left_right_sensor, center_left_sensor, center_right_sensor, right_left_sensor, right_right_sensor;

int LL, LR, CL, CR, RL, RR;

int threshold;

int maxSpeed = 100;

int RF, RB, LF, LB;

String path = "";
String temp = "";
int index = 0;

boolean left, right, straight;

boolean Solved = false;

void setup()
{ 

  LF = 5;
  LB = 6;
  RF = 10;
  RB = 9;

  //Define sensors pins
  left_left_sensor = 14;
  left_right_sensor = 15;
  center_left_sensor = 16;
  center_right_sensor = 17;
  right_left_sensor = 18;
  right_right_sensor = 19;

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

  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  
  analogWrite(RF, 0);
  analogWrite(LF, 0);
  analogWrite(RB, 0);
  analogWrite(LB, 0);
  calibrateSensors();
  readSensors();
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  tone1.begin(3);
 
  digitalWrite(3, HIGH);
  /*play_rtttl(song1);
  play_rtttl(song3);
  delay(2000);*/
  //Timer();
  delay(1000);

}

void loop()
{
  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, LOW);
  
  readSensors();
  
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
  
  if(!(LL <= 0 && LR <= 0 && CL <= 0 && CR <= 0 && RL <= 0 && RR <= 0))
  {
    if(((LL + LR) > 10) && ((CL + CR) > 10) && ((RL + RR) > 10))
    {
      analogWrite(RF, 0);
      analogWrite(LF, 0);
      analogWrite(RB, 0);
      analogWrite(LB, 0);
      analogWrite(RF, maxSpeed);
      analogWrite(LF, maxSpeed);      
      delay(150);
      analogWrite(RF, 0);
      analogWrite(LF, 0);
      analogWrite(RB, 0);
      analogWrite(LB, 0);
      readSensors();

      if(((LL + LR) > 10) && ((CL + CR) > 10) && ((RL + RR) > 10))
      {
        analogWrite(RF, 0);
        analogWrite(LF, 0);
        analogWrite(RB, 0);
        analogWrite(LB, 0);
        play_rtttl(song1);
        generateShortestPath();
        solveTheMaze();
      }
      else
      {
        left = true;
        right = true;
      }
    }
    else
    {
      if(LL >= 5 && LR >= 5)
      {
        left = true;
      }
      if(RL >= 5 && RR >= 5)
      {
        right = true;
      }
    }
      if(left)
      {
        digitalWrite(0, LOW);
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(7, LOW);
        digitalWrite(4, HIGH);
        
        analogWrite(RF, 0);
        analogWrite(LF, 0);
        analogWrite(RB, 0);
        analogWrite(LB, 0);
  
        while (LL >= 5 && LR >= 5)
        {
          analogWrite(RF, maxSpeed);
          analogWrite(LF, maxSpeed);
          readSensors();
        }
        analogWrite(RF, 0);
        analogWrite(LF, 0);
        analogWrite(RB, 0);
        analogWrite(LB, 0);
        play_rtttl(turnTone);
  
        while (CR >= 5)
        {
          analogWrite(RF, maxSpeed);
          analogWrite(LB, maxSpeed);
          readSensors();
        }
  
        while (!(CR >= 5 && CL >= 5))
        {
          analogWrite(RF, maxSpeed);
          analogWrite(LB, maxSpeed);
          readSensors();
        }
        analogWrite(RF, 0);
        analogWrite(LF, 0);
        analogWrite(RB, 0);
        analogWrite(LB, 0);
        delay(75);
        path = path + "L";
      }
  
      else if (CL >= 5 && CR >= 5)
      {
        analogWrite(RB, 0);
        analogWrite(LB, 0);
        if (right)
        {
          while(RR >= 5)
          {
            analogWrite(RF, maxSpeed);
            analogWrite(LF, maxSpeed);
            readSensors();
          }
          if ((LL <= 0 && LR <= 0 && CL <= 0 && CR <= 0 && RL <= 0 && RR <= 0))
          {
            right = true;
            analogWrite(RF, 0);
            analogWrite(LF, 0);
            analogWrite(RB, 0);
            analogWrite(LB, 0);
            play_rtttl(timer);
          }
          else
          {
            right = false;
            path = path + "S";
          }
        }
        else
        {
          analogWrite(RF, maxSpeed);
          analogWrite(LF, maxSpeed);
        }
      }
  
      else if (CL >= 5)
      {
        analogWrite(RB, 0);
        analogWrite(LB, 0);
        if (right)
        {
          while(RR >= 5)
          {
            analogWrite(RF, (maxSpeed / 2));
            analogWrite(LF, maxSpeed);
            readSensors();
          }
          if ((LL <= 0 && LR <= 0 && CL <= 0 && CR <= 0 && RL <= 0 && RR <= 0))
          {
            right = true;
            analogWrite(RF, 0);
            analogWrite(LF, 0);
            analogWrite(RB, 0);
            analogWrite(LB, 0);
            play_rtttl(timer);
          }
          else
          {
            right = false;
            path = path + "S";
          }
        }
        else
        {
          analogWrite(RF, maxSpeed);
          analogWrite(LF, (maxSpeed / 2));
        }
      }
  
      else if (CR >= 5)
      {
        analogWrite(RB, 0);
        analogWrite(LB, 0);
        if (right)
        {
          while(RR >= 5)
          {
            analogWrite(RF, (maxSpeed / 2));
            analogWrite(LF, maxSpeed);
            readSensors();
          }
          if ((LL <= 0 && LR <= 0 && CL <= 0 && CR <= 0 && RL <= 0 && RR <= 0))
          {
            right = true;
            analogWrite(RF, 0);
            analogWrite(LF, 0);
            analogWrite(RB, 0);
            analogWrite(LB, 0);
            play_rtttl(timer);
          }
          else
          {
            right = false;
            path = path + "S";
          }
        }
        else
        {
          analogWrite(RF, (maxSpeed / 2));
          analogWrite(LF, maxSpeed);
        }
      }
      readSensors();
      if ((LL >= 5 || LR >= 5) && (RL >= 5 || RR >= 5))
      {
        right = false;
      }
      if (right)
      {
        digitalWrite(0, HIGH);
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(7, LOW);
        digitalWrite(4, LOW);
        
        analogWrite(RF, 0);
        analogWrite(LF, 0);
        analogWrite(RB, 0);
        analogWrite(LB, 0);
        while (RL >= 5 && RR >= 5)
        {
          analogWrite(RF, maxSpeed);
          analogWrite(LF, maxSpeed);
          readSensors();
        }
  
        analogWrite(RF, 0);
        analogWrite(LF, 0);
        analogWrite(RB, 0);
        analogWrite(LB, 0);
        play_rtttl(turnTone);
  
        while (!(CL >= 5 && CR >= 5))
        {
          analogWrite(LF, maxSpeed);
          analogWrite(RB, maxSpeed);
          readSensors();
        }
        analogWrite(RF, 0);
        analogWrite(LF, 0);
        analogWrite(RB, 0);
        analogWrite(LB, 0);
        delay(75);
        path = path + "R";
      }
    }
  
  else
  {
    digitalWrite(0, HIGH);
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(7, LOW);
    digitalWrite(4, HIGH);
    
    analogWrite(RF, 0);
    analogWrite(LF, 0);
    analogWrite(RB, 0);
    analogWrite(LB, 0);
    play_rtttl(DeadEndTone);

    while (!(CR >= 5 && CL >= 5))
    {
      analogWrite(RF, maxSpeed);
      analogWrite(LB, maxSpeed);
      readSensors();
    }
    analogWrite(RF, 0);
    analogWrite(LF, 0);
    analogWrite(RB, 0);
    analogWrite(LB, 0);
    delay(75);
    path = path + "B";
  }
  left = false;
  right = false;
  straight = false;
}


void calibrateSensors()
{
  int minimum = 1024;
  int maximum = 0;
  for (int i = 0; i < 1000; i++)
  {
    LL = analogRead(left_left_sensor);
    LR = analogRead(left_right_sensor);
    CL = analogRead(center_left_sensor);
    CR = analogRead(center_right_sensor);
    RL = analogRead(right_left_sensor);
    RR = analogRead(right_right_sensor);
    maximum = max(maximum, max(LL, max(LR, max(CL, max(CR, max(RL, RR))))));
    minimum = min(minimum, min(LL, min(LR, min(CL, min(CR, min(RL, RR))))));
    delay(5);
  }
  threshold = (maximum + minimum) / 2;
}

void readSensors()
{
  LL = (analogRead(left_left_sensor) > threshold) ? 10 : 0;
  LR = (analogRead(left_right_sensor) > threshold) ? 10 : 0;
  CL = (analogRead(center_left_sensor) > threshold) ? 10 : 0;
  CR = (analogRead(center_right_sensor) > threshold) ? 10 : 0;
  RL = (analogRead(right_left_sensor) > threshold) ? 10 : 0;
  RR = (analogRead(right_right_sensor) > threshold) ? 10 : 0;
}


void generateShortestPath()
{
  while (path.indexOf("B") != -1)
  {
    index = path.indexOf("B");
    temp = path.substring((index - 1), (index + 2));
    temp = replacement(temp);
    Serial.println(path);

    if (index > 1 && index < (path.length() - 2))
      path = path.substring(0, (index - 1)) + temp + path.substring(index + 2);
    else if (index > 1)
      path = path.substring(0, (index - 1)) + temp;
    else if (index < (path.length() - 2))
      path = temp + path.substring(index + 2);
    else
      path = temp;
  }
}

String replacement(String combination)
{
  if (combination == "LBL")
    return "S";
  else if (combination == "LBS")
    return "R";
  else if (combination == "LBR")
    return "B";
  else if (combination == "SBL")
    return "R";
  else if (combination == "SBS")
    return "B";
  else if (combination == "RBL")
    return "B"; 
}



void solveTheMaze()
{
  while(!Solved && path.length() > 0)
  {

    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    digitalWrite(2, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(4, LOW);

    readSensors();

    if(LL >= 5 && LR >= 5)
    {
      left = true;
    }

    if(CL >= 5 && CR >= 5)
    {
      straight = true;
    }

    if(RL >= 5 && RR >= 5)
    {
      right = true;
    }

    if(!(LL <= 0 && LR <= 0 && CL <= 0 && CR <= 0 && RL <= 0 && RR <= 0))
    {
      if(LL >= 5 && LR >= 5 && CL >= 5 && CR >= 5 && RL >= 5 && RR >= 5)
      {
        analogWrite(RF, maxSpeed);
        analogWrite(LF, (maxSpeed - 5));
        delay(50);
        readSensors();

        if(LL >= 5 && LR >= 5 && CL >= 5 && CR >= 5 && RL >= 5 && RR >= 5)
        {
          Solved = true;
        }
        else
        {
          left = true;
          right = true;
        }
      }
    }

    if (Solved)
    {
      left = false;
      straight = false;
      right = false;
      analogWrite(RF, 0);
      analogWrite(LF, 0);
      analogWrite(RB, 0);
      analogWrite(LB, 0);
    }

    //determining intersection type
    if (left || right)
    {
      if (path.charAt(0) == 'L')
      {
        left = true;
        straight = false;
        right = false;
      }
      else if (path.charAt(0) == 'S')
      {
        left = false;
        straight = true;
        right = false;
      }
      else if (path.charAt(0) == 'R')
      {
        left = false;
        straight = false;
        right = true;
      }
      path = path.substring(1);

      if(left)
      {

        digitalWrite(0, LOW);
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(7, LOW);
        digitalWrite(4, HIGH);
        analogWrite(RF, maxSpeed);
        analogWrite(LF, maxSpeed);
        delay(50);
        analogWrite(RF, 0);
        analogWrite(LF, 0);
        delay(75);

        analogWrite(RF, maxSpeed);
        analogWrite(LF, 0);
        analogWrite(RB, 0);
        analogWrite(LB, maxSpeed);
        delay(100);
        readSensors();
        while(!(CL >= 5 && CR >= 5))
        {
          analogWrite(RF, maxSpeed);
          analogWrite(LF, 0);
          analogWrite(RB, 0);
          analogWrite(LB, maxSpeed);
          readSensors();
        }

        analogWrite(RF, 0);
        analogWrite(LF, 0);
        analogWrite(RB, 0);
        analogWrite(LB, 0);
        delay(100);
      }

      else if (right)
      {

        digitalWrite(0, HIGH);
        digitalWrite(1, LOW);
        digitalWrite(2, LOW);
        digitalWrite(7, LOW);
        digitalWrite(4, LOW);

        analogWrite(RB, 0);
        analogWrite(LB, 0);
        analogWrite(RF, maxSpeed);
        analogWrite(LF, maxSpeed);
        delay(50);
        analogWrite(RF, 0);
        analogWrite(LF, 0);
        delay(100);

        analogWrite(LF, maxSpeed);
        analogWrite(RB, maxSpeed);
        analogWrite(RF, 0);
        analogWrite(LF, 0);
        delay(100);

        readSensors();
        while(!(CL >= 5 && CR >= 5))
        {
          analogWrite(RF, 0);
          analogWrite(LB, 0);
          analogWrite(LF, (maxSpeed - 5));
          analogWrite(RB, (maxSpeed));
          readSensors();
        }

        analogWrite(RF, 0);
        analogWrite(LF, 0);
        analogWrite(RB, 0);
        analogWrite(LB, 0);
        delay(100);
      }
    }

    else if(CL >= 5 && CR >= 5)
    {
      analogWrite(RF, maxSpeed);
      analogWrite(LF, maxSpeed);
    }

    else if (LR >= 5)
    {
      analogWrite(RF, maxSpeed);
      analogWrite(LF, ((maxSpeed / 3) * 2));
    }

    else if (RL >= 5)
    {
      analogWrite(RF, ((maxSpeed / 3) * 2));
      analogWrite(LF, maxSpeed);
    }

    else if (CL >= 5)
    {
      analogWrite(RF, maxSpeed);
      analogWrite(LF, (maxSpeed / 4));
    }

    else if (CR >= 5)
    {
      analogWrite(RF, (maxSpeed / 4));
      analogWrite(LF, maxSpeed);
    }

    else
    {
      analogWrite(RF, 0);
      analogWrite(LF, 0);
    }

    left = false;
    right = false;
    straight = false;
  }

  delay(7000);
}



void play_rtttl(char *p)
{
  // Absolutely no error checking in here

  byte default_dur = 4;
  byte default_oct = 6;
  int bpm = 63;
  int num;
  long wholenote;
  long duration;
  byte note;
  byte scale;

  // format: d=N,o=N,b=NNN:
  // find the start (skip name, etc)

  while(*p != ':') p++;    // ignore name
  p++;                     // skip ':'

  // get default duration
  if(*p == 'd')
  {
    p++; p++;              // skip "d="
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    if(num > 0) default_dur = num;
    p++;                   // skip comma
  }

  // get default octave
  if(*p == 'o')
  {
    p++; p++;              // skip "o="
    num = *p++ - '0';
    if(num >= 3 && num <=7) default_oct = num;
    p++;                   // skip comma
  }


  // get BPM
  if(*p == 'b')
  {
    p++; p++;              // skip "b="
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    bpm = num;
    p++;                   // skip colon
  }


  // BPM usually expresses the number of quarter notes per minute
  wholenote = (60 * 1000L / bpm) * 4;  // this is the time for whole note (in milliseconds)

  // now begin note loop
  while(*p)
  {
    // first, get note duration, if available
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    
    if(num) duration = wholenote / num;
    else duration = wholenote / default_dur;  // we will need to check if we are a dotted note after

    // now get the note
    note = 0;

    switch(*p)
    {
      case 'c':
        note = 1;
        break;
      case 'd':
        note = 3;
        break;
      case 'e':
        note = 5;
        break;
      case 'f':
        note = 6;
        break;
      case 'g':
        note = 8;
        break;
      case 'a':
        note = 10;
        break;
      case 'b':
        note = 12;
        break;
      case 'p':
      default:
        note = 0;
    }
    p++;

    // now, get optional '#' sharp
    if(*p == '#')
    {
      note++;
      p++;
    }

    // now, get optional '.' dotted note
    if(*p == '.')
    {
      duration += duration/2;
      p++;
    }
  
    // now, get scale
    if(isdigit(*p))
    {
      scale = *p - '0';
      p++;
    }
    else
    {
      scale = default_oct;
    }

    scale += OCTAVE_OFFSET;

    if(*p == ',')
      p++;       // skip comma for next note (or we may be at the end)

    // now play the note

    if(note)
    {
      tone1.play(notes[(scale - 4) * 12 + note]);
      delay(duration);
      tone1.stop();
    }
    else
    {
      delay(duration);
    }
  }
}


void Timer()
{

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
  play_rtttl(timer);
  delay(250);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(250);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(250);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(250);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(250);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(250);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(250);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(250);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(150);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(150);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(150);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(150);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(150);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(150);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(150);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(150);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(100);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(100);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(100);

  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  play_rtttl(timer);
  delay(50);
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(4, HIGH);
  play_rtttl(timer);
  delay(1000);
}
