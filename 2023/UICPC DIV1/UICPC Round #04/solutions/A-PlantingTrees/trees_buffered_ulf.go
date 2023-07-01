//Solution by Ulf Lundström
package main
import ("fmt"; "sort"; "bufio"; "os"; "strconv"; "strings")

func main() {
	rdr := bufio.NewReader(os.Stdin)
	str,_ := rdr.ReadString('\n');
	N,_ := strconv.Atoi(str[0:len(str)-1])
	str,_ = rdr.ReadString('\n');
	s := strings.Split(str[0:len(str)-1]," ")
	t := make([]int, N)
	for i := range t {
		t[i],_ = strconv.Atoi(s[i])
	}
	sort.Ints(t)
	res := 0;
	for i, v := range t {
		if v+int(N)-i+1 > res { res = v+int(N)-i+1 }
	}
	fmt.Println(res)
}
