class Solution {
public:
    bool backtrack(vector<int>&matchsticks,vector<int>&sides,int index,int target){
        if(index == matchsticks.size()) return true;
      

        //try putting current matchstick
        for(int side = 0 ; side<4 ;side++){
            if(sides[side] + matchsticks[index] <=target){
                sides[side] += matchsticks[index];
                if(backtrack(matchsticks,sides,index+1,target)) return true;
                sides[side] -= matchsticks[index]; //undo choice backtrack
            }
        }
        return false;
    }


    bool makesquare(vector<int>& matchsticks) {
        
        //calc total len
        int total = 0;

        for(int stick : matchsticks){
            total += stick;
        }

        if(total % 4 != 0) return false;

        int target = total/4; // each side to've this len

        vector<int>sides(4,0); //each side of sq..

        sort(matchsticks.rbegin(),matchsticks.rend());

        return backtrack(matchsticks,sides,0,target);

    }
};