#include <Stepper.h>

#define steps 100
#define echo 7
#define trig 6
long time_sensor;
int dis,ans;
Stepper Stepp(steps,8,11,9,10);

void setup()
{
  Stepp.setSpeed(70);
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT); 

}

void loop()
{
    digitalWrite(trig,LOW);
    delayMicroseconds(5);
    digitalWrite(trig,HIGH);
    delayMicroseconds(13);
    digitalWrite(trig,LOW);
    time_sensor=pulseIn(echo,HIGH);
    dis=(time_sensor/29)/2;
    Serial.println(dis);
    delay(5000);
    if(dis>=7)
    {
      Motor_clockwise();
    }
  
}

void Motor_clockwise()
{
   Stepp.step(steps);
   delay(10000);
   Ultra();
}

void Motor_anticlockwise()
{
   Stepp.step(-steps);
}

void Ultra()
{
   digitalWrite(trig,LOW);
   delayMicroseconds(5);
   digitalWrite(trig,HIGH);
   delayMicroseconds(13);
   digitalWrite(trig,LOW);
   time_sensor=pulseIn(echo,HIGH);
   dis=(time_sensor/29)/2;
   Serial.println(dis);
   if(dis<=3)
   {
      Motor_anticlockwise();
      loop();
   }
   else
   {
      delay(10000);
      Serial.println("here");
      Ultra();
   }
}
