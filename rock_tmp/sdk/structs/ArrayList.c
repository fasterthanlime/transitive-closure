/* structs/ArrayList source file, generated with rock, the ooc compiler written in ooc */

#include "ArrayList.h"

#include <sdk/lang/stdio.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/system.h>
#include <sdk/lang/string.h>
#include <sdk/lang/vararg.h>


void structs_ArrayList__ArrayList_init_impl(structs_ArrayList__ArrayList* this) {
    structs_ArrayList__ArrayList_init_withCapacity(this, 10);
}

void structs_ArrayList__ArrayList_init_withCapacity_impl(structs_ArrayList__ArrayList* this, lang_types__Int capacity) {
    this->capacity = capacity;
    this->data = (void*) GC_MALLOC(capacity * ((lang_types__Iterable*) this)->T->size);
}

void structs_ArrayList__ArrayList_init_withData_impl(structs_ArrayList__ArrayList* this, uint8_t* data, lang_types__Int size) {
    this->size = size;
    this->data = (void*) GC_MALLOC(size * ((lang_types__Iterable*) this)->T->size);
    memcpy(this->data, data, size * ((lang_types__Iterable*) this)->T->size);
    this->capacity = size;
}

void structs_ArrayList__ArrayList_add_impl(structs_ArrayList__ArrayList* this, uint8_t* element) {
    structs_ArrayList__ArrayList_ensureCapacity(this, this->size + 1);
    memcpy(&(this->data[this->size * ((lang_types__Iterable*) this)->T->size]), element, ((lang_types__Iterable*) this)->T->size);
    this->size += 1;
}

void structs_ArrayList__ArrayList_add_withIndex_impl(structs_ArrayList__ArrayList* this, lang_types__Int index, uint8_t* element) {
    if (index == 0) {
        structs_ArrayList__ArrayList_ensureCapacity(this, this->size + 1);
        lang_types__Octet* dst;
        lang_types__Octet* src;
        dst = (void*) this->data + (((lang_types__Iterable*) this)->T->size);
        src = (void*) this->data;
        memmove(dst, src, ((lang_types__Iterable*) this)->T->size * this->size);
        memcpy(&(this->data[0 * ((lang_types__Iterable*) this)->T->size]), element, ((lang_types__Iterable*) this)->T->size);
        this->size += 1;
        return;
    }
    if (index == this->size) {
        structs_ArrayList__ArrayList_add(this, (uint8_t*) element);
        return;
    }
    structs_ArrayList__ArrayList_checkIndex(this, index);
    structs_ArrayList__ArrayList_ensureCapacity(this, this->size + 1);
    lang_types__Octet* dst;
    lang_types__Octet* src;
    dst = (void*) this->data + (((lang_types__Iterable*) this)->T->size * (index + 1));
    src = (void*) this->data + (((lang_types__Iterable*) this)->T->size * index);
    lang_types__Int bsize = (this->size - index) * ((lang_types__Iterable*) this)->T->size;
    memmove(dst, src, bsize);
    memcpy(&(this->data[index * ((lang_types__Iterable*) this)->T->size]), element, ((lang_types__Iterable*) this)->T->size);
    this->size += 1;
}

void structs_ArrayList__ArrayList_clear_impl(structs_ArrayList__ArrayList* this) {
    this->size = 0;
}

void structs_ArrayList__ArrayList_get_impl(structs_ArrayList__ArrayList* this, uint8_t* __returnArg23, lang_types__Int index) {
    structs_ArrayList__ArrayList_checkIndex(this, index);
    if (__returnArg23) {
        memcpy(__returnArg23, &(this->data[index * ((lang_types__Iterable*) this)->T->size]), ((lang_types__Iterable*) this)->T->size);
    }
    return;
}

lang_types__Int structs_ArrayList__ArrayList_indexOf_impl(structs_ArrayList__ArrayList* this, uint8_t* element) {
    lang_types__Int index = 0;
    while (index < this->size) {
        uint8_t* candidate = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
        memcpy(candidate, &(this->data[index * ((lang_types__Iterable*) this)->T->size]), ((lang_types__Iterable*) this)->T->size);
        if (memcmp(candidate, element, ((lang_types__Iterable*) this)->T->size) == 0) {
            return index;
        }
        index += 1;
    }
    return -1;
}

lang_types__Int structs_ArrayList__ArrayList_lastIndexOf_impl(structs_ArrayList__ArrayList* this, uint8_t* element) {
    lang_types__Int index = this->size;
    while (index > -1) {
        uint8_t* candidate = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
        memcpy(candidate, &(this->data[index * ((lang_types__Iterable*) this)->T->size]), ((lang_types__Iterable*) this)->T->size);
        if (memcmp(candidate, element, ((lang_types__Iterable*) this)->T->size) == 0) {
            return index;
        }
        index -= 1;
    }
    return -1;
}

void structs_ArrayList__ArrayList_removeAt_impl(structs_ArrayList__ArrayList* this, uint8_t* __returnArg24, lang_types__Int index) {
    uint8_t* element = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
    memcpy(element, &(this->data[index * ((lang_types__Iterable*) this)->T->size]), ((lang_types__Iterable*) this)->T->size);
    memmove(this->data + (index * ((lang_types__Iterable*) this)->T->size), this->data + ((index + 1) * ((lang_types__Iterable*) this)->T->size), (this->size - index) * ((lang_types__Iterable*) this)->T->size);
    this->size -= 1;
    if (__returnArg24) {
        memcpy(__returnArg24, element, ((lang_types__Iterable*) this)->T->size);
    }
    return;
}

lang_types__Bool structs_ArrayList__ArrayList_remove_impl(structs_ArrayList__ArrayList* this, uint8_t* element) {
    lang_types__Int index = structs_ArrayList__ArrayList_indexOf(this, (uint8_t*) element);
    if (index == -1) {
        return false;
    }
    else {
        structs_ArrayList__ArrayList_removeAt(this, NULL, index);
    }
    return true;
}

void structs_ArrayList__ArrayList_set_impl(structs_ArrayList__ArrayList* this, uint8_t* __returnArg25, lang_types__Int index, uint8_t* element) {
    structs_ArrayList__ArrayList_checkIndex(this, index);
    uint8_t* old = GC_MALLOC(((lang_types__Iterable*) this)->T->size);
    memcpy(old, &(this->data[index * ((lang_types__Iterable*) this)->T->size]), ((lang_types__Iterable*) this)->T->size);
    memcpy(&(this->data[index * ((lang_types__Iterable*) this)->T->size]), element, ((lang_types__Iterable*) this)->T->size);
    if (__returnArg25) {
        memcpy(__returnArg25, old, ((lang_types__Iterable*) this)->T->size);
    }
    return;
}

lang_types__Int structs_ArrayList__ArrayList_size_impl(structs_ArrayList__ArrayList* this) {
    return this->size;
}

void structs_ArrayList__ArrayList_ensureCapacity_impl(structs_ArrayList__ArrayList* this, lang_types__Int newSize) {
    while (newSize > this->capacity) {
        structs_ArrayList__ArrayList_grow(this);
    }
}

void structs_ArrayList__ArrayList_grow_impl(structs_ArrayList__ArrayList* this) {
    this->capacity = this->capacity * 1.100000 + 10;
    lang_types__Pointer tmpData = GC_REALLOC(this->data, this->capacity * ((lang_types__Iterable*) this)->T->size);
    if (tmpData) {
        this->data = (void*) tmpData;
    }
    else {
        printf("Failed to allocate %zu bytes of memory for array to grow! Exiting..\n", this->capacity * ((lang_types__Iterable*) this)->T->size);
        lang_types__Int x = 0;
        x = 1 / x;
    }
}

void structs_ArrayList__ArrayList_checkIndex_impl(structs_ArrayList__ArrayList* this, lang_types__Int index) {
    if (index < 0) {
        lang_types__Exception_throw(lang_types__Exception_new_originMsg((lang_types__Class*) (structs_ArrayList__ArrayList_class()), lang_types____OP_ADD_String_String__String(lang_types____OP_ADD_String_LLong__String("Index too small! ", (lang_types__LLong) (index)), " < 0")));
    }
    if (index >= this->size) {
        lang_types__Exception_throw(lang_types__Exception_new_originMsg((lang_types__Class*) (structs_ArrayList__ArrayList_class()), lang_types____OP_ADD_String_LLong__String(lang_types____OP_ADD_String_String__String(lang_types____OP_ADD_String_LLong__String("Index too big! ", (lang_types__LLong) (index)), " >= "), (lang_types__LLong) (structs_ArrayList__ArrayList_size(this)))));
    }
}

lang_types__Iterator* structs_ArrayList__ArrayList_iterator_impl(structs_ArrayList__ArrayList* this) {
    return ((lang_types__Iterator*) (structs_ArrayList__ArrayListIterator_new_iter((lang_types__Class*)((lang_types__Iterable*) this)->T, this)));
}

structs_ArrayList__ArrayList* structs_ArrayList__ArrayList_clone_impl(structs_ArrayList__ArrayList* this) {
    structs_ArrayList__ArrayList* copy = structs_ArrayList__ArrayList_new_withCapacity((lang_types__Class*)((lang_types__Iterable*) this)->T, structs_ArrayList__ArrayList_size(this));
    structs_List__List_addAll((structs_List__List*) copy, (lang_types__Iterable*) (this));
    return copy;
}

lang_types__Pointer structs_ArrayList__ArrayList_toArray_impl(structs_ArrayList__ArrayList* this) {
    return ((lang_types__Pointer) (this->data));
}

void structs_ArrayList__ArrayList___defaults___impl(structs_ArrayList__ArrayList* this) {lang_types__Object___defaults___impl((lang_types__Object*) this);
    this->size = 0;
}

void structs_ArrayList__ArrayList_init(structs_ArrayList__ArrayList* this) {
    ((lang_types__IterableClass *)((lang_types__Object *)this)->class)->init((lang_types__Iterable*)this);
}

void structs_ArrayList__ArrayList_init_withCapacity(structs_ArrayList__ArrayList* this, lang_types__Int capacity) {
    ((structs_ArrayList__ArrayListClass *)((lang_types__Object *)this)->class)->init_withCapacity((structs_ArrayList__ArrayList*)this, capacity);
}

void structs_ArrayList__ArrayList_init_withData(structs_ArrayList__ArrayList* this, uint8_t* data, lang_types__Int size) {
    ((structs_ArrayList__ArrayListClass *)((lang_types__Object *)this)->class)->init_withData((structs_ArrayList__ArrayList*)this, data, size);
}

void structs_ArrayList__ArrayList_add(structs_ArrayList__ArrayList* this, uint8_t* element) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->add((structs_List__List*)this, element);
}

void structs_ArrayList__ArrayList_add_withIndex(structs_ArrayList__ArrayList* this, lang_types__Int index, uint8_t* element) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->add_withIndex((structs_List__List*)this, index, element);
}

void structs_ArrayList__ArrayList_clear(structs_ArrayList__ArrayList* this) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->clear((structs_List__List*)this);
}

void structs_ArrayList__ArrayList_get(structs_ArrayList__ArrayList* this, uint8_t* __returnArg23, lang_types__Int index) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->get((structs_List__List*)this, __returnArg23, index);
}

lang_types__Int structs_ArrayList__ArrayList_indexOf(structs_ArrayList__ArrayList* this, uint8_t* element) {
    return (lang_types__Int) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->indexOf((structs_List__List*)this, element);
}

lang_types__Int structs_ArrayList__ArrayList_lastIndexOf(structs_ArrayList__ArrayList* this, uint8_t* element) {
    return (lang_types__Int) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->lastIndexOf((structs_List__List*)this, element);
}

void structs_ArrayList__ArrayList_removeAt(structs_ArrayList__ArrayList* this, uint8_t* __returnArg24, lang_types__Int index) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->removeAt((structs_List__List*)this, __returnArg24, index);
}

lang_types__Bool structs_ArrayList__ArrayList_remove(structs_ArrayList__ArrayList* this, uint8_t* element) {
    return (lang_types__Bool) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->remove((structs_List__List*)this, element);
}

void structs_ArrayList__ArrayList_set(structs_ArrayList__ArrayList* this, uint8_t* __returnArg25, lang_types__Int index, uint8_t* element) {
    ((structs_List__ListClass *)((lang_types__Object *)this)->class)->set((structs_List__List*)this, __returnArg25, index, element);
}

lang_types__Int structs_ArrayList__ArrayList_size(structs_ArrayList__ArrayList* this) {
    return (lang_types__Int) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->size((structs_List__List*)this);
}

void structs_ArrayList__ArrayList_ensureCapacity(structs_ArrayList__ArrayList* this, lang_types__Int newSize) {
    ((structs_ArrayList__ArrayListClass *)((lang_types__Object *)this)->class)->ensureCapacity((structs_ArrayList__ArrayList*)this, newSize);
}

void structs_ArrayList__ArrayList_grow(structs_ArrayList__ArrayList* this) {
    ((structs_ArrayList__ArrayListClass *)((lang_types__Object *)this)->class)->grow((structs_ArrayList__ArrayList*)this);
}

void structs_ArrayList__ArrayList_checkIndex(structs_ArrayList__ArrayList* this, lang_types__Int index) {
    ((structs_ArrayList__ArrayListClass *)((lang_types__Object *)this)->class)->checkIndex((structs_ArrayList__ArrayList*)this, index);
}

lang_types__Iterator* structs_ArrayList__ArrayList_iterator(structs_ArrayList__ArrayList* this) {
    return (lang_types__Iterator*) ((lang_types__IterableClass *)((lang_types__Object *)this)->class)->iterator((lang_types__Iterable*)this);
}

structs_ArrayList__ArrayList* structs_ArrayList__ArrayList_clone(structs_ArrayList__ArrayList* this) {
    return (structs_ArrayList__ArrayList*) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->clone((structs_List__List*)this);
}

lang_types__Pointer structs_ArrayList__ArrayList_toArray(structs_ArrayList__ArrayList* this) {
    return (lang_types__Pointer) ((structs_List__ListClass *)((lang_types__Object *)this)->class)->toArray((structs_List__List*)this);
}

void structs_ArrayList__ArrayList___defaults__(structs_ArrayList__ArrayList* this) {
    ((lang_types__ObjectClass *)((lang_types__Object *)this)->class)->__defaults__((lang_types__Object*)this);
}
structs_ArrayList__ArrayList* structs_ArrayList__ArrayList_new(lang_types__Class* T) {
    
    structs_ArrayList__ArrayList* this = ((structs_ArrayList__ArrayList*) (lang_types__Class_alloc__class((lang_types__Class*) structs_ArrayList__ArrayList_class())));
    ((lang_types__Iterable*) this)->T = T;
    structs_ArrayList__ArrayList___defaults__(this);
    structs_ArrayList__ArrayList_init(this);
    return this;
}
structs_ArrayList__ArrayList* structs_ArrayList__ArrayList_new_withCapacity(lang_types__Class* T, lang_types__Int capacity) {
    
    structs_ArrayList__ArrayList* this = ((structs_ArrayList__ArrayList*) (lang_types__Class_alloc__class((lang_types__Class*) structs_ArrayList__ArrayList_class())));
    ((lang_types__Iterable*) this)->T = T;
    structs_ArrayList__ArrayList___defaults__(this);
    structs_ArrayList__ArrayList_init_withCapacity(this, capacity);
    return this;
}
structs_ArrayList__ArrayList* structs_ArrayList__ArrayList_new_withData(lang_types__Class* T, uint8_t* data, lang_types__Int size) {
    
    structs_ArrayList__ArrayList* this = ((structs_ArrayList__ArrayList*) (lang_types__Class_alloc__class((lang_types__Class*) structs_ArrayList__ArrayList_class())));
    ((lang_types__Iterable*) this)->T = T;
    structs_ArrayList__ArrayList___defaults__(this);
    structs_ArrayList__ArrayList_init_withData(this, (uint8_t*) data, size);
    return this;
}

structs_ArrayList__ArrayListClass *structs_ArrayList__ArrayList_class(){
    static lang_types__Bool __done__ = false;
    static structs_ArrayList__ArrayListClass class = 
    {
        {
            {
                {
                    {
                        {
                            .instanceSize = sizeof(structs_ArrayList__ArrayList),
                            .size = sizeof(void*),
                            .name = "ArrayList",
                        },
                        .__defaults__ = (void (*)(lang_types__Object*)) structs_ArrayList__ArrayList___defaults___impl,
                        .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                    },
                },
                .init = (void (*)(lang_types__Iterable*)) structs_ArrayList__ArrayList_init_impl,
                .iterator = (lang_types__Iterator* (*)(lang_types__Iterable*)) structs_ArrayList__ArrayList_iterator_impl,
                .toArrayList = (structs_ArrayList__ArrayList* (*)(lang_types__Iterable*)) lang_types__Iterable_toArrayList_impl,
            },
            .add = (void (*)(structs_List__List*, uint8_t*)) structs_ArrayList__ArrayList_add_impl,
            .add_withIndex = (void (*)(structs_List__List*, lang_types__Int, uint8_t*)) structs_ArrayList__ArrayList_add_withIndex_impl,
            .addAll = (void (*)(structs_List__List*, lang_types__Iterable*)) structs_List__List_addAll_impl,
            .addAll_atStart = (void (*)(structs_List__List*, lang_types__Int, lang_types__Iterable*)) structs_List__List_addAll_atStart_impl,
            .clear = (void (*)(structs_List__List*)) structs_ArrayList__ArrayList_clear_impl,
            .removeLast = (lang_types__Bool (*)(structs_List__List*)) structs_List__List_removeLast_impl,
            .contains = (lang_types__Bool (*)(structs_List__List*, uint8_t*)) structs_List__List_contains_impl,
            .replace = (lang_types__Bool (*)(structs_List__List*, uint8_t*, uint8_t*)) structs_List__List_replace_impl,
            .get = (void (*)(structs_List__List*, uint8_t*, lang_types__Int)) structs_ArrayList__ArrayList_get_impl,
            .indexOf = (lang_types__Int (*)(structs_List__List*, uint8_t*)) structs_ArrayList__ArrayList_indexOf_impl,
            .isEmpty = (lang_types__Bool (*)(structs_List__List*)) structs_List__List_isEmpty_impl,
            .lastIndexOf = (lang_types__Int (*)(structs_List__List*, uint8_t*)) structs_ArrayList__ArrayList_lastIndexOf_impl,
            .removeAt = (void (*)(structs_List__List*, uint8_t*, lang_types__Int)) structs_ArrayList__ArrayList_removeAt_impl,
            .remove = (lang_types__Bool (*)(structs_List__List*, uint8_t*)) structs_ArrayList__ArrayList_remove_impl,
            .set = (void (*)(structs_List__List*, uint8_t*, lang_types__Int, uint8_t*)) structs_ArrayList__ArrayList_set_impl,
            .size = (lang_types__Int (*)(structs_List__List*)) structs_ArrayList__ArrayList_size_impl,
            .clone = (structs_List__List* (*)(structs_List__List*)) structs_ArrayList__ArrayList_clone_impl,
            .first = (void (*)(structs_List__List*, uint8_t*)) structs_List__List_first_impl,
            .last = (void (*)(structs_List__List*, uint8_t*)) structs_List__List_last_impl,
            .lastIndex = (lang_types__Int (*)(structs_List__List*)) structs_List__List_lastIndex_impl,
            .reverse = (void (*)(structs_List__List*)) structs_List__List_reverse_impl,
            .toArray = (lang_types__Pointer (*)(structs_List__List*)) structs_ArrayList__ArrayList_toArray_impl,
            .each = (void (*)(structs_List__List*, __FUNC___T)) structs_List__List_each_impl,
            .join_string = (lang_types__String (*)(structs_List__List*, lang_types__String)) structs_List__List_join_string_impl,
            .join_char = (lang_types__String (*)(structs_List__List*, lang_types__Char)) structs_List__List_join_char_impl,
        },
        .new = structs_ArrayList__ArrayList_new,
        .new_withCapacity = structs_ArrayList__ArrayList_new_withCapacity,
        .init_withCapacity = structs_ArrayList__ArrayList_init_withCapacity_impl,
        .new_withData = structs_ArrayList__ArrayList_new_withData,
        .init_withData = structs_ArrayList__ArrayList_init_withData_impl,
        .ensureCapacity = structs_ArrayList__ArrayList_ensureCapacity_impl,
        .grow = structs_ArrayList__ArrayList_grow_impl,
        .checkIndex = structs_ArrayList__ArrayList_checkIndex_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) structs_List__List_class();
        __done__ = true;
    }
    return &class;
}

void structs_ArrayList__ArrayListIterator_init_iter_impl(structs_ArrayList__ArrayListIterator* this, structs_ArrayList__ArrayList* list) {
    this->list = list;
}

lang_types__Bool structs_ArrayList__ArrayListIterator_hasNext_impl(structs_ArrayList__ArrayListIterator* this) {
    return this->index < structs_ArrayList__ArrayList_size(this->list);
}

void structs_ArrayList__ArrayListIterator_next_impl(structs_ArrayList__ArrayListIterator* this, uint8_t* __returnArg13) {
    uint8_t* element = GC_MALLOC(((lang_types__Iterator*) this)->T->size);
    structs_ArrayList__ArrayList_get(this->list, element, this->index);
    this->index += 1;
    if (__returnArg13) {
        memcpy(__returnArg13, element, ((lang_types__Iterator*) this)->T->size);
    }
    return;
}

lang_types__Bool structs_ArrayList__ArrayListIterator_hasPrev_impl(structs_ArrayList__ArrayListIterator* this) {
    return this->index > 0;
}

void structs_ArrayList__ArrayListIterator_prev_impl(structs_ArrayList__ArrayListIterator* this, uint8_t* __returnArg14) {
    this->index -= 1;
    uint8_t* element = GC_MALLOC(((lang_types__Iterator*) this)->T->size);
    structs_ArrayList__ArrayList_get(this->list, element, this->index);
    if (__returnArg14) {
        memcpy(__returnArg14, element, ((lang_types__Iterator*) this)->T->size);
    }
    return;
}

lang_types__Bool structs_ArrayList__ArrayListIterator_remove_impl(structs_ArrayList__ArrayListIterator* this) {
    uint8_t* __genCall15 = GC_MALLOC(((lang_types__Iterator*) this)->T->size);
    if ((structs_ArrayList__ArrayList_removeAt(this->list, __genCall15, this->index - 1), __genCall15) == (uint8_t*) NULL) {
        return false;
    }
    if (this->index <= structs_ArrayList__ArrayList_size(this->list)) {
        this->index -= 1;
    }
    return true;
}

void structs_ArrayList__ArrayListIterator___defaults___impl(structs_ArrayList__ArrayListIterator* this) {lang_types__Object___defaults___impl((lang_types__Object*) this);
    this->index = 0;
}

void structs_ArrayList__ArrayListIterator_init_iter(structs_ArrayList__ArrayListIterator* this, structs_ArrayList__ArrayList* list) {
    ((structs_ArrayList__ArrayListIteratorClass *)((lang_types__Object *)this)->class)->init_iter((structs_ArrayList__ArrayListIterator*)this, list);
}

lang_types__Bool structs_ArrayList__ArrayListIterator_hasNext(structs_ArrayList__ArrayListIterator* this) {
    return (lang_types__Bool) ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->hasNext((lang_types__Iterator*)this);
}

void structs_ArrayList__ArrayListIterator_next(structs_ArrayList__ArrayListIterator* this, uint8_t* __returnArg13) {
    ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->next((lang_types__Iterator*)this, __returnArg13);
}

lang_types__Bool structs_ArrayList__ArrayListIterator_hasPrev(structs_ArrayList__ArrayListIterator* this) {
    return (lang_types__Bool) ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->hasPrev((lang_types__Iterator*)this);
}

void structs_ArrayList__ArrayListIterator_prev(structs_ArrayList__ArrayListIterator* this, uint8_t* __returnArg14) {
    ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->prev((lang_types__Iterator*)this, __returnArg14);
}

lang_types__Bool structs_ArrayList__ArrayListIterator_remove(structs_ArrayList__ArrayListIterator* this) {
    return (lang_types__Bool) ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->remove((lang_types__Iterator*)this);
}

void structs_ArrayList__ArrayListIterator___defaults__(structs_ArrayList__ArrayListIterator* this) {
    ((lang_types__ObjectClass *)((lang_types__Object *)this)->class)->__defaults__((lang_types__Object*)this);
}
structs_ArrayList__ArrayListIterator* structs_ArrayList__ArrayListIterator_new_iter(lang_types__Class* T, structs_ArrayList__ArrayList* list) {
    
    structs_ArrayList__ArrayListIterator* this = ((structs_ArrayList__ArrayListIterator*) (lang_types__Class_alloc__class((lang_types__Class*) structs_ArrayList__ArrayListIterator_class())));
    ((lang_types__Iterator*) this)->T = T;
    structs_ArrayList__ArrayListIterator___defaults__(this);
    structs_ArrayList__ArrayListIterator_init_iter(this, list);
    return this;
}

structs_ArrayList__ArrayListIteratorClass *structs_ArrayList__ArrayListIterator_class(){
    static lang_types__Bool __done__ = false;
    static structs_ArrayList__ArrayListIteratorClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(structs_ArrayList__ArrayListIterator),
                        .size = sizeof(void*),
                        .name = "ArrayListIterator",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) structs_ArrayList__ArrayListIterator___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
            .init = (void (*)(lang_types__Iterator*)) lang_types__Iterator_init_impl,
            .hasNext = (lang_types__Bool (*)(lang_types__Iterator*)) structs_ArrayList__ArrayListIterator_hasNext_impl,
            .next = (void (*)(lang_types__Iterator*, uint8_t*)) structs_ArrayList__ArrayListIterator_next_impl,
            .hasPrev = (lang_types__Bool (*)(lang_types__Iterator*)) structs_ArrayList__ArrayListIterator_hasPrev_impl,
            .prev = (void (*)(lang_types__Iterator*, uint8_t*)) structs_ArrayList__ArrayListIterator_prev_impl,
            .remove = (lang_types__Bool (*)(lang_types__Iterator*)) structs_ArrayList__ArrayListIterator_remove_impl,
        },
        .new_iter = structs_ArrayList__ArrayListIterator_new_iter,
        .init_iter = structs_ArrayList__ArrayListIterator_init_iter_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Iterator_class();
        __done__ = true;
    }
    return &class;
}
void structs_ArrayList_load() {
    static bool __done__ = false;
    if (!__done__){
        __done__ = true;
        lang_stdio_load();
        lang_types_load();
        lang_memory_load();
        lang_system_load();
        lang_string_load();
        lang_vararg_load();
        structs_List_load();
    }
}


void structs_ArrayList____OP_IDX_ArrayList_Int__T(uint8_t* __returnArg27, lang_types__Class* T, structs_ArrayList__ArrayList* list, lang_types__Int i) {
    uint8_t* __genCall26 = GC_MALLOC(T->size);
    uint8_t* __returnVal28 = GC_MALLOC(T->size);
    memcpy(__returnVal28, (structs_ArrayList__ArrayList_get(list, __genCall26, i), __genCall26), T->size);
    if (__returnArg27) {
        memcpy(__returnArg27, __returnVal28, T->size);
    }
    return;
}

void structs_ArrayList____OP_IDX_ASS_ArrayList_Int_T(lang_types__Class* T, structs_ArrayList__ArrayList* list, lang_types__Int i, uint8_t* element) {
    structs_ArrayList__ArrayList_set(list, NULL, i, (uint8_t*) element);
}

void structs_ArrayList____OP_ADD_ASS_ArrayList_T(lang_types__Class* T, structs_ArrayList__ArrayList* list, uint8_t* element) {
    structs_ArrayList__ArrayList_add(list, (uint8_t*) element);
}

lang_types__Bool structs_ArrayList____OP_SUB_ASS_ArrayList_T__Bool(lang_types__Class* T, structs_ArrayList__ArrayList* list, uint8_t* element) {
    return structs_ArrayList__ArrayList_remove(list, (uint8_t*) element);
}

structs_ArrayList__ArrayList* structs_ArrayList____OP_AS_T__array__ArrayList(lang_types__Class* T, _lang_array__Array array) {
    return structs_ArrayList__ArrayList_new_withData((lang_types__Class*)lang_types__Pointer_class(), (uint8_t*) array.data, array.length);
}
