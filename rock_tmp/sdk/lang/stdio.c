/* lang/stdio source file, generated with rock, the ooc compiler written in ooc */

#include "stdio.h"

#include <sdk/lang/memory.h>
#include <sdk/lang/system.h>
#include <sdk/lang/string.h>
#include <sdk/lang/vararg.h>


lang_types__Int lang_stdio__FStream_close(lang_stdio__FStream this) {
    return fclose(this);
}

void lang_stdio__FStream_flush(lang_stdio__FStream this) {
    fflush(this);
}

lang_types__Char lang_stdio__FStream_readChar(lang_stdio__FStream this) {
    lang_types__Char c;
    lang_types__SizeT count = fread(&(c), 1, 1, this);
    if (count < (lang_types__SizeT) 1) {
        lang_types__Exception_throw(lang_types__Exception_new_originMsg((lang_types__Class*) (lang_stdio__FStream_class()), "Trying to read a char at the end of a file!"));
    }
    return c;
}

lang_types__String lang_stdio__FStream_readLine(lang_stdio__FStream this) {
    lang_types__Int chunk = 128;
    lang_types__Int length = chunk;
    lang_types__Int pos = 0;
    lang_types__Char* str = ((lang_types__Char*) (GC_MALLOC(length)));
    lang_types__Char* returnVal = fgets(str, chunk, this);
    while (str[strlen(str)] != '\n' && returnVal != (lang_types__Char*) NULL) {
        pos += chunk - 1;
        length += chunk;
        lang_types__String tmp = ((lang_types__String) (GC_REALLOC(str, length)));
        if (!tmp) {
            lang_types__Exception_throw(lang_types__Exception_new_originMsg((lang_types__Class*) (lang_stdio__FStream_class()), "Ran out of memory while reading a (apparently never-ending) line!"));
        }
        str = (void*) tmp;
        returnVal = (void*) fgets(str, chunk, this);
    }
    return ((lang_types__String) (str));
}

lang_types__Bool lang_stdio__FStream_hasNext(lang_stdio__FStream this) {
    return feof(this) == 0;
}

void lang_stdio__FStream_write_chr(lang_stdio__FStream this, lang_types__Char chr) {
    fputc(chr, this);
}

void lang_stdio__FStream_write(lang_stdio__FStream this, lang_types__String str) {
    fputs(str, this);
}

lang_types__SizeT lang_stdio__FStream_write_precise(lang_stdio__FStream this, lang_types__Char* str, lang_types__SizeT offset, lang_types__SizeT length) {
    return fwrite(str + offset, 1, length, this);
}
lang_stdio__FStream lang_stdio__FStream_open(lang_types__String filename, lang_types__String mode) {
    
    return fopen(filename, mode);
}

lang_stdio__FStreamClass *lang_stdio__FStream_class(){
    static lang_stdio__FStreamClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_stdio__FStream),
                    .size = sizeof(lang_stdio__FStream),
                    .name = "FStream",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    return &class;
}
void lang_stdio_load() {
    static bool __done__ = false;
    if (!__done__){
        __done__ = true;
        lang_types_load();
        lang_memory_load();
        lang_system_load();
        lang_string_load();
        lang_vararg_load();
    }
}


void lang_stdio__println_withStr(lang_types__Char* str) {
    printf("%s\n", str);
}

void lang_stdio__println() {
    printf("\n");
}
