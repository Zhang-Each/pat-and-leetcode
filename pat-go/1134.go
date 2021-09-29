package main

import "fmt"

type edge struct {
	a int
	b int
}

// 这题对Go不友好，完全一样的写法C++就不会超时
func main() {
	var n, m, l, k int
	var x, y int
	fmt.Scanln(&n, &m)
	var edges = make([]edge, m)
	for i := 0; i < m; i++ {
		fmt.Scanln(&x, &y)
		edges[i] = edge{x, y}
	}
	fmt.Scanln(&l)
	for i := 0; i < l; i++ {
		fmt.Scanf("%d", &k)
		var nodes = make(map[int]int)
		var node int
		var flag int = 1
		for j := 0; j < k; j++ {
			fmt.Scanf("%d", &node)
			nodes[node] = 1
		}
		for j := 0; j < m; j++ {
			if nodes[edges[j].a] != 1 && nodes[edges[j].b] != 1 {
				flag = 0
			}
		}
		if flag == 1 {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}
