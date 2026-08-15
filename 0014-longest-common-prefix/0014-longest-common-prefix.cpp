class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string s=strs[0];
        for(int i=1;i<strs.size();i++){
            while(strs[i].find(s)!=0){
                s.pop_back();
            }
            if(s.empty()) return "";
        }
        return s;
    }
};