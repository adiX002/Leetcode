class Solution {
public:
    string reorganizeString(string S) {
        int N = S.size();
        //a hash calculated by count and its lexicographic order
        vector<int> countLex(26, 0);
        
        //count part
        for(char c: S){
            countLex[c-'a'] += 26;
        }
        //lexicographic part
        for(int i = 0; i < 26; i++){
            countLex[i] += i;
        }
        
        //we start from the char with smaller count
        sort(countLex.begin(), countLex.end());
        
        vector<char> ans(N);
        int cursor = 1;
        for(int code : countLex){
            int count = code/26;
            char c = 'a' + (code%26);
            /*
            if S's length is 3, a character cannot appear more than 2 times
            if S's length is 4, a character cannot appear more than 2 times
            */
            if(count > (N+1)/2) return "";
            for(int i = 0; i < count; i++){
                /*
                the latter char(char with larger count) will start from 0
                for example, in "abaca", 'a' is processed at last, 
                and it will fill 0,2,4th position
                */
                if(cursor >= N) cursor = 0;
                // cout << cursor << " " << c << endl;
                ans[cursor] = c;
                //jump to next next position
                cursor += 2;
            }
        }
        
        return string(ans.begin(), ans.end());
    }
};
