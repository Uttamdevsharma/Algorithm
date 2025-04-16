#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];
int parent[1005];



void bFs(int src){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    

    while (!q.empty()){

        int par = q.front();
        q.pop();

        // cout << par << " ";

        for(int child : adj_list[par]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                parent[child] = par;
                
            }
        }

    }   
}
int main(){
    int n,e;
    cin >> n >> e;

    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);

    }
    memset(vis,false,sizeof(vis));
    
    int s,d;
    cin >> s >> d;

    bFs(s);

    vector<int>path;
    int node=d;

    while(node != -1){
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(),path.end());
}