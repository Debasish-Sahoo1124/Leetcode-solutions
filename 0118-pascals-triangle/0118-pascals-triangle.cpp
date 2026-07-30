class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>ans;
       
        for(int i=0; i<numRows;i++){
             int val=1;
             vector<int>ansrow;
        for(int c=0;c<=i;c++){
            ansrow.push_back(val);
            val=val*(i-c)/(c+1);
        }
        ans.push_back(ansrow);
        }
       return ans;
    }
};