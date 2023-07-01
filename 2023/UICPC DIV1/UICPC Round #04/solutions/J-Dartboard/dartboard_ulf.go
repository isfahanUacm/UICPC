//Solution by Ulf Lundström
package main
import ("fmt";"math")

func main() {
	score := []float64{50,25,10.5,31.5,10.5,21}
	var d = make([]float64, 7)
	d[0] = 0;
	for i := range(score) {
		fmt.Scanf("%f",&d[i+1])
	}
	var sigma float64
	fmt.Scanf("%f",&sigma)
	res := 0.0;
	for i, v := range(score) {
		res = res + v*(math.Exp(-d[i]*d[i]/(2*sigma*sigma))-math.Exp(-d[i+1]*d[i+1]/(2*sigma*sigma)))
	}
	fmt.Println(res)
}
