#include "ConsoleColor.h"



ConsoleColor::ConsoleColor()
	: mColor{ 0 }
{
}

ConsoleColor::ConsoleColor(Text textColor)
	: mColor{ static_cast<uint16_t>(textColor) }
{
}

ConsoleColor::ConsoleColor(Background backgroundColor)
	: mColor{ static_cast<uint16_t>(backgroundColor) }
{
}

ConsoleColor::ConsoleColor(Text textColor, Background backgroundColor)
	: mColor{ static_cast<uint16_t>(static_cast<uint16_t>(textColor) | static_cast<uint16_t>(backgroundColor)) }
{
}

uint16_t ConsoleColor::color() const
{
	return mColor;
}

uint16_t ConsoleColor::color(uint16_t valueToMerge) const
{
	return mColor | (static_cast<uint16_t>(Mask::NoColor) & valueToMerge);
}

void ConsoleColor::set()
{
	mColor = 0;
}

void ConsoleColor::set(Text textColor)
{
	mColor |= static_cast<uint16_t>(Mask::Background) & static_cast<uint16_t>(textColor);
}

void ConsoleColor::set(Background backgroundColor)
{
	mColor |= static_cast<uint16_t>(Mask::Text) & static_cast<uint16_t>(backgroundColor);
}

void ConsoleColor::set(Text textColor, Background backgroundColor)
{
	mColor = static_cast<uint16_t>(textColor) | static_cast<uint16_t>(backgroundColor);
}

ConsoleColor ConsoleColor::standard()
{
	return ConsoleColor(Text::White, Background::Black);
}

ConsoleColor ConsoleColor::from(uint16_t value)
{
	ConsoleColor color;
	color.mColor = static_cast<uint16_t>(Mask::OnlyColor) & value;

	return color;
}

ConsoleColor ConsoleColor::from(CHAR_INFO charInfo)
{
	return from(charInfo.Attributes);
}

