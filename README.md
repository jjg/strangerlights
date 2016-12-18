# STRANGERLIGHTS
A holiday (or really, anyday) display based on the communication system used by Will to talk to his mother in the show [Stranger Things](https://en.wikipedia.org/wiki/Stranger_Things_%28TV_series%29).  

[![Strangerlights Demo Video](http://img.youtube.com/vi/_ogfhmmpy8w/0.jpg)](https://youtu.be/_ogfhmmpy8w)

Electronics inspired by this [Arduino Based Stranger Things Lights](http://www.instructables.com/id/Arduino-Based-Stranger-Things-Lights/) Instructable.

## Requirements
*  A string of WS2811 holiday lights (we used these: [http://amzn.to/2hJojRe](http://amzn.to/2hJojRe))
*  An Arduino Uno or compatible ([http://amzn.to/2hJtwZo](http://amzn.to/2hJtwZo))
*  A power supply (most Arduinos are happy with 5-12VDC)
*  A board to mount the lights (we used styrofoam, but anything big enough should work)
*  A few feet of wire
*  The `strangerlights.ino` firmware included in this repository

The firmware depends on the [FastLED library](https://github.com/FastLED/FastLED) as well, so you'll need to install that into your Arduino IDE before the firmware will compile.

## Test the electronics
Connect the lights to the Arduino as follows:

```
DATA    -> PIN 6
POWER   -> 5V
GROUND  -> GND
```

Load the sketch `strangerlights.ino` on to the Arduino.  If one light turns on every few seconds, you're ready to configure the firmware and customize the message.  If not, check your connections.  It's easy to get them wrong since most strings of these lights don't include documentation.

## Assemble the sign
This amounts to painting the background and either painting or applying the lettering on the sign itself.

It's helpful do this first in order to know where the lights are going to fall over the letters.  We hand-painted the lettering, but you could also print out the letters in a suitable font, just consider the environment you'll be using the sign in and choose a method that can withstand the conditions.

If you're going to use the sign indoors you can simply screw the Arduino board to the back of the sign.  Ours was going outside in the Wisconsin winter so we used a freezer-safe Rubbermaid container to enclose the electronics.

##Configure the firmware
The "firmware" is the Arduino sketch included in this repository.  You'll need to edit this to match your specific sign layout and the message you want to display.

### Light-to-letter mapping
The first step is to configure which light is assigned to what letter.  This is done by modifying the `#define` statements under `// light-to-letter mappings` in the `strangerlights.ino` file.  If you left your light string intact, you can determine the number for a given light by counting them from the end connected to the Arduino, starting with the number `0`.  

On our sign most of the letters fall under every-other light, but we ended up modifying the light string a bit to make it look better.  This meant the mapping is a little bit different than if we had left the string intact.

### Set the message
Setting the message is a bit easier than mapping the lights to letters.  The message is stored in an array defined under `// message array` in the `strangerthings.ino` file.  Each letter of the message is written in caps and must include a trailing underscore (`_`).  The word `SPACE_` is used to add spaces to the message (this turns all lights off and pauses for a fixed amount of time).

### Additional customization
As-is, the firmware will select a random non-black color for each light as it is lit.  If you want to change this behavior, you can modify the line below `// set the selected light to the randomly-selected color` and specify a static RGB value in place of the variables `r`, `g` and `b` in the `CRGB()` function call.
