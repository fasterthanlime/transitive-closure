/* math/Matrix header-forward file, generated with rock, the ooc compiler written in ooc */

#ifndef ___math_Matrix_fwd___
#define ___math_Matrix_fwd___

struct _math_Matrix__Matrix;
typedef struct _math_Matrix__Matrix math_Matrix__Matrix;
struct _math_Matrix__MatrixClass;
typedef struct _math_Matrix__MatrixClass math_Matrix__MatrixClass;

#include <sdk/lang/stdio-fwd.h>
#include <sdk/lang/types-fwd.h>
#include <sdk/lang/memory-fwd.h>
#include <sdk/lang/system-fwd.h>
#include <sdk/lang/string-fwd.h>
#include <sdk/lang/vararg-fwd.h>
#include <sdk/text/Buffer-fwd.h>
#include <./math/Relation-fwd.h>
math_Matrix__MatrixClass *math_Matrix__Matrix_class();
math_Matrix__Matrix* math_Matrix__Matrix_new_rowsCol(lang_types__Int rows, lang_types__Int cols);
void math_Matrix__Matrix_init_rowsCol(math_Matrix__Matrix* this, lang_types__Int rows, lang_types__Int cols);
void math_Matrix__Matrix_init_rowsCol_impl(math_Matrix__Matrix* this, lang_types__Int rows, lang_types__Int cols);
math_Matrix__Matrix* math_Matrix__Matrix_new_rels(_lang_array__Array rels);
void math_Matrix__Matrix_init_rels(math_Matrix__Matrix* this, _lang_array__Array rels);
void math_Matrix__Matrix_init_rels_impl(math_Matrix__Matrix* this, _lang_array__Array rels);
math_Matrix__Matrix* math_Matrix__Matrix_mul(math_Matrix__Matrix* this, math_Matrix__Matrix* other);
math_Matrix__Matrix* math_Matrix__Matrix_mul_impl(math_Matrix__Matrix* this, math_Matrix__Matrix* other);
math_Matrix__Matrix* math_Matrix__Matrix_or(math_Matrix__Matrix* this, math_Matrix__Matrix* other);
math_Matrix__Matrix* math_Matrix__Matrix_or_impl(math_Matrix__Matrix* this, math_Matrix__Matrix* other);
math_Matrix__Matrix* math_Matrix__Matrix_transitiveClosure(math_Matrix__Matrix* this);
math_Matrix__Matrix* math_Matrix__Matrix_transitiveClosure_impl(math_Matrix__Matrix* this);
lang_types__String math_Matrix__Matrix_toString(math_Matrix__Matrix* this);
lang_types__String math_Matrix__Matrix_toString_impl(math_Matrix__Matrix* this);
void math_Matrix_load();
_lang_array__Array math_Matrix____OP_IDX_Matrix_Int__Bool__array(math_Matrix__Matrix* m, lang_types__Int i);

#endif // ___math_Matrix_fwd___
