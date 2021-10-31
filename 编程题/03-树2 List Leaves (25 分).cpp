#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;

struct node {
	int left,right;
	node(int l = -1,int r = -1):left(l),right(r) { }
};

node tree[100];
int ll[100];
int f[100];
int n;
int ans[100];
int j = 0;
int root;

inline void level_order()
{
	queue<int> st;
	if(root == -1) {
		return ;
	}
	st.push(root);
	while(!st.empty()) {
		int node = st.front();
		st.pop();
		if(tree[node].left == -1 && tree[node].right == -1) {
			ans[j++] = node;
		}else if(tree[node].left != -1 && tree[node].right == -1) {
			st.push(tree[node].left);
		}else if (tree[node].left == -1 && tree[node].right != -1) {
			st.push(tree[node].right);
		}else {
			st.push(tree[node].left);
			st.push(tree[node].right);
		}
	}
}

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; ++i) {
		char c1,c2;
		cin >> c1 >> c2;
		if(c1 != '-') {
			tree[i].left = c1 - '0';
			f[c1-'0'] = 1;
		}
		if(c2 != '-') {
			tree[i].right = c2 - '0';
			f[c2-'0'] = 1;
		}
	}
	for(int i = 0; i < n; ++i) {
		if(f[i] != 1) {
			root = i;
			break;
		}
	}
	level_order();
	for(int k = 0; k < j - 1; ++k){
		printf("%d ", ans[k]);
	}
	printf("%d",ans[j-1]);
	return 0;
}
