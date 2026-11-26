class Solution{
    public:
    
    vector<int> prefixmax(vector<int>&height){
        int n = height.size();
        vector<int>prefix(n);
        prefix[0] = height[0];

        for(int i = 1 ; i < n ;i++){
            prefix[i] = max(height[i],prefix[i-1]);
        }
        return prefix;
    }

    vector<int>suffixmax(vector<int>&height){
        int n = height.size();
        vector<int>suffix(n);

        suffix[n-1] = height[n-1];
        for(int i = n -2 ; i >=0 ; i--){
            suffix[i] = max(suffix[i+1],height[i]);
        }

        return suffix;
    }

    int trap(vector<int>&height){
        vector<int>prefix = prefixmax(height);
        vector<int>suffix = suffixmax(height);

        int total = 0;
        for(int i = 0 ; i < height.size(); i++){
           int  leftmax = prefix[i];
           int rightmax = suffix[i];
            
            total += (min(leftmax,rightmax) - height[i]);
        }

        return total;
    }
};