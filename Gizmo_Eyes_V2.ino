boolean isInterrupted = 0;
int mode = 0; //Program starts in 0, blue mode;
int bounceThreshold = 500; // Button debounce.

//Do not change color associations, pinout standardized with Zahrah
int red1 = 3;
int green1 = 5;
int blue1 = 6;
int red2 = 9;
int green2 = 10;
int blue2 = 11;
int redval = 0;
int greenval = 128;
int blueval = 255;

void setup(){
  attachInterrupt(0, interruptHandler1, RISING);//digital pin 2
  pinMode(red1, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(green1, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(blue1, OUTPUT);
  pinMode(blue2, OUTPUT);
}

void loop(){
  isInterrupted = 0;
  if(mode > 2){
    mode = 0;
  }

  switch(mode){
  case 0:
blueEyes();
    break;
  case 1:
    GBEyes();
    break;
  case 2:
rotateEyesFast();
    break;
  }
}

void interruptHandler1(){
  static unsigned long lastpress;
  static unsigned long thispress;
  thispress = millis();
  if(thispress - lastpress > bounceThreshold){
    lastpress = thispress;
    mode++;
    isInterrupted = 1;
  }
}

void blueEyes(){
  off();
  digitalWrite(blue1, HIGH);
  digitalWrite(blue2, HIGH);
}

void GBEyes(){
  off();
  digitalWrite(blue2, HIGH);
  digitalWrite(green1, HIGH);
}

void rotateEyesFast(){
slowbegin1:
  off();
  while(isInterrupted == 0){
    int timer1 = 0;
    int timer2 = 255;

    analogWrite(red1, 255);
    analogWrite(red2, 255);

    while(timer1 <255){
      timer1+=5;
      timer2-=5;
      analogWrite(green1, timer1);
      analogWrite(green2, timer1);
      analogWrite(red1, timer2);
      analogWrite(red2, timer2);
      if(isInterrupted == 1){
        continue;
      }
      delay(20);
    }
    if(isInterrupted == 0){
    delay(500);
    }

    timer1 = 0;
    timer2 = 255;

    while(timer1 <255){
      timer1+=5;
      timer2-=5;
      analogWrite(blue1, timer1);
      analogWrite(blue2, timer1);
      analogWrite(green1, timer2);
      analogWrite(green2, timer2);
      if(isInterrupted == 1){
        continue;
      }
      delay(20);
    }
    if(isInterrupted == 0){
    delay(500);
    }
    timer1 = 0;
    timer2 = 255;

    while(timer1<255){
      timer1+=5;
      timer2-=5;
      analogWrite(red1, timer1);
      analogWrite(red2, timer1);
      analogWrite(blue1, timer2);
      analogWrite(blue2, timer2);
      if(isInterrupted == 1){
        continue;
      }
      delay(20);
    }
    if(isInterrupted == 0){
    delay(500);
    }
    ////////////////////
  }
}

void off(){
  digitalWrite(red1, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(green1, LOW);
  digitalWrite(green2, LOW);
  digitalWrite(blue1, LOW);
  digitalWrite(blue2, LOW);
}









