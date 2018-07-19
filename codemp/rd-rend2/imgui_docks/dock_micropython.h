#include "dock.h"
#include <string>

class DockMicroPython : public Dock {
public:
#ifdef _WIN32
	char repl_filename[128] = {(char *)"tmp.txt"};
	char replbuffer[4096] = {(char *)NULL};
#else
	// fucking gcc cries like a bitch and even casting doesnt for for whatever reason...
	char repl_filename[128];
	char replbuffer[4096];
#endif
	DockMicroPython();
	virtual const char *label();
	virtual void imgui();
};