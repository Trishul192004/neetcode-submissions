class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        int left = 0 ;
        int right = 0;

        for(int i = 0 ; i < n ; i++){
            freq1[s1[i] - 'a']++;
        }


        while(right < m){
            //add current ch. to window 
            freq2[s2[right] - 'a']++;

            if(right - left + 1 > n){//wind size for freq2 to be same as n
                freq2[s2[left] - 'a']--;
                left++;
            }

            //check if current window is a permuation
            if(freq1 == freq2) return true;

            right++;
        }
        
            return false;
    }
};
