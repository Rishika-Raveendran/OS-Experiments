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
        printf("P%d:", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }

    wt = 0;
    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");
    for (j = 0; j < n; j++)
    {
        tat = 0;

        tat = bt[j] + wt;
        printf("\n%d\t\t  %d\t\t    %d\t\t\t%d", p[j], bt[j], wt, tat);
        wt += bt[j];
        total += tat;
    }

    avg_wt = wt / n;

    avg_tat = (float)total / n;
    printf("\n\nAverage Waiting Time=%f", avg_wt);
    printf("\nAverage Turnaround Time=%f\n", avg_tat);
}