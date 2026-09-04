class Solution {
public:
    string decodeString(string s) {
        stack<int>numstack;
        stack<string>strstack;

        string current = "";
        int num = 0;

        for(char ch  : s ){
            
            if(isdigit(ch)){
                num = num * 10 + (ch - '0');
            }

            else if(ch == '['){
                numstack.push(num);
                strstack.push(current);
                num = 0 ;
                current = "";
            }
            else if(ch == ']'){
                int repeat = numstack.top();
                numstack.pop();

                string previous = strstack.top();
                strstack.pop();

                string temp = "";

                for(int i  =  0 ; i < repeat ; i++){
                    temp += current;
                }

                current = previous + temp;
            }

            else {
                current  += ch;
            }
        }

        return current;

    }
};