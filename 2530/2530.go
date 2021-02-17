package main

import "fmt"

func main() {
    var h, m, s int
    var ss int
    fmt.Scanf("%d %d %d", &h, &m, &s)
    fmt.Scanf("%d", &ss)

    s += ss
    m += (int)(s / 60)
    h += (int)(m / 60)

    h %= 24
    m %= 60
    s %= 60

   fmt.Printf("%v %v %v", h, m, s)
}