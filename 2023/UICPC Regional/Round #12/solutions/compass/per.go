// I have no idea what I'm doing.

package main

import (
    "fmt"
)

func main() {
    var n1, n2 int64

    fmt.Scanf("%d\n%d", &n1, &n2)
    n2 -= n1
    if n2 > 180 {
       n2 -= 360
    }
    if n2 <= -180 {
       n2 += 360
    }
    fmt.Printf("%d\n", n2)
}
