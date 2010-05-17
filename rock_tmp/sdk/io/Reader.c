/* io/Reader source file, generated with rock, the ooc compiler written in ooc */

#include "Reader.h"

#include <sdk/lang/stdio.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/system.h>
#include <sdk/lang/string.h>
#include <sdk/lang/vararg.h>
#include <sdk/text/Buffer.h>


void io_Reader__Reader_init_impl(io_Reader__Reader* this) {
}

lang_types__String io_Reader__Reader_readUntil_impl(io_Reader__Reader* this, lang_types__Char end) {
    text_Buffer__Buffer* sb = text_Buffer__Buffer_new_withCapa(40);
    while (io_Reader__Reader_hasNext(this)) {
        lang_types__Char c = io_Reader__Reader_read_char(this);
        if (c == end) {
            break;
        }
        text_Buffer__Buffer_append_chr(sb, c);
    }
    return text_Buffer__Buffer_toString(sb);
}

lang_types__String io_Reader__Reader_readLine_impl(io_Reader__Reader* this) {
    return lang_types__String_trimRight(io_Reader__Reader_readUntil(this, '\n'), '\r');
}

lang_types__Char io_Reader__Reader_peek_impl(io_Reader__Reader* this) {
    lang_types__Char c = io_Reader__Reader_read_char(this);
    io_Reader__Reader_rewind(this, 1);
    return c;
}

void io_Reader__Reader_skipWhile_impl(io_Reader__Reader* this, lang_types__Char unwanted) {
    while (io_Reader__Reader_hasNext(this)) {
        lang_types__Char c = io_Reader__Reader_read_char(this);
        if (c != unwanted) {
            io_Reader__Reader_rewind(this, 1);
            break;
        }
    }
}

void io_Reader__Reader_skip_impl(io_Reader__Reader* this, lang_types__Int offset) {
    if (offset < 0) {
        io_Reader__Reader_rewind(this, -offset);
    }
    else {
        
        {
            lang_types__Int i;
            for (i = 0; i < offset; i++) {
                io_Reader__Reader_read_char(this);
            }
        }
    }
}

void io_Reader__Reader_init(io_Reader__Reader* this) {
    ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->init((io_Reader__Reader*)this);
}

lang_types__SizeT io_Reader__Reader_read(io_Reader__Reader* this, lang_types__String chars, lang_types__Int offset, lang_types__Int count) {
    return (lang_types__SizeT) ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->read((io_Reader__Reader*)this, chars, offset, count);
}

lang_types__Char io_Reader__Reader_read_char(io_Reader__Reader* this) {
    return (lang_types__Char) ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->read_char((io_Reader__Reader*)this);
}

lang_types__String io_Reader__Reader_readUntil(io_Reader__Reader* this, lang_types__Char end) {
    return (lang_types__String) ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->readUntil((io_Reader__Reader*)this, end);
}

lang_types__String io_Reader__Reader_readLine(io_Reader__Reader* this) {
    return (lang_types__String) ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->readLine((io_Reader__Reader*)this);
}

lang_types__Char io_Reader__Reader_peek(io_Reader__Reader* this) {
    return (lang_types__Char) ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->peek((io_Reader__Reader*)this);
}

void io_Reader__Reader_skipWhile(io_Reader__Reader* this, lang_types__Char unwanted) {
    ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->skipWhile((io_Reader__Reader*)this, unwanted);
}

lang_types__Bool io_Reader__Reader_hasNext(io_Reader__Reader* this) {
    return (lang_types__Bool) ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->hasNext((io_Reader__Reader*)this);
}

void io_Reader__Reader_rewind(io_Reader__Reader* this, lang_types__Int offset) {
    ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->rewind((io_Reader__Reader*)this, offset);
}

lang_types__Long io_Reader__Reader_mark(io_Reader__Reader* this) {
    return (lang_types__Long) ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->mark((io_Reader__Reader*)this);
}

void io_Reader__Reader_reset(io_Reader__Reader* this, lang_types__Long marker) {
    ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->reset((io_Reader__Reader*)this, marker);
}

void io_Reader__Reader_skip(io_Reader__Reader* this, lang_types__Int offset) {
    ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->skip((io_Reader__Reader*)this, offset);
}

io_Reader__ReaderClass *io_Reader__Reader_class(){
    static lang_types__Bool __done__ = false;
    static io_Reader__ReaderClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(io_Reader__Reader),
                    .size = sizeof(void*),
                    .name = "Reader",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
        .init = io_Reader__Reader_init_impl,
        .read = io_Reader__Reader_read,
        .read_char = io_Reader__Reader_read_char,
        .readUntil = io_Reader__Reader_readUntil_impl,
        .readLine = io_Reader__Reader_readLine_impl,
        .peek = io_Reader__Reader_peek_impl,
        .skipWhile = io_Reader__Reader_skipWhile_impl,
        .hasNext = io_Reader__Reader_hasNext,
        .rewind = io_Reader__Reader_rewind,
        .mark = io_Reader__Reader_mark,
        .reset = io_Reader__Reader_reset,
        .skip = io_Reader__Reader_skip_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Object_class();
        __done__ = true;
    }
    return &class;
}
void io_Reader_load() {
    static bool __done__ = false;
    if (!__done__){
        __done__ = true;
        lang_stdio_load();
        lang_types_load();
        lang_memory_load();
        lang_system_load();
        lang_string_load();
        lang_vararg_load();
        text_Buffer_load();
    }
}

