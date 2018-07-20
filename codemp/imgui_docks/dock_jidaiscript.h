#include "dock.h"
#include <string>

class DockJidaiScript : public Dock {
public:
#ifdef _WIN32
	char repl_filename[128] = {"tmp.txt"};
	char replbuffer[4096] = {""};
#else
	// fucking gcc cries like a bitch and even casting doesnt for for whatever reason...
	char repl_filename[128];
	char replbuffer[4096];
#endif
	DockJidaiScript();
	virtual const char *label();
	virtual void imgui();
};