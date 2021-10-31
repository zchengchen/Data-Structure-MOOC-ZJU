#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int fa[10010];
int N;

inline void init_set()
{
	for(int i = 1;i <= N; ++i){
		fa[i] = i;
	}
}

inline int get_component()
{
	int res = 0;
	for(int i = 1;i <= N; ++i) {
		if(fa[i] == i) ++res;
	}
	return res;
}

inline int find(int i)
{
	return (fa[i] == i) ? i : (fa[i] = find(fa[i]));
}

inline void merge(int i, int j)
{
	fa[find(i)] = find(j);
}

int main(void)
{
	cin >> N;
	char cmd;
	init_set();
	while(cin >> cmd) {
		if(cmd == 'S') {
			int num = get_component();
			if(num == 1) cout << "The network is connected.";
			else cout << "There are " << num << " components.";
			return 0;
		} else if (cmd == 'I') {
			int t1,t2;
			cin >> t1 >> t2;
			merge(t1,t2);
		} else if (cmd == 'C') {
			int t1,t2;
			cin >> t1 >> t2;
			cout << ((find(t1) == find(t2)) ? "yes\n" : "no\n");
		}
	}
	return 0;
}
