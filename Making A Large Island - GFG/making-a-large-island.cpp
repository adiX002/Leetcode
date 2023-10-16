//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
vector<int> dx={-1,0,1,0},dy={0,1,0,-1};
        int dfs(int x,int y,int id,int n,vector<vector<int>> &vis,vector<vector<int>> &grid) {
            if(x<0 || x>=n || y<0 || y>=n || vis[x][y] || !grid[x][y]) {
                return 0;
            }
            vis[x][y]=id;
            int res=1;
            for(int i=0;i<4;i++) {
                int nx=x+dx[i],ny=y+dy[i];
                res+=dfs(nx,ny,id,n,vis,grid);
            }
            return res;
        }
        int largestIsland(vector<vector<int>> &grid) {
            int n=grid.size();
            unordered_map<int,int> area;
            vector<vector<int>> vis(n,vector<int>(n));
            int id=1,ans=0;
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(grid[i][j] && !vis[i][j]) {
                        area[id]=dfs(i,j,id,n,vis,grid);
                        ans=max(ans,area[id++]);
                    }
                }
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(!grid[i][j]) {
                        set<int> s;
                        for(int k=0;k<4;k++) {
                            int x=i+dx[k],y=j+dy[k];
                            if(x>=0 && x<n && y>=0 && y<n) {
                                s.insert(vis[x][y]);
                            }
                        }
                        int cur=1;
                        for(auto it:s) {
                            cur+=area[it];
                        }
                        ans=max(ans,cur);
                    }
                }
            }
            return ans;
        // Your code goes here.
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends