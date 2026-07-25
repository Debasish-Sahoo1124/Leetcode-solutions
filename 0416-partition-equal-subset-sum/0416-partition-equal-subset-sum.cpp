class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totsum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            totsum+=nums[i];
        }
        int target=totsum/2;
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        if(totsum%2==1) return false;
        
            for(int i=0;i<n;i++) dp[i][0]=true;
             if(target>=nums[0]){
                dp[0][nums[0]]=true;
             }
            for(int i=1;i<n;i++){
                for(int j=1;j<=target;j++){
                   bool nontake=dp[i-1][j];
                   bool take=false;
                   if(j>=nums[i]){
                    take=dp[i-1][j-nums[i]];
                   }
                 dp[i][j]=take||nontake;
                }
                
            
        }
        return dp[n-1][target];
    }
};