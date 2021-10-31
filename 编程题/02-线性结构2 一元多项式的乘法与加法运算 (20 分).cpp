#include<stdio.h>
#include<memory.h>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct elem {
	int coef, exp;
};
int n,m;
elem f1[1010];
elem f2[1010];
elem mulr[1000010];
elem fmulr[100010];
elem addr[1010];
int expf[1000010];
int addrn,muln;

void add_f() {
	int i = 1,j = 1;
	int k = 1;
	while(i <= n && j <= m) {
		if(f1[i].exp == f2[j].exp) {
			if(f1[i].coef + f2[j].coef != 0) {
				addr[k].coef = f1[i].coef + f2[j].coef;
				addr[k].exp = f1[i].exp;
				++k;
			}
			++i;
			++j;
		} else if (f1[i].exp > f2[j].exp) {
			addr[k] = f1[i];
			++k;
			++i;
		} else if(f1[i].exp < f2[j].exp) {
			addr[k] = f2[j];
			++k;
			++j;
		}
	}
	if(i != n+1) {
		for(int o = i; o <= n; ++o){
			addr[k++] = f1[o];
		}
	} else if(j != m+1) {
		for(int o = j; o <= m; ++o){
			addr[k++] = f2[o];
		}
	}
	addrn = k-1;
}

bool cmp(elem& lhs, elem& rhs) 
{
	return lhs.exp > rhs.exp;
}

void mul_r()
{
	int k = 1;
	for(int i = 1;i <= n; ++i) {
		for(int j = 1;j <= m; ++j) {
			int coef = f1[i].coef*f2[j].coef;
			int exp = f1[i].exp+f2[j].exp;
			if(expf[exp] == 0){	
				expf[exp] = k;
			}
			mulr[expf[exp]].coef += coef;
			mulr[expf[exp]].exp = exp;
			if(mulr[expf[exp]].coef == 0) {
				mulr[expf[exp]].exp = 0;
			}
			++k;
		}
	}
	int z = 1;
	for(int o = 1; o < k; ++o) {
		if(mulr[o].coef != 0) {
			fmulr[z++] = mulr[o];
		}
	}
	muln = z - 1;
}

int main(void)
{
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		int coef,exp;
		scanf("%d%d",&coef,&exp);
		f1[i].coef = coef;
		f1[i].exp = exp;
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; ++i) {
		int coef,exp;
		scanf("%d%d",&coef,&exp);
		f2[i].coef = coef;
		f2[i].exp = exp;
	}
	if(n == 0 && m == 0) {
		printf("0 0\n0 0");
		return 0;
	}
	if(n == 0) {
		printf("0 0\n");
		for(int i = 1;i < m; ++i){
			printf("%d %d ", f2[i].coef,f2[i].exp);
		}
		printf("%d %d",f2[m].coef,f2[m].exp);
		return 0;
	}
	if(m == 0) {
		printf("0 0\n");
		for(int i = 1;i < n; ++i){
			printf("%d %d ", f1[i].coef,f1[i].exp);
		}
		printf("%d %d",f1[m].coef,f1[m].exp);
		return 0;
	}
	mul_r();
	sort(fmulr+1,fmulr+muln,cmp);
	for(int i = 1; i < muln; ++i) {
		printf("%d %d ", fmulr[i].coef,fmulr[i].exp);
	}
	printf("%d %d\n", fmulr[muln].coef, fmulr[muln].exp);
	add_f();
	for(int i = 1; i < addrn; ++i) {
		printf("%d %d ", addr[i].coef, addr[i].exp);
	}
	printf("%d %d",addr[addrn].coef, addr[addrn].exp);
	return 0;
}
