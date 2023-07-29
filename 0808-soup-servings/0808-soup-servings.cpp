class Solution {
public:
    vector<vector<double>> memo;
    
    double f(int NA, int NB){
        if(NA <= 0 && NB <= 0) return 0.5;
        if(NA <= 0) return 1.0;
        if(NB <= 0) return 0.0;
        if(memo[NA][NB] > 0) return memo[NA][NB];
        return memo[NA][NB] = 0.25*(f(NA-4,NB)+f(NA-3,NB-1)+f(NA-2,NB-2)+f(NA-1,NB-3));
    };
    
    double soupServings(int N) {
        if(N > 4800) return 1.0;
        //200 because 4800/25+1=193, it's around 200
        memo = vector<vector<double>>(200, vector<double>(200));
        //conversion from 25's multiple to the number of spoons
        return f(ceil((double)N/25), ceil((double)N/25));
    }
};