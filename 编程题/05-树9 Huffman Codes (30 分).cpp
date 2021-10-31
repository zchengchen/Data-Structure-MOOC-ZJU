#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int N,M;
int wpl = 0;
int hsize = 0;
int h[100];
map<string,int> ch_f;
string code[100];

inline void perc_down(int p)
{
	int parent,child;
	int x = h[p];
	for(parent = p; 2*parent <= hsize; parent = child) {
		child = 2*parent;
		if(child+1 <= hsize && h[child+1] < h[child]) ++child;
		if(x < h[child]) break;
		else h[parent] = h[child];
	}
	h[parent] = x;
}

inline void build_heap()
{
	hsize = N;
	for(int i = hsize/2; i >= 1; --i)
		perc_down(i);
}

inline void del_elem(int p)
{
	h[p] = h[hsize--];
	perc_down(p);
}

inline void ins_elem(int x)
{
	int i = ++hsize;
	for(; h[i/2] > x; i /= 2) {
		h[i] = h[i/2];
	}
	h[i] = x;
}

bool cmp(string& lhs, string& rhs)
{
	return lhs.size() < rhs.size();
}

inline bool check_prefix()
{
	sort(code+1,code+N+1,cmp);
	for(int i = 1;i <= N; ++i) {
		for(int j = i+1; j <= N; ++j) {
			if(code[j].substr(0, code[i].size()) == code[i]) {
				return false;
			}
		}
	}
	return true;
}

int main(void)
{
	cin >> N;
	h[0] = -0x3f3f3f3f;
	for(int i = 1; i <= N; ++i) {
		string s;
		int freq;
		cin >> s >> freq;
		ch_f[s] = freq;
		h[i] = freq;
	}
	build_heap();
	for(int i = 1; i < N; ++i) {
		int t1 = h[1];
		del_elem(1);
		int t2 = h[1];
		del_elem(1);
		wpl += t1+t2;
		ins_elem(t1+t2); 
	}
	cin >> M;
	while(M--) {
		int curr_wpl = 0;
		for(int i = 1; i <= N; ++i) {
			string ch,c;
			cin >> ch >> c;
			code[i] = c;
			curr_wpl += ch_f[ch]*c.size();
		}
		cout << ((curr_wpl == wpl && check_prefix())?"Yes":"No");
		cout << (M == 0 ? "" : "\n");
	}
	return 0;
}
