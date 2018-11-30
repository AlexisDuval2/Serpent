#ifndef CONSOLE_IMAGE_H
#define CONSOLE_IMAGE_H


#include "ConsoleColor.h"
#include <vector>
#include <utility>

class ConsoleWriter;


class ConsoleImage
{
	ConsoleImage(ConsoleWriter & consoleWriter, char outputChar = ' ', ConsoleColor color = ConsoleColor::standard()); // ATTENTION DOIT ÊTRE PRIVEE

public:
	ConsoleImage& operator=(ConsoleImage const & im);

	char character(size_t x, size_t y) const;
	ConsoleColor color(size_t x, size_t y) const;
	std::pair<char, ConsoleColor> pixel(size_t x, size_t y) const;

	void fill(char outputChar, ConsoleColor color);
	void fill(size_t x1, size_t y1, size_t width, size_t height, char outputChar, ConsoleColor color);
	void fill(double x1, double y1, double width, double height, char outputChar, ConsoleColor color);

	void drawPoint(size_t x, size_t y, char outputChar, ConsoleColor color);
	void drawPoint(double x, double y, char outputChar, ConsoleColor color);

	void drawLine(size_t x1, size_t y1, size_t x2, size_t y2, char outputChar, ConsoleColor color);
	void drawLine(double x1, double y1, double x2, double y2, char outputChar, ConsoleColor color);
	
	void drawRect(size_t x1, size_t y1, size_t width, size_t height, char outputChar, ConsoleColor color);
	void drawRect(double x1, double y1, double width, double height, char outputChar, ConsoleColor color);
	void drawRect(size_t x1, size_t y1, size_t width, size_t height, char borderOutputChar, ConsoleColor borderColor, char fillOutputChar, ConsoleColor fillColor);
	void drawRect(double x1, double y1, double width, double height, char borderOutputChar, ConsoleColor borderColor, char fillOutputChar, ConsoleColor fillColor);

	void drawText(size_t x, size_t y, std::string const & text, ConsoleColor color, bool horizontal = true);

	void randomize();
	void calib();

	size_t width() const;
	size_t height() const;

private:
	ConsoleWriter & mConsoleWriter;
	std::vector<CHAR_INFO> mBuffer;

	CHAR_INFO* get(size_t x, size_t y) const;
	CHAR_INFO charInfo(char outChar, ConsoleColor color);
	void drawPoint(size_t x, size_t y, CHAR_INFO const & pix);
	void drawPoint(double x, double y, CHAR_INFO const & pix);
	void drawLine(size_t x1, size_t y1, size_t x2, size_t y2, CHAR_INFO const & pix);
	void drawLine(double x1, double y1, double x2, double y2, CHAR_INFO const & pix);
	void drawRect(size_t x1, size_t y1, size_t width, size_t height, CHAR_INFO const & pix);
	void drawRect(double x1, double y1, double width, double height, CHAR_INFO const & pix);

	size_t round(double value) const;

	friend class ConsoleWriter;
};

#endif // CONSOLE_IMAGE_H
