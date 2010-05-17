/* math/Relation header file, generated with rock, the ooc compiler written in ooc */

#ifndef ___math_Relation___
#define ___math_Relation___

#include "Relation-fwd.h"

#include <sdk/lang/types.h>

struct _math_Relation__Relation {
    struct _lang_types__Object __super__;
    lang_types__Int a;
    lang_types__Int b;
};


struct _math_Relation__RelationClass {
    struct _lang_types__ClassClass __super__;
    math_Relation__Relation* (*new)(lang_types__Int, lang_types__Int);
    void (*init)(math_Relation__Relation*, lang_types__Int, lang_types__Int);
};



#endif // ___math_Relation___
