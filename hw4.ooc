import math/[Matrix, Relation]

a = 0, b = 1, c = 2, d = 3, e = 4: Int

rels1 := [rel(a, d), rel(b, c), rel(c, b), rel(d, a), rel(e, a)]
m := Matrix new(rels1)
m toString() println()

"---------------------" println()

m transitiveClosure() toString() println()