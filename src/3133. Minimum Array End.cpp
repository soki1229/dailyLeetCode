// 2024-11-09

class Solution {
public:
    long long minEnd(int n, int x)
    {
        long long s = x;
        for (int i = 1; i < n; i++)
            s = (s+1) | x;

        return s;
    }
};