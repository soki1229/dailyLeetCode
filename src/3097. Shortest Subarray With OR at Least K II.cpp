// 2024-11-10

class Solution {
public:
    void updateFreq(int num, int val)
    {
        for (int i = 0; i < bitFreq.size(); i++)
        {
            if (num & (1 << i))
                bitFreq[i] += val;
        }
    }

    int getNum()
    {
        int num = 0;
        long long pow = 1;
        
        for (int i = 0; i < bitFreq.size(); i++)
        {
            if (bitFreq[i] > 0)
                num += pow;
            
            pow *= 2;
        }

        return num;
    }

    int minimumSubarrayLength(vector<int>& nums, int k)
    {
        if (k == 0)
            return 1;
        
        int n     = nums.size();
        int ret   = INT_MAX;
        int left  = 0;
        int right = 0;
        int curr  = 0;

        while (right < n)
        {
            updateFreq(nums[right], 1);
            curr |= nums[right];

            while (left <= right && curr >= k)
            {
                ret = min(ret, right-left+1);
                updateFreq(nums[left], -1);
                curr = getNum();
                left++;
            }

            right++;
        }

        return ret == INT_MAX? -1 : ret;
    }

private:
    vector<int> bitFreq = vector<int>(32);
};
