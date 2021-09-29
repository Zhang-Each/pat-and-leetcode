package main

import "fmt"

// 本题C++同样算法可以通过，但是使用go来写会超时
func main() {
	var n, m, k int
	var a, b int
	fmt.Scanln(&n, &m)
	var g = make([][]int, n)
	for i := 0; i < n; i++ {
		g[i] = make([]int, 0)
	}
	for i := 0; i < m; i++ {
		fmt.Scanln(&a, &b)
		g[a] = append(g[a], b)
		g[b] = append(g[b], a)
	}
	fmt.Scanf("%d", &k)
	for i := 0; i < k; i++ {
		var nodes = make([]int, n)
		var color = make(map[int]int)
		var count = 0
		for j := 0; j < n; j++ {
			fmt.Scanf("%d", &nodes[j])
			if color[nodes[j]] != 1 {
				count += 1
				color[nodes[j]] = 1
			}
		}
		var is int = 1
		for x := 0; x < n; x++ {
			if is == 0 {
				break
			}
			for y := 0; y < len(g[x]); y++ {
				if nodes[x] == nodes[g[x][y]] {
					is = 0
					break
				}
			}
		}
		if is == 1 {
			fmt.Printf("%d-coloring\n", count)
		} else {
			fmt.Println("No")
		}
	}
}
