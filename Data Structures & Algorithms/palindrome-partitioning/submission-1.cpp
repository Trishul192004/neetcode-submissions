class Solution {
public:

    bool isPalindrome(string &s,int left,int right){
        while(left < right){
            if(s[left] != s[right]) return false;
            
            left++;
            right--;
        }
        return true;
    }



    void solve(string &s,int start,vector<string>&current,vector<vector<string>>&ans){
        
        //we've used entire string
        if(start == s.size()){
            ans.push_back(current);
            return;
        }


        //try every possible substring starting from start
        for(int end = start; end< s.size(); end++){

            if(isPalindrome(s,start,end)){
                //take palindrome
                current.push_back(s.substr(start,end-start+1));

                solve(s,end + 1,current,ans);

                current.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>current;

        solve(s,0,current,ans);

        return ans;        
    }
};
