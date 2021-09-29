package main

import "fmt"

func main() {
	var n, m int
	var exp int
	var conf float64
	var result [1001]float64
	fmt.Scanf("%d", &n)
	for i := 0; i <= 1000; i++ {
		result[i] = 0
	}
	for i := 0; i < n; i++ {
		fmt.Scanf("%d %f", &exp, &conf)
		result[exp] += conf
	}
	fmt.Scanf("%d", &m)
	for i := 0; i < m; i++ {
		fmt.Scanf("%d %f", &exp, &conf)
		result[exp] += conf
	}
	var count int = 0
	for i := 0; i <= 1000; i++ {
		if result[i] != 0 {
			count += 1
		}
	}
	fmt.Printf("%d", count)
	for i := 1000; i >= 0; i-- {
		if result[i] != 0 {
			fmt.Printf(" %d %.1f", i, result[i])
		}
	}
	fmt.Printf("\n")
}
