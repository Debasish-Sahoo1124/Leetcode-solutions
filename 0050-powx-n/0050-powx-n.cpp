class Solution {
public:
    double myPow(double x, int n) {
        double y;
        long long N=n;
        if(N<0){
             x=1/x;
             N=-N;
            
        }
        if(N==0)return 1.0;
         
         y=myPow(x,N/2);
         
        if(N%2==0)return y*y;
        else{
            return x*y*y;
        }
        

    }
};