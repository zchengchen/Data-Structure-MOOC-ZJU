#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<string.h>
#include<iterator>
#include<stdlib.h>
using namespace std;
int M,N,K;
int in[1010];
int flag[1010];
int pop_num = 0;
int low = 0, high = 0;

inline bool check_len()
{
	return (high - pop_num) <= M;
}

inline bool check_seq(int num)
{
	for(int i = num+1; i <= high; ++i) {
		if(flag[i] == 0 && i > num) {
			return false;
		}
	}
	return true;
}

inline void print_res(bool res)
{
	if(K == 0) {
		printf(res?"YES":"NO");
	} else {
		printf(res?"YES\n":"NO\n");
	}
}

int main(void)
{
	scanf("%d%d%d",&M, &N, &K);
	while(K--){
		for(int i = 1; i <= N; ++i){
			scanf("%d",&in[i]);
		}
		memset(flag, 0, sizeof(flag));
		pop_num = 0;
		low = high = in[1];
		if(!check_len()){
			print_res(false);
			goto bottom;
		}else if(!check_seq(in[1])) {
			print_res(false);
			goto bottom;
		}
		++pop_num;
		flag[in[1]] = 1;
		for(int i = 2; i <= N; ++i) {
			int tmp = in[i];
			low = min(low,tmp);
			high = max(tmp,high);
			if(!check_len()) {
				print_res(false);
				goto bottom;
			}
			if(!check_seq(tmp)) {
				print_res(false);
				goto bottom;
			}
			++pop_num;
			flag[tmp] = 1;
		}
		print_res(true);
		bottom:
			int a;
	}
	return 0;
}
