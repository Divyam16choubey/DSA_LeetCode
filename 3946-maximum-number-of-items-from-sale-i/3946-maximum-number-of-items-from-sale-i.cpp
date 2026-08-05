class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> gain(n,0);
        for(int i=0; i<n; i++){
            int fi = items[i][0];

            for(int j=0; j<n; j++){
                if(i == j) continue;

                int fj = items[j][0];
                if(fj % fi == 0)
                    gain[i]++;
            }
        }

        vector<int> p(budget+1, 0);
        for(int i=0; i<n; i++){
            int w = items[i][1];
            int g = gain[i];

            vector<int> q = p;

            for(int r=0; r<w; r++){
                int best = -1000000000;
                for(int k=0, b=r; b<=budget; k++, b+= w){
                    if(k>=1){
                        q[b] = max(
                            q[b],k+g+best);
                    }
                    best = max(best, p[b] - k);
                    
                }
            }
            p.swap(q);
           
        }
         return *max_element(p.begin(), p.end());
    }
};