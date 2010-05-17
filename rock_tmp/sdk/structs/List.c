/* structs/List source file, generated with rock, the ooc compiler written in ooc */

#include "List.h"

#include <sdk/lang/stdio.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/system.h>
#include <sdk/lang/string.h>
#include <sdk/lang/vararg.h>
#include <sdk/text/Buffer.h>


void structs_List__List_init_impl(structs_List__List* this) {
    lang_types__Iterable_init_impl((lang_types__Iterable*) this);
}

void structs_List__List_addAll_impl(structs_List__List* this, lang_types__Iterable* list) {
    structs_List__List_addAll_atStart(this, 0, list);
}

void structs_List__List_addAll_atStart_impl(structs_List__List* this, lang_types__Int start, lang_types__Iterable* list) {
    if (start == 0) {
        
        {
            uint8_t* element = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
            
            {
                lang_types__Iterator* __iter7 = lang_types__Iterable_iterator(list);
                while (lang_types__Iterator_hasNext(__iter7)) {
                    lang_types__Iterator_next(__iter7, element);
                    structs_List__List_add(this, (uint8_t*) element);
                }
            }
        }
        return;
    }
    lang_types__Int index = 0;
    lang_types__Iterator* iter = lang_types__Iterable_iterator(list);
    while (index < start) {
        lang_types__Iterator_next(iter, NULL);
        index += 1;
    }
    while (lang_types__Iterator_hasNext(iter)) {
        uint8_t* __genCall19 = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
        structs_List__List_add(this, (uint8_t*) (lang_types__Iterator_next(iter, __genCall19), __genCall19));
    }
}

lang_types__Bool structs_List__List_removeLast_impl(structs_List__List* this) {
    lang_types__Int size = structs_List__List_size(this);
    if (size > 0) {
        structs_List__List_removeAt(this, NULL, size - 1);
        return true;
    }
    return false;
}

lang_types__Bool structs_List__List_contains_impl(structs_List__List* this, uint8_t* element) {
    return structs_List__List_indexOf(this, (uint8_t*) element) != -1;
}

lang_types__Bool structs_List__List_replace_impl(structs_List__List* this, uint8_t* oldie, uint8_t* kiddo) {
    lang_types__Int idx = structs_List__List_indexOf(this, (uint8_t*) oldie);
    if (idx == -1) {
        return false;
    }
    structs_List__List_set(this, NULL, idx, (uint8_t*) kiddo);
    return true;
}

lang_types__Bool structs_List__List_isEmpty_impl(structs_List__List* this) {
    return (structs_List__List_size(this) == 0);
}

void structs_List__List_first_impl(structs_List__List* this, uint8_t* __returnArg3) {
    uint8_t* __genCall2 = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
    uint8_t* __returnVal4 = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
    memcpy(__returnVal4, (structs_List__List_get(this, __genCall2, 0), __genCall2), ((lang_types__Iterable*) this)->T->size);
    if (__returnArg3) {
        memcpy(__returnArg3, __returnVal4, ((lang_types__Iterable*) this)->T->size);
    }
    return;
}

void structs_List__List_last_impl(structs_List__List* this, uint8_t* __returnArg9) {
    uint8_t* __genCall8 = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
    uint8_t* __returnVal10 = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
    memcpy(__returnVal10, (structs_List__List_get(this, __genCall8, structs_List__List_lastIndex(this)), __genCall8), ((lang_types__Iterable*) this)->T->size);
    if (__returnArg9) {
        memcpy(__returnArg9, __returnVal10, ((lang_types__Iterable*) this)->T->size);
    }
    return;
}

lang_types__Int structs_List__List_lastIndex_impl(structs_List__List* this) {
    return structs_List__List_size(this) - 1;
}

void structs_List__List_reverse_impl(structs_List__List* this) {
    lang_types__Int i = 0;
    lang_types__Int j = structs_List__List_size(this) - 1;
    while (i <= j / 2) {
        uint8_t* __genCall5 = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
        uint8_t* __genCall6 = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
        structs_List__List_set(this, NULL, i, (uint8_t*) (structs_List__List_set(this, __genCall6, j, (uint8_t*) (structs_List__List_get(this, __genCall5, i), __genCall5)), __genCall6));
        i += 1;
        j -= 1;
    }
}

lang_types__Pointer structs_List__List_toArray_impl(structs_List__List* this) {
    uint8_t* arr = GC_MALLOC(structs_List__List_size(this) * ((lang_types__Iterable*) this)->T->size);
    
    {
        lang_types__Int i;
        for (i = 0; i < structs_List__List_size(this); i++) {
            structs_List____OP_IDX_List_Int__T(&(arr[i * ((lang_types__Iterable*) this)->T->size]), (lang_types__Class*)((lang_types__Iterable*) this)->T, this, i);
        }
    }
    return ((lang_types__Pointer) (arr));
}

void structs_List__List_each_impl(structs_List__List* this, __FUNC___T f) {
    
    {
        lang_types__Int i;
        for (i = 0; i < structs_List__List_size(this); i++) {
            uint8_t* __genCall11 = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
            f((uint8_t*) (structs_List__List_get(this, __genCall11, i), __genCall11));
        }
    }
}

lang_types__String structs_List__List_join_string_impl(structs_List__List* this, lang_types__String str) {
    if (!lang_types__Class_inheritsFrom__class(((lang_types__Iterable*) this)->T, (lang_types__Class*) (lang_types__String_class()))) {
        lang_types__Exception_throw(lang_types__Exception_new_noOrigin(lang_types__String_format("You cannot use `String join` with %s instances.", ((lang_types__Iterable*) this)->T->name)));
    }
    text_Buffer__Buffer* result = text_Buffer__Buffer_new();
    lang_types__Bool first = true;
    
    {
        uint8_t* item = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
        
        {
            lang_types__Iterator* __iter12 = structs_List__List_iterator(this);
            while (lang_types__Iterator_hasNext(__iter12)) {
                lang_types__Iterator_next(__iter12, item);
                if (first) {
                    first = false;
                }
                else {
                    text_Buffer__Buffer_append_str(result, str);
                }
                text_Buffer__Buffer_append_str(result, (* (lang_types__String*)item));
            }
        }
    }
    return text_Buffer__Buffer_toString(result);
}

lang_types__String structs_List__List_join_char_impl(structs_List__List* this, lang_types__Char chr) {
    return structs_List__List_join_string(this, lang_types__String_new_withChar(chr));
}

void structs_List__List_init(structs_List__List* this) {
    ((lang_types__IterableClass *)((lang_types__Object *)this)->class)->init((lang_types__Iterable*)this);
}

void structs_List__List_add(structs_List__List* this, uint8_t* element) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->add((structs_List__List*)this, element);
}

void structs_List__List_add_withIndex(structs_List__List* this, lang_types__Int index, uint8_t* element) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->add_withIndex((structs_List__List*)this, index, element);
}

void structs_List__List_addAll(structs_List__List* this, lang_types__Iterable* list) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->addAll((structs_List__List*)this, list);
}

void structs_List__List_addAll_atStart(structs_List__List* this, lang_types__Int start, lang_types__Iterable* list) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->addAll_atStart((structs_List__List*)this, start, list);
}

void structs_List__List_clear(structs_List__List* this) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->clear((structs_List__List*)this);
}

lang_types__Bool structs_List__List_removeLast(structs_List__List* this) {
    return (lang_types__Bool) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->removeLast((structs_List__List*)this);
}

lang_types__Bool structs_List__List_contains(structs_List__List* this, uint8_t* element) {
    return (lang_types__Bool) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->contains((structs_List__List*)this, element);
}

lang_types__Bool structs_List__List_replace(structs_List__List* this, uint8_t* oldie, uint8_t* kiddo) {
    return (lang_types__Bool) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->replace((structs_List__List*)this, oldie, kiddo);
}

void structs_List__List_get(structs_List__List* this, uint8_t* __returnArg33, lang_types__Int index) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->get((structs_List__List*)this, __returnArg33, index);
}

lang_types__Int structs_List__List_indexOf(structs_List__List* this, uint8_t* element) {
    return (lang_types__Int) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->indexOf((structs_List__List*)this, element);
}

lang_types__Bool structs_List__List_isEmpty(structs_List__List* this) {
    return (lang_types__Bool) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->isEmpty((structs_List__List*)this);
}

lang_types__Int structs_List__List_lastIndexOf(structs_List__List* this, uint8_t* element) {
    return (lang_types__Int) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->lastIndexOf((structs_List__List*)this, element);
}

void structs_List__List_removeAt(structs_List__List* this, uint8_t* __returnArg34, lang_types__Int index) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->removeAt((structs_List__List*)this, __returnArg34, index);
}

lang_types__Bool structs_List__List_remove(structs_List__List* this, uint8_t* element) {
    return (lang_types__Bool) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->remove((structs_List__List*)this, element);
}

void structs_List__List_set(structs_List__List* this, uint8_t* __returnArg35, lang_types__Int index, uint8_t* element) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->set((structs_List__List*)this, __returnArg35, index, element);
}

lang_types__Int structs_List__List_size(structs_List__List* this) {
    return (lang_types__Int) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->size((structs_List__List*)this);
}

lang_types__Iterator* structs_List__List_iterator(structs_List__List* this) {
    return (lang_types__Iterator*) ((lang_types__IterableClass *)((lang_types__Object *)this)->class)->iterator((lang_types__Iterable*)this);
}

structs_List__List* structs_List__List_clone(structs_List__List* this) {
    return (structs_List__List*) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->clone((structs_List__List*)this);
}

void structs_List__List_first(structs_List__List* this, uint8_t* __returnArg3) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->first((structs_List__List*)this, __returnArg3);
}

void structs_List__List_last(structs_List__List* this, uint8_t* __returnArg9) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->last((structs_List__List*)this, __returnArg9);
}

lang_types__Int structs_List__List_lastIndex(structs_List__List* this) {
    return (lang_types__Int) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->lastIndex((structs_List__List*)this);
}

void structs_List__List_reverse(structs_List__List* this) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->reverse((structs_List__List*)this);
}

lang_types__Pointer structs_List__List_toArray(structs_List__List* this) {
    return (lang_types__Pointer) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->toArray((structs_List__List*)this);
}

void structs_List__List_each(structs_List__List* this, __FUNC___T f) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->each((structs_List__List*)this, f);
}

lang_types__String structs_List__List_join_string(structs_List__List* this, lang_types__String str) {
    return (lang_types__String) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->join_string((structs_List__List*)this, str);
}

lang_types__String structs_List__List_join_char(structs_List__List* this, lang_types__Char chr) {
    return (lang_types__String) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->join_char((structs_List__List*)this, chr);
}

structs_List__ListClass *structs_List__List_class(){
    static lang_types__Bool __done__ = false;
    static structs_List__ListClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(structs_List__List),
                        .size = sizeof(void*),
                        .name = "List",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
            .init = (void (*)(lang_types__Iterable*)) structs_List__List_init_impl,
            .toArrayList = (structs_ArrayList__ArrayList* (*)(lang_types__Iterable*)) lang_types__Iterable_toArrayList_impl,
        },
        .add = structs_List__List_add,
        .add_withIndex = structs_List__List_add_withIndex,
        .addAll = structs_List__List_addAll_impl,
        .addAll_atStart = structs_List__List_addAll_atStart_impl,
        .clear = structs_List__List_clear,
        .removeLast = structs_List__List_removeLast_impl,
        .contains = structs_List__List_contains_impl,
        .replace = structs_List__List_replace_impl,
        .get = structs_List__List_get,
        .indexOf = structs_List__List_indexOf,
        .isEmpty = structs_List__List_isEmpty_impl,
        .lastIndexOf = structs_List__List_lastIndexOf,
        .removeAt = structs_List__List_removeAt,
        .remove = structs_List__List_remove,
        .set = structs_List__List_set,
        .size = structs_List__List_size,
        .clone = structs_List__List_clone,
        .first = structs_List__List_first_impl,
        .last = structs_List__List_last_impl,
        .lastIndex = structs_List__List_lastIndex_impl,
        .reverse = structs_List__List_reverse_impl,
        .toArray = structs_List__List_toArray_impl,
        .each = structs_List__List_each_impl,
        .join_string = structs_List__List_join_string_impl,
        .join_char = structs_List__List_join_char_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Iterable_class();
        __done__ = true;
    }
    return &class;
}
void structs_List_load() {
    static bool __done__ = false;
    if (!__done__){
        __done__ = true;
        lang_stdio_load();
        lang_types_load();
        lang_memory_load();
        lang_system_load();
        lang_string_load();
        lang_vararg_load();
        text_Buffer_load();
    }
}


void structs_List____OP_IDX_List_Int__T(uint8_t* __returnArg21, lang_types__Class* T, structs_List__List* list, lang_types__Int i) {
    uint8_t* __genCall20 = GC_MALLOC(T->size);
    uint8_t* __returnVal22 = GC_MALLOC(T->size);
    memcpy(__returnVal22, (structs_List__List_get(list, __genCall20, i), __genCall20), T->size);
    if (__returnArg21) {
        memcpy(__returnArg21, __returnVal22, T->size);
    }
    return;
}

void structs_List____OP_IDX_ASS_List_Int_T(lang_types__Class* T, structs_List__List* list, lang_types__Int i, uint8_t* element) {
    structs_List__List_set(list, NULL, i, (uint8_t*) element);
}

void structs_List____OP_ADD_ASS_List_T(lang_types__Class* T, structs_List__List* list, uint8_t* element) {
    structs_List__List_add(list, (uint8_t*) element);
}

lang_types__Bool structs_List____OP_SUB_ASS_List_T__Bool(lang_types__Class* T, structs_List__List* list, uint8_t* element) {
    return structs_List__List_remove(list, (uint8_t*) element);
}
