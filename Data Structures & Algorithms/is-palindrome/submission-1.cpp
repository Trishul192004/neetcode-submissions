class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = s.size() - 1;
        while(left <right){
            //skip punctuation
            if(!isalnum(s[left])){
                left++;
                continue;
            }
            if(!isalnum(s[right])){
                right--;
                continue;
            }

            //compare lowercase chars
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }

            left++;
            right--;

        }
        return true;
    }
};
