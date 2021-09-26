#include <stdio.h>

void main()
{
    int mem_size[10], block_num, pro_size[10], pro_num, occ_by[10], best, i, j;

    for (i = 0; i < 10; i++)
    {

        occ_by[i] = -1;
    }

    printf("\nEnter the number of memory blocks: ");
    scanf("%d", &block_num);

    printf("\nEnter the size of each block: \n");
    for (i = 0; i < block_num; i++)
    {
        printf("Memory block %d : ", i + 1);
        scanf("%d", &mem_size[i]);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &pro_num);

    printf("\nEnter the size of each process: \n");
    for (i = 0; i < pro_num; i++)
    {
        printf("Process %d : ", i + 1);
        scanf("%d", &pro_size[i]);
    }

    for (i = 0; i < pro_num; i++)
    {
        best = 10000000;
        for (j = 0; j < block_num; j++)
        {
            if (mem_size[j] >= pro_size[i] && mem_size[j] < best)
            {
                best = j;
            }
        }
        if (best != 10000000)
        {
            mem_size[best] = i;
            mem_size[best] -= pro_size[i];
            printf(" \nMemory block %d allocated to process %d\n", best + 1, i + 1);
        }
        else
        {

            printf(" \nInsufficient memory! Could not allocate memory for process %d\n", i + 1);
        }
    }
}