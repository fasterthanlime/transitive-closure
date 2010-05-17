/* math/Matrix header file, generated with rock, the ooc compiler written in ooc */

#ifndef ___math_Matrix___
#define ___math_Matrix___

#include "Matrix-fwd.h"

#include <sdk/lang/types.h>

struct _math_Matrix__Matrix {
    struct _lang_types__Object __super__;
    lang_types__Int rows;
    lang_types__Int cols;
    _lang_array__Array data;
};


struct _math_Matrix__MatrixClass {
    struct _lang_types__ClassClass __super__;
    math_Matrix__Matrix* (*new_rowsCol)(lang_types__Int, lang_types__Int);
    void (*init_rowsCol)(math_Matrix__Matrix*, lang_types__Int, lang_types__Int);
    math_Matrix__Matrix* (*new_rels)(_lang_array__Array);
    void (*init_rels)(math_Matrix__Matrix*, _lang_array__Array);
    math_Matrix__Matrix* (*mul)(math_Matrix__Matrix*, math_Matrix__Matrix*);
    math_Matrix__Matrix* (*or)(math_Matrix__Matrix*, math_Matrix__Matrix*);
    math_Matrix__Matrix* (*transitiveClosure)(math_Matrix__Matrix*);
    lang_types__String (*toString)(math_Matrix__Matrix*);
};



#endif // ___math_Matrix___
