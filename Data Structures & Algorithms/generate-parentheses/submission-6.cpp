class Solution {
public:

    void solve(int n, int open, int close,
               vector<string>& ans, string& current) {

        if (current.size() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // We can add '(' as long as we haven't used n opening brackets
        if (open < n) {
            current.push_back('(');

            solve(n, open + 1, close, ans, current);

            current.pop_back();
        }

        if (close < open) { // coz only when ( exists, ) exists
            current.push_back(')');

            solve(n, open, close + 1, ans, current);

            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string current;

        solve(n, 0, 0, ans, current);

        return ans;
    }
};