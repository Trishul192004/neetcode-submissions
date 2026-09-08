class Solution { 
public: 
    string minWindow(string s, string t) { 
        
        int cnt = 0; 
        int n = s.size(); 
        int m = t.size(); 
        
        int sindex = -1; 
        vector<int>hash(256, 0); 
        
        int minlen = INT_MAX; 
 
        // t elements inserted to hash storing char, freq
        for(int i = 0; i < m; i++){ 
            hash[t[i]]++; 
        }  
        
        int l = 0;  
        int r = 0; 
 
        while(r < n){ 
            
            // If current character is still required
            if(hash[s[r]] > 0) 
                cnt++; 
            
            hash[s[r]]--;  
            
            // Window contains all characters of t
            while(cnt == m){ 
                
                // Store minimum window
                if(r - l + 1 < minlen){ 
                    minlen = r - l + 1; 
                    sindex = l; 
                }
                
                // Remove left character
                hash[s[l]]++;
                
                // If this character is now missing,
                // window is no longer valid
                if(hash[s[l]] > 0) 
                    cnt--;
                
                l++;
            }
            
            r++;
        } 
        
        return sindex == -1 ? "" : s.substr(sindex, minlen); 
    } 
};
