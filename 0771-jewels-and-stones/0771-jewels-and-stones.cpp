class Solution {
public:
    int numJewelsInStones(string J, string S) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<char,int> mymap;
        for(int i=0;J[i]!='\0';++i)
            ++mymap[J[i]];
        
        int count = 0;
        for(int i=0;S[i]!='\0';++i)
            if(mymap.find(S[i])!=mymap.end())
                count+=1;
        
        return count;
        
    }
};