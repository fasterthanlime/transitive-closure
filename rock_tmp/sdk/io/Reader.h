/* io/Reader header file, generated with rock, the ooc compiler written in ooc */

#ifndef ___io_Reader___
#define ___io_Reader___

#include "Reader-fwd.h"

#include <sdk/lang/types.h>

struct _io_Reader__Reader {
    struct _lang_types__Object __super__;
    lang_types__Long marker;
};


struct _io_Reader__ReaderClass {
    struct _lang_types__ClassClass __super__;
    void (*init)(io_Reader__Reader*);
    lang_types__SizeT (*read)(io_Reader__Reader*, lang_types__String, lang_types__Int, lang_types__Int);
    lang_types__Char (*read_char)(io_Reader__Reader*);
    lang_types__String (*readUntil)(io_Reader__Reader*, lang_types__Char);
    lang_types__String (*readLine)(io_Reader__Reader*);
    lang_types__Char (*peek)(io_Reader__Reader*);
    void (*skipWhile)(io_Reader__Reader*, lang_types__Char);
    lang_types__Bool (*hasNext)(io_Reader__Reader*);
    void (*rewind)(io_Reader__Reader*, lang_types__Int);
    lang_types__Long (*mark)(io_Reader__Reader*);
    void (*reset)(io_Reader__Reader*, lang_types__Long);
    void (*skip)(io_Reader__Reader*, lang_types__Int);
};



#endif // ___io_Reader___
