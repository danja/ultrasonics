# Experiments in Ultrasonics

*A Few Days Later*

Done a bit more experimentation, see [DevLog](https://github.com/danja/ultrasonics/blob/master/devlog.md)

*Day One*

A medic friend has been talking about ultrasonics, got me interested, I want to play.

But medical probes are expensive and as they tend to use frequencies into the MHz, the electronics will be too. But you can now get little modules, designed for use with Arduinos, with 2x 40kHz transducers complete with onboard digital interfaces. Outrageously cheap (I got 5 modules for about $15 from Amazon, including little mounting brackets).

They arrived this afternoon.

I have some ideas for more interesting projects, but out of the box it seemed reasonable to try them for the purpose intended. I had an usused Arduino Nano, breadboard etc, whicch for convenience I've attached to a scrap of wood. I set up a new project in PlatformIO (I prefer it to the Arduino IDE, easier to maintain larger projects). Found example distance-measuring code online, it worked first time, wow!

But I got bored quickly.

Added a minimal one-transistor driver and speaker to another output port, stuck in a `tone(port, freq)` (and a `noTone(port)` if the distance > 1m).

Within about an hour, from scratch, I had the world's worst theremin.

![minimal theremin](https://github.com/danja/ultrasonics/blob/main/docs/images/theremin-0.jpeg?raw=true)

Little video here : https://youtu.be/0a9vGNTQi6s (also at https://github.com/danja/ultrasonics/blob/main/docs/thereminimal.mp4)

Circuit is trivial :

![minimal theremincircuit](https://github.com/danja/ultrasonics/blob/main/docs/images/theremin-0-circuit.jpeg?raw=true)

**no capacitor!** - just noticed, it was actually bypassed, clumsy me. But shouldn't make a difference as long as the Arduino pin is normally low.

`tone(port, freq)` sends a square wave out to the numbered digital pin. The capacitor will block DC, the resistor limit the current (both values just what seemed reasonable guesses). Transistor I had nearest was a BC109, but practically any transistor would do.  

I suppose I should have a go at making a more usable theremin. One transducer pair for frequency, another for amplitude (will they interact? - *hope so!*). Given the available libraries, MIDI out from an Arduino is pretty trivial.

But what I really want to play with is around spacial scanning, around the phased-array thing, but more minimal.
