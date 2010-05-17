/* lang/vararg source file, generated with rock, the ooc compiler written in ooc */

#include "vararg.h"

#include <sdk/lang/stdio.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/system.h>
#include <sdk/lang/string.h>


lang_vararg__VaListClass *lang_vararg__VaList_class(){
    static lang_vararg__VaListClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_vararg__VaList),
                    .size = sizeof(lang_vararg__VaList),
                    .name = "VaList",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    return &class;
}
void lang_vararg_load() {
    static bool __done__ = false;
    if (!__done__){
        __done__ = true;
        lang_stdio_load();
        lang_types_load();
        lang_memory_load();
        lang_system_load();
        lang_string_load();
    }
}

