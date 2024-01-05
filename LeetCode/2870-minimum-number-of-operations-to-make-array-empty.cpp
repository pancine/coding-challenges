#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> counter;

        for (size_t i = 0; i < nums.size(); i++)
        {
            counter[nums[i]]++;
        }

        int result = 0;
        for (unordered_map<int, int>::iterator it = counter.begin(); it != counter.end(); it++)
        {
            if (it->second == 1)
            {
                return -1;
            }

            if (it->second % 3 == 0)
            {
                result += it->second / 3;
                continue;
            }

            if (it->second % 3 == 1)
            {
                result += 2 + (it->second - 4) / 3;
                continue;
            }

            result += 1 + (it->second - 2) / 3;
        }

        return result;
    }
};
