#include <stdio.h>

void main()
{
    int bt[20], p[20], wt, tat, i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;
    printf("Enter number of process:");
    scanf("%d", &n);

    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++)
    {
        printf("p%d:", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }
    //selection sort
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (bt[j] < bt[pos])
                pos = j;
        }

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    //wt[0] = 0;
    wt = 0;
    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");
    for (j = 0; j < n; j++)
    {
        tat = 0;

        wt += bt[j];
        tat = bt[j] + wt;
        printf("\n%d\t\t  %d\t\t    %d\t\t\t%d", p[j], bt[j], wt, tat);

        total += tat;
    }

    avg_wt = wt / n;

    avg_tat = (float)total / n; //average turnaround time
    printf("\n\nAverage Waiting Time=%f", avg_wt);
    printf("\nAverage Turnaround Time=%f\n", avg_tat);
}