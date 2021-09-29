package main

import "fmt"

var a = make([]int, 0)
var is_max, is_min = true, true
var path = make([]int, 0)

// 打印一条路径的结果
func show() {
	for i := 0; i < len(path); i++ {
		if i != 0 {
			fmt.Printf(" ")
		}
		fmt.Printf("%d", path[i])
	}
	fmt.Printf("\n")
}

func travel(index int) {
	if index >= len(a) {
		return
	}
	path = append(path, a[index])
	// 超出了堆数组，说明到底部了
	if 2*index+1 >= len(a) {
		show()
		path = path[0 : len(path)-1]
	} else {
		var left = 2*index + 1
		var right = 2*index + 2
		if right < len(a) {
			travel(right)
			travel(left)
			// 判断是否出现了不满足最大/最小堆的情况
			if a[left] < a[index] || a[right] < a[index] {
				is_min = false
			}
			if a[left] > a[index] || a[right] > a[index] {
				is_max = false
			}
		} else if right == len(a) {
			travel(left)
			if a[left] < a[index] {
				is_min = false
			}
			if a[left] > a[index] {
				is_max = false
			}
		}
		path = path[0 : len(path)-1]
	}
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	a = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	travel(0)
	if is_max && !is_min {
		fmt.Println("Max Heap")
	} else if is_min && !is_max {
		fmt.Println("Min Heap")
	} else {
		fmt.Println("Not Heap")
	}
}
