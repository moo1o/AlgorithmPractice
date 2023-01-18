package main

import (
	"fmt"
	"math"
)

func main() {
	//fmt.Println(maxValueAfterReverse([]int{2, 4, 9, 24, 2, 1, 10}))
	//fmt.Println(maxValueAfterReverse([]int{2, 3, 1, 5, 4}))
	fmt.Println(maxValueAfterReverse([]int{2, 5, 1, 3, 4}))
	/*
		    2 5 1 3 4
			2 5 1 4 3
			3 4 3 1
	*/
}

func maxValueAfterReverse(nums []int) int {
	answer := 0
	sum := 0
	maxX := -987654321
	minX := 987654321
	maxPos := 0
	minPos := 0

	for i := 1; i < len(nums); i++ {
		curMax := max(nums[i], nums[i-1])
		curMin := min(nums[i], nums[i-1])

		sum += curMax - curMin

		// minX = min(minX, curMax)
		// maxX = max(maxX, curMin)
		if minX > curMax {
			minX = curMax
			minPos = i
		}
		if maxX < curMin {
			maxX = curMin
			maxPos = i
		}

	}
	answer = max(sum, sum+(maxX-minX)*2)
	// for i := 1; i < len(nums); i++ {
	// 	tempSum := sum - abs(nums[i-1]-nums[i]) + abs(nums[len(nums)-1]-nums[i-1])
	// 	answer = max(answer, tempSum)
	// 	tempSum = sum - abs(nums[i-1]-nums[i]) + abs(nums[i]-nums[0])
	// 	answer = max(answer, tempSum)
	// }
	answer = max(answer, sum-abs(nums[maxPos-1]-nums[maxPos])+abs(nums[maxPos]-nums[0]))
	answer = max(answer, sum-abs(nums[maxPos-1]-nums[maxPos])+abs(nums[maxPos-1]-nums[len(nums)-1]))
	answer = max(answer, sum-abs(nums[minPos-1]-nums[minPos])+abs(nums[minPos]-nums[0]))
	answer = max(answer, sum-abs(nums[minPos-1]-nums[minPos])+abs(nums[minPos-1]-nums[len(nums)-1]))

	return answer
}

func abs(num int) int {
	return int(math.Abs(float64(num)))
}

func max(num1, num2 int) int {
	return int(math.Max(float64(num1), float64(num2)))
}

func min(num1, num2 int) int {
	return int(math.Min(float64(num1), float64(num2)))
}
