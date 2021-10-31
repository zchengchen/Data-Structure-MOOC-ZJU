#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int N,M;
int h[1010];

inline void insert(int index, int val)
{
	int i = index;
	for(;h[i/2] > val; i /= 2) {
		h[i] = h[i/2];
	}
	h[i] = val;
}

int main(void)
{
	h[0] = -0x3f3f3f3f;
	scanf("%d%d",&N,&M);
	for(int i = 1; i <= N; ++i) {
		int tmp;
		scanf("%d", &tmp);
		insert(i,tmp);
	}
	for(int i = 0; i < M; ++i) {
		vector<int> ans;
		int index;
		scanf("%d", &index);
		while(index >= 1) {
			ans.push_back(h[index]);
			index /= 2;
		}
		int t = ans.size();
		for(int j = 0; j < t-1; ++j)
			printf("%d ",ans[j]);
		printf("%d",ans[t-1]);
		printf(i == M-1 ? "" : "\n");
	}
	return 0;
}
