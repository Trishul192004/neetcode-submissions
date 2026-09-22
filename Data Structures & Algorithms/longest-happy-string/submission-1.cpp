class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        string res;

        priority_queue<pair<int, char>> maxheap;

        if (a > 0) maxheap.push({a, 'a'});
        if (b > 0) maxheap.push({b, 'b'});
        if (c > 0) maxheap.push({c, 'c'});

        while (!maxheap.empty()) {

            auto [count, maxchar] = maxheap.top();
            maxheap.pop();

            int n = res.size();

            // If using maxchar creates 3 same characters when maximum 2 allowed
            if (n >= 2 && res[n - 1] == maxchar && res[n - 2] == maxchar) {

                // No alternative character available
                if (maxheap.empty())
                    break;

                // Take second most frequent character
                auto [nextcount, nextchar] = maxheap.top();
                maxheap.pop();

                res.push_back(nextchar);
                nextcount--;

                // Put it back if characters remain
                if (nextcount > 0) {
                    maxheap.push({nextcount, nextchar});
                }

                // Put maxchar back because we didn't use it
                maxheap.push({count, maxchar});

            }
            else {

                // We can safely use maxchar
                res.push_back(maxchar);
                count--;

                // Put it back if characters remain
                if (count > 0) {
                    maxheap.push({count, maxchar});
                }
            }
        }

        return res;
    }
};