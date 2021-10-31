#include<stdio.h>
#include<string>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector> 
#include<cstdlib>
using namespace std;
int N,E;
int G[15][15];
int vis[15];
queue<int> q;
vector< vector<int> > dfs_res;
vector< vector<int> > bfs_res;

void dfs(int v, vector<int>& vec)
{
	vis[v] = 1;
	vec.push_back(v);
	for(int i = 0; i < N; ++i) {
		if(G[v][i] && !vis[i]) {
			dfs(i,vec);
		}
	}
}

void bfs(int v, vector<int>& vec)
{
	q.push(v);
	vis[v] = 1;
	vec.push_back(v);
	while(!q.empty()) {
		int tmp = q.front();
		q.pop();
		for(int i = 0; i < N; ++i) {
			if(G[tmp][i] && !vis[i]) {
				vec.push_back(i);
				q.push(i);
				vis[i] = 1;
			}
		}
	}
}

int main(void)
{
	scanf("%d%d",&N, &E);
	for(int i = 0; i < E; ++i) {
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		G[t1][t2] = G[t2][t1] = 1;
	}
	int num1 = 0;
	for(int i = 0; i < N; ++i) {
		if(vis[i] != 1) {
			dfs_res.push_back(vector<int>{});
			dfs(i,dfs_res[num1++]);
		}
	}
	for(int i = 0; i < num1; ++i) {
		printf("{ ");
		int len = dfs_res[i].size();
		for(int j = 0; j < len; ++j) {
			printf("%d ", dfs_res[i][j]);
		}
		printf("}\n");
	}
	int num2 = 0;
	memset(vis,0,sizeof(vis));
	for(int i = 0; i < N; ++i) {
		if(vis[i] != 1) {
			bfs_res.push_back(vector<int>{});
			bfs(i,bfs_res[num2++]);
		}
	}
	for(int i = 0; i < num2; ++i) {
		printf("{ ");
		int len = bfs_res[i].size();
		for(int j = 0; j < len; ++j) {
			printf("%d ", bfs_res[i][j]);
		}
		printf("}");
		printf(i == num2-1 ? "" : "\n");
	}
	return 0;
}
