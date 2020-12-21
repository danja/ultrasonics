## Ultrasonics Devlog

**2020-12-21**

After seeing this delightfully over-engineered [ultrasound levitation project](https://makezine.com/projects/micro-ultrasonic-levitator/), I decided to try to recreate it in a simpler form.
My first attempt used a 2-transistor astable multivibrator to drive the transducers. I found it difficult to get a good lock on 40kHz and physically lining them up in helping hands was really tricky. Plan B used a 555 timer and support knocked together from what I had around.  



I didn't spend much time trying to get the levitation working, was very distracted by the response of the transducers. When driven with a square wave, there are really significant higher harmonics getting across, they only really start dropping after the 10th harmonic, ie. 400kHz!

I have started preparing hardware for trying out some spatial-scanning ideas, but before going there I want to do a load of measuring/analysis of the response of these things. Coincidentally I have some ESP32 audio projects on the go, so I think I'll move over to there for a little while, put together a sweep generator alongside the existing projects.


**2020-12-16** Initial experiments with HC-SR04 module

Had a fiddle making the output behave more like a scale, along the lines of -

float f = pow(2, (float)distance / 5.0f);

Gave up.
