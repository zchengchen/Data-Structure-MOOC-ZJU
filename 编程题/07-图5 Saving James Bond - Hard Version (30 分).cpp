#include<stdio.h>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
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
	node(double _x = 0,double _y = 0) : x(_x),y(_y) { }
};
node o;
node vertex[110];
int path[110];
int last;
bool flag = false;
queue<int> q;

inline double dis(node& t1,node& t2)
{
	return sqrt((t1.x - t2.x) * (t1.x - t2.x) + (t1.y - t2.y) * (t1.y - t2.y));	
}

inline bool check(node &t1)
{
	return (abs(t1.x) + D >= 50) || (abs(t1.y) + D >= 50);
}

bool cmp(int lhs, int rhs)
{
	return dis(vertex[lhs], o) < dis(vertex[rhs], o);
}

void bfs()
{
	while(!q.empty()) {
		int v = q.front();
		if(check(vertex[v])) {
			flag = true;
			last = v;
			return ; 
		}
		q.pop();
		for(int i = 0;i < N; ++i) {
			if(!vis[i] && dis(vertex[i],vertex[v]) <= D) {
				path[i] = v;
				vis[i] = 1;
				q.push(i);
			}
		}	
	}
}

int main(void)
{
	scanf("%d%lf",&N, &D);
	if(D + d/2 >= 50) {
		printf("1");
		return 0; 
	}
	vector<int> first_jump;
	for(int i = 0; i < N; ++i) {
		double x1,y1;
		scanf("%lf%lf",&x1,&y1);
		vertex[i].x = x1;
		vertex[i].y = y1;
		node cur = node(x1,y1);
		if(dis(cur, o) <= D + d/2.0) {
			path[i] = -1;
			vis[i] = 1;
			first_jump.push_back(i);
		}
	}
	sort(first_jump.begin(), first_jump.end(), cmp);
	for(int i = 0; i < first_jump.size(); ++i) {
		q.push(first_jump[i]);
	}
	bfs();
	if(!flag) {
		printf("0");
		return 0;
	}
	vector<int> ans;
	while(last != -1) {
		ans.push_back(last);
		last = path[last];
	}
	printf("%d\n", ans.size() + 1);
	for(int i = ans.size() - 1; i >= 0; --i) {
		printf("%.0lf %.0lf", vertex[ans[i]].x, vertex[ans[i]].y);
		printf(i == 0 ? "" : "\n");
	}
	return 0;
}