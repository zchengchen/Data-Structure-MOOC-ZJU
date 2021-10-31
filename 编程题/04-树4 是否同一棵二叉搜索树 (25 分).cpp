#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> t;
vector<int> ct;
int N,L;

inline bool check(vector<int> t1, vector<int> t2)
{
	vector<int> t1_l,t1_r;
	vector<int> t2_l,t2_r;
	if(t1.size() != t2.size()) return false;
	else if (t1.size() == t2.size() && t1.size() == 0) return true;
	else if (t1.size() == t2.size() && t1.size() == 1) return (t1[0] == t2[0] ? true : false);
	else{
		int r1 = t1[0];
		int r2 = t2[0];
		if(r1 != r2) return false;
		for(int i = 0; i < t1.size(); ++i) {
			if(t1[i] < r1) t1_l.push_back(t1[i]);
			else if(t1[i] > r1) t1_r.push_back(t1[i]);
		}
		for(int i = 0; i < t2.size(); ++i) {
			if(t2[i] < r1) t2_l.push_back(t2[i]);
			else if(t2[i] > r1) t2_r.push_back(t2[i]);
		}
		return check(t1_l,t2_l) && check(t1_r,t2_r);
	}
}

int main(void)
{
	int y = 0;
	cin >> N;
	do {
		if(y == 0) y++;
		else cout << endl;
		cin >> L;
		t.clear();
		ct.clear();
		for(int i = 0; i < N; ++i) {
			int tmp;
			cin >> tmp;
			t.push_back(tmp);
		}
		while(L--){
            ct.clear();
			for(int i = 0; i < N; ++i) {
				int tmp;
				cin >> tmp;
				ct.push_back(tmp);
			}
			cout << (check(t,ct) ? "Yes" : "No");
			cout << (L == 0 ? "" : "\n");
		}
		cin >> N;
	}while(N != 0);
	return 0;
}
