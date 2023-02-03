#define waterSensor A0    // Get the data from  AO pin of Ardunio UNO
#define buzzer 9          // Give the output from pin 9 to buzzer to get a warning signal
#define led 8             // Give the output from pin 8 to led to get a warning signal
const int boundary = 200;   // Detect a limit for warning.

void setup() {
  Serial.begin(9600);     //  Start a communication with Ardunio and your PC
  pinMode(buzzer,OUTPUT);    // Say that it is a  digital output.
  pinMode(led,OUTPUT);      // Say that is a  digital output.
}

void loop() {
  int sensorValue = analogRead(waterSensor);   // Read the datas from water sensor.
  Serial.println(sensorValue);                 // write the datas to Serial Monitor
  
  if(sensorValue >= boundary )                 // If the  readen values from sensor are higher than our limit value.
  {
    Serial.println("it is raining now.Take your umbrella! :");    //  Write to the serial monitor that it is working.
    digitalWrite(buzzer,HIGH);                          // Buzzer is working.
    digitalWrite(led,HIGH);                             // Led flashes.
    delay(100);
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
    delay(100);
  }
  else                                      // if not , buzzer and led is not working.
  {
    digitalWrite(buzzer,LOW);
    digitalWrite(led,LOW);
    Serial.println("it is not raining now. ");
  }
}
