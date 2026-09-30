class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // adjacency list
        vector<vector<int>> graph(numCourses);

        // indegree[i] = number of prerequisites of course i
        vector<int> indegree(numCourses, 0);

        // Build graph
        for(auto &pre : prerequisites) {

            int course = pre[0];
            int prerequisite = pre[1];

            // prerequisite -> course
            graph[prerequisite].push_back(course);

            // course has one more prerequisite
            indegree[course]++;
        }

        // Queue stores courses that have no prerequisites
        queue<int> q;

        // Put all courses with 0 prerequisites
        // into the queue
        for(int i = 0; i < numCourses; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // Count courses we successfully complete
        int completed = 0;

        // BFS
        while(!q.empty()) {

            int course = q.front();
            q.pop();

            completed++;

            // Remove this course as a prerequisite
            // from all neighboring courses
            for(int nextCourse : graph[course]) {

                indegree[nextCourse]--;

                // No prerequisites remaining
                if(indegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }

        // If we completed every course,
        // there is no cycle
        return completed == numCourses;
    }
};