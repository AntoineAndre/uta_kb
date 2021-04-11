/* This file is part of the Uta keyboard controler
* 
* Short Arduino script to use the rotary encoder as a volume controler
* and 3 keys in pullup mode to control the previous/next songs along 
* with a play/pause button.
*
*/

#include <ClickEncoder.h>
#include <TimerOne.h>
#include <HID-Project.h>

template<typename T>
struct TimeStampedValue {
  explicit TimeStampedValue(T value) : _value(value), _timeStamp(0) {}
  void set(const T& value) { _value = value; touch(); }
  operator const T&() const { return _value; }
  void touch() { _timeStamp = millis(); }
  unsigned long getTimeStamp() const { return _timeStamp; }
  
private:
  T _value;
  unsigned long _timeStamp;
};

ClickEncoder encoder(A1, A0, A2);
TimeStampedValue<int16_t> value(0);
int16_t current = 0;

int playButton = 5;
int fwdButton = 4;
int bckButton = 6;

void timerIsr() {
  encoder.service();
}

void setup() {
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);

  Consumer.begin(); // Allows to tranform keystrokes in keyboard commands

  // The three switches are in input pullup mode. No additional resistor is needed therefore
  pinMode(playButton, INPUT_PULLUP);
  pinMode(fwdButton, INPUT_PULLUP);
  pinMode(bckButton, INPUT_PULLUP);
}

void loop() {
  current += encoder.getValue();
  auto diff = current - value;

  // Check the direction change of the encoder
  if (diff != 0) {
    if (diff < 0) {
      volumeChange(MEDIA_VOLUME_DOWN);
    } 
    else {
      volumeChange(MEDIA_VOLUME_UP);
    }
    value.set(current);
  }

  if (!digitalRead(playButton)){
    keyChange(MEDIA_PLAY_PAUSE);
  }
  if (!digitalRead(fwdButton)){
    keyChange(MEDIA_NEXT);
  }
  if (!digitalRead(bckButton)){
    keyChange(MEDIA_PREVIOUS);
  }
}

void keyChange(uint16_t key) {
  Consumer.write(key);
  delay(300); // A delay of 300 ms minimum is required for a key stroke
}

void volumeChange(uint16_t key){
  Consumer.write(key);
}
