/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());
        int cnt = 1;
        int longest = 1;
        if(nums.empty()) return 0;

       for(int i =1 ;i<n;i++){
        if(nums[i] == nums[i-1] + 1) cnt++;
        else if(nums[i]== nums[i-1]){
            continue;
        }
        else{
            cnt =1 ;
        }
        longest = max(longest,cnt);
       }
       return longest;
        
    }
};
*/
class Solution{
    public:
    int longestConsecutive(vector<int> &nums){
        int n = nums.size();
        int cnt =1;
        int longest =1;
        map<int,int>mpp;
        if(nums.empty()) return 0;
        for(int i =0;i<n;i++){
            mpp[nums[i]]++;
        }
        auto prev = mpp.begin();
        for(auto it = next(mpp.begin());it != mpp.end();it++){
            if(it->first == prev->first + 1 ){
                cnt++;
            }
            else{
                cnt =1;
            }
            longest = max(longest,cnt);
            prev = it;
        }
        return longest;
    }
};


