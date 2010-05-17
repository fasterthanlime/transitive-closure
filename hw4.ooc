import math/[Matrix, Relation]

a = 0, b = 1, c = 2, d = 3, e = 4: Int
pretty := "abcdef"

rels1 := [rel(a, d), rel(b, c), rel(c, b), rel(d, a), rel(e, a)]
"i.\n" println()
compute(rels1)

rels2 := [rel(a, b), rel(a, c), rel(b, a), rel(c, a), rel(c, b), rel(e, d)]
"ii.\n" println()
compute(rels2)

rels3 := [rel(a, b), rel(b, c), rel(b, e), rel(b, d), rel(c, b), rel(c, e), rel(d, a), rel(e, b), rel(e, c)]
"iii.\n" println()
compute(rels3)

rels4 := [rel(a, a), rel(a, b), rel(a, c), rel(a, d), rel(b, e), rel(c, d), rel(c, e), rel(d, a), rel(e, b), rel(e, d)]
"iv.\n" println()
compute(rels4)

// compute the transitive closure of a set of relations
compute: func (rels: Relation[]) {

    m := Matrix new(rels)
    "Initial relations:\n" println()
    m printRelations(pretty)
    println()
    
    //tc := m transitiveClosure()
    tc := m warshall()
    println()
    tc printRelations(pretty)
    "=====================\n" println()
    
}