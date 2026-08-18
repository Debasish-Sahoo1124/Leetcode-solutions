class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),c(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev] and 1+dp[prev]>dp[i]){
                    dp[i]=dp[prev]+1;
                      c[i]=c[prev];
                }
                else if(nums[i]>nums[prev] and 1+dp[prev]==dp[i]){
                    c[i]+=c[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int ans=0;
        for(int j=0;j<n;j++){
            if(dp[j]==maxi){
                ans+=c[j];
            }
        }
        return ans;
    }
};