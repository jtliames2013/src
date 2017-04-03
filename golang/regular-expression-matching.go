func isMatchHelper(s string, p string, i int, j int) bool {
	if j == len(p) {
		return i == len(s)
	}

	if j == len(p)-1 || p[j+1] != '*' {
		return i < len(s) && (s[i] == p[j] || p[j] == '.') && isMatchHelper(s, p, i+1, j+1)
	}

	for i < len(s) && (s[i] == p[j] || p[j] == '.') {
		if isMatchHelper(s, p, i, j+2) {
			return true
		}
		i++
	}
	return isMatchHelper(s, p, i, j+2)
}

func isMatch(s string, p string) bool {
	return isMatchHelper(s, p, 0, 0)
}

