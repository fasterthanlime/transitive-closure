
Relation: class {
    
    a, b: Int
    
    init: func (=a, =b) {}
    
}

rel: func (a, b: Int) -> Relation {
    Relation new(a, b)
}
