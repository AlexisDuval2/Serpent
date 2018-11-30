#ifndef CONSOLE_H
#define CONSOLE_H


#include "ConsoleContext.h"
#include "ConsoleKeyReader.h"
#include "ConsoleWriter.h"
#include <string>
#include <stdexcept>


class Console
{
	static ConsoleContext mContext;
	Console(ConsoleContext const & context);

public:
	static void defineContext(ConsoleContext const & context);
	static Console& getInstance();

	static const size_t MaxWidth{ 200 };
	static const size_t MinWidth{ 20 };
	static const size_t MaxHeight{ 100 };
	static const size_t MinHeight{ 20 };

	ConsoleKeyReader& keyReader();
	ConsoleWriter& writer();

	size_t width() const;
	size_t height() const;
	
	class ConsoleExcept : public std::exception {};
	class NoOutputConsole : public ConsoleExcept {};
	class NoInputConsole : public ConsoleExcept {};
	class NoTitleConsole : public ConsoleExcept {};

private:
	HANDLE mHandleConsoleOutput;
	HANDLE mHandleConsoleInput;
	ConsoleKeyReader mConsoleKeyReader;
	ConsoleWriter mConsoleWriter;
	size_t mWidth, mHeight, mBufferLinearSize;
	COORD mBufferSize;
	SMALL_RECT mWindowRect;

	friend class ConsoleKeyReader;
	friend class ConsoleWriter;
	friend class ConsoleImage;
};





#endif // CONSOLE_H