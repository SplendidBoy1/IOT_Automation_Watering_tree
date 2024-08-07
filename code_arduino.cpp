const int button = 7;  
int currentled = 13;

int buttonState = 0;     
int lastButtonState = 0; 
int startPressed = 0;    
int endPressed = 0;      
int holdTime = 0;        

void setup() {
  pinMode(13, OUTPUT); //Led 1
  pinMode(12, OUTPUT); //Led 2
  pinMode(11, OUTPUT); //Led 3
  pinMode(10, OUTPUT); //Led 4
  pinMode(9, OUTPUT); // Led 5
  pinMode(8, OUTPUT); // Led 6
  pinMode(button, INPUT); // Button
  
  digitalWrite(13, HIGH);
  Serial.begin(9600);        // initialize serial communication
}

void loop() {
  buttonState = digitalRead(button); // read the button input
  if (buttonState != lastButtonState) { // button state changed
     updateState();
  }
  lastButtonState = buttonState;        // save state for next loop
}

void shortButtonPressed() {
  for(int i = 13; i >= 8; i--){
    if(currentled == i){
    	digitalWrite(i, LOW);
      	digitalWrite(i - 1, HIGH);
      	currentled = i - 1;
      	break;
    }
    
    if(currentled == 😎 {
      	digitalWrite(currentled, LOW);
      	digitalWrite(13, HIGH);
      	currentled = 13;
      	break;
    }
  }
}

void longButtonPressed() {
  for(int i = 13; i >= 8; i--){
  	digitalWrite(i, HIGH);
  }
  delay(5000);
  for(int i = 12; i >= 8; i--){
  	digitalWrite(i, LOW);
  }
  currentled = 13;
}

void updateState() {
  // the button has been just pressed
  if (buttonState == HIGH) {
      startPressed = millis();
	  endPressed = 0;
  // the button has been just released
  } else {
      endPressed = millis();
  }
  
  if(endPressed != 0) {
  	int holdTime = endPressed - startPressed;
    if(holdTime <= 5000) {
      	Serial.println("Short button pressed!");
    	shortButtonPressed();
    }
    else {
      	Serial.println("Long button pressed!");
    	longButtonPressed();
    }
  }
}