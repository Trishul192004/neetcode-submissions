class Solution{
    public:
    void merge(vector<int>&nums1,int n ,vector<int>&nums2,int m){
        int i = 0 ;
        int j = 0 ;

        vector<int>res;
        while(i < n && j < m){
            if(nums1[i] <= nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
                res.push_back(nums2[j]);
                j++;
            }
        }

        while(i < n ){
            res.push_back(nums1[i]);
            i++;
        }
        while(j < m){
            res.push_back(nums2[j]);
            j++;
        }

        for( int k =0 ; k < res.size(); k++){
            nums1[k] = res[k];
        }

    }
};