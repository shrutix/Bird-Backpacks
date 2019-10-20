#define photosensor A0

String inputString = "";
boolean stringComplete = false;

int sensor_val = 0;
char sendBuffer[32];
char ch = 0;

void setup() {
  Serial.begin(115200);
//  inputString.reserve(200);
//  pinMode(LED_BUILTIN, OUTPUT);
//  digitalWrite(LED_BUILTIN, LOW);
}

void loop(){
  if (Serial.available()) {
     ch = Serial.read();
     if ( ch == '0' ) {
       sendTelemetry();
     }
  }
}

void sendTelemetry() {
//  digitalWrite(LED_BUILTIN, HIGH);
  memset(sendBuffer, 0, sizeof(sendBuffer));
  int sensor_val = analogRead(photosensor);
  sprintf(sendBuffer, "S s:%d", sensor_val);
  Serial.println(sendBuffer);
//  digitalWrite(LED_BUILTIN, LOW);
}
