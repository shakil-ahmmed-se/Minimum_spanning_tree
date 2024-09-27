#include<bits/stdc++.h>
using namespace std;
const long long int  INF = 1e18 + 2;

class Edge{
public:
    long long int u;
    long long int v;
    long long int w;

    Edge(long long int u,long long int v,long long int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main(){
    long long int n,e;
    cin>>n>>e;
    vector<Edge> v;
    while (e--){
        long long int  a,b,w;
        cin>>a>>b>>w;
        Edge ed(a,b,w);
        v.push_back(ed);
    }
    int s;
    cin>>s;
    long long int dist[n+1];
    for ( int i = 1; i <= n; i++){
        dist[i] = INF;
    }
    dist[s] = 0;

    for ( int i = 1; i <= n; i++){
        for ( int j = 0; j < v.size(); j++){
            Edge ed = v[j];
            long long int a = ed.u;
            long long int b = ed.v;
            long long int w = ed.w;

            if(dist[a] + w < dist[b]){
                dist[b] = dist[a] + w;
            }
        }
    }

    bool cycle = false;
    for ( int j = 0; j < v.size(); j++){
        Edge ed = v[j];
        long long int a = ed.u;
        long long int b = ed.v;
        long long int w = ed.w;

        if(dist[a] + w < dist[b]){
            cycle = true;
            // break;
        }
        
    }

    if(cycle){
        cout<<"Negative Cycle Detected"<<endl;
       
    }
    else{
        
        int q;
        cin>>q;
        while (q--){
            int d;
            cin>>d;
           if(dist[d] >= INF-10000){
            
            cout<<"Not Possible"<<endl;
           }
           else{
            cout<<dist[d]<<endl;
           }
        }
    
    }

    return 0;
}
