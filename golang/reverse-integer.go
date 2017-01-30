func reverse(x int) int {
	neg := false
	res := 0
	if x < 0 {
		neg = true
		x = -x
	}
	for x > 0 {
		res = res*10 + x%10
		x /= 10
	}
	if res > math.MaxInt32 {
		res = 0
	}
	if neg {
		res = -res
	}
	return res
}

