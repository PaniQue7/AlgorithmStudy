#include <iostream>
#include <string.h>
#include <set>

#define MIN(a, b) (a > b ? b : a)
#define LEFTOVER(a, b) (a - b < 0? 0 : a - b)

using namespace std;

int a, b, c;
set<int> result;

void moveWater(int bottles[], int from, int to)
{
    int toBottleSize;
    switch(to){
        case 0:
            toBottleSize = a;
            break;
        case 1:
            toBottleSize = b;
            break;
        case 2:
            toBottleSize = c;
            break;
    }
    int leftSpace = toBottleSize - bottles[to];
    bottles[to] += leftSpace > bottles[from] ? bottles[from] : leftSpace;
    bottles[from] = bottles[from] - leftSpace;
    if(bottles[from] < 0)
        bottles[from] = 0;
}

void aFirst(int bottles[])
{
    // C -> A
    // A -> B ; if A emtpy save C
    // A -> C ; save C
    //
    // reset state
    // C -> A
    // C -> B
    // A -> B ; if A empty save C // this is same as C -> B and save
    // A -> C ; save C
    for(int i = 0; i < 2; i++)
    {
        // Set tmp State
        int bottleTmp[3];
        memcpy(bottleTmp, bottles, sizeof(int) * 3);

        // C -> A
        moveWater(bottleTmp, 2, 0);

        if(i == 1)
        {
            // C -> B at second round
            moveWater(bottleTmp, 2, 1);
        }

        moveWater(bottleTmp, 0, 1);
        if(bottleTmp[0] == 0)
            result.insert(bottleTmp[2]);
        else
        {
            moveWater(bottleTmp, 0, 2);
            result.insert(bottleTmp[2]);
        }
    }
}

void bFirst(int bottles[])
{
    // C -> B ; save C
    // C -> A <> leave it
    // B -> A 
    // B -> C if any left <> leave it
    // A -> B ; if A is 0 save C
    // A -> C ; save C
    for(int i = 0; i < 2; i++)
    {
        int bottleTmp[3];
        memcpy(bottleTmp, bottles, sizeof(int) * 3);

        // C -> B
        moveWater(bottleTmp, 2, 1);

        if(i == 0)
            result.insert(bottleTmp[2]);
        else
        {
            // C -> A
            moveWater(bottleTmp, 2, 0);
        }

        // B -> A
        moveWater(bottleTmp, 1, 0);
        for(int j = 0; j < 2; j++)
        {
            // save state
            int tmp[3];
            memcpy(tmp, bottleTmp, sizeof(int) * 3);

            if(j == 1)
            {
                // B -> C
                moveWater(tmp, 1, 2);
                // A -> B since B changed. No need to do B -> A, A -> B
                moveWater(tmp, 0, 1);
                if(tmp[0] == 0)
                    // C -> B, (C -> A), B -> A, B -> C, A -> B
                    result.insert(tmp[2]);
            }
            moveWater(tmp, 0, 2);
            if(tmp[0] == 0)
                // C -> B, (C -> A), B -> A, A -> C
                result.insert(tmp[2]);
            else
            {
                moveWater(tmp, 0, 1);
                // C -> B, (C -> A), B -> A, A -> C, A -> B
                result.insert(tmp[2]);
            }
        }
    }
}

int main(void)
{
    int bottles[3] = {};
    cin >> a >> b >> c;
    bottles[2] = c;

    result.insert(c);

    aFirst(bottles);
    bFirst(bottles);

    set<int>::iterator it = result.begin();
    for(it; it != result.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}
