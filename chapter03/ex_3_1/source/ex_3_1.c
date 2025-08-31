/*
* This program implements a binary search with only
* one conditional check within the loop instead of
* two. 
*/

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int sorted_array[] = {2, 3, 4, 5, 6, 7};
    
    // Create a loop of search terms and print out their positions
    printf("Term\tPosition\n");
    for (int i = 0; i < 10; i++)
    {
        int index = binsearch(i, sorted_array, 6);
        printf("%4d\t%8d\n", i, index);
    }


}

int binsearch(int x, int v[], int n)
{
    int low, mid, high;

    low  = 0;
    high = n - 1;

    while(low != high)
    {
        mid = (low + high) / 2;

        if (x > v[mid])
        {
            low = mid + 1;
        } else
        {
            high = mid;
        }
    }

    if (x == v[low])
    {
        return low;
    } else
    {
        return -1;
    }
}

