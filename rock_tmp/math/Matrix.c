/* math/Matrix source file, generated with rock, the ooc compiler written in ooc */

#include "Matrix.h"

#include <sdk/lang/stdio.h>
#include <sdk/lang/memory.h>
#include <sdk/lang/system.h>
#include <sdk/lang/string.h>
#include <sdk/lang/vararg.h>
#include <sdk/text/Buffer.h>
#include <./math/Relation.h>


void math_Matrix__Matrix_init_rowsCol_impl(math_Matrix__Matrix* this, lang_types__Int rows, lang_types__Int cols) {
    this->cols = cols;
    this->rows = rows;
    this->data = _lang_array__Array_new(_lang_array__Array, rows);
    {
        int __arrayCrea36__i;
        for(__arrayCrea36__i = 0; __arrayCrea36__i < rows; __arrayCrea36__i++) { 
            _lang_array__Array __arrayCrea36_sub = _lang_array__Array_new(lang_types__Bool, cols);
            _lang_array__Array_set(this->data, __arrayCrea36__i, _lang_array__Array, __arrayCrea36_sub);
        }
    };
}

void math_Matrix__Matrix_init_rels_impl(math_Matrix__Matrix* this, _lang_array__Array rels) {
    lang_types__Int max = 0;
    
    {
        lang_types__Int i;
        for (i = 0; i < rels.length; i++) {
            math_Relation__Relation* rel = _lang_array__Array_get(rels, i, math_Relation__Relation*);
            if (rel->a > max) {
                max = rel->a;
            }
            if (rel->b > max) {
                max = rel->b;
            }
        }
    }
    math_Matrix__Matrix_init_rowsCol(this, max + 1, max + 1);
    
    {
        lang_types__Int i;
        for (i = 0; i < rels.length; i++) {
            math_Relation__Relation* rel = _lang_array__Array_get(rels, i, math_Relation__Relation*);
            _lang_array__Array_set(_lang_array__Array_get(this->data, rel->a, _lang_array__Array), rel->b, lang_types__Bool, true);
        }
    }
}

math_Matrix__Matrix* math_Matrix__Matrix_mul_impl(math_Matrix__Matrix* this, math_Matrix__Matrix* other) {
    math_Matrix__Matrix* a = this;
    math_Matrix__Matrix* b = other;
    math_Matrix__Matrix* c = math_Matrix__Matrix_new_rowsCol(a->rows, b->cols);
    if (a->cols != b->rows) {
        lang_types__Exception_throw(lang_types__Exception_new_originMsg((lang_types__Class*) (math_Matrix__Matrix_class()), lang_types__String_format("Can't multiply \n%s\n with \n%s.\nThe first one should have as many columns as the second has rows.", math_Matrix__Matrix_toString(a), math_Matrix__Matrix_toString(b))));
    }
    
    {
        lang_types__Int cRow;
        for (cRow = 0; cRow < c->rows; cRow++) {
            
            {
                lang_types__Int cCol;
                for (cCol = 0; cCol < c->cols; cCol++) {
                    lang_types__Bool sum = false;
                    
                    {
                        lang_types__Int aCol;
                        for (aCol = 0; aCol < a->cols; aCol++) {
                            sum = sum || (_lang_array__Array_get(math_Matrix____OP_IDX_Matrix_Int__Bool__array(a, cRow), aCol, lang_types__Bool) && _lang_array__Array_get(math_Matrix____OP_IDX_Matrix_Int__Bool__array(b, aCol), cCol, lang_types__Bool));
                        }
                    }
                    _lang_array__Array_set(math_Matrix____OP_IDX_Matrix_Int__Bool__array(c, cRow), cCol, lang_types__Bool, sum);
                }
            }
        }
    }
    return c;
}

math_Matrix__Matrix* math_Matrix__Matrix_or_impl(math_Matrix__Matrix* this, math_Matrix__Matrix* other) {
    math_Matrix__Matrix* a = this;
    math_Matrix__Matrix* b = other;
    if (a->rows != b->rows || a->cols != b->cols) {
        lang_types__Exception_throw(lang_types__Exception_new_originMsg((lang_types__Class*) (math_Matrix__Matrix_class()), lang_types__String_format("Can't or \n%s\n with \n%s.\nThey should have the same number of columns and rows.", math_Matrix__Matrix_toString(a), math_Matrix__Matrix_toString(b))));
    }
    math_Matrix__Matrix* c = math_Matrix__Matrix_new_rowsCol(a->rows, a->cols);
    
    {
        lang_types__Int row;
        for (row = 0; row < a->rows; row++) {
            
            {
                lang_types__Int col;
                for (col = 0; col < a->cols; col++) {
                    _lang_array__Array_set(math_Matrix____OP_IDX_Matrix_Int__Bool__array(c, row), col, lang_types__Bool, _lang_array__Array_get(math_Matrix____OP_IDX_Matrix_Int__Bool__array(a, row), col, lang_types__Bool) || _lang_array__Array_get(math_Matrix____OP_IDX_Matrix_Int__Bool__array(b, row), col, lang_types__Bool));
                }
            }
        }
    }
    return c;
}

math_Matrix__Matrix* math_Matrix__Matrix_transitiveClosure_impl(math_Matrix__Matrix* this) {
    math_Matrix__Matrix* mr = this;
    math_Matrix__Matrix* a = mr;
    math_Matrix__Matrix* b = a;
    
    {
        lang_types__Int i;
        for (i = 2; i < (this->rows + 1); i++) {
            a = math_Matrix__Matrix_mul(a, mr);
            b = math_Matrix__Matrix_or(b, a);
        }
    }
    return b;
}

lang_types__String math_Matrix__Matrix_toString_impl(math_Matrix__Matrix* this) {
    text_Buffer__Buffer* b = text_Buffer__Buffer_new();
    
    {
        lang_types__Int row;
        for (row = 0; row < this->data.length; row++) {
            text_Buffer__Buffer_append_str(b, "(");
            
            {
                lang_types__Int col;
                for (col = 0; col < _lang_array__Array_get(this->data, row, _lang_array__Array).length; col++) {
                    text_Buffer__Buffer_append_str(b, _lang_array__Array_get(_lang_array__Array_get(this->data, row, _lang_array__Array), col, lang_types__Bool) ? " 1 " : " 0 ");
                }
            }
            text_Buffer__Buffer_append_str(b, ")");
            if (row < this->data.length - 1) {
                text_Buffer__Buffer_append_str(b, "\n");
            }
        }
    }
    return text_Buffer__Buffer_toString(b);
}

void math_Matrix__Matrix_init_rowsCol(math_Matrix__Matrix* this, lang_types__Int rows, lang_types__Int cols) {
    ((math_Matrix__MatrixClass *)((lang_types__Object *)this)->class)->init_rowsCol((math_Matrix__Matrix*)this, rows, cols);
}

void math_Matrix__Matrix_init_rels(math_Matrix__Matrix* this, _lang_array__Array rels) {
    ((math_Matrix__MatrixClass *)((lang_types__Object *)this)->class)->init_rels((math_Matrix__Matrix*)this, rels);
}

math_Matrix__Matrix* math_Matrix__Matrix_mul(math_Matrix__Matrix* this, math_Matrix__Matrix* other) {
    return (math_Matrix__Matrix*) ((math_Matrix__MatrixClass *)((lang_types__Object *)this)->class)->mul((math_Matrix__Matrix*)this, other);
}

math_Matrix__Matrix* math_Matrix__Matrix_or(math_Matrix__Matrix* this, math_Matrix__Matrix* other) {
    return (math_Matrix__Matrix*) ((math_Matrix__MatrixClass *)((lang_types__Object *)this)->class)->or((math_Matrix__Matrix*)this, other);
}

math_Matrix__Matrix* math_Matrix__Matrix_transitiveClosure(math_Matrix__Matrix* this) {
    return (math_Matrix__Matrix*) ((math_Matrix__MatrixClass *)((lang_types__Object *)this)->class)->transitiveClosure((math_Matrix__Matrix*)this);
}

lang_types__String math_Matrix__Matrix_toString(math_Matrix__Matrix* this) {
    return (lang_types__String) ((math_Matrix__MatrixClass *)((lang_types__Object *)this)->class)->toString((math_Matrix__Matrix*)this);
}
math_Matrix__Matrix* math_Matrix__Matrix_new_rowsCol(lang_types__Int rows, lang_types__Int cols) {
    
    math_Matrix__Matrix* this = ((math_Matrix__Matrix*) (lang_types__Class_alloc__class((lang_types__Class*) math_Matrix__Matrix_class())));
    lang_types__Object___defaults__((lang_types__Object*) this);
    math_Matrix__Matrix_init_rowsCol(this, rows, cols);
    return this;
}
math_Matrix__Matrix* math_Matrix__Matrix_new_rels(_lang_array__Array rels) {
    
    math_Matrix__Matrix* this = ((math_Matrix__Matrix*) (lang_types__Class_alloc__class((lang_types__Class*) math_Matrix__Matrix_class())));
    lang_types__Object___defaults__((lang_types__Object*) this);
    math_Matrix__Matrix_init_rels(this, rels);
    return this;
}

math_Matrix__MatrixClass *math_Matrix__Matrix_class(){
    static lang_types__Bool __done__ = false;
    static math_Matrix__MatrixClass class = 
    {
        {
            {
                {
                    .instanceSize = sizeof(math_Matrix__Matrix),
                    .size = sizeof(void*),
                    .name = "Matrix",
                },
                .__defaults__ = (void (*)(lang_types__Object*)) lang_types__Object___defaults___impl,
                .__destroy__ = (void (*)(lang_types__Object*)) lang_types__Object___destroy___impl,
            },
        },
        .new_rowsCol = math_Matrix__Matrix_new_rowsCol,
        .init_rowsCol = math_Matrix__Matrix_init_rowsCol_impl,
        .new_rels = math_Matrix__Matrix_new_rels,
        .init_rels = math_Matrix__Matrix_init_rels_impl,
        .mul = math_Matrix__Matrix_mul_impl,
        .or = math_Matrix__Matrix_or_impl,
        .transitiveClosure = math_Matrix__Matrix_transitiveClosure_impl,
        .toString = math_Matrix__Matrix_toString_impl,
    };
    lang_types__Class *classPtr = (lang_types__Class *) &class;
    if(!__done__){
        classPtr->super = (lang_types__Class*) lang_types__Object_class();
        __done__ = true;
    }
    return &class;
}
void math_Matrix_load() {
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
        math_Relation_load();
    }
}


_lang_array__Array math_Matrix____OP_IDX_Matrix_Int__Bool__array(math_Matrix__Matrix* m, lang_types__Int i) {
    return _lang_array__Array_get(m->data, i, _lang_array__Array);
}
