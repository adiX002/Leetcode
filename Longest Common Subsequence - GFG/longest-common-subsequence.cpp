//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequen
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
         vector<vector<int>> vec(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (s1[i] == s2[j]) {
                    vec[i][j] = (i == 0 || j == 0) ? 1 : 1 + vec[i-1][j-1];
                } else {
                    if (i == 0 && j == 0) {
                        vec[i][j] = 0;
                    } else if (i == 0) {
                        vec[i][j] = vec[i][j-1];
                    } else if (j == 0) {
                        vec[i][j] = vec[i-1][j];
                    } else {
                        vec[i][j] = max(vec[i-1][j], vec[i][j-1]);
                    }
                }
            }
        }
        return vec[n-1][m-1];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends