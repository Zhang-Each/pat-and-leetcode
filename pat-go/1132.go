package main

import (
	"fmt"
	"strconv"
)

func main() {
	var n int
	var s string
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanln(&s)
		len := int(len(s) / 2)
		var a, b string
		a, b = s[0:len], s[len:]
		var a_int, b_int, s_int int
		a_int, _ = strconv.Atoi(a)
		b_int, _ = strconv.Atoi(b)
		s_int, _ = strconv.Atoi(s)
		// 拿到满分的关键代码，b可能会是0
		if a_int == 0 || b_int == 0 {
			fmt.Printf("No\n")
			continue
		}
		if int64(s_int)%int64(a_int*b_int) == 0 {
			fmt.Printf("Yes\n")
		} else {
			fmt.Printf("No\n")
		}
	}
}
