/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 */

// @lc code=start
class Solution {
public:
    struct  trie{
        bool isEnd;
        trie* next[26];
        trie():isEnd(false){
            memset(next,0,sizeof(next));
        }
    };
    trie* root=new trie();
    void insert(string s){
        trie* cur = root;
        int n  = s.size();
        for(int i=0;i<n;++i){
            if(!cur->next[s[i]-'a']){
                trie* next = new trie();
                cur->next[s[i]-'a'] = next;
            }
            cur = cur->next[s[i]-'a'];
        }
        cur->isEnd = true;
    }
    bool search(string s){
        trie* cur = root;
        int n = s.size();
        for(int i=0;i<n;++i){
            if(!cur->next[s[i]-'a']) return false;
            cur  = cur->next[s[i]-'a'];
            if(!cur->isEnd) return false;
        }
        return cur->isEnd;
    }
    string longestWord(vector<string>& words) {
        string s ="";
        for(auto w:words){
            insert(w);
        }
        for(auto w:words){
            if(search(w)){
                if(s.size()<w.size()){
                    s = w;
                }
                if(s.size()==w.size()){
                    s = s.compare(w)>0? w :s;
                }
            }
        }
        return s;
    }
};
// @lc code=end

