package main

import ( 
	"fmt"
	//"os"
	)

func main() {

	//argsWithProg := os.Args

	someDNA := "AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC"
	t := []rune(someDNA)
	A := 0; G := 0; T := 0; C := 0

	for i := 0; i < len(t); i++ {
		
        base := t[i]
        switch {
        case base == 'A':
        	A++
        case base == 'C':
        	C++
        case base == 'G':
        	G++
        case base == 'T':
        	T++
        default:
        	fmt.Printf("base %q wasn't counted", base)
        }
    }

    fmt.Printf("As: %d, Cs: %d, Gs: %d, Ts: %d \n", A, C, G, T)
}
