#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<string.h>
#include<iterator>
#include<stdlib.h>
using namespace std;

struct node {
	int val;
	int next;
	int addr;
};
int N,head,K;
node list[100010];
node in[100010];

int main(void)
{
	scanf("%d%d%d",&head, &N, &K);
	for(int i = 1;i <= N; ++i) {
		int addr,val,next;
		scanf("%d%d%d", &addr,&val,&next);
		in[addr].next = next;
		in[addr].val = val;
	}
	int curr = head;
	int i = 1;
	while(curr != -1) {
		list[i].addr = curr;
		list[i].val = in[curr].val;
		curr = in[curr].next;
		list[i].next = curr;
		++i;
	}
	int num = i-1;
	int j = 1;
	while(j+K-1 <= num){
		int beg = j;
		int end = j+K-1;
		j = end+1;
		while(beg <= end) {
			node tmp = list[beg];
			list[beg] = list[end];
			list[end] = tmp;
			++beg;
			--end;
		}
	}
	for(int i = 1;i < num; ++i){
		list[i].next = list[i+1].addr;
	}
	list[num].next = -1;
	for(int i = 1;i <= num; ++i) {
		if(list[i].next == -1){
			printf("%05d %d %d",list[i].addr,list[i].val,list[i].next);
		}else{
			printf("%05d %d %05d\n",list[i].addr,list[i].val,list[i].next);
		}
	}
	return 0;
}
