#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long N = 100;
long long dist[N][N];
int main(){
    long long n,e;
    cin>>n>>e;
    
    for (long long i = 1; i <= n; i++)
    {
       for (long long j = 1; j <= n; j++)
       {
            dist[i][j] = INF;

            if(i == j ){
                dist[i][j] = 0;
            }
       }
       
    }
    while (e--)
    {
        long long a,b,w;
        cin>>a>>b>>w;
        if(dist[a][b] == INF || dist[a][b] > w)  dist[a][b] =  w;
    }
  
        
    for (long long k = 1; k <= n; k++)
    {
         for (long long i = 1; i <= n; i++)
        {
            for (long long j = 1; j <= n; j++)
            {
                if(dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        
    }
    
    long long q;
    cin>>q;
    while (q--)
    {
        long long x,y;
        cin>>x>>y;
        if(dist[x][y] == INF) cout<<"-1"<<endl;
        else cout<<dist[x][y]<<endl;
    }

   

    return 0;
}