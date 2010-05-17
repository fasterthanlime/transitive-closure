/* math/Relation header-forward file, generated with rock, the ooc compiler written in ooc */

#ifndef ___math_Relation_fwd___
#define ___math_Relation_fwd___

struct _math_Relation__Relation;
typedef struct _math_Relation__Relation math_Relation__Relation;
struct _math_Relation__RelationClass;
typedef struct _math_Relation__RelationClass math_Relation__RelationClass;

#include <sdk/lang/stdio-fwd.h>
#include <sdk/lang/types-fwd.h>
#include <sdk/lang/memory-fwd.h>
#include <sdk/lang/system-fwd.h>
#include <sdk/lang/string-fwd.h>
#include <sdk/lang/vararg-fwd.h>
math_Relation__RelationClass *math_Relation__Relation_class();
math_Relation__Relation* math_Relation__Relation_new(lang_types__Int a, lang_types__Int b);
void math_Relation__Relation_init(math_Relation__Relation* this, lang_types__Int a, lang_types__Int b);
void math_Relation__Relation_init_impl(math_Relation__Relation* this, lang_types__Int a, lang_types__Int b);
void math_Relation_load();
math_Relation__Relation* math_Relation__rel(lang_types__Int a, lang_types__Int b);

#endif // ___math_Relation_fwd___
