
#include <Servo.h>

int servoPin1 = 2;           //Pin that the servo is attached to.
int moveRate = 1;        //the time between updates in milliseconds
int minAngle = 90;     //sets the low point of the movement range
int maxAngle = 135;   //sets the high point of the movement range
int moveIncrement = 1;    // how much to move the motor each cycle 
int servoAngle1;

long lastTimeYouMoved1;

Servo servo1;  // create the Servo object

int ldr1Pin = A0;
int ldr1Val;

int ldr2Pin = 3;
int ldr2Val;

int pot1Pin = A1;
int pot1Val;

int minLightLevel = 700;
int maxLightLevel = 900;

int ldrMin = 550;
int ldrMax = 950;

int moveMin = 50;
int moveMax = 5;


// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        5 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 8 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 0 // Time (in milliseconds) to pause between pixels



void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  // put your setup code here, to run once:

  servo1.attach(servoPin1);  //attach the servo to the corresponding control pin
  servoAngle1=minAngle;

Serial.begin(9600);
}

void loop() {
ldr1Val = analogRead(ldr1Pin);
ldr2Val = analogRead(ldr1Pin);
pot1Val = analogRead(pot1Pin);

 ldr1Val = constrain(ldr1Val,minLightLevel,maxLightLevel);
  #define pixel  = map(ldr1Val,minLightLevel,maxLightLevel,0,255);

  moveRate = map(ldr2Val,ldrMin,ldrMax,moveMin,moveMax);

// The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop

 

  
  Serial.print("light1:********* ");
  Serial.println (ldr1Val);
  Serial.print("light2: ");
  Serial.println (ldr2Val);

Serial.print("pot: ");
Serial.println(pot1Val); 

if (ldr1Val <= 750)
{
   pixels.setPixelColor(i, pixels.Color(120,180,255));
 //Serial.println("YESSSS!!");
}
else
{
  pixels.setPixelColor(i, pixels.Color(150,0,0));
 // Serial.println("NOOOO!!");
}

}

if (ldr2Val <= 750)
{
 servoAngle1 = minAngle;
   //pixels.setPixelColor(i, pixels.Color(255,255, 51));
 //Serial.println("YESSSS!!");
}
else
{
 servoAngle1 = maxAngle;
 // pixels.setPixelColor(i, pixels.Color(150,0,0));
 // Serial.println("NOOOO!!");
}





 //if(millis()-lastTimeYouMoved1>=moveRate) //this very simple statement is the timer,
//{                                          //it subtracts the value of the moment in time the last blink happened, and sees if that number is larger than your set blinking value


//servoAngle1 += moveIncrement;

 // if (servoAngle1 <= minAngle || servoAngle1 >= maxAngle) 
 // {
 //   moveIncrement = -moveIncrement;
 // }

servo1.write(servoAngle1); //write the value to the servo

//lastTimeYouMoved1 = millis();            //save the value in time that this switch occured, so we can use it again.
   
//}
}

