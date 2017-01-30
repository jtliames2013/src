func isPalindrome(x int) bool {
	if x < 0 {
		return false
	}
	base := 1
	for base <= x {
		base *= 10
	}
	base /= 10
	for x > 0 {
		if x%10 != x/base {
			return false
		}
		x %= base
		x /= 10
		base /= 100
	}
	return true
}

