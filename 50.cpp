class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) {
            auto ans = 1 / pow(x, abs(n));
            return ans != std::numeric_limits<double>::infinity() ? ans : 0;
        }
        else{
            auto ans = pow(x, n);
            return ans;
        }
    }
    double pow(double x, int n){
        if(n == 0) return 1;
        if(n == 1) return x;
        auto t = pow(x, n / 2);
        t *= t;
        if(n % 2){
            t *= x;
        } 
        return t;
    }
};