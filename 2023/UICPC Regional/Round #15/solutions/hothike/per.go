// I have no idea what I'm doing.

package main

import (
    "fmt"
)

func main() {
    var n, d, t int
    var T [100]int

    fmt.Scanf("%d", &n)

    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &T[i])
    }
    t = 50
    for i := 0; i < n-2; i++ {
        var v int
        v = T[i]
        if T[i+2] > v {
           v = T[i+2]
        }
        if v < t {
           d = i+1
           t = v
        }
    }
    fmt.Printf("%d %d\n", d, t)
}
