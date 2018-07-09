#include "dock.h"
#include <string>

class DockMicroPython : public Dock {
public:
	char repl_filename[128] = {"tmp.txt"};
	char replbuffer[4096] = {0};

	DockMicroPython();
	virtual const char *label();
	virtual void imgui();
};