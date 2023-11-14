const int redPin =11;		// sensor to control red color
const int greenPin = 12;	// sensor to control green color
const int bluePin = 13; 	// sensor to control blue color
const int motionSensorPin = 2; // pin to read fron the motion sensor
const int redButtonPin = 3; // red button
const int greenButtonPin = 4; // blue button
const int blueButtonPin = 5; // green button
const int whiteButtonPin = 6; // white button
const int blackButtonPin = 7; // black button

enum ColourOption{ BLACK, RED, GREEN, BLUE, WHITE };

ColourOption selectedColourOption;

int redButtonValue;
int greenButtonValue;
int blueButtonValue;
int whiteButtonValue;
int blackButtonValue;

int greenLightLevel = 0;
int redLightLevel = 0;
int blueLightLevel = 0;

int motionDetectorValuePrevious;
int motionDetectorValueCurrent;



void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  pinMode(motionSensorPin, INPUT);

  pinMode(redButtonPin, INPUT);
  pinMode(greenButtonPin, INPUT);
  pinMode(blueButtonPin, INPUT);
  pinMode(whiteButtonPin, INPUT);
  pinMode(blackButtonPin, INPUT);
}

void loop() {

  redButtonValue = digitalRead(redButtonPin);
  greenButtonValue = digitalRead(greenButtonPin);
  blueButtonValue = digitalRead(blueButtonPin);
  whiteButtonValue = digitalRead(whiteButtonPin);
  blackButtonValue = digitalRead(blackButtonPin);

  if(redButtonValue == HIGH){
    selectedColourOption = RED;
  }

  if(greenButtonValue == HIGH){
    selectedColourOption = GREEN;
  }

  if(blueButtonValue == HIGH){
    selectedColourOption = BLUE;
  }

  if(whiteButtonValue == HIGH){
    selectedColourOption = WHITE;
  }

  if(blackButtonValue == HIGH){
    selectedColourOption = BLACK;
  }
  
  motionDetectorValuePrevious = motionDetectorValueCurrent;
  motionDetectorValueCurrent = digitalRead(motionSensorPin);

  if (motionDetectorValuePrevious == LOW && motionDetectorValueCurrent == HIGH) {   // pin state change: LOW -> HIGH
    switch(selectedColourOption) {
      case RED:
        if (redLightLevel >= 220) { break; }

        redLightLevel += 10;
        break;
      case GREEN:
        if (greenLightLevel >= 220) { break; }

        greenLightLevel += 10;
        break;
      case BLUE:
        if (blueLightLevel >= 220) { break; }
 
        blueLightLevel += 10;
        break;
      case WHITE:
        if (!(redLightLevel >= 220)) {
          redLightLevel += 10;
        }
        if (!(greenLightLevel >= 220)) {
          greenLightLevel += 10;
        }
        if (!(blueLightLevel >= 220)) {
          blueLightLevel += 10;
        }
        break;
      case BLACK:
        if (!(redLightLevel <= 0)) {
          redLightLevel -= 10;
        }
        if (!(greenLightLevel <= 0)) {
          greenLightLevel -= 10;
        }
        if (!(blueLightLevel <= 0)) {
          blueLightLevel -= 10;
        }
        break;
    }
  }

  analogWrite(redPin, redLightLevel);
  analogWrite(bluePin, blueLightLevel);
  analogWrite(greenPin, greenLightLevel);
}
