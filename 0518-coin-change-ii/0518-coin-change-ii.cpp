class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
         vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return f(n-1,amount,coins,dp);
    }
    int f(int ind,int amount, vector<int>& coins,vector<vector<int>>& dp){
        int n=coins.size();
        
        if(ind==0) {
            return dp[ind][amount] = (amount%coins[0]==0);
        }
        if(amount==0) return 1;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int nontake=f(ind-1,amount,coins,dp);
        int take=0;
        if(amount>=coins[ind]){
            take=f(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=take+nontake;
    }
};