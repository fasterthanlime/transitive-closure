/* lang/stdio header file, generated with rock, the ooc compiler written in ooc */

#ifndef ___lang_stdio___
#define ___lang_stdio___

#include "stdio-fwd.h"

#include <sdk/lang/types.h>

struct _lang_stdio__FILEClass {
    struct _lang_types__ClassClass __super__;
};


struct _lang_stdio__FStreamClass {
    struct _lang_types__ClassClass __super__;
    lang_stdio__FStream (*open)(lang_types__String, lang_types__String);
    lang_types__Int (*close)(lang_stdio__FStream);
    void (*flush)(lang_stdio__FStream);
    lang_types__Char (*readChar)(lang_stdio__FStream);
    lang_types__String (*readLine)(lang_stdio__FStream);
    lang_types__Bool (*hasNext)(lang_stdio__FStream);
    void (*write_chr)(lang_stdio__FStream, lang_types__Char);
    void (*write)(lang_stdio__FStream, lang_types__String);
    lang_types__SizeT (*write_precise)(lang_stdio__FStream, lang_types__Char*, lang_types__SizeT, lang_types__SizeT);
};



#endif // ___lang_stdio___
