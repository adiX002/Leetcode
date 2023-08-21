//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int delR[]={-1,-1,-1,0,0,1,1,1};
        int delC[]={-1,0,1,-1,1,-1,0,1};
        int ans=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==1)
                {
                    int cnt=0;
                    for(int k=0;k<8;k++)
                    {
                        int nrow=i+delR[k];
                        int ncol=j+delC[k];
                        if(nrow>=0 && ncol>=0 && nrow<matrix.size() && ncol<matrix[0].size() && matrix[nrow][ncol]==0)
                        {
                            cnt++;
                        }
                    }
                    if(cnt!=0 && cnt%2==0){
                        ans++;
                        //cout<<i<<" "<<j<<endl;
                    }
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends