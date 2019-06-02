long x[3];
long y[3];

void judgeTF(){
  if(x[1]==0x7f&&x[2]==0x7f){
    Serial.println("invalid");
    }
  if(x[1]==0x55&&x[2]==0x55){
    Serial.println("valid");
    }  
  }

int judge1(){
//  Serial.println(x[0]/16);
  if((x[0]/16)==13){
    return 1;//0xD
  }else if((x[0]/16)==12){
    return 2;//0xC
    }else if((x[0]/16)==14){
      return 3;//0xE
      }else if((x[0]/16)==15){
      return 4;//0xF
      }else if((x[0]/16)==9){
      return 5;//0x9
      }
    
  return 0;
  }

void getmillis(){
  unsigned long times = millis();
  y[0]=0xff;
  y[1] = times&0x7f+0x80;
  y[2] = (times>>7)&0x7f+0x80;
  for(int i = 0;i < 3; i++){
    Serial.write(y[i]);
  }
}

void getSID(){
  y[0]=0xF9;
  y[1]=0x50;
  y[2]=0x4b;
  
  Serial.write(y[0]);
  Serial.write(y[1]);
  Serial.write(y[2]);
  
}

void getAD(){
  int p = x[0]%16+13;
  long y1 = digitalRead(p);
  y[0] = x[0];
  y[1] = y1&0x7F+0x80;
  y[2] = (y1>>7)&7 + (p<<3)&0x78 + 0x80;
    for(int i = 0;i < 3; i++){
    Serial.write(y[i]);
  }
  }
void control(){
   int p = x[0]%16;
   if(x[2]%2==1){
    
    }else{
   long num = (x[1]/2)+(x[2]/128);
   analogWrite(p,num);
      }
    y[0]=x[0];
    y[1]=x[1];
    y[2]=x[2];
    for(int i = 0;i < 3; i++){
    Serial.write(y[i]);
  }
  }
void inverse(){
  int p = x[0]%16;
  Serial.write(x[0]);
  long judge = x[1];
  Serial.write(judge);
  if(judge!=0){
    digitalWrite(p,1);
    long y = digitalRead(p);
    Serial.write(y);
  }else{
    digitalWrite(p,0);
    long y = digitalRead(p);
    Serial.write(y);
    }
  }

void inverseR(){
  int p = x[0]%16;
  Serial.write(x[0]);
  int judge = x[1];
  long y = digitalRead(p);
  Serial.write(y);
  }

  
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(15,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0 ;
  while(Serial.available()){
    x[i] = Serial.read();
//    Serial.print(x[i]);
    i++;
    }
    if(i==3){
      if(judge1()==1){
        control();
        }
      if(judge1()==3){
        getAD();
        }
      if(judge1()==4){
        if((x[0]%16)==0xf){
            getmillis();
          }
        if((x[0]%16)==0x9){
            getSID();
          }
        if((x[0]%16)==0xA){
            judgeTF();
          }
        }
      }

    if(i==2){
    if(judge1()==5){
        inverse();
      }
    if(judge1()==2){
        inverseR();
      }
      }

    delay(1000);
}
