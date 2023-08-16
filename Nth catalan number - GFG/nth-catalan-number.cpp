//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        int mode=1e9+7;
        vector<long int> dp(n+1,1);
        
        for(int i=2;i<=n;i++)
        {
            long int res=0;
            for(int j=i;j>0;j--)
            {
                res+=(dp[j-1]*dp[i-j])%mode;
            }
            dp[i]=res%mode;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends