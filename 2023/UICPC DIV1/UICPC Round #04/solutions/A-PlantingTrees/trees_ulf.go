//Solution by Ulf Lundström
package main
import ("fmt"; "sort")

func main() {
	var N int
	fmt.Scanf("%d", &N)
	t := make([]int, N)
	for i := range t {
		fmt.Scanf("%d", &t[i])
	}
	sort.Ints(t)
	res := 0;
	for i, v := range t {
		if v+N-i+1 > res { res = v+N-i+1 }
	}
	fmt.Println(res)
}
