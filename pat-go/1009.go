package main

import "fmt"

func main() {
	var n, m int = 0, 0
	fmt.Scanf("%d", &n)
	var x = make([]float64, 1001)
	var y = make([]float64, 1001)
	var z = make([]float64, 2001)
	var exp int
	var cof float64
	for i := 0; i < n; i++ {
		fmt.Scanf("%d %f", &exp, &cof)
		x[exp] = cof
	}
	fmt.Scanf("%d", &m)
	for i := 0; i < m; i++ {
		fmt.Scanf("%d %f", &exp, &cof)
		y[exp] = cof
	}
	for i := 0; i < 1001; i++ {
		for j := 0; j < 1001; j++ {
			z[i+j] += x[i] * y[j]
		}
	}
	var count int = 0
	for i := 0; i < 2001; i++ {
		if z[i] != 0 {
			count += 1
		}
	}
	fmt.Printf("%d", count)
	for i := 2000; i >= 0; i-- {
		if z[i] != 0 {
			fmt.Printf(" %d %.1f", i, z[i])
		}
	}
	fmt.Printf("\n")
}
