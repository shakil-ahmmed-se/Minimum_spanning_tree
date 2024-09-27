#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
int parentSize[N];

void dsu_set(int n){
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
    
}
int dsu_find(int node){
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a,int b){
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if(leaderA != leaderB){
        if(parentSize[leaderA] > parentSize[leaderB]){
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else{
            parent[leaderA] = leaderB;
            
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main(){
    int n;
    cin>>n;
    dsu_set(n);
    int sum = 0;
    for (int i = 0; i < n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if(leaderA == leaderB){
           cout<<parent[leaderA]<<" "<<parent[leaderB]<<endl;
        }
        else{
            dsu_union(a,b);
        }
    }
    
    return 0;
}