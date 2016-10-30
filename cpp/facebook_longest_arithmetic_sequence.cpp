http://codercareer.blogspot.com/2014/03/no-53-longest-arithmetic-sequence.html

No. 53 - Longest Arithmetic Sequence
Question 1: Given an array, please get the length of the longest arithmetic sequence. The element order in the arithmetic sequence should be same as the element order in the array. For example, in the array {1, 6, 3, 5, 9, 7}, the longest arithmetic sequence is 1, 3, 5, and 7, whose elements have same order as they are in the array, and the length is 4.

Analysis: Every pair of two adjacent numbers in an arithmetic sequence has exactly same difference. For example, 1, 3, 5, and 7 is an arithmetic sequence, and the pairs (1, 3), (3, 5), and (5, 7) have the same difference 2.

There are n(n-1)/2 pairs out of an array with n elements. These pairs can be categorized into a set of groups, of which each group of pairs have the same difference. For example, the pairs of numbers in the array {1, 6, 3, 5, 9, 7} can be categorized into groups:

Difference -1: (6, 5)
Difference 2: (1, 3), (3, 5), (5, 7)
Difference 3: (6, 9)
…

Therefore, a hash table can be defined for the groups. The key in the hash table is the difference of pairs, and the value in the hash table is a list of pairs with same difference. The code to build the hash table can be implemented in C# as the following:

internal class Pair
{
    public int First { get; set; }
    public int Second { get; set; }
}

private static Dictionary<int, List<Pair>> BuildHashTable(int[] numbers)
{
    var hashTable = new Dictionary<int, List<Pair>>();
    for(int i = 0; i < numbers.Length; ++i)
    {
        for(int j = i + 1; j < numbers.Length; ++j)
        {
            Pair pair = new Pair
            {
                First = i,
                Second = j
            };

            int diff = numbers[j] - numbers[i];
            if(hashTable.Keys.Contains(diff))
            {
                hashTable[diff].Add(pair);
            }
            else
            {
                List<Pair> newValue = new List<Pair>();
                newValue.Add(pair);
                hashTable[diff] = newValue;
            }
        }
    }

    return hashTable;
}

In the code above, the values of the hash table is pairs of indexes, rather than elements themselves of the array. The pairs are sorted according to their first elements.

The next step is to get the length of pairs with each difference. A list of pairs with difference k is got given a key k in the hash table. If an element A[i] is mth element is an arithmetic sequence with a common difference k, and there is a pair (A[i], A[j]) (j>i) in the list of pairs, the element A[j] should be the m+1thelemement in the arithmetic sequence.

Therefore, the code to get the max length of all arithmetic sequences can be implemented as:

private static int Analyze(Dictionary<int, List<Pair>> hashTable, int lengthOfNumbers)
{
    int maxLength = 0;
    foreach(var key in hashTable.Keys)
    {
        int[] lengths = new int[lengthOfNumbers];
        for (int i = 0; i < lengthOfNumbers; ++i)
        {
            lengths[i] = 1;
        }

        foreach(Pair pair in hashTable[key])
        {
            lengths[pair.Second] = lengths[pair.First] + 1;
        }

        foreach(var length in lengths)
        {
            if(length > maxLength)
            {
                maxLength = length;
            }
        }
    }

    return maxLength;
}

public static int GetMaxLengthOfArithmeticSequence(int[] numbers)
{
    var hashTable = BuildHashTable(numbers);
    return Analyze(hashTable, numbers.Length);
}

The source code with unit test cases are shared at: http://ideone.com/jxRDkd.

As mentioned above, there are O(n2) pairs in an array with n elements. Therefore, the time and space efficiencies of this solution is O(n2) given an array with n elements.

Question 2: Given an array, please get the length of the longest arithmetic sequence. The element order in the arithmetic sequence is not necessarily same as the element order in the array. For example, in the array {1, 6, 3, 5, 9, 7}, the longest arithmetic sequence is 1, 3, 5, 7, and 9, and the length is 5.

Analysis: Different from the previous problem, there are no limitations on the order of arithmetic sequence. Consequently, we can sort the array before we try to get the maximal length of arithmetic sequences. The code is almost same as before, except for the revision that there is an additional line of code to sort the array, as listed below:

public static int GetMaxLengthOfArithmeticSequence(int[] numbers)
{
    Array.Sort(numbers);
    var hashTable = BuildHashTable(numbers);
    return Analyze(hashTable, numbers.Length);
}

The source code with unit test cases are shared at: http://ideone.com/lEqNm3.

