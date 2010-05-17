/* structs/ArrayList header file, generated with rock, the ooc compiler written in ooc */

#ifndef ___structs_ArrayList___
#define ___structs_ArrayList___

#include "ArrayList-fwd.h"

#include <sdk/lang/types.h>
#include <sdk/structs/List.h>

struct _structs_ArrayList__ArrayList {
    struct _structs_List__List __super__;
    uint8_t* data;
    lang_types__Int capacity;
    lang_types__Int size;
};


struct _structs_ArrayList__ArrayListIterator {
    struct _lang_types__Iterator __super__;
    structs_ArrayList__ArrayList* list;
    lang_types__Int index;
};


struct _structs_ArrayList__ArrayListClass {
    struct _structs_List__ListClass __super__;
    structs_ArrayList__ArrayList* (*new)(lang_types__Class*);
    structs_ArrayList__ArrayList* (*new_withCapacity)(lang_types__Class*, lang_types__Int);
    void (*init_withCapacity)(structs_ArrayList__ArrayList*, lang_types__Int);
    structs_ArrayList__ArrayList* (*new_withData)(lang_types__Class*, uint8_t*, lang_types__Int);
    void (*init_withData)(structs_ArrayList__ArrayList*, uint8_t*, lang_types__Int);
    void (*ensureCapacity)(structs_ArrayList__ArrayList*, lang_types__Int);
    void (*grow)(structs_ArrayList__ArrayList*);
    void (*checkIndex)(structs_ArrayList__ArrayList*, lang_types__Int);
    void (*__defaults__)(structs_ArrayList__ArrayList*);
};


struct _structs_ArrayList__ArrayListIteratorClass {
    struct _lang_types__IteratorClass __super__;
    structs_ArrayList__ArrayListIterator* (*new_iter)(lang_types__Class*, structs_ArrayList__ArrayList*);
    void (*init_iter)(structs_ArrayList__ArrayListIterator*, structs_ArrayList__ArrayList*);
    void (*__defaults__)(structs_ArrayList__ArrayListIterator*);
};



#endif // ___structs_ArrayList___
