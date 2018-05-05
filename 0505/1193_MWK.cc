#include <cstdio>

int main(void)
{
    int num;
    scanf("%d", &num);
    num -= 1;
    int i;
    for(i = 1; num >= i; i++)
    {
        num -= i;
    }

    int up;
    int down;
    bool even = false;

    if(i%2 == 0)
    {
        up = 1;
        down = i;
        even = true;
    }
    else
    {
        up = i;
        down = 1;
    }
    
    while(num--)
    {
        if(even)
        {
            up ++;
            down --;
        }
        else 
        {
            up--;
            down++;
        }
    }
    printf("%d/%d\n", up, down);
}

