/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack <int> nums;
        stack <string> strs;
        int num = 0;
        int len = s.size();
        for (int i=0;i<len;++i){
            if (s[i]>='0' && s[i]<='9'){ // 数字的话需要把之间的数字当作高位 然后把现在得拼到num中
             num = num*10 +s[i]-'0';
                }
            else if((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z')){ //如果是字母 先拼到目前的res中
                res =res+  s[i];
            } 
            else if(s[i]=='['){ //左括号则把现在的res和num压栈 并且初始化 
                nums.push(num);
                num = 0;
                strs.push(res);
                res = "";
            }
            else{ //右括号则把栈中的数字取出作为次数 res作为需要倍化的字符串 把结果加入str栈中
                int times= nums.top();
                nums.pop();
                for(int j=0;j<times;++j){
                    strs.top()+=res; // 现在需要倍化字符串是res 处理完成后res变成现在的top
                }
                res = strs.top();
                strs.pop();
            }
        }
        return res;
    }
};
// @lc code=end

