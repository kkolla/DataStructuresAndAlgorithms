#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *last_combo;
int* next_combo(int *src, int* combo, int maxsize, int combosize)
/*
 * 0 1 2 3 4 5
 * 0 1 2
 */
{
    if (combosize == 1)
    {
        if (combo[0] == maxsize-1)
            return NULL;
        else {
            combo[0]++;
        	return combo;
    	}
    }
 	if(combo[combosize-1] < maxsize-1)
    {
        combo[combosize-1] = combo[combosize-1] + 1;
    } else if (memcmp(combo,last_combo,combosize)){
        combo = next_combo(src,combo,maxsize-1,combosize-1);
        combo[combosize-1] = combo[combosize-2] + 1;
    }

    return combo;
}

int main()
{
    int *a;
    int *combo;
    int size = 2;
    int src_size=8;
    int i,j;
    combo = (int*)malloc(sizeof(int)*size);
    last_combo = (int*)malloc(sizeof(int)*size);
    a = (int*)malloc(sizeof(int)*src_size);

    memset(a,0,src_size);
    memset(combo,0,size);
    memset(last_combo,0,size);

    for(i=0; i<src_size;i++)
    {
        a[i] = i;
    }

    for(i=0; i<size;i++)
    {
        combo[i] = a[i];
    }

    for(i=src_size-1,j=size-1; j>=0;i--,j--)
    {
        last_combo[j] = a[i];
    }

    printf("\n****************************\n");

    for(i=0; i<size;i++)
    {
        printf("%d",combo[i]);
    }
        for(i=0; i<size;i++)
    {
        printf("%d",last_combo[i]);
    }

    printf("\n************* START ***************\n");

    printf("\n");
    while (memcmp(combo,last_combo,size))
    {
    	combo = next_combo(a, combo, src_size, size);
    	printf("\n");
        for(i=0; i<size;i++)
        {
            printf("%d",combo[i]);
        }
    }

    return 0;
}
