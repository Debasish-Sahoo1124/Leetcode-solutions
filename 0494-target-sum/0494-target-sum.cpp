class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         int n=nums.size();
        return countcom(n,target,nums);
    }
    int findways(vector<int>& nums, int target){
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        if(nums[0]==0) dp[0][0]=2;
        else dp[0][0]=1;
        if(nums[0]!=0 and nums[0]<=target) dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int sum=0;sum<=target;sum++){
                int nontake=dp[i-1][sum];
                int take=0;
                if(nums[i]<=sum) take=dp[i-1][sum-nums[i]];
                dp[i][sum]=take+nontake;

            }
        }
        return dp[n-1][target];

    }
    int countcom(int n,int d,vector<int>& nums){
        int totsum=0;
        for(int x : nums){
            totsum+=x;
        }
        if((totsum-d)<0 || (totsum-d)%2==1) return false;
        return findways(nums,(totsum-d)/2);
    }
};