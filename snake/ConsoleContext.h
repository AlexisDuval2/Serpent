#ifndef CONSOLE_CONTEXT_H
#define CONSOLE_CONTEXT_H


#include <string>


struct ConsoleContext
{
	size_t width;				// in range [40, 160]
	size_t height;				// in range [40, 80]
	std::string title;

	int16_t fontWidth;
	int16_t fontHeight;
	std::wstring fontName;

	ConsoleContext();
	ConsoleContext(size_t w, size_t h, std::string const & t, int16_t fw, int16_t fh, std::wstring const & fn);

	static ConsoleContext themeStandard();
	static ConsoleContext themeCompact();
	static ConsoleContext themePixelSquare(size_t w, size_t h, int16_t fSize, std::wstring const & fn = L"Consolas");
	static ConsoleContext themeSquare(size_t screenSize, int16_t fSize, std::wstring const & fn = L"Consolas");
};



#endif // CONSOLE_CONTEXT_H
