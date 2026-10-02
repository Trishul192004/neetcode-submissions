class Solution {
public:

    int openLock(vector<string>& deadends, string target) {

        // Store all deadends in a set
        unordered_set<string> dead;

        for(string s : deadends) {
            dead.insert(s);
        }

        // If starting position itself is blocked
        if(dead.count("0000")) {
            return -1;
        }

        // BFS queue
        queue<string> q;

        // Visited states
        unordered_set<string> visited;

        q.push("0000");
        visited.insert("0000");

        int turns = 0;

        while(!q.empty()) {

            int size = q.size();

            // Process all states at current level
            while(size--) {

                string current = q.front();
                q.pop();

                // Target reached
                if(current == target) {
                    return turns;
                }

                // Try changing each of the 4 wheels
                for(int i = 0; i < 4; i++) {

                    string next = current;

                    // Turn wheel forward
                    if(next[i] == '9')
                        next[i] = '0';
                    else
                        next[i]++;

                    // Add if valid
                    if(!dead.count(next) &&
                       !visited.count(next)) {

                        visited.insert(next);
                        q.push(next);
                    }


                    // Turn wheel backward
                    next = current;

                    if(next[i] == '0')
                        next[i] = '9';
                    else
                        next[i]--;

                    // Add if valid
                    if(!dead.count(next) &&
                       !visited.count(next)) {

                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // Move to next BFS level
            turns++;
        }

        // Target cannot be reached
        return -1;
    }
};