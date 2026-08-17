class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()<b.size();
        });
        int n=words.size();
        vector<int>dp(n+1,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(comparison(words[i],words[prev]) and dp[prev]+1>dp[i]){
                    dp[i]=1+dp[prev];
                }
                
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
    bool comparison(string &s1,string &s2){
        if(s1.size()!=s2.size()+1) return false;
        int first=0;
        int second =0;
        while(first<s1.size()){
            if(s1[first]==s2[second] and s1.size()>s2.size()){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first==s1.size() and second ==s2.size()) return true;
        return false;
    }
};