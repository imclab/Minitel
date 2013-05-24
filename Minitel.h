/**
 * Minitel library for Arduino (v0.1) / May 2013
 * http://github.com/01010101/Minitel
 *
 * By Jerome Saint-Clair aka 01010101
 * http://saint-clair.net
 * 
 * For the Graffiti Research Lab France
 * http://graffitiresearchlab.fr
 * 
 * Based on works by the Tetalab (Fabrice, Renaud, PG & Phil)
 * http://tetalab.org
 */

#ifndef Minitel_h
#define Minitel_h

#include "Arduino.h"
#include "SoftwareSerial.h"

// Modes

#define GRAPHIC_MODE 14
#define TEXT_MODE 15

#define HORIZONTAL 0
#define VERTICAL 1

// Cursor moves
#define LEFT 8
#define RIGHT 9
#define DOWN 10
#define UP 11

// Cursor positionning
#define HOME 13
#define LINE_END 24

#define TOP_LEFT 30
#define TOP_RIGHT 1001
#define BOTTOM_LEFT 1002
#define BOTTOM_RIGHT 1003
#define CENTER 1004

// Cursor visibility
// Preceeded by 27
#define CURSOR_SHOW 17
#define CURSOR_HIDE 20

// Clear screen
#define CLEARSCREEN 12

// Font type
// Preceeded by 27
// DOUBLE-HEIGHT and DOUBLE may not work on certain Minitels
#define SIZE_NORMAL 76
#define SIZE_DOUBLE_HEIGHT 77
#define SIZE_DOUBLE_WIDTH 78
#define SIZE_DOUBLE 79


// Colors (+80 for background, +64 for text)
// Preceeded by 27
// 64->71 txt color black, red, green, yellow, blue, magenta, cyan, white
// 80->87 bg color black, red, green, yellow, blue, magenta, cyan, white
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define MAGENTA 4
#define BLUE 5
#define CYAN 6
#define WHITE 7

// Blink
// Preceeded by 27
#define BLINK_ON 72
#define BLINK_OFF 73

// Incrustation
// Preceeded by 27
#define INCRUSTATION_ON 75
#define INCRUSTATION_OFF 74

// Underline
#define UNDERLINE_ON 90
#define UNDERLINE_OFF 89

// Underline
#define LINE_MASK_ON 88
#define LINE_MASK_OFF 95

// Video mode
#define VIDEO_INVERT 93
#define VIDEO_STANDARD 92
#define VIDEO_TRANSPARENT 94

// Speeds
#define SPEED_75 0
#define SPEED_300 1
#define SPEED_4800 100
#define SPEED_9600 111 // ??? Minitel 2 ???

// Bip
#define BIP 7

// Accents
#define ACCUTE 65
#define GRAVE 66
#define CIRCUMFLEX 67
#define UMLAUT 72

#define SUB_ARTICLE_SEPARATOR 31;

// Preceeded by 25
#define SPE_CHAR_BOOK 35
#define SPE_CHAR_PARAGRAPH 39
#define SPE_CHAR_ARROW_LEFT 44
#define SPE_CHAR_ARROW_UP 45
#define SPE_CHAR_ARROW_RIGHT 46
#define SPE_CHAR_ARROW_DOWN 47
#define SPE_CHAR_CIRCLE 48
#define SPE_CHAR_MINUS_PLUS 49
#define SPE_CHAR_1_4 60
#define SPE_CHAR_1_2 61
#define SPE_CHAR_3_4 62
#define SPE_CHAR_UPPER_OE 106
#define SPE_CHAR_LOWER_OE 122
#define SPE_CHAR_BETA 123

/*
#define kPause  160
#define k1  177
#define k2  178
#define k3  51
#define k4  180
#define k5  53
#define k6  54
#define k7  183
#define k8  184
#define k9  57
#define k0  48
#define kStar  170
#define kHash  163

#define kComa  172
#define kDot  46
#define kExcl  39
#define kSemi  187
#define kDash  45
#define kColon  58
#define kInterro  63

#define kMenu  147
#define kSomm  198
#define kGuide  68
#define kAnnul  197
#define kCorrect  71
#define kRetour  66
#define kSuite  72
#define kRepet  195
#define kEnvoi  65

#define kA  65
#define kB  66
#define kC  195
#define kD  68
#define kE  197
#define kF  198
#define kG  71
#define kH  72
#define kI  201
#define kJ  202
#define kK  75
#define kL  204
#define kM  77
#define kN  78
#define kO  207
#define kP  80
#define kQ  209
#define kR  210
#define kS  83
#define kT  212
#define kU  85
#define kV  86
#define kW  215
#define kX  216
#define kY  89
#define kZ  90
*/

class Minitel : public SoftwareSerial {

private :	
	//String _characters;
	//String _accents;
	byte _currentBgColor;
	byte _currentTextColor;
	byte _currentMode;
	byte _currentVideo;
	byte _currentSize;
	boolean _currentUnderline;
	boolean _currentBlink;
	boolean _currentShowCursor;
	boolean _menuKeyPressed;
	void init();
	void refreshSettings();
	void mode(byte mode);
	void cursor(boolean b);
	void blink(boolean b);
	void pixelate(boolean b);
	void video(byte v);
	void incrustation(boolean b);
	void lineMask(boolean b);
	boolean isValidChar(byte index);
	boolean isAccent(char c);
	boolean printAccentChar(char c);
	void printAccent(int index);
	char getAccentLetter(int letterIndex);


public :

	Minitel();
	Minitel(int rx, int tx);
	byte getGraphicChar(String s);
	void serialprint7(byte b);
	void graphic(String s, int x, int y);
	void graphic(String s);
	void textByte(byte c);
	void textByte(byte b, int x, int y);
	boolean textChar(byte c);
	boolean textChar(byte c, int x, int y);
	void text(String s, int x, int y);
	void text(String s);
	void text(String s, int x, int y, int orientation);
	void text(String s, int orientation);
	byte getCharByte(char c);
	void specialChar(byte c, int x, int y);
	void specialChar(byte c);
	void repeat(byte n);
	void bgColor(byte c);
	void textColor(byte c);
	void useDefaultColors();
	void moveCursorTo(int x, int y);
	void moveCursor(byte dir);
	void moveCursorTo(byte location);
	void moveCursor(byte dir, int n);
	void cursor();
	void noCursor();
	void clearScreen();
	void graphicMode();
	void textMode();
	void blink();
	void noBlink();
	void charSize(byte type);
	void incrustation();
	void noIncrustation();
	void pixelate();
	void noPixelate();
	void lineMask();
	void noLineMask();
	void standardVideo();
	void invertVideo();
	void transparentVideo();
	void setMaxSpeed();
	void bip(long duration);
	char getKey();
	byte getKeyCode();
	boolean isMenuKey();
	void rect(char c, int x, int y, int w, int h);
	void rect(byte c, int x, int y, int w, int h);
	void spiral(int x, int y, int siz, int c);

};

#endif