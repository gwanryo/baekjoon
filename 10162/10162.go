package main

import "fmt"

func main() {
	var t int
	fmt.Scanf("%d", &t)

	if t%10 != 0 {
		fmt.Printf("-1")
	} else {
		fmt.Printf("%v %v %v", (int)(t/300), (int)((t%300)/60), (int)(((t%300)%60)/10))
	}
}
