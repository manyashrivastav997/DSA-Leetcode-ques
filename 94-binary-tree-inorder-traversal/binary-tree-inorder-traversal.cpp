#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodeStack;
        TreeNode* current = root;

        while (current != nullptr || !nodeStack.empty()) {
            // 1. Reach the leftmost node of the current node
            while (current != nullptr) {
                nodeStack.push(current);
                current = current->left;
            }

            // 2. Current is NULL, pop the top element from the stack
            current = nodeStack.top();
            nodeStack.pop();

            // 3. Add the node value to the result
            result.push_back(current->val);

            // 4. Move to the right subtree
            current = current->right;
        }

        return result;
    }
};
