#include<stdio.h>
#include<string>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<iomanip>
#include<cstdlib>
using namespace std;
int N,M;
int G[1010][1010];
int ans[1010];
int vis[1010];

void bfs(int v)
{
    memset(vis,0,sizeof(vis));	
    queue<int> q;
    vis[v] = 1;
    q.push(v);
 
    for (int level = 0; level < 6; level++) {
        vector<int> vec;
        while (!q.empty()) {
            int node = q.front();
            vec.push_back(node);
            q.pop();
        }
        for (int i = 0; i < vec.size(); i++) {
            int node = vec[i];
            for (int i = 1; i <= N; i++) {
                if (!vis[i] && G[node][i] == 1) {
                    q.push(i);
                    vis[i] = 1;
                    ++ans[v];
                }
            }
        }
    }
}

int main(void)
{
	scanf("%d%d",&N,&M);
	for(int i = 0; i < M; ++i) {
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		G[t1][t2] = G[t2][t1] = 1;
	}
	for(int i = 1; i <= N; ++i) {
		bfs(i);
	}
	for(int i = 1; i <= N; ++i) {
		printf("%d: %.2lf%%", i,double(ans[i]+1)/N*100.0);
		printf(i == N? "" : "\n");
	}
	return 0;
}
