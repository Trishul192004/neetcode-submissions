class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0) return false;

        map<int,int>freq;

        //freq
        for(int x : hand){
            freq[x]++;
        }

        while(!freq.empty()){
           
            int start = freq.begin()->first;

            //build consecutive group
            for(int x = start ; x < start + groupSize ;x++){

                if(freq[x] == 0)return false; //reqd card absent

                //use 1 card
                freq[x]--;

                //remove if no cards left
                if(freq[x] == 0){
                    freq.erase(x);
                }

            }
        }
        return true;
    }
};
