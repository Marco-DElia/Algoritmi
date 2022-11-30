#include <stdio.h>
#define max_size 50

void vprint (int *v, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d, ", v[i]);
    }
    printf("\n");
}

void vcpy (int d[], int v[], int n)
{
    for (int i = 0; i < n; i++)
        d[i] = v[i];
}

int join (int v[], int l, int m, int r)
{
    int nswap = 0;
    int vl[max_size];
    int vr[max_size];

    vcpy (vl, v + l, m - l + 1);
    vcpy (vr, v + m + 1, r - m);

    int i = 0, j = 0;
    while (i < m - l + 1 && j < r - m)
    {
        if (vl[i] <= vr[j])
        {
            v[l + i + j] = vl[i];
            i++;
        }
        else if (vr[j] < vl[i])
        {
            v[l + i + j] = vr[j];
            nswap += m - l + 1 - i;
            //printf ("NSWAAP: %d\n", nswap);

            j++;
        }
    }
    while (i < m - l + 1)
    {
        v[l + i + j] = vl[i];
        i++;
    }
    while (j < r - m)
    {
        v[l + i + j] = vr[j];
        nswap += m - l + 1 - i;

        j++;
    }
    return nswap;
}

int merge_sort (int v[], int l, int r)
{
    int nswap = 0;
    if (l < r)
    {
        int m = (l + r) / 2;
        nswap += merge_sort (v, l, m);
        //vprint (v, m - l + 1);
        
        nswap += merge_sort (v, m + 1, r);
        //vprint (v, r - m);

        nswap += join (v, l, m, r);
    }
    //printf ("%d\n", nswap);
    return nswap;
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}

//
void solve (int books[], int n, int cash, int *book1, int *book2)
{
    merge_sort (books, 0, n - 1);
    vprint (books, n);

    int b1 = -1, b2 = -1;
    int i = 0;
    int index;
    while (books[i] < cash)
    {
        index = binarySearch (books, i, n - 1, cash - books[i]);
        //printf ("i = %d, index = %d\n", i, index);
        if (index != -1)
        {
            if (b1 == -1 && b2 == -1)
            {
                b1 = i;
                b2 = index;
            }
            else if ((books[index] - books[i]) < books[b2] - books[b1])
            {
                b1 = i;
                b2 = index;
            }
        }
        i++;
    }
    *book1 = b1;
    *book2 = b2;

    printf ("Peter should buy books whose prices are %d and %d.\n", books[b1], books[b2]);

}


int main ()
{
    int books[100];
    int n = 0;
    int cash = 0;
    int b1, b2;
    //solve (books, 5, 10, &b1, &b2);
    //printf ("%d %d\n", b1, b2);

    char buff[64];

    while (1)
    {
        while (fgets (buff, 24, stdin) && buff[0] == '\n');
        
        if (buff[0] == 'O') break;

        sscanf (buff, "%d", &n);
        printf ("DIMENSIONE %d\n", n);

        for (int i = 0; i < n; i++)
        {
            scanf ("%d\n", &books[i]);
        }
        scanf ("%d", &cash);
        solve (books, n, cash, &b1, &b2);
    }

    return 0;
}