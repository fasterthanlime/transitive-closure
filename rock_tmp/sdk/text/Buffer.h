/* text/Buffer header file, generated with rock, the ooc compiler written in ooc */

#ifndef ___text_Buffer___
#define ___text_Buffer___

#include "Buffer-fwd.h"

#include <sdk/lang/types.h>
#include <sdk/io/Writer.h>
#include <sdk/io/Reader.h>

struct _text_Buffer__Buffer {
    struct _lang_types__Object __super__;
    lang_types__SizeT size;
    lang_types__SizeT capacity;
    lang_types__Char* data;
};


struct _text_Buffer__BufferWriter {
    struct _io_Writer__Writer __super__;
    text_Buffer__Buffer* buffer;
};


struct _text_Buffer__BufferReader {
    struct _io_Reader__Reader __super__;
    text_Buffer__Buffer* buffer;
};


struct _text_Buffer__BufferClass {
    struct _lang_types__ClassClass __super__;
    text_Buffer__Buffer* (*new)();
    void (*init)(text_Buffer__Buffer*);
    text_Buffer__Buffer* (*new_withCapa)(lang_types__SizeT);
    void (*init_withCapa)(text_Buffer__Buffer*, lang_types__SizeT);
    text_Buffer__Buffer* (*new_withContent)(lang_types__String);
    void (*init_withContent)(text_Buffer__Buffer*, lang_types__String);
    void (*append_str)(text_Buffer__Buffer*, lang_types__String);
    void (*append_strWithLength)(text_Buffer__Buffer*, lang_types__String, lang_types__SizeT);
    void (*append_chr)(text_Buffer__Buffer*, lang_types__Char);
    lang_types__Int (*get_strWithLengthOffset)(text_Buffer__Buffer*, lang_types__Char*, lang_types__SizeT, lang_types__SizeT);
    lang_types__Char (*get_chr)(text_Buffer__Buffer*, lang_types__Int);
    void (*checkLength)(text_Buffer__Buffer*, lang_types__SizeT);
    lang_types__String (*toString)(text_Buffer__Buffer*);
};


struct _text_Buffer__BufferWriterClass {
    struct _io_Writer__WriterClass __super__;
    text_Buffer__BufferWriter* (*new)();
    text_Buffer__BufferWriter* (*new_withBuffer)(text_Buffer__Buffer*);
    void (*init_withBuffer)(text_Buffer__BufferWriter*, text_Buffer__Buffer*);
    text_Buffer__Buffer* (*buffer)(text_Buffer__BufferWriter*);
};


struct _text_Buffer__BufferReaderClass {
    struct _io_Reader__ReaderClass __super__;
    text_Buffer__BufferReader* (*new)();
    text_Buffer__BufferReader* (*new_withBuffer)(text_Buffer__Buffer*);
    void (*init_withBuffer)(text_Buffer__BufferReader*, text_Buffer__Buffer*);
    text_Buffer__Buffer* (*buffer)(text_Buffer__BufferReader*);
};



#endif // ___text_Buffer___
