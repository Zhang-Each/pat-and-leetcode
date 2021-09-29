package main

import "fmt"

func check(n int, s int) bool {
	var val int = 0
	for true {
		if n <= 0 {
			break
		}
		val = val*s + n%s
		n /= s
	}
	return prime(val)
}

func prime(n int) bool {
	if n <= 3 {
		return n >= 2
	}
	for i := 2; i <= n/2; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var a, b int
	for true {
		fmt.Scanf("%d", &a)
		if a < 0 {
			break
		}
		fmt.Scanf("%d", &b)
		if !prime(a) {
			fmt.Println("No")
		} else if check(a, b) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
