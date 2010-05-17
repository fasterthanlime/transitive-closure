/* io/Writer source file, generated with rock, the ooc compiler written in ooc */

#include "Writer.h"

#include <sdk/lang/stdio.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/system.h>
#include <sdk/lang/string.h>
#include <sdk/lang/vararg.h>
#include <sdk/io/Reader.h>


void io_Writer__Writer_init_impl(io_Writer__Writer* this) {
}

lang_types__SizeT io_Writer__Writer_write_implicitLength_impl(io_Writer__Writer* this, lang_types__String chars) {
    return io_Writer__Writer_write(this, chars, strlen(chars));
}

lang_types__SizeT io_Writer__Writer_write_fromReader_impl(io_Writer__Writer* this, io_Reader__Reader* source, lang_types__SizeT bufferSize) {
    lang_types__String buffer = lang_types__String_new_withLength(bufferSize);
    lang_types__Int cursor;
    lang_types__Int bytesRead;
    lang_types__Int bytesTransfered;
    cursor = 0;
    bytesTransfered = 0;
    while (io_Reader__Reader_hasNext(source)) {
        bytesRead = io_Reader__Reader_read(source, buffer, cursor, bufferSize);
        bytesTransfered += io_Writer__Writer_write(this, buffer, bytesRead);
    }
    return ((lang_types__SizeT) (bytesTransfered));
}

void io_Writer__Writer_write_fromReaderDefaultBufferSize_impl(io_Writer__Writer* this, io_Reader__Reader* source) {
    io_Writer__Writer_write_fromReader(this, source, 8192);
}

void io_Writer__Writer_init(io_Writer__Writer* this) {
    ((io_Writer__WriterClass *)((lang_types__Object *)this)->class)->init((io_Writer__Writer*)this);
}

void io_Writer__Writer_close(io_Writer__Writer* this) {
    ((io_Writer__WriterClass *)((lang_types__Object *)this)->class)->close((io_Writer__Writer*)this);
}

void io_Writer__Writer_write_chr(io_Writer__Writer* this, lang_types__Char chr) {
    ((io_Writer__WriterClass *)((lang_types__Object *)this)->class)->write_chr((io_Writer__Writer*)this, chr);
}

lang_types__SizeT io_Writer__Writer_write(io_Writer__Writer* this, lang_types__String chars, lang_types__SizeT length) {
    return (lang_types__SizeT) ((io_Writer__WriterClass *)((lang_types__Object *)this)->class)->write((io_Writer__Writer*)this, chars, length);
}

lang_types__SizeT io_Writer__Writer_write_implicitLength(io_Writer__Writer* this, lang_types__String chars) {
    return (lang_types__SizeT) ((io_Writer__WriterClass *)((lang_types__Object *)this)->class)->write_implicitLength((io_Writer__Writer*)this, chars);
}

lang_types__SizeT io_Writer__Writer_write_fromReader(io_Writer__Writer* this, io_Reader__Reader* source, lang_types__SizeT bufferSize) {
    return (lang_types__SizeT) ((io_Writer__WriterClass *)((lang_types__Object *)this)->class)->write_fromReader((io_Writer__Writer*)this, source, bufferSize);
}

void io_Writer__Writer_write_fromReaderDefaultBufferSize(io_Writer__Writer* this, io_Reader__Reader* source) {
    ((io_Writer__WriterClass *)((lang_types__Object *)this)->class)->write_fromReaderDefaultBufferSize((io_Writer__Writer*)this, source);
}

io_Writer__WriterClass *io_Writer__Writer_class(){
    static lang_types__Bool __done__ = false;
    static io_Writer__WriterClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(io_Writer__Writer),
                    .size = sizeof(void*),
                    .name = "Writer",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
        .init = io_Writer__Writer_init_impl,
        .close = io_Writer__Writer_close,
        .write_chr = io_Writer__Writer_write_chr,
        .write = io_Writer__Writer_write,
        .write_implicitLength = io_Writer__Writer_write_implicitLength_impl,
        .write_fromReader = io_Writer__Writer_write_fromReader_impl,
        .write_fromReaderDefaultBufferSize = io_Writer__Writer_write_fromReaderDefaultBufferSize_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Object_class();
        __done__ = true;
    }
    return &class;
}
void io_Writer_load() {
    static bool __done__ = false;
    if (!__done__){
        __done__ = true;
        lang_stdio_load();
        lang_types_load();
        lang_memory_load();
        lang_system_load();
        lang_string_load();
        lang_vararg_load();
        io_Reader_load();
    }
}

