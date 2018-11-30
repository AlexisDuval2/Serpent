#ifndef CONSOLE_WRITER_H
#define CONSOLE_WRITER_H


#include "ConsoleImage.h"
#include <map>
#include <string>

class Console;



class ConsoleWriter
{
	ConsoleWriter(Console & console);

public:
	size_t width() const;
	size_t height() const;

	void gotoxy(size_t x, size_t y);
	void setColor(ConsoleColor const & color);

	ConsoleImage& createImage(std::string const & imageName, char outputChar = ' ', ConsoleColor color = ConsoleColor::standard());
	void removeImage(std::string const & imageName);
	ConsoleImage& image(std::string const & imageName);
	
	void push(std::string const & imageName);
	void push(std::string const & imageName1, std::string const & imageName2);

	void randomize();
	void calib();

private:
	Console & mConsole;
	std::map<std::string, ConsoleImage> mImages;

	void write(ConsoleImage const & image);

	friend class Console;
	friend class ConsoleImage;
};




#endif // CONSOLE_WRITER_H
