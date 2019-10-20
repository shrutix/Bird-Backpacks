String inputString = "";
boolean stringComplete = false;
const int photoResistor = A0;
const int led = 13;
int value;
char sendBuffer[32];
char ch = 0;
//long startTime;

void setup() {
  Serial.begin(9600);
  pinMode(photoResistor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  //long currentTime = millis();
  //long diffTime = currentTime - startTime;
    value = analogRead(photoResistor);
    Serial.println(value);
    delay(200);
  
    if (value < 800) {
      digitalWrite(led, LOW);
    } else {
      digitalWrite(led, HIGH);
    }
  

} 
