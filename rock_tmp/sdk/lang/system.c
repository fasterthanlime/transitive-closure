/* lang/system source file, generated with rock, the ooc compiler written in ooc */

#include "system.h"

#include <sdk/lang/stdio.h>
#include <sdk/lang/types.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/string.h>
#include <sdk/lang/vararg.h>

void lang_system_load() {
    static bool __done__ = false;
    if (!__done__){
        __done__ = true;
        lang_stdio_load();
        lang_types_load();
        lang_memory_load();
        lang_string_load();
        lang_vararg_load();
    }
}

