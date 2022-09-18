class Solution {
public:
  
    int longestContinuousSubstring(string s) {
       int cnt  = 1;
        int maxi = 1;
        for(int i=0; i<=s.size() - 1; i++){
           if(s[i] + 1 == s[i+1])cnt++;
            else cnt = 1;
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};