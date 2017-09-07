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

public int HammingDistance(vector<unsigned int> nums)
{
        int res=0;
        for (int i=0; i<32; i++) {
            int count=0;
            for (auto n:nums) {
                count+=((n>>i) & 0x1);
            }
            res+=count*(nums.size()-count);
        }
        
        return res;
}

