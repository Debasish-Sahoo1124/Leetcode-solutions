class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>> >,greater<pair<int,pair<int,int>>>>pq;
        int n=grid.size();
        int m= grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0]=grid[0][0];
        pq.push({dis[0][0],{0,0}});
        while(!pq.empty()){
            int wt=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==n-1 and col==m-1) return wt;
            int drow[]={0,1};
            int dcol[]={1,0};
            for(int i=0;i<2;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m){
                    if(wt+grid[nrow][ncol]<dis[nrow][ncol]){
                        dis[nrow][ncol]=wt+grid[nrow][ncol];
                        pq.push({dis[nrow][ncol],{nrow,ncol}});
                    }
                }
            }

        }
        return 0;
    }
};