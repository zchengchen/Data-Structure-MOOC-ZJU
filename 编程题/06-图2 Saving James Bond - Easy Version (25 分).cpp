#include<stdio.h>
#include<string>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<cstdlib>
using namespace std;
int N;
double D;
double d = 15;
int vis[110];
struct node {
	double x,y;
	node(double _x = 0,double _y = 0):x(_x),y(_y) { }
};
node vertex[110];
bool flag = false;

inline double dis(node& t1,node& t2)
{
	return sqrt((t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y));	
}

inline bool check(node &t1)
{
	return (abs(t1.x)+D >= 50) || (abs(t1.y)+D >= 50);
}

void dfs(int v)
{
	if(flag) return ;
	if(check(vertex[v])){
		flag = true;
		return ;
	}
	vis[v] = 1;
	for(int i = 0; i < N; ++i) {
		if(v != i && !vis[i] && dis(vertex[i],vertex[v]) <= D) {
			dfs(i);
		}
	}
}

int main(void)
{
	scanf("%d%lf",&N, &D);
	for(int i = 0; i < N; ++i) {
		double x1,y1;
		scanf("%lf%lf",&x1,&y1);
		vertex[i].x = x1;
		vertex[i].y = y1;
	}
	node o;
	o.x = o.y = 0;
	for(int i = 0; i < N; ++i) {
		if(!flag && !vis[i] && dis(vertex[i],o) <= d/2.0+D) {
			dfs(i);
		}
	}
	printf(flag ? "Yes" : "No");
	return 0;
}
