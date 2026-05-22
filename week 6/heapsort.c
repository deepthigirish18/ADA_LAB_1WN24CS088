#include <stdio.h>
#include <time.h>

void heapcom(int a[], int n)
{
    int i, j, k, item;

    for(i = 1; i <= n; i++)
    {
        item = a[i];
        j = i;
        k = j / 2;

        while(k != 0 && item > a[k])
        {
            a[j] = a[k];
            j = k;
            k = j / 2;
        }
        a[j] = item;
    }
}

void adjust(int a[], int n)
{
    int item, i, j;

    j = 1;
    item = a[j];
    i = 2 * j;

    while(i <= n)
    {
        if((i + 1) <= n)
        {
            if(a[i] < a[i + 1])
                i++;
        }

        if(item < a[i])
        {
            a[j] = a[i];
            j = i;
            i = 2 * j;
        }
        else
            break;
    }

    a[j] = item;
}

void heapsort(int a[], int n)
{
    int i, temp;

    heapcom(a, n);

    for(i = n; i >= 1; i--)
    {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;

        adjust(a, i - 1);
    }
}

int main()
{
    int i, n, a[20], ch = 1;
    clock_t start, end;
    double time_taken;

    while(ch)
    {
        printf("\nEnter number of elements: ");
        scanf("%d", &n);

        if(n > 19)
        {
            printf("Maximum size is 19\n");
            return 0;
        }

        printf("Enter elements:\n");

        for(i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        start = clock();

        heapsort(a, n);

        end = clock();

        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nSorted elements:\n");

        for(i = 1; i <= n; i++)
            printf("%d ", a[i]);

        printf("\n\nTime taken = %lf seconds\n", time_taken);

        printf("\nRun again? (1/0): ");
        scanf("%d", &ch);
    }

    return 0;
}
