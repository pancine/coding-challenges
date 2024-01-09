#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
  public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> leafs1, leafs2;
        getLeafs(root1, leafs1);
        getLeafs(root2, leafs2);

        if (leafs1.size() != leafs2.size())
        {
            return false;
        }

        return equal(leafs1.begin(), leafs1.end(), leafs2.begin());
    }

  private:
    void getLeafs(TreeNode *node, vector<int> &leafs)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            leafs.push_back(node->val);
            return;
        }

        if (node->left != nullptr)
            getLeafs(node->left, leafs);
        if (node->right != nullptr)
            getLeafs(node->right, leafs);
    }
};
