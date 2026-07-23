class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n= obstacleGrid.size();
        int m= obstacleGrid[0].size();
        vector<int>prev(m,0);
        for(int i=0;i<n;i++){
            vector<int>temp(m,0);
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1) temp[j]=0;
                else if(i==0 and j==0){
                    temp[j]=1;
                }
                else if(j==0){
                    temp[j]=prev[j];
                }
                else{
                    if(obstacleGrid[i][j]!=1){
                        temp[j]=temp[j-1]+prev[j];
                    }
                    else{
                        continue;
                    }
                }
            }
            prev=temp;
        }
        return prev[m-1];
    }
};