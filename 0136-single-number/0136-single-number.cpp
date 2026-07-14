class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int num : nums){
            freq[num]++;
        }
        int x;
        for(auto it : freq){
            if(it.second==1){
                x=it.first;
            }
        }
        return x;
    }
};