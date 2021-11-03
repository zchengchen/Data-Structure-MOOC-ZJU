#include<cstdio>
#include<algorithm>
using namespace std;

int N,M;
const int inf = 0x3f3f3f3f;
int G[110][110];
int mstep[110];
int ans_step;
int ans_index;

inline void init()
{
	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= N; ++j) {
			G[i][j] = G[j][i] = inf;
		}
		G[i][i] = 0;
	}
}

inline void floyd()
{
	for(int k = 1; k <= N; ++k) {
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= N; ++j) {
				if(G[i][k] + G[k][j] < G[i][j]) {
					G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
	}
}

int main(void)
{
	scanf("%d%d", &N, &M);
	init();
	for(int i = 0; i < M; ++i) {
		int v1,v2,w;
		scanf("%d%d%d",&v1, &v2, &w);
		G[v1][v2] = G[v2][v1] = w;
	}
	floyd();
	for(int i = 1; i <= N; ++i) {
		int max_step = -1;
		for(int j = 1; j <= N; ++j) {
			max_step = max(max_step, G[i][j]);
		}
		mstep[i] = max_step;
	}
	ans_step = inf;
	for(int i = 1; i <= N; ++i) {
		if(ans_step > mstep[i]) {
		 	ans_step = mstep[i];
		 	ans_index = i;
		 }
	}
	
	if(ans_step == inf) printf("0");
	else printf("%d %d", ans_index, ans_step);
	return 0;
}
