// 2024-11-08

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
    {
        vector<int> ret;
        
        int val = pow(2, maximumBit) - 1;
        for (int i = 0; i < nums.size(); i++)
        {
            val ^= nums[i];
            ret.push_back(val);
        }

        reverse(ret.begin(), ret.end());
        
        return ret;
    }
};