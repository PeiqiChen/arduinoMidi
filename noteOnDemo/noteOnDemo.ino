
int note[] = {108, 96, 84, 72, 60, 48};

void setup() {
  //start serial communication
  Serial.begin(9600);
}

void loop() {
  // create a local variable to hold the input on pin A0
  int keyVal = analogRead(A0);
  // send the value from A0 to the Serial Monitor
  Serial.println(keyVal);

  // play the note corresponding to each value on A0
  if (keyVal >= 630) {
    // play the first frequency in the array on pin 8
    noteOn(0x90  ,note[0] , 0x7f);
    delay(100);
    for(int i=255;i>=1;i--)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
  }
  for(int i= 1;i<=255;i++)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
  }
  } else if (keyVal >= 610 && keyVal <= 630) {
    // play the second frequency in the array on pin 8
    noteOn(0x90  ,note[1] , 0x7f);
    delay(100);
    for(int i=255;i>=1;i--)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
  }
  for(int i= 1;i<=255;i++)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
  }
  } else if (keyVal >= 590 && keyVal <= 610) {
    // play the second frequency in the array on pin 8
    noteOn(0x90  ,note[2] , 0x7f);
    delay(100);
    for(int i=255;i>=1;i--)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
       //delay(1);
  }
  for(int i= 1;i<=255;i++)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
       //delay(1);
  }
  } else if (keyVal >= 570 && keyVal <= 590) {
    // play the third frequency in the array on pin 8
    noteOn(0x90  ,note[3] , 0x7f);
    delay(100);
    for(int i=255;i>=1;i--)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
       delay(1);
  }
  for(int i= 1;i<=255;i++)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
       delay(1);
  }
  } else if (keyVal >= 550 && keyVal <= 570) {
    // play the second frequency in the array on pin 8
    noteOn(0x90  ,note[4] , 0x7f);
    delay(100);
    for(int i=255;i>=1;i--)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
       delay(2);
  }
  for(int i= 1;i<=255;i++)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
       delay(2);
  }
  } else if (keyVal >= 490 && keyVal <= 550) {
    // play the fourth frequency in the array on pin 8
    noteOn(0x90  ,note[5] , 0x7f);
    delay(100);
    for(int i=255;i>=1;i--)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
       delay(4);
       
  }
  for(int i= 1;i<=255;i++)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
       delay(4);
      
  }
  } else {
    // if the value is out of range, play no tone
    noteOn(0x80  ,note[1] , 0x7f);
  }
}


void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}
