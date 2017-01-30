func longestPalindrome(s string) string {
	longest, left, right := 0, 0, 0
	if len(s) == 0 {
		return s
	}

	for i := 0; i < len(s); i++ {
		var l, r int
		for j := 0; j < 2; j++ {
			if j == 0 {
				l, r = i, i
			} else {
				l, r = i, i+1
			}
			for ; l >= 0 && r < len(s); l, r = l-1, r+1 {
				if s[l] != s[r] {
					break
				}
			}
			if longest < r-l-1 {
				longest = r - l - 1
				left, right = l+1, r-1
			}
		}
	}
	return s[left : right+1]
}

