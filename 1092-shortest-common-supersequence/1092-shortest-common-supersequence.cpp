class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
              if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
              }
              else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

              }
            }
        }
        string ans="";
        int l=n;
        int r=m;
        while(l>0 and r>0){
            if(str1[l-1]==str2[r-1]){
                ans+=str1[l-1];
                l--;
                r--;
            }
            else if(dp[l-1][r]>dp[l][r-1]){
               ans+=str1[l-1];
               l--;

            }
            else{
                ans+=str2[r-1];
                r--;
            }
        }
        while(l>0) { 
            ans+=str1[l-1];
               l--;
        }
        while(r>0){
                ans+=str2[r-1];
                r--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};