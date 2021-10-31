#include<cstdio>
#include<iostream>
#include<string>
#include<cstdlib>
#include<memory>
using namespace std;

struct node {
	int val;
	node* left;
	node* right;	
};

inline int get_height(node* t)
{
	if(!t) return 0;
	else return max(get_height(t->left), get_height(t->right)) + 1;
}

inline node* ll_rotate(node* t)
{
	node* fr = t->left;
	t->left = fr->right;
	fr->right = t;
	return fr;
}

inline node* rr_rotate(node* t)
{
	node* fr = t->right;
	t->right = fr->left;
	fr->left = t;
	return fr;
}

inline node* lr_rotate(node* t)
{
	t->left = rr_rotate(t->left);
	return ll_rotate(t);
}

inline node* rl_rotate(node* t)
{
	t->right = ll_rotate(t->right);
	return rr_rotate(t);
}

node* insert(node* t, int val)
{
	if(!t) {
		node* tmp = (node*) malloc(sizeof(struct node));
		tmp->left = tmp->right = NULL;
		tmp->val = val;
		
		return tmp;
	} else if(val < t->val) {
		t->left = insert(t->left,val);
		if(get_height(t->left) - get_height(t->right) >= 2) {
			if(val < t->left->val) t = ll_rotate(t);
			else t = lr_rotate(t);
		}
		return t;
	} else if (val > t->val) {
		t->right = insert(t->right,val);
		if(get_height(t->right) - get_height(t->left) >= 2) {
			if(val > t->right->val) t = rr_rotate(t);
			else t = rl_rotate(t);
		}
		return t;
	}
	return t;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	node* t = NULL;
	for(int i = 0;i < n; ++i) {
		int tmp;
		scanf("%d", &tmp);
		t = insert(t,tmp);
	}
	cout << t->val;
	return 0;
}
