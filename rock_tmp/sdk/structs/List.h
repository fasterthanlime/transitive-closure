/* structs/List header file, generated with rock, the ooc compiler written in ooc */

#ifndef ___structs_List___
#define ___structs_List___

#include "List-fwd.h"

#include <sdk/lang/types.h>

struct _structs_List__List {
    struct _lang_types__Iterable __super__;
};


struct _structs_List__ListClass {
    struct _lang_types__IterableClass __super__;
    void (*add)(structs_List__List*, uint8_t*);
    void (*add_withIndex)(structs_List__List*, lang_types__Int, uint8_t*);
    void (*addAll)(structs_List__List*, lang_types__Iterable*);
    void (*addAll_atStart)(structs_List__List*, lang_types__Int, lang_types__Iterable*);
    void (*clear)(structs_List__List*);
    lang_types__Bool (*removeLast)(structs_List__List*);
    lang_types__Bool (*contains)(structs_List__List*, uint8_t*);
    lang_types__Bool (*replace)(structs_List__List*, uint8_t*, uint8_t*);
    void (*get)(structs_List__List*, uint8_t*, lang_types__Int);
    lang_types__Int (*indexOf)(structs_List__List*, uint8_t*);
    lang_types__Bool (*isEmpty)(structs_List__List*);
    lang_types__Int (*lastIndexOf)(structs_List__List*, uint8_t*);
    void (*removeAt)(structs_List__List*, uint8_t*, lang_types__Int);
    lang_types__Bool (*remove)(structs_List__List*, uint8_t*);
    void (*set)(structs_List__List*, uint8_t*, lang_types__Int, uint8_t*);
    lang_types__Int (*size)(structs_List__List*);
    structs_List__List* (*clone)(structs_List__List*);
    void (*first)(structs_List__List*, uint8_t*);
    void (*last)(structs_List__List*, uint8_t*);
    lang_types__Int (*lastIndex)(structs_List__List*);
    void (*reverse)(structs_List__List*);
    lang_types__Pointer (*toArray)(structs_List__List*);
    void (*each)(structs_List__List*, __FUNC___T);
    lang_types__String (*join_string)(structs_List__List*, lang_types__String);
    lang_types__String (*join_char)(structs_List__List*, lang_types__Char);
};



#endif // ___structs_List___
