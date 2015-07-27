/**
 * Colorful text console output
 */

#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
/**
 *  Text Attributes
 */
typedef enum _text_attributes_e {
	ALL_ATTRIBUTES_OFF	= 0,	/* All attributes off */
	BOLD_ON			= 1,	/* Bold on */
	UNDERSCORE		= 4,	/* Underscore
					(on monochrome display adapter only) */
	/*BLINK_ON		= 5,*/	/* Blink on */
	REVERSE_VIDEO_ON	= 7,	/* Reverse video on */
	/*CONCEALED_ON		= 8,*/	/* Concealed on */
	STRIKE_OUT		= 9	/* Striked out */
} text_attributes_e;

text_attributes_e _attributes[] = { ALL_ATTRIBUTES_OFF, BOLD_ON, UNDERSCORE,
	/*BLINK_ON,*/ REVERSE_VIDEO_ON, /*CONCEALED_ON,*/ STRIKE_OUT};

/**
 *  Text Foreground Colors
 */
typedef enum _foreground_colors_e {
	FG_BLACK	= 30,
	FG_RED		= 31,
	FG_GREEN	= 32,
	FG_YELLOW	= 33,
	FG_BLUE		= 34,
	FG_MAGENTA	= 35,
	FG_CYAN		= 36,
	FG_WHITE	= 37,
	FG_LITE_BLACK	= 90,
	FG_LITE_RED	= 91,
	FG_LITE_GREEN	= 92,
	FG_LITE_YELLOW	= 93,
	FG_LITE_BLUE	= 94,
	FG_LITE_MAGENTA	= 95,
	FG_LITE_CYAN	= 96,
	FG_LITE_WHITE	= 97
} foreground_colors_e;

foreground_colors_e _fg_colors[] = { FG_BLACK, FG_RED, FG_GREEN, FG_YELLOW,
	FG_BLUE, FG_MAGENTA, FG_CYAN, FG_WHITE, FG_LITE_BLACK, FG_LITE_RED,
	FG_LITE_GREEN, FG_LITE_YELLOW, FG_LITE_BLUE, FG_LITE_MAGENTA,
	FG_LITE_CYAN, FG_LITE_WHITE };
/**
 *  Text Background Colors
 */
typedef enum _background_colors_e {
	BG_BLACK	= 40,
	BG_RED		= 41,
	BG_GREEN	= 42,
	BG_YELLOW	= 43,
	BG_BLUE		= 44,
	BG_MAGENTA	= 45,
	BG_CYAN		= 46,
	BG_WHITE	= 47,
	BG_LITE_BLACK	= 100,
	BG_LITE_RED	= 101,
	BG_LITE_GREEN	= 102,
	BG_LITE_YELLOW	= 103,
	BG_LITE_BLUE	= 104,
	BG_LITE_MAGENTA	= 105,
	BG_LITE_CYAN	= 106,
	BG_LITE_WHITE	= 107
} background_colors_e;

background_colors_e _bg_colors[] = { BG_BLACK, BG_RED, BG_GREEN, BG_YELLOW,
	BG_BLUE, BG_MAGENTA, BG_CYAN, BG_WHITE, BG_LITE_BLACK, BG_LITE_RED,
	BG_LITE_GREEN, BG_LITE_YELLOW, BG_LITE_BLUE, BG_LITE_MAGENTA,
	BG_LITE_CYAN, BG_LITE_WHITE };

int main(void) {
	/*
	 * How’s the color magic works?
	 * 0x1B is a special code that used to do all the color settings.
	 * With 0x1B and an open square blacket “[“, initiate the setting.
	 *
	 * Set console output text attribute:
	 *	(attribute);(fore color);(background color)
	 *	printf("%c[%d;%d;%dm", 0x1B, 1, 33, 40);
	 *
	 * Reset consolet output text attribute:
	 *	printf("%c[%d;%d;%dm", 0x1B, 0, 0, 0);
	 *
	 * http://cc.byexamples.com/2007/01/20/print-color-string-without-ncurses/
	 */

	/* Demo 1: A couple of basic examples */
	printf("%c[%d;%dm", 0x1B, ALL_ATTRIBUTES_OFF, FG_RED);
	printf("Red console\n");
	printf("%c[%d;%dm", 0x1B, ALL_ATTRIBUTES_OFF, FG_GREEN);
	printf("Green console\n");
	printf("%c[%d;%dm", 0x1B, ALL_ATTRIBUTES_OFF, FG_YELLOW);
	printf("Yellow console\n");

	/* Reset the initial text attributes */
	printf("%c[%d;%d;%dm", 0x1B, 0, 0, 0);

	/* Sizes of attributes */
	const int attr_cnt =
		sizeof(_attributes) / sizeof(text_attributes_e);
	const int fg_color_cnt =
		sizeof(_fg_colors) / sizeof(foreground_colors_e);
	const int bg_color_cnt =
		sizeof(_bg_colors) / sizeof(background_colors_e);

	/* Demo 2: Randomly picked attributes */
	srand(time(NULL));
	for(int line = 0; line < 10; line ++) {
		/* Pick attributes randomely */
		const text_attributes_e attr =
			_attributes[rand() % attr_cnt];
		const foreground_colors_e fg_col
			= _fg_colors[rand() % fg_color_cnt];
		const background_colors_e bg_col
			= _bg_colors[rand() % bg_color_cnt];
		printf("Attribute: %03d, "
				"Foreground Color %03d, "
				"Background Color %03d: ",
				attr, fg_col, bg_col);

		/*
		 *  (attribute);
		 *  (foreground color);
		 *  (background color)
		 */
		printf("%c[%d;%d;%dm", 0x1B, attr, fg_col, bg_col);
		printf("Hello, world!");
		printf("%c[%d;%d;%dm", 0x1B, 0, 0, 0);
		printf("\n");
	}

#if 0
	/* Demo 3: Overal attributes */
	for(int i = 0; i < attr_cnt; i ++) {
		for(int j = 0; j < fg_color_cnt; j ++) {
			for(int k = 0; k < bg_color_cnt; k ++) {
				/*
				 *  (attribute);
				 *  (foreground color);
				 *  (background color)
				 */
				printf("Attribute: %03d, "
						"Foreground Color %03d, "
						"Background Color %03d: ",
						_attributes[i],
						_fg_colors[j],
						_bg_colors[k]);
				printf("%c[%d;%d;%dm", 0x1B,
						_attributes[i],
						_fg_colors[j],
						_bg_colors[k]);
				printf("Hello, world!");
				printf("%c[%d;%d;%dm", 0x1B, 0, 0, 0);
				printf("\n");
			}
			printf("\n");
		}
	}
#endif

	return 0;
}
