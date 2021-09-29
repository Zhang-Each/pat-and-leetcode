package main

import (
	"fmt"
	"math"
	"strconv"
)

func is_prime(n int) bool {
	if n <= 3 {
		return n >= 2
	}
	for i := 2; i <= int(math.Sqrt(float64(n)))+1; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var s, t int
	var num string
	fmt.Scanln(&s, &t)
	fmt.Scanln(&num)
	// 试了好几次发现这里要改成<= s-t，脑残了
	for i := 0; i <= s-t; i++ {
		var sub = num[i : i+t]
		temp, _ := strconv.Atoi(sub)
		//fmt.Printf("%d\n", temp)
		if is_prime(temp) {
			fmt.Println(sub)
			return
		}
	}
	fmt.Println("404")
}
