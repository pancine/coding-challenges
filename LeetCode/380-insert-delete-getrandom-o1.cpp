#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
  public:
    unordered_set<int> set;

    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (set.count(val))
            return false;

        set.insert(val);
        return true;
    }

    bool remove(int val)
    {
        if (set.count(val) == 0)
        {
            return false;
        }

        set.erase(val);
        return true;
    }

    int getRandom()
    {
        int random = rand() % set.size();
        unordered_set<int>::iterator it = set.begin();
        for (int i = 0; i < random; i++, it++){ }

        return *it;
    }
};
