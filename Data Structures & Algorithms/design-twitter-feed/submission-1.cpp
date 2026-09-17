class Twitter {
public:

    unordered_map<int,unordered_set<int>>following;//userid,followingid
    unordered_map<int,vector<pair<int,int>>>tweets;//userid, {timestamp,tweetid}
    int timer = 0;

    Twitter() {
        timer = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        timer++;
        tweets[userId].push_back({timer,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<pair<int,int>>pq;

        //add tweets from people user follows
        for(int followee : following[userId]){    
            for(auto tweet : tweets[followee]){
                pq.push(tweet);
            }
        }

        for(auto tweet : tweets[userId]){
            pq.push(tweet);
        }

        vector<int>ans;
        //get max 10 recnet tweets
        while(!pq.empty() && ans.size()<10){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
