/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode *root, vector<int> &ans, int maxi) {
        queue<TreeNode*> q;
        q.push(root), q.push(NULL);

        while (!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();

            if (temp == NULL) {
                ans.push_back(maxi);
                maxi = INT_MIN;

                if (!q.empty()) q.push(NULL);
            }
            else {
                maxi = max(maxi, temp->val);

                if (temp->left)     q.push(temp->left);
                if (temp->right)    q.push(temp->right);
            }
        }
    }
    
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL)   return {};
        
        vector<int> ans;
        int maxi = INT_MIN;
        
        solve(root, ans, maxi);
        
        return ans;
    }
};
