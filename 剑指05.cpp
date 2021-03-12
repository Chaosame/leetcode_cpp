class Solution {
public:
    string replaceSpace(string s) {
        int s_len = s.size();
        string res = "";
        for(int i =0;i<s_len;i++){
            if (s[i]!=' ') res+=s[i];
            else res+= "%20";
        }
        return res;
    }
};