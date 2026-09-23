class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for(char ch : s){

            if(ch == '('){
                low++;
                high++;
            }

            else if (ch == ')'){
                low--;
                high--;
            }

            else{ // *
             low--; //treat * as ')'
             high++; // * as (
            }
            
            // if max possible (  as negative
            if(high < 0) return false;
            
            //min cant be negative
            if(low < 0) low = 0 ;
        }

        return low == 0;
      
    }
};
