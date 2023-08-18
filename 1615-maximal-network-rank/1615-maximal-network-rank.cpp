class Solution {
public:
    int encode(int i, int j){
        if(i > j) swap(i, j);
        //n's range [2,100]
        //i*128+j
        return (i<<7)+j;
    }
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degrees(n, 0);
        unordered_set<int> edges;
        
        for(vector<int>& road : roads){
            edges.insert(encode(road[0], road[1]));
            ++degrees[road[0]];
            ++degrees[road[1]];
        }
        
        int max_i = max_element(degrees.begin(), degrees.end()) - degrees.begin();
        int max_degree = degrees[max_i];
        int max_degree_count = count(degrees.begin(), degrees.end(), max_degree);
        
        size_t ans = 0;
        
        if(max_degree_count == 1){
            //there are only one city with max degree
            //try all other cities
            for(int j = 0; j < n; ++j){
                if(j == max_i) continue;
                ans = max(ans, max_degree+degrees[j]-edges.count(encode(max_i, j)));
            }
        }else{
            int roads_btw_max_degree = count_if(roads.begin(), roads.end(),
                [&degrees, &max_degree](vector<int>& r){
                    return (degrees[r[0]] == max_degree) && (degrees[r[1]] == max_degree);});
            ans = max_degree * 2 - (roads_btw_max_degree == max_degree_count*(max_degree_count-1)/2);
        }
        
        return ans;
    }
};