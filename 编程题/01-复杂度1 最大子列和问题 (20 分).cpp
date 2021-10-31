#include<cstdio>
#include<algorithm>
using namespace std;

int main(void)
{
    int K;
    scanf("%d",&K);
    int maxans = 0,nowans = 0;
    for(int i = 0; i < K; ++i){
        int tmp;
        scanf("%d",&tmp);
        nowans += tmp;
        maxans = max(maxans,nowans);
        nowans = nowans < 0 ? 0 : nowans;
    }
    printf("%d",maxans);
    return 0;
}
