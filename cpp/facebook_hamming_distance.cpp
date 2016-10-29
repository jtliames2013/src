Total hamming distance of all numbers in array. The array contains all 64 bits integers,
   and two integers respectively having 0 and 1 at one digit contributes 1 hamming distance.
   E.g. 11011 : 10011 has Hamming distance 1, and 11111 : 01100 has 3.
   
   Follow up: Do better than O(n^2) brute force.

int hamming_distance(unsigned x, unsigned y)
{
    int dist = 0;
    unsigned  val = x ^ y;

    // Count the number of bits set
    while (val != 0)
    {
        // A bit is set, so increment the count and clear the bit
        dist++;
        val &= val - 1;
    }

    // Return the number of differing bits
    return dist;
}

public int HammingDistance(vector<int> input)
{
  // the result is the number of 1 bits x number of 0 bits
  int total = 0;
  int n=input.size();
  if (n==0) return 0;

    // Counts number of bits set per position
    vector<int> onebitscounter(32, 0);
    for (int i = 0; i < n; ++i)
    {
      int j = 0;
      while (input[i] != 0)
      {
        if (input[i] % 2 == 1)
          onebitscounter[j] += 1;
        // shift one bit to the right
        input[i] = input[i] >> 1;
        ++j;
      }
    }

    for (int k = 0; k < 32; ++k)
    {
      total += onebitscounter[k] * (n - onebitscounter[k]);
    }

  return total;
}
