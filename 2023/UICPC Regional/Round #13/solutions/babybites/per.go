// I have no idea what I'm doing.

package main

import (
    "fmt"
    "strconv"
)

func main() {
    var n int

    fmt.Scanf("%d", &n)

    for i := 1; i <= n; i++ {
        var token string
        fmt.Scanf("%s", &token)
        if token != "mumble" && token != strconv.Itoa(i) {
            fmt.Printf("something is fishy");
            return;
        }
    }
    fmt.Printf("makes sense");
}
