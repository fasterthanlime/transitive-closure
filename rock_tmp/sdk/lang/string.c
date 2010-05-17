/* lang/string source file, generated with rock, the ooc compiler written in ooc */

#include "string.h"

#include <sdk/lang/stdio.h>
#include <sdk/lang/types.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/system.h>
#include <sdk/lang/vararg.h>

void lang_string_load() {
    static bool __done__ = false;
    if (!__done__){
        __done__ = true;
        lang_stdio_load();
        lang_types_load();
        lang_memory_load();
        lang_system_load();
        lang_vararg_load();
    }
}

