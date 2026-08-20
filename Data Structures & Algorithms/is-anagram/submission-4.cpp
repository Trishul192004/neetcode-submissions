/*class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        int count[26] = {};

        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int value : count) {
            if (value != 0) {
                return false;
            }
        }

        return true;
    }
};

*/
class Solution{
    public:
    bool isAnagram(string s , string t){
        if(s.size() != t.size()) return false;
        
        unordered_map<char,int>hash;

        for(int i=0;i<s.size();i++){
            hash[s[i] - 'a' ]++;
            hash[t[i] - 'a']--;
        }
        for(auto pair:hash){
            if(pair.second != 0 ) return false;
        }
            return true;

    }
};