#define Pot A0
double ADCx;
double T;
double B;
double T0;
double R0;
double R5;
void setup() {
  Serial.begin(9600);
  B = 3435;
  T0 = 298.15;
  R0 = 10000;
  R5 = 10000; 
}
void loop() {
  ADCx = analogRead(A0);
  int sensorValue1 = analogRead(A1);
  T = ( B * T0 )/ ( B + T0*( log( (1024/ADCx - 1)*R5 ) - log(R0) ) ) - 273.15;
  Serial.print("温度：");
  Serial.println(T);
  Serial.print("光强：");
  Serial.println(sensorValue1);
  Serial.println('\n');
  delay(1000);
}
