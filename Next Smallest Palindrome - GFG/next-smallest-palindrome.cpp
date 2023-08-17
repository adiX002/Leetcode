//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
 vector<int> generateNextPalindrome(int num[], int n) {    // code here
      bool change=1;
      for(int i=0;i<n/2;i++)
     {
         if(num[i]<num[n-i-1])
         change=1;
         else if(num[i]>num[n-i-1])
          change=0;
          num[n-i-1]=num[i];
     }
     vector<int> res(n);
     for(int i=0;i<n;i++)
     res[i]=num[i];
     
     int ind=n/2;
     bool carry=change;
     while(carry && ind<n){
         if(res[ind]==9){
             res[ind]=0;
             res[n-ind-1]=0;
         }else{
             res[ind]++;
             res[n-ind-1]=res[ind];
             carry=0;
         }
         ind++;
     }
      if(carry){
          res[0]=1;
          res.push_back(1);
      }
      
      return res;
      
     // code here
 }

};;

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends