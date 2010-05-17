import text/Buffer, Relation

/**
   A rows*cols boolean matrix
 */
Matrix: class {
 
    rows, cols: Int
    data: Bool[][]
    
    /**
       Construct an empty (all-false) rows*cols boolean matrix
     */
    init: func ~rowsCol (=rows, =cols) {
        data = Bool[rows][cols] new()
    }
    
    /**
       Construct the boolean matrix from a set of relations
     */
    init: func ~rels (rels: Relation[]) {
        // figure out the matrix's size from the given relations
        max := 0
        for(i in 0..rels length) {
            rel := rels[i]
            if(rel a > max) max = rel a
            if(rel b > max) max = rel b
        }
        // allocate the data
        init(max + 1, max + 1)
        
        for(i in 0..rels length) {
            rel := rels[i]
            data[rel a][rel b] = true
        }
    }
    
    /**
       :return: The result of the multiplication of this matrix
       with `other`
     */
    mul: func (other: This) -> This {
        // aliases
        a := this; b := other
        c := new(a rows, b cols)
        
        if(a cols != b rows) {
            Exception new(This, "Can't multiply \n%s\n with \n%s.\nThe first one should have as many columns as the second has rows." format(a toString(), b toString())) throw()
        }
        
        for(cRow in 0..c rows) {
            for(cCol in 0..c cols) {
                sum := false
                for(aCol in 0..a cols) {
                    sum = sum || (a[cRow][aCol] && b[aCol][cCol])
                }
                c[cRow][cCol] = sum
            }
        }
        
        c
    }
    
    or: func (other: This) -> This {
        // aliases
        a := this; b := other
        
        if(a rows != b rows || a cols != b cols) {
            Exception new(This, "Can't or \n%s\n with \n%s.\nThey should have the same number of columns and rows." format(a toString(), b toString())) throw()
        }
        
        c := new(a rows, a cols)
        for(row in 0..a rows) {
            for(col in 0..a cols) {
                c[row][col] = a[row][col] || b[row][col]
            }
        }
        
        c
    }
    
    transitiveClosure: func -> This {
        // aliases
        mr := this
        a := mr
        b := a
        
        // from 2 to n, inclusive
        for(i in 2..(rows + 1)) {
            a = a mul(mr)
            b = b or(a)
        }
        
        b
    }
 
    /**
       :return: A string representation of this matrix
     */
    toString: func -> String {
        b := Buffer new()
        for(row in 0..data length) {
            b append("(")
            for(col in 0..data[row] length) {
                b append(data[row][col] ? " 1 " : " 0 ")
            }
            b append(")")
            if(row < data length - 1) b append("\n")
        }
        b toString()
    }
    
}

operator[] (m: Matrix, i: Int) -> Bool[] { m data[i] }

