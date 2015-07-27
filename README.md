# colorful_console

Colorful Output to Linux Console
================================

Overview
--------
How’s the color magic works?
0x1B is a special code that used to do all the color settings.
With 0x1B and an open square blacket “[“, initiate the setting.

Set console output text attribute:
	(attribute);(fore color);(background color)
	printf("%c[%d;%d;%dm", 0x1B, 1, 33, 40);

Reset consolet output text attribute:
	printf("%c[%d;%d;%dm", 0x1B, 0, 0, 0);

Example
-------

How to build
------------
g++ -Wall -o colorful_console_test main.cpp

How to run
----------
./colorful_console_test


Reference
---------
http://cc.byexamples.com/2007/01/20/print-color-string-without-ncurses/
