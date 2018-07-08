#ifndef UTILS_CPP_ALL_H
#define UTILS_CPP_ALL_H

#include "../ccall.h"

CCALL size_t strlcpy(char *dst, const char *src, size_t dstsize);
CCALL const char *get_filename_extension(const char *filename);

#endif