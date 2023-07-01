//Solution by Ulf Lundström
package main
import "fmt"

func main() {
	var X float64
	fmt.Scanf("%f",&X)
	if X == 10 {
		fmt.Println("No solution")
		return
	}
	const k int64 = 10000
	Y := int64(X*float64(k))
	var P, A0 int64 = 1,1
	empty := true
	for n := 1; n < 9; n++ {
		for A0 = 1; A0 < 10; A0++ {
			A := (P*10-1)*A0*k/(10*k-Y)
			if A/P == A0 && ((A-A0*P)*10+A0)*k == Y*A {
				fmt.Println(A)
				empty = false;
			}
		}
		P = P*10
	}
	if empty {
		fmt.Println("No solution")
	}
}
