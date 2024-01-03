#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    int numberOfBeams(vector<string> &bank)
    {
        int result = 0, lastRow = 0, current = 0;

        for (size_t i = 0; i < bank.size(); i++)
        {
            for (string::iterator it = bank[i].begin(); it != bank[i].end(); it++)
            {
                if (*it == '1')
                {
                    current++;
                }
            }

            result += lastRow * current;
            if (current != 0)
            {
                lastRow = current;
            }
            current = 0;
        }

        return result;
    }
};
