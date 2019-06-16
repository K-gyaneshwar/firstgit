#include<iostream>
#include<list>
#include<queue>
#include<cstdbool>
using namespace std;

class graph{
    int size;
    list<int> *adj;
    public:
        graph(int s){
        size=s+1;
        adj = new list<int>[size];
    }
    void insert(int u,int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    list<int> adjList(int u){
        return adj[u];
    }
    void bfs(int v){
        bool *marked = new bool[size];
        int * dist = new int[size];
        for(int i=0;i<size;i++){
            marked[i]=0;
            dist[i]=0;
        }
        queue<int> q;
        q.push(v);
        marked[v]=1;
        dist[v]=0;
        int temp;
        list<int> l;
        while(!q.empty()){
            temp=q.front();
            q.pop();
            l=adjList(temp);
            for(int x:l){
                if(!marked[x]){
                    q.push(x);
                    marked[x]=1;
                    dist[x]=dist[temp]+1;
                    cout<<"node "<<x<<" at distance "<<dist[x]<<endl;
                }
            }
            //cout<<endl;
        }
        delete marked;
    }
    ~graph(){
        delete adj;
    }
};

int main(){
    graph g(9);
    g.insert(1,2);
    g.insert(1,8);
    g.insert(1,6);
    g.insert(3,2);
    g.insert(8,3);
    g.insert(6,7);
    g.insert(3,4);
    g.insert(9,5);
    g.insert(7,5);
    g.insert(4,5);
    g.insert(3,9);
    g.insert(9,7);

    g.bfs(1);
    //cout<<endl;


}
