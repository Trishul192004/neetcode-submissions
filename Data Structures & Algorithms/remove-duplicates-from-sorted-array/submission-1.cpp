class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        int i;
        for(int i = 0 ; i < nums.size() ; i++){
            st.insert(nums[i]);
        }

        for( int x : st){
            nums[i] = x ;
            i++;
        }

        return i;
    }
};