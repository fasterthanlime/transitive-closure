/* io/Writer header file, generated with rock, the ooc compiler written in ooc */

#ifndef ___io_Writer___
#define ___io_Writer___

#include "Writer-fwd.h"

#include <sdk/lang/types.h>

struct _io_Writer__Writer {
    struct _lang_types__Object __super__;
};


struct _io_Writer__WriterClass {
    struct _lang_types__ClassClass __super__;
    void (*init)(io_Writer__Writer*);
    void (*close)(io_Writer__Writer*);
    void (*write_chr)(io_Writer__Writer*, lang_types__Char);
    lang_types__SizeT (*write)(io_Writer__Writer*, lang_types__String, lang_types__SizeT);
    lang_types__SizeT (*write_implicitLength)(io_Writer__Writer*, lang_types__String);
    lang_types__SizeT (*write_fromReader)(io_Writer__Writer*, io_Reader__Reader*, lang_types__SizeT);
    void (*write_fromReaderDefaultBufferSize)(io_Writer__Writer*, io_Reader__Reader*);
};



#endif // ___io_Writer___
