class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int tSize = target.size(), k = 0;
        
        for (int i = 1; i <= target[tSize - 1]; i++) {
            if (i == target[k]) {
                ans.push_back("Push");
                k++;
            }
            else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        
        return ans;
    }
};
