/* hw4 source file, generated with rock, the ooc compiler written in ooc */

#include "hw4.h"

#include <sdk/lang/stdio.h>
#include <sdk/lang/types.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/system.h>
#include <sdk/lang/string.h>
#include <sdk/lang/vararg.h>
#include <./math/Matrix.h>
#include <./math/Relation.h>

lang_types__Int hw4__a;
lang_types__Int hw4__b;
lang_types__Int hw4__c;
lang_types__Int hw4__d;
lang_types__Int hw4__e;
_lang_array__Array hw4__rels1;
math_Matrix__Matrix* hw4__m;
void hw4_load() {
    static bool __done__ = false;
    if (!__done__){
        __done__ = true;
        lang_stdio_load();
        lang_types_load();
        lang_memory_load();
        lang_system_load();
        lang_string_load();
        lang_vararg_load();
        math_Matrix_load();
        math_Relation_load();
        hw4__a = 0;
        hw4__b = 1;
        hw4__c = 2;
        hw4__d = 3;
        hw4__e = 4;
        hw4__rels1 = _lang_array__Array_new(math_Relation__Relation*, 5);
        
        {
            math_Relation__Relation** __ptrLit29 = (math_Relation__Relation*[]) { math_Relation__rel(hw4__a, hw4__d), math_Relation__rel(hw4__b, hw4__c), math_Relation__rel(hw4__c, hw4__b), math_Relation__rel(hw4__d, hw4__a), math_Relation__rel(hw4__e, hw4__a) };
            memcpy(hw4__rels1.data, __ptrLit29, 5 * ((lang_types__Class*) math_Relation__Relation_class())->size);
        }
        hw4__m = math_Matrix__Matrix_new_rels(hw4__rels1);
        lang_types__String_println(math_Matrix__Matrix_toString(hw4__m));
        lang_types__String_println("---------------------");
        lang_types__String_println(math_Matrix__Matrix_toString(math_Matrix__Matrix_transitiveClosure(hw4__m)));
    }
}


int main() {
    GC_INIT();
    hw4_load();
}

