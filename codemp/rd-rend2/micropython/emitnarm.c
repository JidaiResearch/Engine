// ARM specific stuff

#include "mpconfig.h"

#if MICROPY_EMIT_ARM

// This is defined so that the assembler exports generic assembler API macros
#define GENERIC_ASM_API (1)
#include "asmarm.h"

#define N_ARM (1)
#define EXPORT_FUN(name) emit_native_arm_##name
#include "emitnative.c"

#endif
