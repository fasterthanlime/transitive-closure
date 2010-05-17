/* lang/memory source file, generated with rock, the ooc compiler written in ooc */

#include "memory.h"

#include <sdk/lang/stdio.h>
#include <sdk/lang/types.h>
#include <sdk/lang/system.h>
#include <sdk/lang/string.h>
#include <sdk/lang/vararg.h>

void lang_memory_load() {
    static bool __done__ = false;
    if (!__done__){
        __done__ = true;
        lang_stdio_load();
        lang_types_load();
        lang_system_load();
        lang_string_load();
        lang_vararg_load();
    }
}

#if defined(__OOC_USE_GC__)

lang_types__Pointer lang_memory__gc_calloc(lang_types__SizeT nmemb, lang_types__SizeT size) {
    return GC_MALLOC(nmemb * size);
}
#endif
