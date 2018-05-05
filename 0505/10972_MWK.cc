#include<iostream>
#include<algorithm>

using namespace std;
int array[100001];
int num;

bool checkEnd(int s)
{
    bool result = true;
    for(int i = s + 1; i < num; i++)
    {
        if(array[i] > array[i-1])
        {
            result = false;
        }
    }
    return result;
}

bool nextPermutation(int index)
{
    bool done;
    if(index + 1 < num - 1)
    {
        done = nextPermutation(index+1);
    }
    else
    {
        if(array[index] < array[index + 1])
        {
            int tmp = array[index];
            array[index] = array[index + 1];
            array[index + 1] = tmp;
            return true;
        }
        else 
            return false;
    }

    if(!done)
    {
        int i;
        for(i = index; i < num - 1; i++)
        {
            if(array[i + 1] < array[i])
                break;
        }
        
        int stand = array[i - 1];
        int min = 9999999;
        int ind;
        for(int j = i; j < num; j++)
        {
            if(array[j] < min && array[j] > stand)
            {
                min = array[j];
                ind = j;
            }
        }
        if(min == 9999999)
            return false;
        array[ind] = array[i - 1];
        array[i - 1] = min;
        sort(array + i, array + num);
        return true;
    }
    else
        return true;
}

    

int main(void)
{
    cin >> num;
    for(int i = 0; i < num; i++)
    {
        int tmp;
        cin >> tmp;
        array[i] = tmp;
    }

    if(checkEnd(0))
    {
        cout << -1 << "\n";
        return 0;
    }

    nextPermutation(0);
    for(int i = 0; i < num; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n";
    return 0;
}


