class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int mx=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
               if(mx<count){
                mx=count;
               }
               count=0;
            }
            else{
                count++;
            }
        }
         mx=max(count,mx);
        return mx;
    }
};