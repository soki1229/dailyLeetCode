// 2024-11-07

class Solution {
public:
    int largestCombination(vector<int>& candidates)
    {
        vector<int> arr(33, 0);

        for (int i : candidates)
        {
            int n = 0;
            while (i)
            {
                if (i%2)
                    arr[n]++;

                n += 1;
                i = i / 2;
            }
        }

        return *max_element(arr.begin(), arr.end());
    }
};