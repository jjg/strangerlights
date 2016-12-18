#include <FastLED.h>
#define DATA_PIN 6
#define NUM_LEDS 50 //change this to the number of LEDs in the strip
#define COLOR_ORDER RGB

// light-to-letter mappings
#define A_ 15
#define B_ 13
#define C_ 11
#define D_ 9
#define E_ 7
#define F_ 5
#define G_ 3
#define H_ 0
#define I_ 33
#define J_ 31
#define K_ 29
#define L_ 27
#define M_ 25
#define N_ 23
#define O_ 21
#define P_ 19
#define Q_ 16
#define R_ 34
#define S_ 36
#define T_ 38
#define U_ 40
#define V_ 42
#define W_ 44
#define X_ 46
#define Y_ 49
#define SPACE_ 99

// message array
int word_letters[] = {M_,E_,R_,R_,Y_,SPACE_,C_,H_,R_,I_,S_,T_,M_,A_,S_};

CRGB leds[NUM_LEDS]; 

void setup(){

    // initialize the FastLED library
    FastLED.addLeds<WS2811, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);

    // initialize the random number generator by getting some
    // noise from one of the Arduinoanalog pins
    randomSeed(analogRead(0));

}

void loop(){

    FastLED.clear();

    for(int i = 0; i < (sizeof(word_letters)/sizeof(int)); i++){

        int r = random(0, 2) * 255;
        int g = random(0, 2) * 255;
        int b = random(0, 2) * 255;

        // if the randomly-selected color is black, make it red
        if(r == 0 && g == 0 && b == 0){
            r = 255;
        }

        // if the "letter" is a space, turn off all lights and pause briefly
        if(word_letters[i] == SPACE_){

          leds[word_letters[i]] = CRGB(0,0,0);
          FastLED.show();
          delay(500);

        } else {

          // set the selected light to the randomly-selected color
          leds[word_letters[i]] = CRGB(r,g,b);
          FastLED.show();
          delay(1000);

          // turn the light back off and pause briefly before 
          // illuminating the next letter
          leds[word_letters[i]] = CRGB(0,0,0);
          FastLED.show();
          delay(500);
          
        }
    }

    // turn all lights off and wait 5 seconds before showing the message again
    FastLED.clear();
    delay(5000);

}
