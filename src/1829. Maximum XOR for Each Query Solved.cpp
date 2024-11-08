// 2024-11-08

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
    {
        vector<int> ret(nums.size());
        
        int val = pow(2, maximumBit) - 1;
        
        auto it = ret.rbegin();
        for (auto n : nums)
            *it++ = val ^= n;
        
        return ret;
    }
};