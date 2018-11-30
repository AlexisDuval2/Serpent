#ifndef CONSOLE_COLOR_H
#define CONSOLE_COLOR_H


#define NOMINMAX
#include <Windows.h>
#include <cstdint>



class ConsoleColor
{
public:
	enum class Text : uint16_t {
		Black			= 0,
		Red				= FOREGROUND_RED,
		Green			= FOREGROUND_GREEN,
		Blue			= FOREGROUND_BLUE,
		Yellow			= Red | Green,
		Magenta			= Red | Blue,
		Cyan			= Green | Blue,
		White			= Red | Green | Blue,
		BrightRed		= Red | FOREGROUND_INTENSITY,
		BrightGreen		= Green | FOREGROUND_INTENSITY,
		BrightBlue		= Blue | FOREGROUND_INTENSITY,
		BrightYellow	= Yellow | FOREGROUND_INTENSITY,
		BrightMagenta	= Magenta | FOREGROUND_INTENSITY,
		BrightCyan		= Cyan | FOREGROUND_INTENSITY,
		BrightWhite		= White | FOREGROUND_INTENSITY
	};
	static const Text tk{ Text::Black };
	static const Text tw{ Text::White };
	static const Text tr{ Text::Red };
	static const Text tg{ Text::Green };
	static const Text tb{ Text::Blue };
	static const Text ty{ Text::Yellow };
	static const Text tm{ Text::Magenta };
	static const Text tc{ Text::Cyan };
	static const Text tK{ Text::Black };
	static const Text tW{ Text::BrightWhite };
	static const Text tR{ Text::BrightRed };
	static const Text tG{ Text::BrightGreen };
	static const Text tB{ Text::BrightBlue };
	static const Text tY{ Text::BrightYellow };
	static const Text tM{ Text::BrightMagenta };
	static const Text tC{ Text::BrightCyan };

	enum class Background : uint16_t {
		Black			= 0,
		Red				= BACKGROUND_RED,
		Green			= BACKGROUND_GREEN,
		Blue			= BACKGROUND_BLUE,
		Yellow			= Red | Green,
		Magenta			= Red | Blue,
		Cyan			= Green | Blue,
		White			= Red | Green | Blue,
		BrightRed		= Red | BACKGROUND_INTENSITY,
		BrightGreen		= Green | BACKGROUND_INTENSITY,
		BrightBlue		= Blue | BACKGROUND_INTENSITY,
		BrightYellow	= Yellow | BACKGROUND_INTENSITY,
		BrightMagenta	= Magenta | BACKGROUND_INTENSITY,
		BrightCyan		= Cyan | BACKGROUND_INTENSITY,
		BrightWhite		= White | BACKGROUND_INTENSITY
	};
	static const Background bk{ Background::Black };
	static const Background bw{ Background::White };
	static const Background br{ Background::Red };
	static const Background bg{ Background::Green };
	static const Background bb{ Background::Blue };
	static const Background by{ Background::Yellow };
	static const Background bm{ Background::Magenta };
	static const Background bc{ Background::Cyan };
	static const Background bK{ Background::Black };
	static const Background bW{ Background::BrightWhite };
	static const Background bR{ Background::BrightRed };
	static const Background bG{ Background::BrightGreen };
	static const Background bB{ Background::BrightBlue };
	static const Background bY{ Background::BrightYellow };
	static const Background bM{ Background::BrightMagenta };
	static const Background bC{ Background::BrightCyan };

	enum class Mask {	
		Text			= 0b1111'1111'0000'1111,
		Background		= 0b1111'1111'1111'0000,
		NoColor			= Text & Background,
		OnlyColor		= ~NoColor
	};

	ConsoleColor();
	ConsoleColor(Text textColor);
	ConsoleColor(Background backgroundColor);
	ConsoleColor(Text textColor, Background backgroundColor);

	uint16_t color() const;
	uint16_t color(uint16_t valueToMerge) const;

	void set();
	void set(Text textColor);
	void set(Background backgroundColor);
	void set(Text textColor, Background backgroundColor);

	static ConsoleColor standard();
	static ConsoleColor from(uint16_t value);
	static ConsoleColor from(CHAR_INFO charInfo);

private:
	uint16_t mColor;

};

inline ConsoleColor operator+(ConsoleColor::Text tColor, ConsoleColor::Background bColor) {
	return ConsoleColor(tColor, bColor);
}
inline ConsoleColor operator+(ConsoleColor::Background bColor, ConsoleColor::Text tColor) {
	return ConsoleColor(tColor, bColor);
}


#endif // CONSOLE_COLOR_H
