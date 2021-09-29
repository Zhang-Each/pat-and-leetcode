package main

import (
	"fmt"
)

func main() {
	var input string
	fmt.Scanln(&input)
	var sum int = 0
	for i := 0; i < len(input); i++ {
		sum += int(input[i] - '0')
	}
	var words = [10]string{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}
	arr := make([]int, 0)
	for true {
		arr = append(arr, sum%10)
		sum /= 10
		if sum == 0 {
			break
		}
	}
	for i := len(arr) - 1; i >= 0; i-- {
		fmt.Printf(words[arr[i]])
		if i != 0 {
			fmt.Printf(" ")
		}
	}
	fmt.Printf("\n")
}
