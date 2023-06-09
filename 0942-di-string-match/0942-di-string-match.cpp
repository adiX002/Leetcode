class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans;
        
        int low = 0;
        int high = S.size();
        
        for(int i = 0; i < S.size(); i++){
            if(S[i]=='I')
                ans.push_back(low++);
            else
                ans.push_back(high--);
        }
        // ans.push_back(high); 
        ans.push_back(low);
        return ans;
    }
};