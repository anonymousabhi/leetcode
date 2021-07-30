#include <iostream>
#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>> &graph, int u,int v){
    cout<<"adding edge from "<<u<<" to "<<v<<endl;
    graph[u].push_back(v);
}

void print(vector<vector<int>> graph) {
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph[i].size();j++){
            cout<<i<<"has a edge to "<<graph[i][j]<<endl;
        }
    }
}

void dfsHelper(vector<vector<int>> graph,vector<int> &vis,int src){
    cout<<src<<" ";
    vis[src] = 1;
    for(auto it: graph[src]){
        if(vis[it] == 0){
            dfsHelper(graph,vis,it);
        }
    }
}


void dfs(vector<vector<int>> graph,vector<int> vis,int vertices){
    int components = 0;
    for(int i=0;i<vertices;i++){
        if(vis[i] == 0){
            dfsHelper(graph,vis,i);
            components++;
        }
    }
    cout<<"Total no of components are : "<<components<<endl; 
    
}

int main() {

    
    int vertices = 7;
    vector<vector<int>> graph(vertices,vector<int>(0,0));
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,2,5);
    addEdge(graph,5,6);
    addEdge(graph,3,5);
    
    print(graph);
    
    //Graph
    cout<<"DFS is "<<endl;
    vector<int> vis(7,0);
    dfs(graph,vis,vertices);
    
	return 0;
}
