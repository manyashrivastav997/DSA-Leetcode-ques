#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        // Base case: If the tree is empty, return an empty list.
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = q.front();
                q.pop();
                
                currentLevel.push_back(currentNode->val);
                
                if (currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }
                if (currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
            }
            
            result.push_back(currentLevel);
        }
        
        return result;
    }
};
