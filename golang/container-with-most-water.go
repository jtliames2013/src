func Min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func Max(x, y int) int {
	if x > y {
		return x
	}
	return y
}

func maxArea(height []int) int {
	left, right := 0, len(height)-1
	var area int
	for left < right {
		area = Max(area, Min(height[left], height[right])*(right-left))
		if height[left] <= height[right] {
			left++
		} else if height[left] >= height[right] {
			right--
		}
	}

	return area
}

