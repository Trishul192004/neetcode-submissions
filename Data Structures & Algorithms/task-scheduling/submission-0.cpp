class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Count frequency of each task
        vector<int> freq(26, 0);

        for(char task : tasks) {
            freq[task - 'A']++;
        }

        // Step 2: Max heap based on frequency
        priority_queue<int> maxHeap;

        for(int f : freq) {
            if(f > 0) {
                maxHeap.push(f);
            }
        }

        // Step 3: Process tasks
        int time = 0;

        while(!maxHeap.empty()) {

            vector<int> temp;

            // Process n + 1 tasks
            for(int i = 0; i < n + 1; i++) {

                if(!maxHeap.empty()) {

                    int freq = maxHeap.top();
                    maxHeap.pop();

                    temp.push_back(freq);
                }
            }

            // Decrease frequency and put back
            for(int freq : temp) {

                freq--;

                if(freq > 0) {
                    maxHeap.push(freq);
                }
            }

            // Update time
            if(maxHeap.empty()) {
                time += temp.size();
            }
            else {
                time += n + 1;
            }
        }

        return time;
    }
};