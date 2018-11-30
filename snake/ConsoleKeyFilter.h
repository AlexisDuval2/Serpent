#ifndef CONSOLE_KEY_FILTER_H
#define CONSOLE_KEY_FILTER_H


#include "ConsoleKeyEvent.h"


// These filters are for one key filtering. If you need to filter a 
// combination of n specific keys, you must not include the first key 
// in any of the following filters.


class ConsoleKeyFilter
{
public:
	virtual bool isFiltered(ConsoleKeyEvent const & consoleKeyEvent) const = 0;
};


#endif // CONSOLE_KEY_FILTER_H
