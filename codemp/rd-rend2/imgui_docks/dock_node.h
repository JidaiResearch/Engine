#include "dock.h"
#include <string>

#ifndef _WIN32
#pragma GCC diagnostic ignored "-fpermissive"
#pragma GCC diagnostic ignored "-pedantic"
#endif

class DockNode : public Dock {
public:

#ifdef _WIN32
	char repl_filename[128] = {"tmp.txt"};
	char replbuffer[4096] = {""};
#else
	// fucking gcc cries like a bitch and even casting doesnt for for whatever reason...
	char repl_filename[128];
	char replbuffer[4096];
#endif

	DockNode();
	virtual const char *label();
	virtual void imgui();
};