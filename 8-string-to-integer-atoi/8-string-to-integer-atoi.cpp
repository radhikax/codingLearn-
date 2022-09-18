class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        long result = 0;
         int sign = 1;
        int  i =0;
        // whitespaces
        while(s[i] == ' ')i++;
       // sign -ve, +ve
        if(s[i] == '-' || s[i] == '+'){
            sign = s[i++]== '+' ? 1:-1;
        }
        // string to int
        if(!(s[i] >='0' && s[i] <= '9')) return 0;;
        while(i < n && s[i] >='0' && s[i] <='9' ){
            result = result*10 + (s[i++] - '0');
            //handling overflow condition
            if(result*sign <= INT_MIN) return INT_MIN;
            if(result*sign >= INT_MAX) return INT_MAX;
        }
        return result*sign;
      
    }
};