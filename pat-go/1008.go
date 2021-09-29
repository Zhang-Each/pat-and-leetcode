package main

import "fmt"

func main() {
	var n, m int = 0, 0
	var last, result int = 0, 0
	fmt.Scanf("%d", &n)
	result += 5 * n
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &m)
		var change = m - last
		last = m
		if change > 0 {
			result += 6 * change
		} else {
			result -= 4 * change
		}
	}
	fmt.Printf("%d\n", result)
}
