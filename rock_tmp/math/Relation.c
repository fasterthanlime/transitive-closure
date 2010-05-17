/* math/Relation source file, generated with rock, the ooc compiler written in ooc */

#include "Relation.h"

#include <sdk/lang/stdio.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/system.h>
#include <sdk/lang/string.h>
#include <sdk/lang/vararg.h>


void math_Relation__Relation_init_impl(math_Relation__Relation* this, lang_types__Int a, lang_types__Int b) {
    this->b = b;
    this->a = a;
}

void math_Relation__Relation_init(math_Relation__Relation* this, lang_types__Int a, lang_types__Int b) {
    ((math_Relation__RelationClass *)((lang_types__Object *)this)->class)->init((math_Relation__Relation*)this, a, b);
}
math_Relation__Relation* math_Relation__Relation_new(lang_types__Int a, lang_types__Int b) {
    
    math_Relation__Relation* this = ((math_Relation__Relation*) (lang_types__Class_alloc__class((lang_types__Class*) math_Relation__Relation_class())));
    lang_types__Object___defaults__((lang_types__Object*) this);
    math_Relation__Relation_init(this, a, b);
    return this;
}

math_Relation__RelationClass *math_Relation__Relation_class(){
    static lang_types__Bool __done__ = false;
    static math_Relation__RelationClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(math_Relation__Relation),
                    .size = sizeof(void*),
                    .name = "Relation",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
        .new = math_Relation__Relation_new,
        .init = math_Relation__Relation_init_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Object_class();
        __done__ = true;
    }
    return &class;
}
void math_Relation_load() {
    static bool __done__ = false;
    if (!__done__){
        __done__ = true;
        lang_stdio_load();
        lang_types_load();
        lang_memory_load();
        lang_system_load();
        lang_string_load();
        lang_vararg_load();
    }
}


math_Relation__Relation* math_Relation__rel(lang_types__Int a, lang_types__Int b) {
    return math_Relation__Relation_new(a, b);
}
