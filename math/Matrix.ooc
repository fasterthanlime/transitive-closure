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
        
        "Mr = " println()
        mr toString() println()
        
        // from 2 to n, inclusive
        for(i in 2..(rows + 1)) {
            a = a mul(mr)
            b = b or(a)
            
            "\n   ----------" println()
            "\nMr^%d = \n" format(i) println()
            a toString() println()
            "\nAt step %d, b = \n" format(i) println()
            b toString() println()
        }
        
        "\nFinal transitive closure boolean matrix = \n" println()
        b toString() println()
        b
    }
    
    warshall: func -> This {
        w := clone()
        n := rows
        
        for(k in 0..n) {
            for(i in 0..n) {
                for(j in 0..n) {
                    w[i][j] = w[i][j] || (w[i][k] && w[k][j])
                }
            }
            
            "\nAt step k = %d, the warshall matrix w = \n" format(k + 1) println()
            w toString() println()
        }
        
        "\nFinal warshall matrix = \n" println()
        w toString() println()
        
        w
    }
    
    clone: func -> This {
        copy := new(rows, cols)
        for(row in 0..rows) for(col in 0..cols) {
            copy[row][col] = this[row][col]
        }
        copy
    }
    
    printRelations: func (pretty: String) {
        for(row in 0..rows) for(col in 0..cols) {
            if(this[row][col]) {
                "(%c, %c) " format(pretty[row], pretty[col]) print()
            }
        }
        println()
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

