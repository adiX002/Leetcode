//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> ans_Row;
        int maxVal = INT_MIN;
        
        for(int i = 0; i < n; i++){
            int sumRow = 0;
            int sumCol = 0;
            for(int j = 0; j < n; j++){
                    
                    sumRow += matrix[i][j];
                    sumCol += matrix[j][i];
            }
            
            maxVal = max(maxVal, max(sumRow, sumCol));
            ans_Row.push_back(sumRow);
            // ans_Col.push_back(sumCol);
        }
        
        
        int sum = 0;
        for(auto a : ans_Row){
            
            sum += abs(a - maxVal);
        }
        
        return sum;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends