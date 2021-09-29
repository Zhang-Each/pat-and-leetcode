package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var a, b, c, neg int = 0, 0, 0, 0
	var count int = 0
	var result string = ""
	fmt.Scanf("%d %d", &a, &b)
	c = a + b
	if c == 0 {
		fmt.Printf("0\n")
		return
	}
	if c < 0 {
		c = -c
		neg = 1
	}
	for true {
		if c == 0 {
			break
		}
		var p = c % 10
		c /= 10
		result += strconv.Itoa(p)
		count += 1
		if count%3 == 0 && c > 0 {
			result += ","
		}
	}
	if neg == 1 {
		fmt.Printf("-")
	}
	for i := strings.Count(result, "") - 2; i >= 0; i-- {
		fmt.Printf("%c", result[i])
	}
	fmt.Printf("\n")
}
