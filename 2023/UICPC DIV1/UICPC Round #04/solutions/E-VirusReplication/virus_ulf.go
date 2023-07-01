//Solution by Ulf Lundström
package main
import "fmt"

func main() {
	var s1, s2 string
	fmt.Scanf("%s %s",&s1, &s2)
	var l1, l2 = len(s1), len(s2)
	var start, end = 0,l2;
	for i := 0; i < l1 && i < l2 && s1[i] == s2[i]; i++ {
		start = i+1;
	}
	for i := 1; l1-i >= start && l2-i >= start && s1[l1-i] == s2[l2-i]; i++ {
		end = l2-i;
	}
	fmt.Println(end-start)
}
