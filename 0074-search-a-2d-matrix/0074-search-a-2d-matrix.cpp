class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m=matrix.size(),n=matrix[0].size();
        int start=0,end=n*m-1;
        
        while(start<=end){
            int mid=end-(end-start)/2;
            int mid_ele=matrix[mid/n][mid%n];
            
            if(mid_ele==target)return true;
            else if(mid_ele<target)start=mid+1;
            else end=mid-1;
            
        }
        
        return false;
    }
};