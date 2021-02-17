package main

import "fmt"

func main() {
    var a, b, c int
    fmt.Scanf("%d %d %d", &a, &b, &c)
    if a == b && b == c {
        fmt.Printf("%d", 10000 + a * 1000)
    } else if a == b || b == c {
        fmt.Printf("%d", 1000 + b * 100)
    } else if c == a {
        fmt.Printf("%d", 1000 + a * 100)
    } else {
        var d int
        if a > b {
            if c > a {
                d = c
            } else {
                d = a
            }
        } else {
            if c > b {
                d = c
            } else {
                d = b
            }
        }
        fmt.Printf("%d", d*100)
    }
}