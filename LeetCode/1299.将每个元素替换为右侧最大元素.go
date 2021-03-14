/*
 * @lc app=leetcode.cn id=1299 lang=golang
 *
 * [1299] 将每个元素替换为右侧最大元素
 */

// @lc code=start
func replaceElements(arr []int) []int {
	var res = make([]int, len(arr), len(arr))
	res[len(arr) - 1] = -1
	for i := len(arr) - 2; i >= 0; i -- {
		if res[i + 1] > arr[i + 1] {
			res[i] = res[i + 1]
		} else {
			res[i] = arr[i + 1]
		}
	}
	return res
}
// @lc code=end

