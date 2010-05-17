/* text/Buffer source file, generated with rock, the ooc compiler written in ooc */

#include "Buffer.h"

#include <sdk/lang/stdio.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/system.h>
#include <sdk/lang/string.h>
#include <sdk/lang/vararg.h>


void text_Buffer__Buffer_init_impl(text_Buffer__Buffer* this) {
    text_Buffer__Buffer_init_withCapa(this, 128);
}

void text_Buffer__Buffer_init_withCapa_impl(text_Buffer__Buffer* this, lang_types__SizeT capacity) {
    this->capacity = capacity;
    this->data = (void*) GC_MALLOC(capacity);
    this->size = 0;
}

void text_Buffer__Buffer_init_withContent_impl(text_Buffer__Buffer* this, lang_types__String data) {
    this->data = (void*) lang_types__String_clone(data);
    this->size = strlen(data);
    this->capacity = strlen(data);
}

void text_Buffer__Buffer_append_str_impl(text_Buffer__Buffer* this, lang_types__String str) {
    lang_types__Int length = strlen(str);
    text_Buffer__Buffer_append_strWithLength(this, str, length);
}

void text_Buffer__Buffer_append_strWithLength_impl(text_Buffer__Buffer* this, lang_types__String str, lang_types__SizeT length) {
    text_Buffer__Buffer_checkLength(this, this->size + length);
    memcpy(((lang_types__Char*) (this->data)) + this->size, ((lang_types__Char*) (str)), length);
    this->size += length;
}

void text_Buffer__Buffer_append_chr_impl(text_Buffer__Buffer* this, lang_types__Char chr) {
    text_Buffer__Buffer_checkLength(this, this->size + 1);
    this->data[this->size] = chr;
    this->size += 1;
}

lang_types__Int text_Buffer__Buffer_get_strWithLengthOffset_impl(text_Buffer__Buffer* this, lang_types__Char* str, lang_types__SizeT offset, lang_types__SizeT length) {
    if (offset >= this->size) {
        lang_types__Exception_throw(lang_types__Exception_new_originMsg((lang_types__Class*) (text_Buffer__Buffer_class()), "Buffer overflow! Offset is larger than buffer size."));
    }
    lang_types__Int copySize;
    if ((offset + length) > this->size) {
        copySize = this->size - offset;
    }
    else {
        copySize = length;
    }
    memcpy(str, (((lang_types__Char*) (this->data))) + offset, copySize);
    return copySize;
}

lang_types__Char text_Buffer__Buffer_get_chr_impl(text_Buffer__Buffer* this, lang_types__Int offset) {
    if (offset >= (lang_types__Int) this->size) {
        lang_types__Exception_throw(lang_types__Exception_new_originMsg((lang_types__Class*) (text_Buffer__Buffer_class()), "Buffer overflow! Offset is larger than buffer size."));
    }
    return this->data[offset];
}

void text_Buffer__Buffer_checkLength_impl(text_Buffer__Buffer* this, lang_types__SizeT min) {
    if (min >= this->capacity) {
        lang_types__SizeT newCapa = min * 1.200000 + 10;
        lang_types__Pointer tmp = GC_REALLOC(this->data, newCapa);
        if (!tmp) {
            lang_types__Exception_throw(lang_types__Exception_new_originMsg((lang_types__Class*) (text_Buffer__Buffer_class()), lang_types____OP_ADD_String_LLong__String("Couldn't allocate enough memory for Buffer to grow to capacity ", (lang_types__LLong) (newCapa))));
        }
        this->data = (void*) tmp;
        this->capacity = newCapa;
    }
}

lang_types__String text_Buffer__Buffer_toString_impl(text_Buffer__Buffer* this) {
    text_Buffer__Buffer_checkLength(this, this->size + 1);
    this->data[this->size] = '\0';
    return ((lang_types__String) (this->data));
}

void text_Buffer__Buffer_init(text_Buffer__Buffer* this) {
    ((text_Buffer__BufferClass *)((lang_types__Object *)this)->class)->init((text_Buffer__Buffer*)this);
}

void text_Buffer__Buffer_init_withCapa(text_Buffer__Buffer* this, lang_types__SizeT capacity) {
    ((text_Buffer__BufferClass *)((lang_types__Object *)this)->class)->init_withCapa((text_Buffer__Buffer*)this, capacity);
}

void text_Buffer__Buffer_init_withContent(text_Buffer__Buffer* this, lang_types__String data) {
    ((text_Buffer__BufferClass *)((lang_types__Object *)this)->class)->init_withContent((text_Buffer__Buffer*)this, data);
}

void text_Buffer__Buffer_append_str(text_Buffer__Buffer* this, lang_types__String str) {
    ((text_Buffer__BufferClass *)((lang_types__Object *)this)->class)->append_str((text_Buffer__Buffer*)this, str);
}

void text_Buffer__Buffer_append_strWithLength(text_Buffer__Buffer* this, lang_types__String str, lang_types__SizeT length) {
    ((text_Buffer__BufferClass *)((lang_types__Object *)this)->class)->append_strWithLength((text_Buffer__Buffer*)this, str, length);
}

void text_Buffer__Buffer_append_chr(text_Buffer__Buffer* this, lang_types__Char chr) {
    ((text_Buffer__BufferClass *)((lang_types__Object *)this)->class)->append_chr((text_Buffer__Buffer*)this, chr);
}

lang_types__Int text_Buffer__Buffer_get_strWithLengthOffset(text_Buffer__Buffer* this, lang_types__Char* str, lang_types__SizeT offset, lang_types__SizeT length) {
    return (lang_types__Int) ((text_Buffer__BufferClass *)((lang_types__Object *)this)->class)->get_strWithLengthOffset((text_Buffer__Buffer*)this, str, offset, length);
}

lang_types__Char text_Buffer__Buffer_get_chr(text_Buffer__Buffer* this, lang_types__Int offset) {
    return (lang_types__Char) ((text_Buffer__BufferClass *)((lang_types__Object *)this)->class)->get_chr((text_Buffer__Buffer*)this, offset);
}

void text_Buffer__Buffer_checkLength(text_Buffer__Buffer* this, lang_types__SizeT min) {
    ((text_Buffer__BufferClass *)((lang_types__Object *)this)->class)->checkLength((text_Buffer__Buffer*)this, min);
}

lang_types__String text_Buffer__Buffer_toString(text_Buffer__Buffer* this) {
    return (lang_types__String) ((text_Buffer__BufferClass *)((lang_types__Object *)this)->class)->toString((text_Buffer__Buffer*)this);
}
text_Buffer__Buffer* text_Buffer__Buffer_new() {
    
    text_Buffer__Buffer* this = ((text_Buffer__Buffer*) (lang_types__Class_alloc__class((lang_types__Class*) text_Buffer__Buffer_class())));
    lang_types__Object___defaults__((lang_types__Object*) this);
    text_Buffer__Buffer_init(this);
    return this;
}
text_Buffer__Buffer* text_Buffer__Buffer_new_withCapa(lang_types__SizeT capacity) {
    
    text_Buffer__Buffer* this = ((text_Buffer__Buffer*) (lang_types__Class_alloc__class((lang_types__Class*) text_Buffer__Buffer_class())));
    lang_types__Object___defaults__((lang_types__Object*) this);
    text_Buffer__Buffer_init_withCapa(this, capacity);
    return this;
}
text_Buffer__Buffer* text_Buffer__Buffer_new_withContent(lang_types__String data) {
    
    text_Buffer__Buffer* this = ((text_Buffer__Buffer*) (lang_types__Class_alloc__class((lang_types__Class*) text_Buffer__Buffer_class())));
    lang_types__Object___defaults__((lang_types__Object*) this);
    text_Buffer__Buffer_init_withContent(this, data);
    return this;
}

text_Buffer__BufferClass *text_Buffer__Buffer_class(){
    static lang_types__Bool __done__ = false;
    static text_Buffer__BufferClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(text_Buffer__Buffer),
                    .size = sizeof(void*),
                    .name = "Buffer",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
        .new = text_Buffer__Buffer_new,
        .init = text_Buffer__Buffer_init_impl,
        .new_withCapa = text_Buffer__Buffer_new_withCapa,
        .init_withCapa = text_Buffer__Buffer_init_withCapa_impl,
        .new_withContent = text_Buffer__Buffer_new_withContent,
        .init_withContent = text_Buffer__Buffer_init_withContent_impl,
        .append_str = text_Buffer__Buffer_append_str_impl,
        .append_strWithLength = text_Buffer__Buffer_append_strWithLength_impl,
        .append_chr = text_Buffer__Buffer_append_chr_impl,
        .get_strWithLengthOffset = text_Buffer__Buffer_get_strWithLengthOffset_impl,
        .get_chr = text_Buffer__Buffer_get_chr_impl,
        .checkLength = text_Buffer__Buffer_checkLength_impl,
        .toString = text_Buffer__Buffer_toString_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Object_class();
        __done__ = true;
    }
    return &class;
}

void text_Buffer__BufferWriter_init_impl(text_Buffer__BufferWriter* this) {
    this->buffer = text_Buffer__Buffer_new();
}

void text_Buffer__BufferWriter_init_withBuffer_impl(text_Buffer__BufferWriter* this, text_Buffer__Buffer* buffer) {
    this->buffer = buffer;
}

text_Buffer__Buffer* text_Buffer__BufferWriter_buffer_impl(text_Buffer__BufferWriter* this) {
    return this->buffer;
}

void text_Buffer__BufferWriter_close_impl(text_Buffer__BufferWriter* this) {
}

void text_Buffer__BufferWriter_write_chr_impl(text_Buffer__BufferWriter* this, lang_types__Char chr) {
    text_Buffer__Buffer_append_chr(this->buffer, chr);
}

lang_types__SizeT text_Buffer__BufferWriter_write_impl(text_Buffer__BufferWriter* this, lang_types__String chars, lang_types__SizeT length) {
    text_Buffer__Buffer_append_strWithLength(this->buffer, chars, length);
    return length;
}

void text_Buffer__BufferWriter_init(text_Buffer__BufferWriter* this) {
    ((io_Writer__WriterClass *)((lang_types__Object *)this)->class)->init((io_Writer__Writer*)this);
}

void text_Buffer__BufferWriter_init_withBuffer(text_Buffer__BufferWriter* this, text_Buffer__Buffer* buffer) {
    ((text_Buffer__BufferWriterClass *)((lang_types__Object *)this)->class)->init_withBuffer((text_Buffer__BufferWriter*)this, buffer);
}

text_Buffer__Buffer* text_Buffer__BufferWriter_buffer(text_Buffer__BufferWriter* this) {
    return (text_Buffer__Buffer*) ((text_Buffer__BufferWriterClass *)((lang_types__Object *)this)->class)->buffer((text_Buffer__BufferWriter*)this);
}

void text_Buffer__BufferWriter_close(text_Buffer__BufferWriter* this) {
    ((io_Writer__WriterClass *)((lang_types__Object *)this)->class)->close((io_Writer__Writer*)this);
}

void text_Buffer__BufferWriter_write_chr(text_Buffer__BufferWriter* this, lang_types__Char chr) {
    ((io_Writer__WriterClass *)((lang_types__Object *)this)->class)->write_chr((io_Writer__Writer*)this, chr);
}

lang_types__SizeT text_Buffer__BufferWriter_write(text_Buffer__BufferWriter* this, lang_types__String chars, lang_types__SizeT length) {
    return (lang_types__SizeT) ((io_Writer__WriterClass *)((lang_types__Object *)this)->class)->write((io_Writer__Writer*)this, chars, length);
}
text_Buffer__BufferWriter* text_Buffer__BufferWriter_new() {
    
    text_Buffer__BufferWriter* this = ((text_Buffer__BufferWriter*) (lang_types__Class_alloc__class((lang_types__Class*) text_Buffer__BufferWriter_class())));
    lang_types__Object___defaults__((lang_types__Object*) this);
    text_Buffer__BufferWriter_init(this);
    return this;
}
text_Buffer__BufferWriter* text_Buffer__BufferWriter_new_withBuffer(text_Buffer__Buffer* buffer) {
    
    text_Buffer__BufferWriter* this = ((text_Buffer__BufferWriter*) (lang_types__Class_alloc__class((lang_types__Class*) text_Buffer__BufferWriter_class())));
    lang_types__Object___defaults__((lang_types__Object*) this);
    text_Buffer__BufferWriter_init_withBuffer(this, buffer);
    return this;
}

text_Buffer__BufferWriterClass *text_Buffer__BufferWriter_class(){
    static lang_types__Bool __done__ = false;
    static text_Buffer__BufferWriterClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(text_Buffer__BufferWriter),
                        .size = sizeof(void*),
                        .name = "BufferWriter",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
            .init = (void (*)(io_Writer__Writer*)) text_Buffer__BufferWriter_init_impl,
            .close = (void (*)(io_Writer__Writer*)) text_Buffer__BufferWriter_close_impl,
            .write_chr = (void (*)(io_Writer__Writer*, lang_types__Char)) text_Buffer__BufferWriter_write_chr_impl,
            .write = (lang_types__SizeT (*)(io_Writer__Writer*, lang_types__String, lang_types__SizeT)) text_Buffer__BufferWriter_write_impl,
            .write_implicitLength = (lang_types__SizeT (*)(io_Writer__Writer*, lang_types__String)) io_Writer__Writer_write_implicitLength_impl,
            .write_fromReader = (lang_types__SizeT (*)(io_Writer__Writer*, io_Reader__Reader*, lang_types__SizeT)) io_Writer__Writer_write_fromReader_impl,
            .write_fromReaderDefaultBufferSize = (void (*)(io_Writer__Writer*, io_Reader__Reader*)) io_Writer__Writer_write_fromReaderDefaultBufferSize_impl,
        },
        .new = text_Buffer__BufferWriter_new,
        .new_withBuffer = text_Buffer__BufferWriter_new_withBuffer,
        .init_withBuffer = text_Buffer__BufferWriter_init_withBuffer_impl,
        .buffer = text_Buffer__BufferWriter_buffer_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) io_Writer__Writer_class();
        __done__ = true;
    }
    return &class;
}

void text_Buffer__BufferReader_init_impl(text_Buffer__BufferReader* this) {
    this->buffer = text_Buffer__Buffer_new();
}

void text_Buffer__BufferReader_init_withBuffer_impl(text_Buffer__BufferReader* this, text_Buffer__Buffer* buffer) {
    this->buffer = buffer;
}

text_Buffer__Buffer* text_Buffer__BufferReader_buffer_impl(text_Buffer__BufferReader* this) {
    return this->buffer;
}

lang_types__SizeT text_Buffer__BufferReader_read_impl(text_Buffer__BufferReader* this, lang_types__String chars, lang_types__Int offset, lang_types__Int count) {
    lang_types__Int copySize = text_Buffer__Buffer_get_strWithLengthOffset(this->buffer, ((lang_types__Char*) (chars)) + offset, ((io_Reader__Reader*) this)->marker, count);
    ((io_Reader__Reader*) this)->marker += copySize;
    return ((lang_types__SizeT) (copySize));
}

lang_types__Char text_Buffer__BufferReader_read_char_impl(text_Buffer__BufferReader* this) {
    lang_types__Char c = text_Buffer__Buffer_get_chr(this->buffer, ((io_Reader__Reader*) this)->marker);
    ((io_Reader__Reader*) this)->marker += 1;
    return c;
}

lang_types__Bool text_Buffer__BufferReader_hasNext_impl(text_Buffer__BufferReader* this) {
    return ((io_Reader__Reader*) this)->marker < (lang_types__Long) this->buffer->size;
}

void text_Buffer__BufferReader_rewind_impl(text_Buffer__BufferReader* this, lang_types__Int offset) {
    ((io_Reader__Reader*) this)->marker -= offset;
    if (((io_Reader__Reader*) this)->marker < (lang_types__Long) 0) {
        ((io_Reader__Reader*) this)->marker = 0;
    }
}

lang_types__Long text_Buffer__BufferReader_mark_impl(text_Buffer__BufferReader* this) {
    return ((io_Reader__Reader*) this)->marker;
}

void text_Buffer__BufferReader_reset_impl(text_Buffer__BufferReader* this, lang_types__Long marker) {
    ((io_Reader__Reader*) this)->marker = marker;
}

void text_Buffer__BufferReader_init(text_Buffer__BufferReader* this) {
    ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->init((io_Reader__Reader*)this);
}

void text_Buffer__BufferReader_init_withBuffer(text_Buffer__BufferReader* this, text_Buffer__Buffer* buffer) {
    ((text_Buffer__BufferReaderClass *)((lang_types__Object *)this)->class)->init_withBuffer((text_Buffer__BufferReader*)this, buffer);
}

text_Buffer__Buffer* text_Buffer__BufferReader_buffer(text_Buffer__BufferReader* this) {
    return (text_Buffer__Buffer*) ((text_Buffer__BufferReaderClass *)((lang_types__Object *)this)->class)->buffer((text_Buffer__BufferReader*)this);
}

lang_types__SizeT text_Buffer__BufferReader_read(text_Buffer__BufferReader* this, lang_types__String chars, lang_types__Int offset, lang_types__Int count) {
    return (lang_types__SizeT) ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->read((io_Reader__Reader*)this, chars, offset, count);
}

lang_types__Char text_Buffer__BufferReader_read_char(text_Buffer__BufferReader* this) {
    return (lang_types__Char) ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->read_char((io_Reader__Reader*)this);
}

lang_types__Bool text_Buffer__BufferReader_hasNext(text_Buffer__BufferReader* this) {
    return (lang_types__Bool) ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->hasNext((io_Reader__Reader*)this);
}

void text_Buffer__BufferReader_rewind(text_Buffer__BufferReader* this, lang_types__Int offset) {
    ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->rewind((io_Reader__Reader*)this, offset);
}

lang_types__Long text_Buffer__BufferReader_mark(text_Buffer__BufferReader* this) {
    return (lang_types__Long) ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->mark((io_Reader__Reader*)this);
}

void text_Buffer__BufferReader_reset(text_Buffer__BufferReader* this, lang_types__Long marker) {
    ((io_Reader__ReaderClass *)((lang_types__Object *)this)->class)->reset((io_Reader__Reader*)this, marker);
}
text_Buffer__BufferReader* text_Buffer__BufferReader_new() {
    
    text_Buffer__BufferReader* this = ((text_Buffer__BufferReader*) (lang_types__Class_alloc__class((lang_types__Class*) text_Buffer__BufferReader_class())));
    lang_types__Object___defaults__((lang_types__Object*) this);
    text_Buffer__BufferReader_init(this);
    return this;
}
text_Buffer__BufferReader* text_Buffer__BufferReader_new_withBuffer(text_Buffer__Buffer* buffer) {
    
    text_Buffer__BufferReader* this = ((text_Buffer__BufferReader*) (lang_types__Class_alloc__class((lang_types__Class*) text_Buffer__BufferReader_class())));
    lang_types__Object___defaults__((lang_types__Object*) this);
    text_Buffer__BufferReader_init_withBuffer(this, buffer);
    return this;
}

text_Buffer__BufferReaderClass *text_Buffer__BufferReader_class(){
    static lang_types__Bool __done__ = false;
    static text_Buffer__BufferReaderClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(text_Buffer__BufferReader),
                        .size = sizeof(void*),
                        .name = "BufferReader",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
            .init = (void (*)(io_Reader__Reader*)) text_Buffer__BufferReader_init_impl,
            .read = (lang_types__SizeT (*)(io_Reader__Reader*, lang_types__String, lang_types__Int, lang_types__Int)) text_Buffer__BufferReader_read_impl,
            .read_char = (lang_types__Char (*)(io_Reader__Reader*)) text_Buffer__BufferReader_read_char_impl,
            .readUntil = (lang_types__String (*)(io_Reader__Reader*, lang_types__Char)) io_Reader__Reader_readUntil_impl,
            .readLine = (lang_types__String (*)(io_Reader__Reader*)) io_Reader__Reader_readLine_impl,
            .peek = (lang_types__Char (*)(io_Reader__Reader*)) io_Reader__Reader_peek_impl,
            .skipWhile = (void (*)(io_Reader__Reader*, lang_types__Char)) io_Reader__Reader_skipWhile_impl,
            .hasNext = (lang_types__Bool (*)(io_Reader__Reader*)) text_Buffer__BufferReader_hasNext_impl,
            .rewind = (void (*)(io_Reader__Reader*, lang_types__Int)) text_Buffer__BufferReader_rewind_impl,
            .mark = (lang_types__Long (*)(io_Reader__Reader*)) text_Buffer__BufferReader_mark_impl,
            .reset = (void (*)(io_Reader__Reader*, lang_types__Long)) text_Buffer__BufferReader_reset_impl,
            .skip = (void (*)(io_Reader__Reader*, lang_types__Int)) io_Reader__Reader_skip_impl,
        },
        .new = text_Buffer__BufferReader_new,
        .new_withBuffer = text_Buffer__BufferReader_new_withBuffer,
        .init_withBuffer = text_Buffer__BufferReader_init_withBuffer_impl,
        .buffer = text_Buffer__BufferReader_buffer_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) io_Reader__Reader_class();
        __done__ = true;
    }
    return &class;
}
void text_Buffer_load() {
    static bool __done__ = false;
    if (!__done__){
        __done__ = true;
        lang_stdio_load();
        lang_types_load();
        lang_memory_load();
        lang_system_load();
        lang_string_load();
        lang_vararg_load();
        io_Writer_load();
        io_Reader_load();
    }
}

