func convert(s string, numRows int) string {
	if numRows == 1 {
		return s
	}
	res := make([]byte, len(s))
	cycle := 2*numRows - 2
	index := 0
	for i := 0; i < numRows; i++ {
		for j := i; j < len(s); j += cycle {
			res[index] = s[j]
			index++
			next := j + 2*(numRows-i-1)
			if i > 0 && i < numRows-1 && next < len(s) {
				res[index] = s[next]
				index++
			}
		}
	}
	return string(res)
}

