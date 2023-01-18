package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Println(divide(10, 3))
}

func divide(dividend int, divisor int) int {
	uDividend := abs(dividend)
	uDivisor := abs(divisor)
	var answer int64
	var sum int64
	var i int64
	var sign bool

	if (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) {
		sign = true
	}
	if uDivisor == 1 {
		answer = uDividend
		if sign {
			answer = -answer
			if answer < -(math.MaxInt32 + 1) {
				answer = -(math.MaxInt32 + 1)
			}
		} else if answer > math.MaxInt32 {
			answer = math.MaxInt32
		}
		return int(answer)
	}

	for i = 0; ; i++ {
		if uDividend >= sum && uDividend-sum < uDivisor {
			answer = i
			break
		}
		if i != 0 && uDividend > sum+sum {
			sum += sum
			i = i + i - 1
			continue
		}
		if sign && i == math.MaxInt32+1 || i == math.MaxInt32 {
			answer = i
			break
		}
		sum += uDivisor
	}

	if sign {
		answer = -answer
	}

	return int(answer)
}

func abs(n int) int64 {
	return int64(math.Abs(float64(n)))
}
