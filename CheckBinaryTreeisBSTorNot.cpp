#include <iostream>
#include <climits>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBSTHelper(TreeNode *node, long long minVal, long long maxVal)
{
    if (node == nullptr)
    {
        return true;
    }
    if (node->val <= minVal || node->val >= maxVal)
    {
        return false;
    }
    return isValidBSTHelper(node->left, minVal, node->val) &&
           isValidBSTHelper(node->right, node->val, maxVal);
}

bool isValidBST(TreeNode *root)
{
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

int main()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if (isValidBST(root))
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }

    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
