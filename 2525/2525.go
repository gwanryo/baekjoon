package main

import "fmt"

func main() {
    var a, b, c int

    fmt.Scanf("%d %d", &a, &b)
    fmt.Scanf("%d", &c)

    a += (int)((b + c) / 60)
    a %= 24
    b += c % 60
    b %= 60

    fmt.Printf("%v %v", a, b)
}