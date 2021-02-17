package main

import "fmt"

func main() {
    var a, b, c int
    fmt.Scanf("%d %d %d", &a, &b, &c)
    
    if b > c {
        if a > b {
            fmt.Printf("%v %v %v", c, b, a)
        } else if a > c{
            fmt.Printf("%v %v %v", c, a, b)
        } else {
            fmt.Printf("%v %v %v", a, c, b)
        }
    } else {
        if a > c {
            fmt.Printf("%v %v %v", b, c, a)
        } else if a > b {
            fmt.Printf("%v %v %v", b, a, c)
        } else {
            fmt.Printf("%v %v %v", a, b, c)
        }
    }
}