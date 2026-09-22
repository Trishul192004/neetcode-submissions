class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>freq;

        //count freq
        for(char ch : s){
            freq[ch]++;
        }

        //max heap : freq,char
        priority_queue<pair<int,char>>pq;

        for(auto it : freq){
            pq.push({it.second,it.first});
        }

        string ans;

        while(pq.size() >=2){
            auto[freq1,ch1] = pq.top();
            pq.pop();

            auto[freq2,ch2] = pq.top();
            pq.pop();

            //use 2 diff. chars
            ans += ch1;
            ans += ch2;

            freq1--;
            freq2--;

            if(freq1 > 0) pq.push({freq1,ch1});
            if(freq2 > 0) pq.push({freq2,ch2});

        }

        //1 ch. may remain
        if(!pq.empty()){
            auto[count,ch] = pq.top();

            if(count > 1 ) return ""; //if >1 remains impossible

            //check last ch. is different
            if(!ans.empty() && ans.back() == ch){
                return "";
            }  
            //else last ch . is diff so add to ans
                ans += ch;
            
        }

        return ans;
    }
};