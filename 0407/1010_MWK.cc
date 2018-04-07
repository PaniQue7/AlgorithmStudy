#include<iostream>
using namespace std;
int main(void){
    int T,a,b;
    cin >> T;
    long long res=1;
    for(int i=0; i<T; i++) 
    {
        cin >> a >> b;
        int count=0,flag=0,bb=b,aa=a;
        if(a>b/2)
            a=b-a;
        if(a!=0){
            if(b==30)
            {
                b=29;
                count++;
                flag=1;
            }
            for(int j=b; count!=a; j--)
            {
                count++;
                res *= j;

            }
            for(int j=a-1; j>0; j--)
                res /= j;

            if(flag==1)
                res = (res * 30);
            res /= a;
        }

        if(a==0 || aa==0 || aa==bb)
            res=1;
        cout << res <<'\n';
        res=1;
    }

    return 0;
}
