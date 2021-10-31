#include<cstdio>
#include<algorithm>
using namespace std;
int num[10010];
const int inf = 0x3f3f3f3f;
int main(void)
{
    int K;
    scanf("%d",&K);
    int maxans = -inf,nowans = 0;
    int begans = 0,endans = 0,begtmp = 0;
    for(int i = 0; i < K; ++i){
        int tmp;
        scanf("%d",&tmp);
        num[i] = tmp;
        nowans += tmp;
        if(maxans < nowans){
            maxans = nowans;
            begans = begtmp;
            endans = i;
        }
        if(nowans < 0){
            begtmp = i+1;
            nowans = 0;
        }
    }
    if(maxans >= 0)
        printf("%d %d %d",maxans,num[begans],num[endans]);
    else
        printf("%d %d %d",0,num[0],num[K-1]);
    return 0;
}
