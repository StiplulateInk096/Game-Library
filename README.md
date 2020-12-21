# Game-Library
A simple game library made using SDL2.


WARNING:
	This is not only terrible, it is unfinished, not intended for general use and has no documentation.

If you do however choose to use it, it is fairly simple.

The library is just an extension for C++ and SDL2.
The basic project goes:


	void setup() {
		setTitle("example");
	}
	void loop() {
		circle(width / 2, height / 2, getSmaller(width, height) / 2);
	}

"setup" is called in start of the game, "loop" is called once per frame.

"setTitle" is given a string and will set the title of the game engine to that.

"circle" draws the outline of a circle, it takes three arguments:
	x, y, r
"x" and "y" are is the position of the circle in pixels.
"r" is the radius of the circle.

"getSmaller" takes two arguments and returns the lower,
"getLarger" does the opposite,
and here it is used to make sure the circle fits on the screen.
