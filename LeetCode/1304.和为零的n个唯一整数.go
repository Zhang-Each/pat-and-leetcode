/*
 * @lc app=leetcode.cn id=1304 lang=golang
 *
 * [1304] 和为零的N个唯一整数
 */

// @lc code=start
func sumZero(n int) []int {
	var res []int
	for i := 1; i <= n / 2; i ++ {
		res = append(res, i)
		res = append(res, -i)
	}
	if n % 2 == 1 {
		res = append(res, 0)
	}
	return res
}
// @lc code=end

