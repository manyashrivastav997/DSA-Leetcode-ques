#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (!root) return result;
        
        std::stack<TreeNode*> st;
        st.push(root);
        
        // Traverse the tree in Root -> Right -> Left order
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            result.push_back(curr->val);
            
            // Push left first so right is processed first (LIFO)
            if (curr->left) {
                st.push(curr->left);
            }
            if (curr->right) {
                st.push(curr->right);
            }
        }
        
        // Reverse the result to get Left -> Right -> Root (Postorder)
        std::reverse(result.begin(), result.end());
        return result;
    }
};
