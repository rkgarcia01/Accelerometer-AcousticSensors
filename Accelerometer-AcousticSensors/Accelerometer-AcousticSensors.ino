const int xInput = A0;
const int yInput = A1;
const int zInput = A2;
int xRaw = 0; 
int yRaw = 0;
int zRaw = 0;

int xMic = A3;
int yMic = A4;
int zMic = A5;
int sensorValue = 0;

float ScalingPercentage = 20.0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL, Time, Millis, Date, XG, YG, ZG, XMICSCALED, XMICACTUAL, YMICSCALED, YMICACTUAL, ZMICSCALED, ZMICACTUAL");
  Serial.println("RESETTIMER");
}

void loop() {
  // put your main code here, to run repeatedly:
  float xMicScaled = ScaledV(xMic);
  float yMicScaled = ScaledV(yMic);
  float zMicScaled = ScaledV(zMic);
  float xMicActual = ActualV(xMicScaled);
  float yMicActual = ActualV(yMicScaled);
  float zMicActual = ActualV(zMicScaled);
  
  

  xRaw = analogRead(xInput);
  int x = map(xRaw, 262, 413, 100, -100);
  float xg = (float)x/(-100.00);
  yRaw = analogRead(yInput);
  int y = map(yRaw, 271, 415, 100, -100);
  float yg = (float)y/(-100.00);
  zRaw = analogRead(zInput);
  int z = map(zRaw, 282, 416, 100, -100);
  float zg = (float)z / (-100.00);

  Serial.print( (String)"DATA, TIME, "+millis()+", DATE, ");
  Serial.print(xg);
  Serial.print(" ,");
  Serial.print(yg);
  Serial.print(" ,");
  Serial.print(zg);
  Serial.print(" ,");
  Serial.print(xMicScaled);
  Serial.print(" ,");
  Serial.print(xMicActual);
  Serial.print(" ,");
  Serial.print(yMicScaled);
  Serial.print(" ,");
  Serial.print(yMicActual);
  Serial.print(" ,");
  Serial.print(zMicScaled);
  Serial.print(" ,");
  Serial.println(zMicActual);

}
float ScaledV(int analogPin){
    sensorValue = analogRead(analogPin);
    float MaxScaledVoltage = 5.00 * ScalingPercentage;
    float ScaledVoltage = sensorValue * (MaxScaledVoltage /1023);
    return ScaledVoltage;
}
float ActualV(int ScaledV){
  return ScaledV / ScalingPercentage;
}
