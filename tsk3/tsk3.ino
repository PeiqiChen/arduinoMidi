
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);     // 设置波特率用于串口通信
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=255;i>=1;i--)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
       delay(5);
       Serial.println(i);
       Serial.println('\n');
  }
  for(int i= 1;i<=255;i++)
  {
       analogWrite(10,i); //pin10 白灯
       analogWrite(9,i); //pin9 红灯
       analogWrite(6,i); //pin6 蓝灯
       analogWrite(5,i); //pin5 绿灯
       analogWrite(3,i); //pin3 黄灯
       delay(5);
  }
}
