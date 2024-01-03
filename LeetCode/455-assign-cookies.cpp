#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        if (!s.size())
        {
            return 0;
        }

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int result = 0;

        vector<int>::reverse_iterator srit = s.rbegin();
        for (vector<int>::reverse_iterator grit = g.rbegin(); grit != g.rend(); grit++)
        {
            if (*grit <= *srit)
            {
                result++;
                srit++;
                if (srit == s.rend())
                {
                    return result;
                }
            }
        }

        return result;
    }
};