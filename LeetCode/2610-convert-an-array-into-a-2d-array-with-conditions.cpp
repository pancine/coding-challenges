#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {
        unordered_map<int, int> map;

        int n = 0;

        for (int i : nums)
        {
            map[i]++;
            n = max(n, map[i]);
        }

        vector<vector<int>> result(n);

        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++)
        {
            cout << it->first << " " << it->second << endl;
            for (int i = 0; i < it->second; i++)
            {
                result[i].push_back(it->first);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;

    vector<int> v = {1,3,4,1,2,3,1};

    vector<vector<int>> result = sol.findMatrix(v);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}