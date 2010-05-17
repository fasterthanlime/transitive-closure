/* lang/types source file, generated with rock, the ooc compiler written in ooc */

#include "types.h"

#include <sdk/lang/stdio.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/system.h>
#include <sdk/lang/string.h>
#include <sdk/lang/vararg.h>
#include <sdk/structs/List.h>
#include <sdk/structs/ArrayList.h>
#include <sdk/text/Buffer.h>


void lang_types__Object___defaults___impl(lang_types__Object* this) {
}

void lang_types__Object___destroy___impl(lang_types__Object* this) {
}

lang_types__Bool lang_types__Object_instanceOf(lang_types__Object* this, lang_types__Class* T) {
    if (!this) {
        return false;
    }
    return lang_types__Class_inheritsFrom__class(this->class, T);
}

void lang_types__Object___defaults__(lang_types__Object* this) {
    ((lang_types__ObjectClass *)((lang_types__Object *)this)->class)->__defaults__((lang_types__Object*)this);
}

void lang_types__Object___destroy__(lang_types__Object* this) {
    ((lang_types__ObjectClass *)((lang_types__Object *)this)->class)->__destroy__((lang_types__Object*)this);
}

lang_types__ObjectClass *lang_types__Object_class(){
    static lang_types__ObjectClass class = 
    {
        {
            .instanceSize = sizeof(lang_types__Object),
            .size = sizeof(void*),
            .name = "Object",
        },
        .__defaults__ = lang_types__Object___defaults___impl,
        .__destroy__ = lang_types__Object___destroy___impl,
    };
    return &class;
}

lang_types__Object* lang_types__Class_alloc__class(lang_types__Class* this) {
    lang_types__Object* object = ((lang_types__Object*) (GC_MALLOC(this->instanceSize)));
    if (object) {
        object->class = this;
    }
    return object;
}

lang_types__Bool lang_types__Class_inheritsFrom__class(lang_types__Class* this, lang_types__Class* T) {
    if (this == T) {
        return true;
    }
    return (this->super ? lang_types__Class_inheritsFrom__class(this->super, T) : false);
}

lang_types__ClassClass *lang_types__Class_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__ClassClass class = 
    {
        {
            {
                .instanceSize = sizeof(lang_types__Class),
                .size = sizeof(void*),
                .name = "Class",
            },
            .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
            .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Object_class();
        __done__ = true;
    }
    return &class;
}

lang_types__ArrayClass *lang_types__Array_class(){
    static lang_types__ArrayClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__Array),
                    .size = sizeof(lang_types__Array),
                    .name = "Array",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    return &class;
}

void lang_types__None_init_impl(lang_types__None* this) {
}

void lang_types__None_init(lang_types__None* this) {
    ((lang_types__NoneClass *)((lang_types__Object *)this)->class)->init((lang_types__None*)this);
}
lang_types__None* lang_types__None_new() {
    
    lang_types__None* this = ((lang_types__None*) (lang_types__Class_alloc__class((lang_types__Class*) lang_types__None_class())));
    lang_types__Object___defaults__((lang_types__Object*) this);
    lang_types__None_init(this);
    return this;
}

lang_types__NoneClass *lang_types__None_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__NoneClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__None),
                    .size = sizeof(void*),
                    .name = "None",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
        .new = lang_types__None_new,
        .init = lang_types__None_init_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Object_class();
        __done__ = true;
    }
    return &class;
}

lang_types__VoidClass *lang_types__Void_class(){
    static lang_types__VoidClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__Void),
                    .size = sizeof(lang_types__Void),
                    .name = "Void",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    return &class;
}

lang_types__String lang_types__Pointer_toString(lang_types__Pointer this) {
    return lang_types__String_format("%p", this);
}

lang_types__PointerClass *lang_types__Pointer_class(){
    static lang_types__PointerClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__Pointer),
                    .size = sizeof(lang_types__Pointer),
                    .name = "Pointer",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    return &class;
}

lang_types__Bool lang_types__Char_isAlphaNumeric(lang_types__Char this) {
    return lang_types__Char_isAlpha(this) || lang_types__Char_isDigit(this);
}

lang_types__Bool lang_types__Char_isAlpha(lang_types__Char this) {
    return lang_types__Char_isLower(this) || lang_types__Char_isUpper(this);
}

lang_types__Bool lang_types__Char_isLower(lang_types__Char this) {
    return this >= 'a' && this <= 'z';
}

lang_types__Bool lang_types__Char_isUpper(lang_types__Char this) {
    return this >= 'A' && this <= 'Z';
}

lang_types__Bool lang_types__Char_isDigit(lang_types__Char this) {
    return this >= '0' && this <= '9';
}

lang_types__Bool lang_types__Char_isHexDigit(lang_types__Char this) {
    return lang_types__Char_isDigit(this) || (this >= 'A' && this <= 'F') || (this >= 'a' && this <= 'f');
}

lang_types__Bool lang_types__Char_isControl(lang_types__Char this) {
    return (this >= (lang_types__Char) 0 && this <= (lang_types__Char) 31) || this == (lang_types__Char) 127;
}

lang_types__Bool lang_types__Char_isGraph(lang_types__Char this) {
    return lang_types__Char_isPrintable(this) && this != ' ';
}

lang_types__Bool lang_types__Char_isPrintable(lang_types__Char this) {
    return this >= (lang_types__Char) 32 && this <= (lang_types__Char) 126;
}

lang_types__Bool lang_types__Char_isPunctuation(lang_types__Char this) {
    return lang_types__Char_isPrintable(this) && !lang_types__Char_isAlphaNumeric(this) && this != ' ';
}

lang_types__Bool lang_types__Char_isWhitespace(lang_types__Char this) {
    return this == ' ' || this == '\f' || this == '\n' || this == '\r' || this == '\t' || this == '\v';
}

lang_types__Bool lang_types__Char_isBlank(lang_types__Char this) {
    return this == ' ' || this == '\t';
}

lang_types__Int lang_types__Char_toInt(lang_types__Char this) {
    if (lang_types__Char_isDigit(this)) {
        return ((lang_types__Int) ((this - '0')));
    }
    return -1;
}

lang_types__String lang_types__Char_toString(lang_types__Char this) {
    return lang_types__String_new_withChar(this);
}

void lang_types__Char_print(lang_types__Char this) {
    printf("%c", this);
}

void lang_types__Char_println(lang_types__Char this) {
    printf("%c\n", this);
}

lang_types__CharClass *lang_types__Char_class(){
    static lang_types__CharClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__Char),
                    .size = sizeof(lang_types__Char),
                    .name = "Char",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    return &class;
}

lang_types__SCharClass *lang_types__SChar_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__SCharClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__SChar),
                        .size = sizeof(lang_types__SChar),
                        .name = "SChar",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Char_class();
        __done__ = true;
    }
    return &class;
}

lang_types__UCharClass *lang_types__UChar_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__UCharClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__UChar),
                        .size = sizeof(lang_types__UChar),
                        .name = "UChar",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Char_class();
        __done__ = true;
    }
    return &class;
}

lang_types__WCharClass *lang_types__WChar_class(){
    static lang_types__WCharClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__WChar),
                    .size = sizeof(lang_types__WChar),
                    .name = "WChar",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    return &class;
}

lang_types__Bool lang_types__String_compare(lang_types__String this, lang_types__String other, lang_types__Int start, lang_types__Int length) {
    
    {
        lang_types__Int i;
        for (i = 0; i < length; i++) {
            if (lang_types____OP_IDX_String_SizeT__Char(this, start + i) != lang_types____OP_IDX_String_SizeT__Char(other, i)) {
                return false;
            }
        }
    }
    return true;
}

lang_types__Bool lang_types__String_compare_implicitLength(lang_types__String this, lang_types__String other, lang_types__Int start) {
    return lang_types__String_compare(this, other, start, strlen(other));
}

lang_types__Bool lang_types__String_compare_whole(lang_types__String this, lang_types__String other) {
    return lang_types__String_compare(this, other, 0, strlen(other));
}

lang_types__Bool lang_types__String_equals(lang_types__String this, lang_types__String other) {
    if ((this == (lang_types__String) NULL) || (other == (lang_types__String) NULL)) {
        return false;
    }
    if (strlen(this) != strlen(other)) {
        return false;
    }
    
    {
        lang_types__Int i;
        for (i = 0; i < strlen(other); i++) {
            if (lang_types____OP_IDX_String_SizeT__Char(this, i) != lang_types____OP_IDX_String_SizeT__Char(other, i)) {
                return false;
            }
        }
    }
    return true;
}

lang_types__Int lang_types__String_toInt(lang_types__String this) {
    return ((lang_types__Int) (strtol(this, NULL, 10)));
}

lang_types__Int lang_types__String_toInt_withBase(lang_types__String this, lang_types__Int base) {
    return ((lang_types__Int) (strtol(this, NULL, base)));
}

lang_types__Long lang_types__String_toLong(lang_types__String this) {
    return strtol(this, NULL, 10);
}

lang_types__Long lang_types__String_toLong_withBase(lang_types__String this, lang_types__Long base) {
    return strtol(this, NULL, base);
}

lang_types__LLong lang_types__String_toLLong(lang_types__String this) {
    return ((lang_types__LLong) (strtol(this, NULL, 10)));
}

lang_types__LLong lang_types__String_toLLong_withBase(lang_types__String this, lang_types__LLong base) {
    return ((lang_types__LLong) (strtol(this, NULL, base)));
}

lang_types__ULong lang_types__String_toULong(lang_types__String this) {
    return strtoul(this, NULL, 10);
}

lang_types__ULong lang_types__String_toULong_withBase(lang_types__String this, lang_types__ULong base) {
    return strtoul(this, NULL, base);
}

lang_types__Float lang_types__String_toFloat(lang_types__String this) {
    return strtof(this, NULL);
}

lang_types__Double lang_types__String_toDouble(lang_types__String this) {
    return strtod(this, NULL);
}

lang_types__LDouble lang_types__String_toLDouble(lang_types__String this) {
    return strtold(this, NULL);
}

lang_types__Bool lang_types__String_isEmpty(lang_types__String this) {
    return (this == (lang_types__String) NULL) || (lang_types____OP_IDX_String_SizeT__Char(this, 0) == (lang_types__Char) 0);
}

lang_types__Bool lang_types__String_startsWith(lang_types__String this, lang_types__String s) {
    if (strlen(this) < strlen(s)) {
        return false;
    }
    
    {
        lang_types__Int i;
        for (i = 0; i < strlen(s); i++) {
            if (lang_types____OP_IDX_String_SizeT__Char(this, i) != lang_types____OP_IDX_String_SizeT__Char(s, i)) {
                return false;
            }
        }
    }
    return true;
}

lang_types__Bool lang_types__String_startsWith_withChar(lang_types__String this, lang_types__Char c) {
    return lang_types____OP_IDX_String_SizeT__Char(this, 0) == c;
}

lang_types__Bool lang_types__String_endsWith(lang_types__String this, lang_types__String s) {
    lang_types__Int l1 = strlen(this);
    lang_types__Int l2 = strlen(s);
    if (l1 < l2) {
        return false;
    }
    lang_types__Int offset = (l1 - l2);
    
    {
        lang_types__Int i;
        for (i = 0; i < l2; i++) {
            if (lang_types____OP_IDX_String_SizeT__Char(this, i + offset) != lang_types____OP_IDX_String_SizeT__Char(s, i)) {
                return false;
            }
        }
    }
    return true;
}

lang_types__Int lang_types__String_indexOf_charZero(lang_types__String this, lang_types__Char c) {
    return lang_types__String_indexOf_char(this, c, 0);
}

lang_types__Int lang_types__String_indexOf_char(lang_types__String this, lang_types__Char c, lang_types__Int start) {
    lang_types__Int length = strlen(this);
    
    {
        lang_types__Int i;
        for (i = start; i < length; i++) {
            if (lang_types____OP_IDX_String_SizeT__Char(this, i) == c) {
                return i;
            }
        }
    }
    return -1;
}

lang_types__Int lang_types__String_indexOf_stringZero(lang_types__String this, lang_types__String s) {
    return lang_types__String_indexOf_string(this, s, 0);
}

lang_types__Int lang_types__String_indexOf_string(lang_types__String this, lang_types__String s, lang_types__Int start) {
    lang_types__Int length = strlen(this);
    lang_types__Int slength = strlen(s);
    
    {
        lang_types__Int i;
        for (i = start; i < length; i++) {
            if (lang_types__String_compare(this, s, i, slength)) {
                return i;
            }
        }
    }
    return -1;
}

lang_types__Bool lang_types__String_contains_char(lang_types__String this, lang_types__Char c) {
    return lang_types__String_indexOf_charZero(this, c) != -1;
}

lang_types__Bool lang_types__String_contains_string(lang_types__String this, lang_types__String s) {
    return lang_types__String_indexOf_stringZero(this, s) != -1;
}

lang_types__String lang_types__String_trim_space(lang_types__String this) {
    return lang_types__String_trim(this, ' ');
}

lang_types__String lang_types__String_trim(lang_types__String this, lang_types__Char c) {
    if (strlen(this) == 0) {
        return this;
    }
    lang_types__Int start = 0;
    while (lang_types____OP_IDX_String_SizeT__Char(this, start) == c) {
        start += 1;
    }
    lang_types__Int end = strlen(this);
    if (start >= end) {
        return "";
    }
    while (lang_types____OP_IDX_String_SizeT__Char(this, end - 1) == c) {
        end -= 1;
    }
    if (start != 0 || end != strlen(this)) {
        return lang_types__String_substring(this, start, end);
    }
    return this;
}

lang_types__String lang_types__String_trim_string(lang_types__String this, lang_types__String s) {
    if (strlen(this) == 0) {
        return this;
    }
    lang_types__Int start = 0;
    while (lang_types__String_contains_char(s, lang_types____OP_IDX_String_SizeT__Char(this, start))) {
        start += 1;
    }
    lang_types__Int end = strlen(this);
    if (start >= end) {
        return "";
    }
    while (lang_types__String_contains_char(s, lang_types____OP_IDX_String_SizeT__Char(this, end - 1))) {
        end -= 1;
    }
    if (start != 0 || end != strlen(this)) {
        return lang_types__String_substring(this, start, end);
    }
    return this;
}

lang_types__String lang_types__String_trimLeft_space(lang_types__String this) {
    return lang_types__String_trimLeft(this, ' ');
}

lang_types__String lang_types__String_trimLeft(lang_types__String this, lang_types__Char c) {
    if (strlen(this) == 0) {
        return this;
    }
    lang_types__Int start = 0;
    while (lang_types____OP_IDX_String_SizeT__Char(this, start) == c) {
        start += 1;
    }
    lang_types__Int end = strlen(this);
    if (start >= end) {
        return "";
    }
    if (start != 0) {
        return lang_types__String_substring_tillEnd(this, start);
    }
    return this;
}

lang_types__String lang_types__String_trimLeft_string(lang_types__String this, lang_types__String s) {
    if (strlen(this) == 0) {
        return this;
    }
    lang_types__Int start = 0;
    while (lang_types__String_contains_char(s, lang_types____OP_IDX_String_SizeT__Char(this, start))) {
        start += 1;
    }
    lang_types__Int end = strlen(this);
    if (start >= end) {
        return "";
    }
    if (start != 0) {
        return lang_types__String_substring_tillEnd(this, start);
    }
    return this;
}

lang_types__String lang_types__String_trimRight_space(lang_types__String this) {
    return lang_types__String_trimRight(this, ' ');
}

lang_types__String lang_types__String_trimRight(lang_types__String this, lang_types__Char c) {
    if (strlen(this) == 0) {
        return this;
    }
    lang_types__Int end = strlen(this);
    if (0 >= end) {
        return "";
    }
    while (lang_types____OP_IDX_String_SizeT__Char(this, end - 1) == c) {
        end -= 1;
    }
    if (end != strlen(this)) {
        return lang_types__String_substring(this, 0, end);
    }
    return this;
}

lang_types__String lang_types__String_trimRight_string(lang_types__String this, lang_types__String s) {
    if (strlen(this) == 0) {
        return this;
    }
    lang_types__Int end = strlen(this);
    while (lang_types__String_contains_char(s, lang_types____OP_IDX_String_SizeT__Char(this, end - 1))) {
        end -= 1;
    }
    if (0 >= end) {
        return "";
    }
    if (end != strlen(this)) {
        return lang_types__String_substring(this, 0, end);
    }
    return this;
}

lang_types__Char lang_types__String_first(lang_types__String this) {
    return lang_types____OP_IDX_String_SizeT__Char(this, 0);
}

lang_types__Int lang_types__String_lastIndex(lang_types__String this) {
    return strlen(this) - 1;
}

lang_types__Char lang_types__String_last(lang_types__String this) {
    return lang_types____OP_IDX_String_SizeT__Char(this, lang_types__String_lastIndex(this));
}

lang_types__Int lang_types__String_lastIndexOf(lang_types__String this, lang_types__Char c) {
    lang_types__Int i = strlen(this);
    while (i) {
        if (lang_types____OP_IDX_String_SizeT__Char(this, i) == c) {
            return i;
        }
        i -= 1;
    }
    return -1;
}

lang_types__String lang_types__String_substring_tillEnd(lang_types__String this, lang_types__Int start) {
    lang_types__Int len = strlen(this);
    if (start > len) {
        lang_types__Exception_throw(lang_types__Exception_new_originMsg((lang_types__Class*) (lang_types__String_class()), lang_types__String_format("String.substring: out of bounds: length = %zd, start = %zd\n", len, start)));
        return ((lang_types__String) (NULL));
    }
    lang_types__SizeT diff = (len - start);
    lang_types__String sub = lang_types__String_new_withLength(diff);
    memcpy(sub, (((lang_types__Char*) (this))) + start, diff);
    lang_types____OP_IDX_ASS_String_SizeT_Char(sub, diff, '\0');
    return sub;
}

lang_types__String lang_types__String_substring(lang_types__String this, lang_types__Int start, lang_types__Int end) {
    lang_types__Int len = strlen(this);
    if (start == end) {
        return "";
    }
    if (end < 0) {
        end = len + end + 1;
    }
    if (start > len || start > end || end > len) {
        lang_types__Exception_throw(lang_types__Exception_new_originMsg((lang_types__Class*) (lang_types__String_class()), lang_types__String_format("String.substring: out of bounds: length = %zd, start = %zd, end = %zd\n", len, start, end)));
        return ((lang_types__String) (NULL));
    }
    lang_types__Int diff = (end - start);
    lang_types__String sub = lang_types__String_new_withLength(diff);
    memcpy(sub, (((lang_types__Char*) (this))) + start, diff);
    return sub;
}

lang_types__String lang_types__String_reverse(lang_types__String this) {
    lang_types__Int len = strlen(this);
    if (!len) {
        return ((lang_types__String) (NULL));
    }
    lang_types__String result = lang_types__String_new_withLength(len + 1);
    
    {
        lang_types__SizeT i;
        for (i = 0; i < len; i++) {
            lang_types____OP_IDX_ASS_String_SizeT_Char(result, i, lang_types____OP_IDX_String_SizeT__Char(this, (len - 1) - i));
        }
    }
    lang_types____OP_IDX_ASS_String_SizeT_Char(result, len, 0);
    return result;
}

void lang_types__String_print(lang_types__String this) {
    printf("%s", this);
    fflush(stdout);
}

void lang_types__String_println(lang_types__String this) {
    printf("%s\n", this);
}

lang_types__String lang_types__String_times(lang_types__String this, lang_types__Int count) {
    lang_types__Int length = strlen(this);
    lang_types__Char* result = ((lang_types__Char*) (GC_MALLOC((length * count) + 1)));
    
    {
        lang_types__Int i;
        for (i = 0; i < count; i++) {
            memcpy(result + (i * length), this, length);
        }
    }
    result[length * count] = '\0';
    return ((lang_types__String) (result));
}

lang_types__String lang_types__String_clone(lang_types__String this) {
    lang_types__Int length = strlen(this);
    lang_types__String copy = lang_types__String_new_withLength(length);
    memcpy(copy, this, length + 1);
    return copy;
}

lang_types__String lang_types__String_append(lang_types__String this, lang_types__String other) {
    lang_types__Int length = strlen(this);
    lang_types__Int rlength = strlen(other);
    lang_types__Char* copy = ((lang_types__Char*) (lang_types__String_new_withLength(length + rlength)));
    memcpy(copy, this, length);
    memcpy(copy + length, other, rlength + 1);
    return ((lang_types__String) (copy));
}

lang_types__String lang_types__String_append_char(lang_types__String this, lang_types__Char other) {
    lang_types__Int length = strlen(this);
    lang_types__Char* copy = ((lang_types__Char*) (lang_types__String_new_withLength(length + 1)));
    memcpy(copy, this, length);
    copy[length] = other;
    copy[length + 1] = '\0';
    return ((lang_types__String) (copy));
}

lang_types__Int lang_types__String_count_char(lang_types__String this, lang_types__Char what) {
    lang_types__Int count = 0;
    
    {
        lang_types__Int i;
        for (i = 0; i < strlen(this); i++) {
            if (lang_types____OP_IDX_String_SizeT__Char(this, i) == what) {
                count += 1;
            }
        }
    }
    return count;
}

lang_types__Int lang_types__String_count_string(lang_types__String this, lang_types__String what) {
    lang_types__Int length = strlen(this);
    lang_types__Int whatLength = strlen(what);
    lang_types__Int count = 0;
    lang_types__Int i = 0;
    while (i < length) {
        if (lang_types__String_compare(this, what, i, whatLength)) {
            count += 1;
            i += whatLength;
        }
        else {
            i += 1;
        }
    }
    return count;
}

lang_types__String lang_types__String_replace(lang_types__String this, lang_types__Char oldie, lang_types__Char kiddo) {
    if (!lang_types__String_contains_char(this, oldie)) {
        return this;
    }
    lang_types__Int length = strlen(this);
    lang_types__String copy = lang_types__String_clone(this);
    
    {
        lang_types__Int i;
        for (i = 0; i < length; i++) {
            if (lang_types____OP_IDX_String_SizeT__Char(copy, i) == oldie) {
                lang_types____OP_IDX_ASS_String_SizeT_Char(copy, i, kiddo);
            }
        }
    }
    return copy;
}

lang_types__String lang_types__String_replace_string(lang_types__String this, lang_types__String oldie, lang_types__String kiddo) {
    if (!lang_types__String_contains_string(this, oldie)) {
        return this;
    }
    lang_types__Int length = strlen(this);
    lang_types__Int oldieLength = strlen(oldie);
    text_Buffer__Buffer* buffer = text_Buffer__Buffer_new_withCapa(length);
    lang_types__Int i = 0;
    while (i < length) {
        if (lang_types__String_compare(this, oldie, i, oldieLength)) {
            text_Buffer__Buffer_append_str(buffer, kiddo);
            i += oldieLength;
        }
        else {
            text_Buffer__Buffer_append_chr(buffer, (((lang_types__Char*) (this)))[i]);
            i += 1;
        }
    }
    return text_Buffer__Buffer_toString(buffer);
}

lang_types__String lang_types__String_prepend(lang_types__String this, lang_types__String other) {
    return lang_types__String_append(other, this);
}

lang_types__String lang_types__String_prepend_char(lang_types__String this, lang_types__Char other) {
    lang_types__Int length = strlen(this);
    lang_types__Char* copy = ((lang_types__Char*) (lang_types__String_new_withLength(length + 1)));
    copy[0] = other;
    memcpy(copy + 1, this, length);
    return ((lang_types__String) (copy));
}

lang_types__String lang_types__String_toLower(lang_types__String this) {
    lang_types__Int length = strlen(this);
    lang_types__Char* copy = ((lang_types__Char*) (lang_types__String_new_withLength(length)));
    
    {
        lang_types__Int i;
        for (i = 0; i < length; i++) {
            copy[i] = tolower(((lang_types__Char) (lang_types____OP_IDX_String_SizeT__Char(this, i))));
        }
    }
    return ((lang_types__String) (copy));
}

lang_types__String lang_types__String_toUpper(lang_types__String this) {
    lang_types__Int length = strlen(this);
    lang_types__Char* copy = ((lang_types__Char*) (lang_types__String_new_withLength(length)));
    
    {
        lang_types__Int i;
        for (i = 0; i < length; i++) {
            copy[i] = toupper(((lang_types__Char) (lang_types____OP_IDX_String_SizeT__Char(this, i))));
        }
    }
    return ((lang_types__String) (copy));
}

lang_types__Char lang_types__String_charAt(lang_types__String this, lang_types__SizeT index) {
    if (index < (lang_types__SizeT) 0 || index > (lang_types__SizeT) strlen(this)) {
        lang_types__Exception_throw(lang_types__Exception_new_originMsg((lang_types__Class*) (lang_types__String_class()), lang_types__String_format("Accessing a String out of bounds index = %d, length = %d!", index, strlen(this))));
    }
    return (((lang_types__Char*) (this)))[index];
}

lang_types__String lang_types__String_format(lang_types__String this, ...) {
    lang_vararg__VaList list;
    va_start(list, this);
    lang_types__Int length = vsnprintf(NULL, 0, this, list);
    lang_types__String output = lang_types__String_new_withLength(length);
    va_end(list);
    va_start(list, this);
    vsnprintf(output, length + 1, this, list);
    va_end(list);
    return output;
}

lang_types__Int lang_types__String_scanf(lang_types__String this, lang_types__String format, ...) {
    lang_vararg__VaList list;
    va_start(list, format);
    lang_types__Int retval = vsscanf(this, format, list);
    va_end(list);
    return retval;
}

lang_types__StringIterator* lang_types__String_iterator(lang_types__String this) {
    return lang_types__StringIterator_new_withStr((lang_types__Class*)lang_types__Char_class(), this);
}
lang_types__String lang_types__String_new_withLength(lang_types__Int length) {
    
    lang_types__Char* result = ((lang_types__Char*) (GC_MALLOC(length + 1)));
    result[length] = '\0';
    return ((lang_types__String) (result));
}
lang_types__String lang_types__String_new_withChar(lang_types__Char c) {
    
    lang_types__String result = lang_types__String_new_withLength(1);
    lang_types____OP_IDX_ASS_String_SizeT_Char(result, 0, c);
    return result;
}

lang_types__StringClass *lang_types__String_class(){
    static lang_types__StringClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__String),
                    .size = sizeof(lang_types__String),
                    .name = "String",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    return &class;
}

lang_types__Int lang_types__Comparable_compareTo(Comparable__reference this, lang_types__Class* T, uint8_t* other) {
    return (lang_types__Int) this.impl->compareTo(this.obj, T, other);
}

lang_types__ComparableClass *lang_types__Comparable_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__ComparableClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__Comparable),
                    .size = sizeof(void*),
                    .name = "Comparable",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Object_class();
        __done__ = true;
    }
    return &class;
}

lang_types__String lang_types__LLong_toString(lang_types__LLong this) {
    return lang_types__String_format("%lld", this);
}

lang_types__String lang_types__LLong_toHexString(lang_types__LLong this) {
    return lang_types__String_format("%llx", this);
}

lang_types__Bool lang_types__LLong_isOdd(lang_types__LLong this) {
    return this % 2 == (lang_types__LLong) 1;
}

lang_types__Bool lang_types__LLong_isEven(lang_types__LLong this) {
    return this % 2 == (lang_types__LLong) 0;
}

lang_types__Bool lang_types__LLong_in(lang_types__LLong this, lang_types__Range range) {
    return this >= (lang_types__LLong) range.min && this < (lang_types__LLong) range.max;
}

lang_types__LLongClass *lang_types__LLong_class(){
    static lang_types__LLongClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__LLong),
                    .size = sizeof(lang_types__LLong),
                    .name = "LLong",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    return &class;
}

lang_types__LongClass *lang_types__Long_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__LongClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__Long),
                        .size = sizeof(lang_types__Long),
                        .name = "Long",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__LLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__IntClass *lang_types__Int_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__IntClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__Int),
                        .size = sizeof(lang_types__Int),
                        .name = "Int",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__LLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__ShortClass *lang_types__Short_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__ShortClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__Short),
                        .size = sizeof(lang_types__Short),
                        .name = "Short",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__LLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__String lang_types__ULLong_toString(lang_types__ULLong this) {
    return lang_types__String_format("%llu", this);
}

lang_types__Bool lang_types__ULLong_in(lang_types__ULLong this, lang_types__Range range) {
    return this >= (lang_types__ULLong) range.min && this < (lang_types__ULLong) range.max;
}

lang_types__ULLongClass *lang_types__ULLong_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__ULLongClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__ULLong),
                        .size = sizeof(lang_types__ULLong),
                        .name = "ULLong",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__LLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__ULongClass *lang_types__ULong_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__ULongClass class = 
    {
        {
            {
                {
                    {
                        {
                            .instanceSize = sizeof(lang_types__ULong),
                            .size = sizeof(lang_types__ULong),
                            .name = "ULong",
                        },
                        .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                        .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                    },
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__ULLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__UIntClass *lang_types__UInt_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__UIntClass class = 
    {
        {
            {
                {
                    {
                        {
                            .instanceSize = sizeof(lang_types__UInt),
                            .size = sizeof(lang_types__UInt),
                            .name = "UInt",
                        },
                        .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                        .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                    },
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__ULLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__UShortClass *lang_types__UShort_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__UShortClass class = 
    {
        {
            {
                {
                    {
                        {
                            .instanceSize = sizeof(lang_types__UShort),
                            .size = sizeof(lang_types__UShort),
                            .name = "UShort",
                        },
                        .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                        .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                    },
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__ULLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__Int8Class *lang_types__Int8_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__Int8Class class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__Int8),
                        .size = sizeof(lang_types__Int8),
                        .name = "Int8",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__LLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__Int16Class *lang_types__Int16_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__Int16Class class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__Int16),
                        .size = sizeof(lang_types__Int16),
                        .name = "Int16",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__LLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__Int32Class *lang_types__Int32_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__Int32Class class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__Int32),
                        .size = sizeof(lang_types__Int32),
                        .name = "Int32",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__LLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__Int64Class *lang_types__Int64_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__Int64Class class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__Int64),
                        .size = sizeof(lang_types__Int64),
                        .name = "Int64",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__LLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__UInt8Class *lang_types__UInt8_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__UInt8Class class = 
    {
        {
            {
                {
                    {
                        {
                            .instanceSize = sizeof(lang_types__UInt8),
                            .size = sizeof(lang_types__UInt8),
                            .name = "UInt8",
                        },
                        .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                        .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                    },
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__ULLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__UInt16Class *lang_types__UInt16_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__UInt16Class class = 
    {
        {
            {
                {
                    {
                        {
                            .instanceSize = sizeof(lang_types__UInt16),
                            .size = sizeof(lang_types__UInt16),
                            .name = "UInt16",
                        },
                        .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                        .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                    },
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__ULLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__UInt32Class *lang_types__UInt32_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__UInt32Class class = 
    {
        {
            {
                {
                    {
                        {
                            .instanceSize = sizeof(lang_types__UInt32),
                            .size = sizeof(lang_types__UInt32),
                            .name = "UInt32",
                        },
                        .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                        .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                    },
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__ULLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__UInt64Class *lang_types__UInt64_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__UInt64Class class = 
    {
        {
            {
                {
                    {
                        {
                            .instanceSize = sizeof(lang_types__UInt64),
                            .size = sizeof(lang_types__UInt64),
                            .name = "UInt64",
                        },
                        .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                        .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                    },
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__ULLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__OctetClass *lang_types__Octet_class(){
    static lang_types__OctetClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__Octet),
                    .size = sizeof(lang_types__Octet),
                    .name = "Octet",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    return &class;
}

lang_types__SizeTClass *lang_types__SizeT_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__SizeTClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__SizeT),
                        .size = sizeof(lang_types__SizeT),
                        .name = "SizeT",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__LLong_class();
        __done__ = true;
    }
    return &class;
}

lang_types__String lang_types__Bool_toString(lang_types__Bool this) {
    return this ? "true" : "false";
}

lang_types__BoolClass *lang_types__Bool_class(){
    static lang_types__BoolClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__Bool),
                    .size = sizeof(lang_types__Bool),
                    .name = "Bool",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    return &class;
}

lang_types__String lang_types__LDouble_toString(lang_types__LDouble this) {
    lang_types__String str = GC_MALLOC(64);
    sprintf(str, "%.2Lf", this);
    return str;
}

lang_types__LDouble lang_types__LDouble_abs(lang_types__LDouble this) {
    return this < (lang_types__LDouble) 0 ? -this : this;
}

lang_types__LDoubleClass *lang_types__LDouble_class(){
    static lang_types__LDoubleClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__LDouble),
                    .size = sizeof(lang_types__LDouble),
                    .name = "LDouble",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    return &class;
}

lang_types__FloatClass *lang_types__Float_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__FloatClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__Float),
                        .size = sizeof(lang_types__Float),
                        .name = "Float",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__LDouble_class();
        __done__ = true;
    }
    return &class;
}

lang_types__DoubleClass *lang_types__Double_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__DoubleClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__Double),
                        .size = sizeof(lang_types__Double),
                        .name = "Double",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
        },
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__LDouble_class();
        __done__ = true;
    }
    return &class;
}
lang_types__Range lang_types__Range_new(lang_types__Int min, lang_types__Int max) {
    
    lang_types__Range this;
    this.min = min;
    this.max = max;
    return this;
}

lang_types__RangeClass *lang_types__Range_class(){
    static lang_types__RangeClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__Range),
                    .size = sizeof(lang_types__Range),
                    .name = "Range",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
    };
    return &class;
}

void lang_types__Iterator_init_impl(lang_types__Iterator* this) {
}

void lang_types__Iterator_init(lang_types__Iterator* this) {
    ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->init((lang_types__Iterator*)this);
}

lang_types__Bool lang_types__Iterator_hasNext(lang_types__Iterator* this) {
    return (lang_types__Bool) ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->hasNext((lang_types__Iterator*)this);
}

void lang_types__Iterator_next(lang_types__Iterator* this, uint8_t* __returnArg31) {
    ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->next((lang_types__Iterator*)this, __returnArg31);
}

lang_types__Bool lang_types__Iterator_hasPrev(lang_types__Iterator* this) {
    return (lang_types__Bool) ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->hasPrev((lang_types__Iterator*)this);
}

void lang_types__Iterator_prev(lang_types__Iterator* this, uint8_t* __returnArg32) {
    ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->prev((lang_types__Iterator*)this, __returnArg32);
}

lang_types__Bool lang_types__Iterator_remove(lang_types__Iterator* this) {
    return (lang_types__Bool) ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->remove((lang_types__Iterator*)this);
}

lang_types__IteratorClass *lang_types__Iterator_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__IteratorClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__Iterator),
                    .size = sizeof(void*),
                    .name = "Iterator",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
        .init = lang_types__Iterator_init_impl,
        .hasNext = lang_types__Iterator_hasNext,
        .next = lang_types__Iterator_next,
        .hasPrev = lang_types__Iterator_hasPrev,
        .prev = lang_types__Iterator_prev,
        .remove = lang_types__Iterator_remove,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Object_class();
        __done__ = true;
    }
    return &class;
}

void lang_types__Iterable_init_impl(lang_types__Iterable* this) {
}

structs_ArrayList__ArrayList* lang_types__Iterable_toArrayList_impl(lang_types__Iterable* this) {
    structs_ArrayList__ArrayList* result = structs_ArrayList__ArrayList_new((lang_types__Class*)this->T);
    
    {
        uint8_t* elem = GC_MALLOC(this->T->size);
        
        {
            lang_types__Iterator* __iter1 = lang_types__Iterable_iterator(this);
            while (lang_types__Iterator_hasNext(__iter1)) {
                lang_types__Iterator_next(__iter1, elem);
                structs_ArrayList__ArrayList_add(result, (uint8_t*) elem);
            }
        }
    }
    return result;
}

void lang_types__Iterable_init(lang_types__Iterable* this) {
    ((lang_types__IterableClass *)((lang_types__Object *)this)->class)->init((lang_types__Iterable*)this);
}

lang_types__Iterator* lang_types__Iterable_iterator(lang_types__Iterable* this) {
    return (lang_types__Iterator*) ((lang_types__IterableClass *)((lang_types__Object *)this)->class)->iterator((lang_types__Iterable*)this);
}

structs_ArrayList__ArrayList* lang_types__Iterable_toArrayList(lang_types__Iterable* this) {
    return (structs_ArrayList__ArrayList*) ((lang_types__IterableClass *)((lang_types__Object *)this)->class)->toArrayList((lang_types__Iterable*)this);
}

lang_types__IterableClass *lang_types__Iterable_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__IterableClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__Iterable),
                    .size = sizeof(void*),
                    .name = "Iterable",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
        .init = lang_types__Iterable_init_impl,
        .iterator = lang_types__Iterable_iterator,
        .toArrayList = lang_types__Iterable_toArrayList_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Object_class();
        __done__ = true;
    }
    return &class;
}

void lang_types__StringIterator_init_withStr_impl(lang_types__StringIterator* this, lang_types__String str) {
    this->str = str;
}

lang_types__Bool lang_types__StringIterator_hasNext_impl(lang_types__StringIterator* this) {
    return this->i < strlen(this->str);
}

void lang_types__StringIterator_next_impl(lang_types__StringIterator* this, uint8_t* __returnArg16) {
    lang_types__Char c = lang_types____OP_IDX_String_SizeT__Char(this->str, this->i);
    this->i += 1;
    if (__returnArg16) {
        memcpy(__returnArg16, &(c), ((lang_types__Iterator*) this)->T->size);
    }
    return;
}

lang_types__Bool lang_types__StringIterator_hasPrev_impl(lang_types__StringIterator* this) {
    return this->i > 0;
}

void lang_types__StringIterator_prev_impl(lang_types__StringIterator* this, uint8_t* __returnArg17) {
    this->i -= 1;
    lang_types__Char __returnVal18 = lang_types____OP_IDX_String_SizeT__Char(this->str, this->i);
    if (__returnArg17) {
        memcpy(__returnArg17, &(__returnVal18), ((lang_types__Iterator*) this)->T->size);
    }
    return;
}

lang_types__Bool lang_types__StringIterator_remove_impl(lang_types__StringIterator* this) {
    return false;
}

void lang_types__StringIterator___defaults___impl(lang_types__StringIterator* this) {lang_types__Object___defaults___impl((lang_types__Object*) this);
    this->i = 0;
}

void lang_types__StringIterator_init_withStr(lang_types__StringIterator* this, lang_types__String str) {
    ((lang_types__StringIteratorClass *)((lang_types__Object *)this)->class)->init_withStr((lang_types__StringIterator*)this, str);
}

lang_types__Bool lang_types__StringIterator_hasNext(lang_types__StringIterator* this) {
    return (lang_types__Bool) ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->hasNext((lang_types__Iterator*)this);
}

void lang_types__StringIterator_next(lang_types__StringIterator* this, uint8_t* __returnArg16) {
    ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->next((lang_types__Iterator*)this, __returnArg16);
}

lang_types__Bool lang_types__StringIterator_hasPrev(lang_types__StringIterator* this) {
    return (lang_types__Bool) ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->hasPrev((lang_types__Iterator*)this);
}

void lang_types__StringIterator_prev(lang_types__StringIterator* this, uint8_t* __returnArg17) {
    ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->prev((lang_types__Iterator*)this, __returnArg17);
}

lang_types__Bool lang_types__StringIterator_remove(lang_types__StringIterator* this) {
    return (lang_types__Bool) ((lang_types__IteratorClass *)((lang_types__Object *)this)->class)->remove((lang_types__Iterator*)this);
}

void lang_types__StringIterator___defaults__(lang_types__StringIterator* this) {
    ((lang_types__ObjectClass *)((lang_types__Object *)this)->class)->__defaults__((lang_types__Object*)this);
}
lang_types__StringIterator* lang_types__StringIterator_new_withStr(lang_types__Class* T, lang_types__String str) {
    
    lang_types__StringIterator* this = ((lang_types__StringIterator*) (lang_types__Class_alloc__class((lang_types__Class*) lang_types__StringIterator_class())));
    ((lang_types__Iterator*) this)->T = T;
    lang_types__StringIterator___defaults__(this);
    lang_types__StringIterator_init_withStr(this, str);
    return this;
}

lang_types__StringIteratorClass *lang_types__StringIterator_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__StringIteratorClass class = 
    {
        {
            {
                {
                    {
                        .instanceSize = sizeof(lang_types__StringIterator),
                        .size = sizeof(void*),
                        .name = "StringIterator",
                    },
                    .__defaults__ = (void (*)(lang_types__Object*)) lang_types__StringIterator___defaults___impl,
                    .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
                },
            },
            .init = (void (*)(lang_types__Iterator*)) lang_types__Iterator_init_impl,
            .hasNext = (lang_types__Bool (*)(lang_types__Iterator*)) lang_types__StringIterator_hasNext_impl,
            .next = (void (*)(lang_types__Iterator*, uint8_t*)) lang_types__StringIterator_next_impl,
            .hasPrev = (lang_types__Bool (*)(lang_types__Iterator*)) lang_types__StringIterator_hasPrev_impl,
            .prev = (void (*)(lang_types__Iterator*, uint8_t*)) lang_types__StringIterator_prev_impl,
            .remove = (lang_types__Bool (*)(lang_types__Iterator*)) lang_types__StringIterator_remove_impl,
        },
        .new_withStr = lang_types__StringIterator_new_withStr,
        .init_withStr = lang_types__StringIterator_init_withStr_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Iterator_class();
        __done__ = true;
    }
    return &class;
}

void lang_types__Cell_init_impl(lang_types__Cell* this, uint8_t* val) {
    memcpy(this->val, val, this->T->size);
}

void lang_types__Cell___defaults___impl(lang_types__Cell* this) {lang_types__Object___defaults___impl((lang_types__Object*) this);
    this->val = GC_MALLOC(this->T->size);
}

void lang_types__Cell_init(lang_types__Cell* this, uint8_t* val) {
    ((lang_types__CellClass *)((lang_types__Object *)this)->class)->init((lang_types__Cell*)this, val);
}

void lang_types__Cell___defaults__(lang_types__Cell* this) {
    ((lang_types__ObjectClass *)((lang_types__Object *)this)->class)->__defaults__((lang_types__Object*)this);
}
lang_types__Cell* lang_types__Cell_new(lang_types__Class* T, uint8_t* val) {
    
    lang_types__Cell* this = ((lang_types__Cell*) (lang_types__Class_alloc__class((lang_types__Class*) lang_types__Cell_class())));
    this->T = T;
    lang_types__Object___defaults__((lang_types__Object*) this);
    lang_types__Cell_init(this, (uint8_t*) val);
    return this;
}

lang_types__CellClass *lang_types__Cell_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__CellClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__Cell),
                    .size = sizeof(void*),
                    .name = "Cell",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Cell___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
        .new = lang_types__Cell_new,
        .init = lang_types__Cell_init_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Object_class();
        __done__ = true;
    }
    return &class;
}

void lang_types__Exception_init_originMsg_impl(lang_types__Exception* this, lang_types__Class* origin, lang_types__String msg) {
    this->msg = msg;
    this->origin = origin;
}

void lang_types__Exception_init_noOrigin_impl(lang_types__Exception* this, lang_types__String msg) {
    this->msg = msg;
}

void lang_types__Exception_crash_impl(lang_types__Exception* this) {
    fflush(stdout);
    lang_types__Int x = 0;
    x = 1 / x;
    printf("%d", x);
}

lang_types__String lang_types__Exception_getMessage_impl(lang_types__Exception* this) {
    lang_types__Int max = 1024;
    lang_types__String buffer = ((lang_types__String) (GC_MALLOC(max)));
    if (this->origin) {
        snprintf(buffer, max, "[%s in %s]: %s\n", ((lang_types__Object*) (this))->class->name, this->origin->name, this->msg);
    }
    else {
        snprintf(buffer, max, "[%s]: %s\n", ((lang_types__Object*) (this))->class->name, this->msg);
    }
    return buffer;
}

void lang_types__Exception_print_impl(lang_types__Exception* this) {
    fprintf(stderr, "%s", lang_types__Exception_getMessage(this));
}

void lang_types__Exception_throw_impl(lang_types__Exception* this) {
    lang_types__Exception_print(this);
    lang_types__Exception_crash(this);
}

void lang_types__Exception_init_originMsg(lang_types__Exception* this, lang_types__Class* origin, lang_types__String msg) {
    ((lang_types__ExceptionClass *)((lang_types__Object *)this)->class)->init_originMsg((lang_types__Exception*)this, origin, msg);
}

void lang_types__Exception_init_noOrigin(lang_types__Exception* this, lang_types__String msg) {
    ((lang_types__ExceptionClass *)((lang_types__Object *)this)->class)->init_noOrigin((lang_types__Exception*)this, msg);
}

void lang_types__Exception_crash(lang_types__Exception* this) {
    ((lang_types__ExceptionClass *)((lang_types__Object *)this)->class)->crash((lang_types__Exception*)this);
}

lang_types__String lang_types__Exception_getMessage(lang_types__Exception* this) {
    return (lang_types__String) ((lang_types__ExceptionClass *)((lang_types__Object *)this)->class)->getMessage((lang_types__Exception*)this);
}

void lang_types__Exception_print(lang_types__Exception* this) {
    ((lang_types__ExceptionClass *)((lang_types__Object *)this)->class)->print((lang_types__Exception*)this);
}

void lang_types__Exception_throw(lang_types__Exception* this) {
    ((lang_types__ExceptionClass *)((lang_types__Object *)this)->class)->throw((lang_types__Exception*)this);
}
lang_types__Exception* lang_types__Exception_new_originMsg(lang_types__Class* origin, lang_types__String msg) {
    
    lang_types__Exception* this = ((lang_types__Exception*) (lang_types__Class_alloc__class((lang_types__Class*) lang_types__Exception_class())));
    lang_types__Object___defaults__((lang_types__Object*) this);
    lang_types__Exception_init_originMsg(this, origin, msg);
    return this;
}
lang_types__Exception* lang_types__Exception_new_noOrigin(lang_types__String msg) {
    
    lang_types__Exception* this = ((lang_types__Exception*) (lang_types__Class_alloc__class((lang_types__Class*) lang_types__Exception_class())));
    lang_types__Object___defaults__((lang_types__Object*) this);
    lang_types__Exception_init_noOrigin(this, msg);
    return this;
}

lang_types__ExceptionClass *lang_types__Exception_class(){
    static lang_types__Bool __done__ = false;
    static lang_types__ExceptionClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(lang_types__Exception),
                    .size = sizeof(void*),
                    .name = "Exception",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
        .new_originMsg = lang_types__Exception_new_originMsg,
        .init_originMsg = lang_types__Exception_init_originMsg_impl,
        .new_noOrigin = lang_types__Exception_new_noOrigin,
        .init_noOrigin = lang_types__Exception_init_noOrigin_impl,
        .crash = lang_types__Exception_crash_impl,
        .getMessage = lang_types__Exception_getMessage_impl,
        .print = lang_types__Exception_print_impl,
        .throw = lang_types__Exception_throw_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Object_class();
        __done__ = true;
    }
    return &class;
}
lang_types__Int lang_types__INT_MAX;
lang_types__Int lang_types__INT_MIN;
void lang_types_load() {
    static bool __done__ = false;
    if (!__done__){
        __done__ = true;
        lang_stdio_load();
        lang_memory_load();
        lang_system_load();
        lang_string_load();
        lang_vararg_load();
        structs_List_load();
        structs_ArrayList_load();
        text_Buffer_load();
        lang_types__INT_MAX = 2147483647;
        lang_types__INT_MIN = -lang_types__INT_MAX - 1;
    }
}


lang_types__String lang_types____OP_AS_Char__String(lang_types__Char value) {
    return lang_types__Char_toString(value);
}

lang_types__Bool lang_types____OP_EQ_String_String__Bool(lang_types__String str1, lang_types__String str2) {
    return lang_types__String_equals(str1, str2);
}

lang_types__Bool lang_types____OP_NE_String_String__Bool(lang_types__String str1, lang_types__String str2) {
    return !lang_types__String_equals(str1, str2);
}

lang_types__Char lang_types____OP_IDX_String_SizeT__Char(lang_types__String string, lang_types__SizeT index) {
    return lang_types__String_charAt(string, index);
}

void lang_types____OP_IDX_ASS_String_SizeT_Char(lang_types__String string, lang_types__SizeT index, lang_types__Char value) {
    if (index < (lang_types__SizeT) 0 || index > (lang_types__SizeT) strlen(string)) {
        lang_types__Exception_throw(lang_types__Exception_new_originMsg((lang_types__Class*) (lang_types__String_class()), lang_types__String_format("Writing to a String out of bounds index = %d, length = %d!", index, strlen(string))));
    }
    (((lang_types__Char*) (string)))[index] = value;
}

lang_types__String lang_types____OP_IDX_String_Range__String(lang_types__String string, lang_types__Range range) {
    return lang_types__String_substring(string, range.min, range.max);
}

lang_types__String lang_types____OP_MUL_String_Int__String(lang_types__String str, lang_types__Int count) {
    return lang_types__String_times(str, count);
}

lang_types__String lang_types____OP_ADD_String_String__String(lang_types__String left, lang_types__String right) {
    return lang_types__String_append(left, right);
}

lang_types__String lang_types____OP_ADD_LLong_String__String(lang_types__LLong left, lang_types__String right) {
    return lang_types____OP_ADD_String_String__String(lang_types__LLong_toString(left), right);
}

lang_types__String lang_types____OP_ADD_String_LLong__String(lang_types__String left, lang_types__LLong right) {
    return lang_types____OP_ADD_String_String__String(left, lang_types__LLong_toString(right));
}

lang_types__String lang_types____OP_ADD_Int_String__String(lang_types__Int left, lang_types__String right) {
    return lang_types____OP_ADD_String_String__String(lang_types__LLong_toString((lang_types__LLong) left), right);
}

lang_types__String lang_types____OP_ADD_String_Int__String(lang_types__String left, lang_types__Int right) {
    return lang_types____OP_ADD_String_String__String(left, lang_types__LLong_toString((lang_types__LLong) right));
}

lang_types__String lang_types____OP_ADD_Bool_String__String(lang_types__Bool left, lang_types__String right) {
    return lang_types____OP_ADD_String_String__String(lang_types__Bool_toString(left), right);
}

lang_types__String lang_types____OP_ADD_String_Bool__String(lang_types__String left, lang_types__Bool right) {
    return lang_types____OP_ADD_String_String__String(left, lang_types__Bool_toString(right));
}

lang_types__String lang_types____OP_ADD_Double_String__String(lang_types__Double left, lang_types__String right) {
    return lang_types____OP_ADD_String_String__String(lang_types__LDouble_toString((lang_types__LDouble) left), right);
}

lang_types__String lang_types____OP_ADD_String_Double__String(lang_types__String left, lang_types__Double right) {
    return lang_types____OP_ADD_String_String__String(left, lang_types__LDouble_toString((lang_types__LDouble) right));
}

lang_types__String lang_types____OP_ADD_String_Char__String(lang_types__String left, lang_types__Char right) {
    return lang_types__String_append_char(left, right);
}

lang_types__String lang_types____OP_ADD_Char_String__String(lang_types__Char left, lang_types__String right) {
    return lang_types__String_prepend_char(right, left);
}
