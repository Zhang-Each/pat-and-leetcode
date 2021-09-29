package main

import "fmt"

// 将以字符串形式存储的数字str按照radix进位制进行转换
// 这题没有通过所有的测试点，只得到了22/25的分数
func convert(str string, radix int) int64 {
	var result int64 = 0
	for i := 0; i < len(str); i++ {
		num := 0
		if str[i] >= '0' && str[i] <= '9' {
			num = int(str[i] - '0')
		} else {
			num = int(str[i]-'a') + 10
		}
		result = result*int64(radix) + int64(num)
	}
	return result
}

func main() {
	var n1, n2 string
	var tag, radix int
	fmt.Scanln(&n1, &n2, &tag, &radix)
	if tag == 2 {
		n1, n2 = n2, n1
	}
	var val1 int64 = convert(n1, radix)
	var val2 int64
	for i := 2; i <= 36; i++ {
		val2 = convert(n2, i)
		if val2 == val1 {
			fmt.Printf("%d\n", i)
			return
		}
	}
	fmt.Printf("Impossible\n")
}
