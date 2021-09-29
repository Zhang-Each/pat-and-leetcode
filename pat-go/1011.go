package main

import "fmt"

func main() {
	var a [3]float64
	var result float64 = 1
	var str [3]string
	var game = [3]string{"W", "T", "L"}
	for i := 0; i < 3; i++ {
		fmt.Scanln(&a[0], &a[1], &a[2])
		max := 0.0
		for j := 0; j < 3; j++ {
			if a[j] > max {
				max = a[j]
				str[i] = game[j]
			}
		}
		result *= max
	}
	result = (result*0.65 - 1) * 2
	for i := 0; i < 3; i++ {
		fmt.Printf(str[i] + " ")
	}
	fmt.Printf("%.2f\n", result)
}
