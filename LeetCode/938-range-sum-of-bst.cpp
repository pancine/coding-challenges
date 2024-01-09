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
    int low, high;

  public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        this->low = low;
        this->high = high;

        return sumBST(root);
    }

  private:
    int sumBST(TreeNode *node)
    {
        int sum = 0;
        if (node->left != nullptr && (node->val > this->low || node->val >= high))
        {
            sum += sumBST(node->left);
        }
        if (node->right != nullptr && (node->val <= this->low || node->val < high))
        {
            sum += sumBST(node->right);
        }
        if (node->val >= this->low && node->val <= this->high)
        {
            sum += node->val;
        }

        return sum;
    }
};
