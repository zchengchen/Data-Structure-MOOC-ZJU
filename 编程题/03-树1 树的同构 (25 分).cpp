#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

struct node {
	int left,right;
	char val;
	
	node(int l = -1,int r = -1,char v = '@'):left(l),right(r),val(v) { } 	
};

node tree1[100];
node tree2[100];
int t1[100];
int t2[100];
int n1,n2;
int r1,r2;

bool same(int root1,int root2)
{
	//printf("func %d %d\n", root1, root2);
	if(root1 != -1 && root2 != -1){
		if(tree1[root1].val == tree2[root2].val) {
			int r1_left = tree1[root1].left,r1_right = tree1[root1].right;
			int r2_left = tree2[root2].left,r2_right = tree2[root2].right;
			/*if(tree1[r1_left].val == tree1[r2_left].val && tree1[r1_right].val == tree2[r2_right].val) {
				return same(r1_left,r2_left) && same(r1_right,r2_right);
			} else if (tree1[r1_left].val != tree1[r2_left].val && tree1[r1_right].val != tree2[r2_right].val) {
				return same(r1_left,r2_right) && same(r1_right,r2_left);
			} else {
				return false;
			}*/
			return (same(r1_left,r2_left) && same(r1_right,r2_right)) || (same(r1_left,r2_right) && same(r1_right,r2_left));
		}else {
			return false;
		}
	} else if (root1 == -1 && root2 == -1){
		return true;
	} else {
		return false;
	}
}

int main(void)
{
	scanf("%d",&n1);
	for(int i = 0; i < n1; ++i){
		char left,right;
		cin >> tree1[i].val >> left >> right;
		if(right != '-'){
			tree1[i].right = (right - '0');
			t1[tree1[i].right] = 1;
		} else {
			tree1[i].right = -1;
		}
		if(left != '-'){
			tree1[i].left = (left - '0');
			t1[tree1[i].left] = 1;
		} else {
			tree1[i].left = -1;
		}
	}
	scanf("%d",&n2);
	for(int i = 0; i < n2; ++i){
		char left,right;
		cin >> tree2[i].val >> left >> right;
		if(right != '-'){
			tree2[i].right = (right - '0');
			t2[tree2[i].right] = 1;
		} else {
			tree2[i].right = -1;
		}
		if(left != '-'){
			tree2[i].left = (left - '0');
			t2[tree2[i].left] = 1;
		} else {
			tree2[i].left = -1;
		}
	}
	if(n1 != n2) {
		printf("No");
		return 0;
	}
	for(int i = 0; i < n1; ++i){
		if(t1[i] != 1) {
			r1 = i;
			break;
		}
	}
	for(int i = 0; i < n2; ++i) {
		if(t2[i] != 1) {
			r2 = i;
			break;
		}
	}
	//printf("r1 %d r2 %d\n",r1 ,r2);
	printf(same(r1,r2) ? "Yes" : "No");
	return 0;
}
