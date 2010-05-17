/* lang/types header file, generated with rock, the ooc compiler written in ooc */

#ifndef ___lang_types___
#define ___lang_types___

#include "types-fwd.h"


struct _lang_types__Object {
    lang_types__Class* class;
};


struct _lang_types__Class {
    struct _lang_types__Object __super__;
    lang_types__SizeT instanceSize;
    lang_types__SizeT size;
    lang_types__String name;
    lang_types__Class* super;
};


struct _lang_types__None {
    struct _lang_types__Object __super__;
};


struct _lang_types__Comparable {
    struct _lang_types__Object __super__;
};


struct _Comparable__reference {
    lang_types__ComparableClass* impl;
    lang_types__Object* obj;
};

struct _lang_types__Range {
    lang_types__Int min;
    lang_types__Int max;
};

struct _lang_types__Iterator {
    struct _lang_types__Object __super__;
    lang_types__Class* T;
};


struct _lang_types__Iterable {
    struct _lang_types__Object __super__;
    lang_types__Class* T;
};


struct _lang_types__StringIterator {
    struct _lang_types__Iterator __super__;
    lang_types__Int i;
    lang_types__String str;
};


struct _lang_types__Cell {
    struct _lang_types__Object __super__;
    lang_types__Class* T;
    uint8_t* val;
};


struct _lang_types__Exception {
    struct _lang_types__Object __super__;
    lang_types__Class* origin;
    lang_types__String msg;
};


struct _lang_types__ObjectClass {
    struct _lang_types__Class __super__;
    void (*__defaults__)(lang_types__Object*);
    void (*__destroy__)(lang_types__Object*);
    lang_types__Bool (*instanceOf)(lang_types__Object*, lang_types__Class*);
};


struct _lang_types__ClassClass {
    struct _lang_types__ObjectClass __super__;
    lang_types__Object* (*alloc__class)(lang_types__Class*);
    lang_types__Bool (*inheritsFrom__class)(lang_types__Class*, lang_types__Class*);
};


struct _lang_types__ArrayClass {
    struct _lang_types__ClassClass __super__;
};


struct _lang_types__NoneClass {
    struct _lang_types__ClassClass __super__;
    lang_types__None* (*new)();
    void (*init)(lang_types__None*);
};


struct _lang_types__VoidClass {
    struct _lang_types__ClassClass __super__;
};


struct _lang_types__PointerClass {
    struct _lang_types__ClassClass __super__;
    lang_types__String (*toString)(lang_types__Pointer);
};


struct _lang_types__CharClass {
    struct _lang_types__ClassClass __super__;
    lang_types__Bool (*isAlphaNumeric)(lang_types__Char);
    lang_types__Bool (*isAlpha)(lang_types__Char);
    lang_types__Bool (*isLower)(lang_types__Char);
    lang_types__Bool (*isUpper)(lang_types__Char);
    lang_types__Bool (*isDigit)(lang_types__Char);
    lang_types__Bool (*isHexDigit)(lang_types__Char);
    lang_types__Bool (*isControl)(lang_types__Char);
    lang_types__Bool (*isGraph)(lang_types__Char);
    lang_types__Bool (*isPrintable)(lang_types__Char);
    lang_types__Bool (*isPunctuation)(lang_types__Char);
    lang_types__Bool (*isWhitespace)(lang_types__Char);
    lang_types__Bool (*isBlank)(lang_types__Char);
    lang_types__Int (*toInt)(lang_types__Char);
    lang_types__String (*toString)(lang_types__Char);
    void (*print)(lang_types__Char);
    void (*println)(lang_types__Char);
};


struct _lang_types__SCharClass {
    struct _lang_types__CharClass __super__;
};


struct _lang_types__UCharClass {
    struct _lang_types__CharClass __super__;
};


struct _lang_types__WCharClass {
    struct _lang_types__ClassClass __super__;
};


struct _lang_types__StringClass {
    struct _lang_types__ClassClass __super__;
    lang_types__String (*new_withLength)(lang_types__Int);
    lang_types__String (*new_withChar)(lang_types__Char);
    lang_types__Bool (*compare)(lang_types__String, lang_types__String, lang_types__Int, lang_types__Int);
    lang_types__Bool (*compare_implicitLength)(lang_types__String, lang_types__String, lang_types__Int);
    lang_types__Bool (*compare_whole)(lang_types__String, lang_types__String);
    lang_types__Bool (*equals)(lang_types__String, lang_types__String);
    lang_types__Int (*toInt)(lang_types__String);
    lang_types__Int (*toInt_withBase)(lang_types__String, lang_types__Int);
    lang_types__Long (*toLong)(lang_types__String);
    lang_types__Long (*toLong_withBase)(lang_types__String, lang_types__Long);
    lang_types__LLong (*toLLong)(lang_types__String);
    lang_types__LLong (*toLLong_withBase)(lang_types__String, lang_types__LLong);
    lang_types__ULong (*toULong)(lang_types__String);
    lang_types__ULong (*toULong_withBase)(lang_types__String, lang_types__ULong);
    lang_types__Float (*toFloat)(lang_types__String);
    lang_types__Double (*toDouble)(lang_types__String);
    lang_types__LDouble (*toLDouble)(lang_types__String);
    lang_types__Bool (*isEmpty)(lang_types__String);
    lang_types__Bool (*startsWith)(lang_types__String, lang_types__String);
    lang_types__Bool (*startsWith_withChar)(lang_types__String, lang_types__Char);
    lang_types__Bool (*endsWith)(lang_types__String, lang_types__String);
    lang_types__Int (*indexOf_charZero)(lang_types__String, lang_types__Char);
    lang_types__Int (*indexOf_char)(lang_types__String, lang_types__Char, lang_types__Int);
    lang_types__Int (*indexOf_stringZero)(lang_types__String, lang_types__String);
    lang_types__Int (*indexOf_string)(lang_types__String, lang_types__String, lang_types__Int);
    lang_types__Bool (*contains_char)(lang_types__String, lang_types__Char);
    lang_types__Bool (*contains_string)(lang_types__String, lang_types__String);
    lang_types__String (*trim_space)(lang_types__String);
    lang_types__String (*trim)(lang_types__String, lang_types__Char);
    lang_types__String (*trim_string)(lang_types__String, lang_types__String);
    lang_types__String (*trimLeft_space)(lang_types__String);
    lang_types__String (*trimLeft)(lang_types__String, lang_types__Char);
    lang_types__String (*trimLeft_string)(lang_types__String, lang_types__String);
    lang_types__String (*trimRight_space)(lang_types__String);
    lang_types__String (*trimRight)(lang_types__String, lang_types__Char);
    lang_types__String (*trimRight_string)(lang_types__String, lang_types__String);
    lang_types__Char (*first)(lang_types__String);
    lang_types__Int (*lastIndex)(lang_types__String);
    lang_types__Char (*last)(lang_types__String);
    lang_types__Int (*lastIndexOf)(lang_types__String, lang_types__Char);
    lang_types__String (*substring_tillEnd)(lang_types__String, lang_types__Int);
    lang_types__String (*substring)(lang_types__String, lang_types__Int, lang_types__Int);
    lang_types__String (*reverse)(lang_types__String);
    void (*print)(lang_types__String);
    void (*println)(lang_types__String);
    lang_types__String (*times)(lang_types__String, lang_types__Int);
    lang_types__String (*clone)(lang_types__String);
    lang_types__String (*append)(lang_types__String, lang_types__String);
    lang_types__String (*append_char)(lang_types__String, lang_types__Char);
    lang_types__Int (*count_char)(lang_types__String, lang_types__Char);
    lang_types__Int (*count_string)(lang_types__String, lang_types__String);
    lang_types__String (*replace)(lang_types__String, lang_types__Char, lang_types__Char);
    lang_types__String (*replace_string)(lang_types__String, lang_types__String, lang_types__String);
    lang_types__String (*prepend)(lang_types__String, lang_types__String);
    lang_types__String (*prepend_char)(lang_types__String, lang_types__Char);
    lang_types__String (*toLower)(lang_types__String);
    lang_types__String (*toUpper)(lang_types__String);
    lang_types__Char (*charAt)(lang_types__String, lang_types__SizeT);
    lang_types__String (*format)(lang_types__String, ...);
    lang_types__Int (*scanf)(lang_types__String, lang_types__String, ...);
    lang_types__StringIterator* (*iterator)(lang_types__String);
};


struct _lang_types__ComparableClass {
    struct _lang_types__ClassClass __super__;
    lang_types__Int (*compareTo)(void*, lang_types__Class*, uint8_t*);
};


struct _lang_types__LLongClass {
    struct _lang_types__ClassClass __super__;
    lang_types__String (*toString)(lang_types__LLong);
    lang_types__String (*toHexString)(lang_types__LLong);
    lang_types__Bool (*isOdd)(lang_types__LLong);
    lang_types__Bool (*isEven)(lang_types__LLong);
    lang_types__Bool (*in)(lang_types__LLong, lang_types__Range);
};


struct _lang_types__LongClass {
    struct _lang_types__LLongClass __super__;
};


struct _lang_types__IntClass {
    struct _lang_types__LLongClass __super__;
};


struct _lang_types__ShortClass {
    struct _lang_types__LLongClass __super__;
};


struct _lang_types__ULLongClass {
    struct _lang_types__LLongClass __super__;
};


struct _lang_types__ULongClass {
    struct _lang_types__ULLongClass __super__;
};


struct _lang_types__UIntClass {
    struct _lang_types__ULLongClass __super__;
};


struct _lang_types__UShortClass {
    struct _lang_types__ULLongClass __super__;
};


struct _lang_types__Int8Class {
    struct _lang_types__LLongClass __super__;
};


struct _lang_types__Int16Class {
    struct _lang_types__LLongClass __super__;
};


struct _lang_types__Int32Class {
    struct _lang_types__LLongClass __super__;
};


struct _lang_types__Int64Class {
    struct _lang_types__LLongClass __super__;
};


struct _lang_types__UInt8Class {
    struct _lang_types__ULLongClass __super__;
};


struct _lang_types__UInt16Class {
    struct _lang_types__ULLongClass __super__;
};


struct _lang_types__UInt32Class {
    struct _lang_types__ULLongClass __super__;
};


struct _lang_types__UInt64Class {
    struct _lang_types__ULLongClass __super__;
};


struct _lang_types__OctetClass {
    struct _lang_types__ClassClass __super__;
};


struct _lang_types__SizeTClass {
    struct _lang_types__LLongClass __super__;
};


struct _lang_types__BoolClass {
    struct _lang_types__ClassClass __super__;
    lang_types__String (*toString)(lang_types__Bool);
};


struct _lang_types__LDoubleClass {
    struct _lang_types__ClassClass __super__;
    lang_types__String (*toString)(lang_types__LDouble);
    lang_types__LDouble (*abs)(lang_types__LDouble);
};


struct _lang_types__FloatClass {
    struct _lang_types__LDoubleClass __super__;
};


struct _lang_types__DoubleClass {
    struct _lang_types__LDoubleClass __super__;
};


struct _lang_types__RangeClass {
    struct _lang_types__ClassClass __super__;
    lang_types__Range (*new)(lang_types__Int, lang_types__Int);
};


struct _lang_types__IteratorClass {
    struct _lang_types__ClassClass __super__;
    void (*init)(lang_types__Iterator*);
    lang_types__Bool (*hasNext)(lang_types__Iterator*);
    void (*next)(lang_types__Iterator*, uint8_t*);
    lang_types__Bool (*hasPrev)(lang_types__Iterator*);
    void (*prev)(lang_types__Iterator*, uint8_t*);
    lang_types__Bool (*remove)(lang_types__Iterator*);
};


struct _lang_types__IterableClass {
    struct _lang_types__ClassClass __super__;
    void (*init)(lang_types__Iterable*);
    lang_types__Iterator* (*iterator)(lang_types__Iterable*);
    structs_ArrayList__ArrayList* (*toArrayList)(lang_types__Iterable*);
};


struct _lang_types__StringIteratorClass {
    struct _lang_types__IteratorClass __super__;
    lang_types__StringIterator* (*new_withStr)(lang_types__Class*, lang_types__String);
    void (*init_withStr)(lang_types__StringIterator*, lang_types__String);
    void (*__defaults__)(lang_types__StringIterator*);
};


struct _lang_types__CellClass {
    struct _lang_types__ClassClass __super__;
    lang_types__Cell* (*new)(lang_types__Class*, uint8_t*);
    void (*init)(lang_types__Cell*, uint8_t*);
    void (*__defaults__)(lang_types__Cell*);
};


struct _lang_types__ExceptionClass {
    struct _lang_types__ClassClass __super__;
    lang_types__Exception* (*new_originMsg)(lang_types__Class*, lang_types__String);
    void (*init_originMsg)(lang_types__Exception*, lang_types__Class*, lang_types__String);
    lang_types__Exception* (*new_noOrigin)(lang_types__String);
    void (*init_noOrigin)(lang_types__Exception*, lang_types__String);
    void (*crash)(lang_types__Exception*);
    lang_types__String (*getMessage)(lang_types__Exception*);
    void (*print)(lang_types__Exception*);
    void (*throw)(lang_types__Exception*);
};



#endif // ___lang_types___
