#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
const int N = 1e5+5;
vector<pi> v[N];
bool vist[N];
class Edge{
    public:
     int a;
     int b;
     int w;

     Edge(int a,int b,int w){
        this->a = a;
        this->b = b;
        this->w = w;

     }
};
class cmp{
    public:
     bool operator()(Edge a, Edge b){
        return a.w > b.w;
     }
};
void prims(int s,int n){
    priority_queue<Edge,vector<Edge>,cmp> pq;
    pq.push(Edge(s,s,0));

    vector<Edge> edgeList;
    int cnt = 0;
    while (!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();

        int a = parent.a;
        int b = parent.b;
        int w = parent.w;
        if(vist[b]) continue;
        vist[b] =true;
        cnt++;
        edgeList.push_back(parent);

        for (int i = 0; i < v[b].size(); i++)
        {
            pi child = v[b][i];
            int childNode = child.first;
            int childCost = child.second;

            if(!vist[childNode]){
                pq.push(Edge(b,childNode,childCost));
            }
        }
        
    }   
    edgeList.erase(edgeList.begin());
    long long int cost =  0;
    for(Edge val : edgeList){
        cost += (long long) (val.w);
    }
   if(cnt == n){
     cout<<cost<<endl;
   }
   else cout<<"IMPOSSIBLE"<<endl;
}

int main(){
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }
    prims(1,n);
    return 0;
}