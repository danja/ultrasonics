# Experiments in Ultrasonics

*Day One*

A medic friend has been talking about ultrasonics, got me interested, I want to play.

But medical probes are expensive and as they tend to use frequencies into the MHz, the electronics will be too. But you can now get little modules, designed for use with Arduinos, with 2x 40kHz transducers complete with onboard digital interfaces. Outrageously cheap (I got 5 modules for about $15 from Amazon, including little mounting brackets).

They arrived this afternoon.

I have some ideas for more interesting projects, but out of the box it seemed reasonable to try them for the purpose intended. I had an usused Arduino Nano, breadboard etc, whicch for convenience I've attached to a scrap of wood. I set up a new project in PlatformIO (I prefer it to the Arduino IDE, easier to maintain larger projects). Found example distance-measuring code online, it worked first time, wow!

But I got bored quickly. 

Added a minimal one-transistor driver and speaker to another output port, stuck in a `tone(port, freq)` (and a `noTone(port)` if the distance > 1m).

Within about an hour, from scratch, I had the world's worst theremin.



