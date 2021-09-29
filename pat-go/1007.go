package main

import "fmt"

func main() {
	var n int
	fmt.Scanf("%d", &n)
	var arr = make([]int, n)
	var count1, count2 int = 0, 0
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &arr[i])
		if arr[i] < 0 {
			count1++
		}
		if arr[i] == 0 {
			count2++
		}
	}
	// 两种特殊情况，全部都是负数和全部是负数+0
	if count1 == n {
		fmt.Print("0 %d %d\n", arr[0], arr[n-1])
		return
	} else if count2 >= 1 && count1+count2 == n {
		for i := 0; i < n; i++ {
			if arr[i] == 0 {
				fmt.Print("0 0 0\n")
				return
			}
		}
	}
	var max, sum int = 0, 0
	var head, tail int = 0, 0
	for i := 0; i < n; i++ {
		sum = 0
		for j := i; j < n; j++ {
			sum += arr[j]
			if sum > max {
				max = sum
				head = arr[i]
				tail = arr[j]
			}
		}
	}
	fmt.Printf("%d %d %d\n", max, head, tail)
	return
}
