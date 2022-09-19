class Solution {
public:
  bool isPalindrome(string &s, int l, int r){
      while( l < r){
          if(s[l++] != s[r--])return false;
      }
      return true;
  }
  string longestPalindrome(string s) {
        
      string maxs = s.substr(0,1);
      for(int i=0; i<s.length(); i++){
          for(int j = i+1; j < s.length(); j++){
              if(isPalindrome(s,i,j) && maxs.length() < j - i + 1){
                  maxs = s.substr(i, j-i+1);
              }
          }
      }
      return maxs;
    }
    
};