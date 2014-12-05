int mq3_analogPin = A0; // connected to the output pin of MQ3 
int red = 6;
const int pingPin = 11;
unsigned int duration, inches;

void setup(){
  Serial.begin(9600); // open serial at 9600 bps
}

void loop()
{
  // give ample warmup time for readings to stabilize
  pinMode(red,OUTPUT);

  int mq3_value = analogRead(mq3_analogPin);
  
  if (mq3_value > 80) {
    digitalWrite (red, HIGH);
  }
  
    else 
    {
      digitalWrite (red, LOW);
      
  }
  if (red == HIGH) {
    pinMode(pingPin, OUTPUT);          // Set pin to OUTPUT
  digitalWrite(pingPin, LOW);        // Ensure pin is low
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);       // Start ranging
  delayMicroseconds(5);              //   with 5 microsecond burst
  digitalWrite(pingPin, LOW);        // End ranging
  pinMode(pingPin, INPUT);           // Set pin to INPUT
  duration = pulseIn(pingPin, HIGH); // Read echo pulse
  inches = duration / 74 / 2;        // Convert to inches
  Serial.println(inches);            // Display result

//else 
	

  }

  delay(100); //Just here to slow down the output.
  
  
  
}
