class Solution {
private:
    //to check character
    bool valid(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            return 1;
        }
            return 0;
    }
        
    //to lowercase
    char tolowerCase(char ch){
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            return ch;
        }else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }
    
     //to valid palindrome
    bool checkPalindrome(string a) {
        int st = 0;
        int e = a.size()-1;
        
        while(st<=e){
            if(a[st] != a[e]){
                return 0;
            }else{
                st++;
                e--;
            }
        }
         return 1;
    }
    
public:    
    //to valid palindrome
    bool isPalindrome(string s) {
        string temp = "";
        //faltu characters hatao
        for(int j=0; j<s.length(); j++){
            if(valid(s[j]))
                temp.push_back(s[j]);
        }
        //lowercase kardo
        for(int j=0; j<temp.length(); j++){
            temp[j] = tolowerCase(temp[j]);
        }
        return checkPalindrome(temp);
    }
};