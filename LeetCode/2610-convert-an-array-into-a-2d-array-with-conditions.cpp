#include <unordered_map>
#include <vector>

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
            for (int i = 0; i < it->second; i++)
            {
                result[i].push_back(it->first);
            }
        }

        return result;
    }
};
