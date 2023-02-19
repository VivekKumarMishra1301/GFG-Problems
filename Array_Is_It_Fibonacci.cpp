// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> GeekNum) {
        // code here
        if(n<=k){
            return GeekNum[n-1];
        }
        if(k==1){
            return GeekNum[0];
        }
        long long hold=accumulate(GeekNum.begin(),GeekNum.end(),0);
        GeekNum.push_back(hold);
        long long sum=0;
        
        for(int i=0;i<(n-k)-1;i++){
            sum+=GeekNum[i];
            hold+=GeekNum[GeekNum.size()-1];
            long long num=hold-sum;
            GeekNum.push_back(num);
        }
        return GeekNum[GeekNum.size()-1];
        
    }
};