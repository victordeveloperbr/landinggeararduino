// by victor
//variable to use

const int P_RED = 9;
const int P_GREEN = 10;
const int P_BLUE = 12;
void setup() {
  // initialize pin variable and initialize serial com.

  //serial com
  Serial.begin(9600);

  //defining leds output
  pinMode(P_RED, OUTPUT);
  pinMode(P_GREEN, OUTPUT);
  pinMode(P_BLUE, OUTPUT);
  
  //initialize without color; 
  defineColor(0,0,0);
}

void loop() {
  if(Serial.available()) {
    String gearStatus = Serial.readStringUntil('\n');
// checking landing gear status;
  if(gearStatus == "GEAR_DOWN") {
      defineColor(255, 0, 0);
      delay(3000);
      defineColor(0,255,0);
  } else if (gearStatus == "GEAR_UP") {
      defineColor(255, 0, 0);
      delay(3000);
      defineColor(0,0,0);
  } else {
    defineColor(255, 0, 0);
    Serial.println("Landing Gear Error");
    gearStatus == "GEAR_ERROR\n";
  }
  }


  

}

void defineColor(int red, int green, int blue) {
  analogWrite(P_RED, red);
  analogWrite(P_GREEN, green);
  analogWrite(P_BLUE, blue);
}