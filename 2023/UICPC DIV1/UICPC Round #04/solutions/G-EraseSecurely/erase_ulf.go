//Solution by Ulf Lundström
package main
import "fmt"

func main() {
	var N int
	var s1, s2 string
	fmt.Scanf("%d %s %s",&N, &s1, &s2)
	for i := 0; i < len(s1); i++ {
		if (s1[i] == s2[i]) == (N%2 == 1) {
			fmt.Println("Deletion failed")
			return
		}
	}
	fmt.Println("Deletion succeeded")
}
