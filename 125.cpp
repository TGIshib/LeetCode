class Solution {
public:
    bool isPalindrome(string s) {
        if(!s.size()) return true;
        int start = 0, fin = s.size() - 1;
        while(start < fin){
            while(start < fin && !is_letter(s[start])) start++;
            while(start < fin && !is_letter(s[fin])) fin--;
            if(start >= fin) return true;
            if(get_low(s[start]) != get_low(s[fin])) return false;
            start++;
            fin--;
        }
        return true;
    }
    bool is_letter(char c){
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
    }
    char get_low(char c){
        if(c >= 'A' && c <= 'Z') return 'a' + c - 'A';
        return c;
    }
};
