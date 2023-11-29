class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> s(n);
        return s.count();
    }
};