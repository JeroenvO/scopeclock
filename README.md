# scopeclock

C port of https://github.com/kosma/bakingbread because the python was too heavy to run on my Raspberry Pi 1.
Compiled version runs on Raspberry Debian minimal.

![Screenshot](https://raw.githubusercontent.com/JeroenvO/scopeclock/master/screenshot.jpg)

Compile:
-----
``gcc scopeclock.c -o scopeclock -lm ``

Usage
-----

Connect your stereo sound card output to your oscilloscope in XY mode.

Use any player capable of reading raw audio in unsigned, 8-bit, stereo, 44100Hz sample rate mode. Linux example:

``./scopeclock | aplay -f U8 -c 2 -r 44100``

Any other sample rate can work as well, 48000 is sometimes better.

If the clock appears square, the soundcard is clipping. Reduce the volume with for instance ``alsamixer``.

Limitations
-----------

Sound card output is band-limited. The implications, amongst others, are that
it's really hard to just draw in a *goto(x,y)* manner. I used some crude tricks
to prevent the dot from swinging wildly around the screen; alas, they are not
perfect and may cause flickering as a result. See
[this presentation](http://xiph.org/video/vid2.shtml) to learn enough DSP basics
to know how band-limiting affects signals (especially square waves).