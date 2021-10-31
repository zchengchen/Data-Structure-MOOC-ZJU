#include<string>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;

int n;
int in_ord[100];
int pre_ord[100];
stack<int> st;
stack<int> ans;

void get_rt(int pre_l, int pre_r, int in_l,int in_r)
{
	if(ans.size() == n) {
		return ;
	}
	if(pre_l > pre_r || in_l > in_r) {
		return ;
	}
	int rt = pre_ord[pre_l];
	//printf("l = %d, r = %d, l = %d, r = %d\n",pre_l,pre_r,in_l,in_r);
	//printf("rt = %d\n",rt);
	int z;
	for(z = in_l; z <= in_r; ++z) {
		if(in_ord[z] == rt) {
			break;
		}
	}
	int num_left = z - in_l;
	int num_right = pre_r - pre_l + 1 - num_left;
	ans.push(rt);
	get_rt(pre_l+num_left+1,pre_r,z+1,in_r);
	get_rt(pre_l+1,pre_l+num_left,in_l,z-1);
}

int main(void)
{
	cin >> n;
	int j = 0;
	int k = 0;
	for(int i = 0 ; i < 2*n; ++i) {
		string cmd;
		cin >> cmd;
		if(cmd == "Push") {
			int val;
			cin >> val;
			st.push(val);
			pre_ord[j++] = val;
		} else if (cmd == "Pop") {
			int tmp = st.top();
			st.pop();
			in_ord[k++] = tmp;
		}
	}
	get_rt(0,n-1,0,n-1);
	int res[100];
	int o = 0;
	while(!ans.empty()) {
		res[o++] = ans.top();
		ans.pop();
	}
	for(int i = 0; i < o; ++i) {
		printf("%d", res[i]);
		printf(i == o-1 ? "" : " ");
	}
	return 0;
}
