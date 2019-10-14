#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int gcd(int a,int b)
{
    return (b==0?a:gcd(b,a%b));
}

int main()
{
    vector<int> ans;
    int n1,m1,n2,m2;
    int k;
    scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
    if(n1*m2>n2*m1)
    {
        int tmp_n,tmp_m;
        tmp_n=n1;
        tmp_m=m1;
        n1=n2;
        m1=m2;
        n2=tmp_n;
        m2=tmp_m;
    }
    for(int i=1;i<k;i++)
    {
        if((i*m1>n1*k)&&(i*m2<n2*k))
        {
            if(gcd(k,i)==1)
            {
                ans.push_back(i);
            }
        }
    }
    int first_flag=0;
    for(size_t i=0;i<ans.size();i++)
    {
        if(first_flag==1)
        {
            printf(" ");
        }
        first_flag=1;
        printf("%d/%d", ans[i],k);
    }
    return 0;
}
