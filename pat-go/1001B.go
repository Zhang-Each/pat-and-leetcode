package main

import "fmt"

func main() {
	var n int
	var count int = 0
	fmt.Scanf("%d", &n)
	for true {
		if n == 1 {
			break
		}
		if n%2 == 0 {
			n /= 2
		} else {
			n = (3*n + 1) / 2
		}
		count += 1
	}
	fmt.Printf("%d\n", count)
}
