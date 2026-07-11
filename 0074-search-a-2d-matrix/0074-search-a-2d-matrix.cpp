class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            int d=n-1;
            int k=0;
            while(d>=k){
               int  mid=(d+k)/2;
                if(matrix[i][mid]==target){
                    return true;
                }
                else if(matrix[i][mid]<target){
                    k=mid+1;
                }
                else{
                    d=mid-1;
                }
            }
           
        }
        return false;

    }
};