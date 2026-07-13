class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n and nums[i]!=0){
            i++;
        }
        int j=i+1;
        while(j<n){
            if(nums[j]!=0 ) {
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else{
                j++;
            }
        }
    }
};