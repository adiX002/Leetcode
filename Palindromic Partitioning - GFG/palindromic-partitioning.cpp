//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int>dp;
    int valid(int i,int j,string s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j]) return 0;
            i++,j--;
        }
        return 1;
    }
    int func(int i,int j,string s)
    {
        if(i>j || valid(i,j,s)) return 0;
        int ans=1e9;
        if(dp[i]!=-1) return dp[i];
        for(int x=i;x<=j;x++)
        {
            if(valid(i,x,s))
            {
                int tmp=1+func(x+1,j,s);
                ans=min(ans,tmp);
            }
        }
        return dp[i]=ans;
    }
    int palindromicPartition(string str)
    {
        int n=str.size();
        dp.resize(n,-1);
        return func(0,n-1,str);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends