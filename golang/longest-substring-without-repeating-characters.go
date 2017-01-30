func lengthOfLongestSubstring(s string) int {
	pos := map[byte]int{}
	longest := math.MinInt32
	var l, r int
	for l, r = 0, 0; r < len(s); r++ {
		if index, ok := pos[s[r]]; ok {
			if longest < r-l {
				longest = r - l
			}
			for i := l; i < index; i++ {
				delete(pos, s[i])
			}
			l = index + 1
		}
		pos[s[r]] = r
	}
	if longest < r-l {
		longest = r - l
	}
	return longest
}

