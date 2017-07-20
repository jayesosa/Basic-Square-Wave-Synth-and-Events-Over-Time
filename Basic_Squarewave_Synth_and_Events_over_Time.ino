int oscillatorPin = 14;
int ledPin = 13;
int buttonPin = 12;
int buttonPin2 = 11;

unsigned long triggerTime = 0;

// assigning the frequencies of the notes wanted to variables
int middleAFrequency = 220;
int middleCFrequency = 261;
int middleDFrequency = 293;
int highAFrequency = 440;
int middleFFrequency = 349;
int middleGFrequency = 392;
int highCFrequency = 523;

void setup() {
pinMode(oscillatorPin, OUTPUT);
pinMode(ledPin, OUTPUT);
pinMode(buttonPin, INPUT);
pinMode(buttonPin2, INPUT);
}
 
void loop() {

  // if the first button is pressed, the following code will execute
  if(digitalRead(buttonPin) == HIGH) {

    // the LED light will flash on
    digitalWrite(ledPin, HIGH);

    // set the trigger time equal to millis that will track how many milliseconds its been since the user started the program
    triggerTime = millis();
    // a while loop for when millis is less than the amount of time since the program has opened plus 300, the middle A frequency value
    // will be sent to the playFrequency function at the bottom to play a square wave of the note
    while(millis() < triggerTime + 300) {
      playFrequency(middleAFrequency);
    }
 
    triggerTime = millis();
    while(millis() < triggerTime + 300) {
      playFrequency(middleCFrequency);
    }

    triggerTime = millis();
    while(millis() < triggerTime + 300) {
      playFrequency(middleDFrequency);
    }

    triggerTime = millis();
    while(millis() < triggerTime + 300) {
      playFrequency(highAFrequency);
    }

    // a for loop that increments i by 1 everytime up until 8
    // each time will send the middle C frequency value to the play lazer fucntion at the bottom
    for (int i = 0; i < 8; i ++) {

      playLazer(middleCFrequency);
    }

    // the amount of time being delayed for before the program will run again when the user presses the button
    delay(20);

 // if the button is not pressed, the LED will remain off
  } else {
    digitalWrite(ledPin, LOW);
  }

  // repeat the same for button 2 except the frequency notes being played are going to be different 
  if(digitalRead(buttonPin2) == HIGH) {
 
    digitalWrite(ledPin, HIGH);
 
    triggerTime = millis();
    while(millis() < triggerTime + 300) {
      playFrequency(middleCFrequency);
    }
 
    triggerTime = millis();
    while(millis() < triggerTime + 300) {
      playFrequency(middleFFrequency);
    }

    triggerTime = millis();
    while(millis() < triggerTime + 300) {
      playFrequency(middleGFrequency);
    }

    triggerTime = millis();
    while(millis() < triggerTime + 300) {
      playFrequency(highCFrequency);
    }

    for (int i = 0; i < 8; i ++) {

      playLazer(middleCFrequency);
    }

    delay(20);
 
  } else {
    digitalWrite(ledPin, LOW);
  }
}

// the function that gets called within the while loops that gets sent the frequency of the given note and divides it by 1000000 along with 2 to get an on and off square waveform
void playFrequency(int freq) {
  digitalWrite(oscillatorPin, HIGH);
  delayMicroseconds(1000000 / freq / 2);
  digitalWrite(oscillatorPin, LOW);
  delayMicroseconds(1000000 / freq / 2);
}

// the function that gets called within the for loop
// accepts the frequency of the given note
void playLazer(int freq) {
 int freqToReach = freq / 4; // dividing the note frequency by 4
 double currentFreq = freq; // assigning the current note frequency as a double float number
 while(currentFreq > freqToReach) { // stay within the while loop if the current frequency is larger than the divided frequency
 for(byte i=0; i<5; i++) { // use a for loop to interate through 5 cycles where the square wave is formed like the playFrequency fucntion
 digitalWrite(oscillatorPin, HIGH);
 delayMicroseconds(1000000 / currentFreq / 2);
 digitalWrite(oscillatorPin, LOW);
 delayMicroseconds(1000000 / currentFreq / 2);
 }
 currentFreq *= 0.5; // after we have broken out of the for loop, the current frequency is add multiplied by 0.5  
 }
}

