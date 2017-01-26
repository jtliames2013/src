1. hash table
func twoSum(nums []int, target int) []int {
	res := make([]int, 2)
	table := map[int]int{}

	for i, num := range nums {
		if index, ok := table[target-num]; ok {
			res[0] = index
			res[1] = i
			return res
		}
		table[num] = i
	}
	return res
}

2. two pointers
type Element struct {
	index int
	val   int
}
type ByVal []Element

func (a ByVal) Len() int           { return len(a) }
func (a ByVal) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByVal) Less(i, j int) bool { return a[i].val < a[j].val }

func twoSum(nums []int, target int) []int {
	res := make([]int, 2)
	elements := make([]Element, len(nums))

	for i, num := range nums {
		elements[i].index = i
		elements[i].val = num
	}
	sort.Sort(ByVal(elements))

	for l, r := 0, len(nums)-1; l < r; {
		if elements[l].val+elements[r].val == target {
			res[0] = elements[l].index
			res[1] = elements[r].index
			return res
		} else if elements[l].val+elements[r].val < target {
			l = l + 1
		} else {
			r = r - 1
		}
	}

	return res
}

