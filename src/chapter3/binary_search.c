#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int alt_binsearch(int x, int v[], int n);
void init_vector(int v[], int n);

int main()
{
    int n = 100000;
    int v[n];

    init_vector(v, n);

    int x = 634;

    int max_iter = 1000000;

    // BOOK BINSEARCH
    long book_clock = clock();

    for (int i = 0; i < max_iter; ++i)
    {
        binsearch(x, v, n);
    }
    book_clock = clock() - book_clock;

    // ALT BINSEARCH
    long alt_clock = clock();
    for (int i = 0; i < max_iter; ++i)
    {
        alt_binsearch(x, v, n);
    }
    alt_clock = clock() - alt_clock;

    printf("Book method took %.4f seconds and alt method took %.4f seconds\n", (double)book_clock / CLOCKS_PER_SEC, (double)alt_clock / CLOCKS_PER_SEC);

    return 0;
}

void init_vector(int v[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        v[i] = i;
    }
}

int binsearch(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (x < v[mid])
        {
            high = mid - 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int alt_binsearch(int x, int v[], int n)
{
    int low, mid, high;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (x == v[low - 1])
    {
        return low - 1;
    }

    return -1;
}