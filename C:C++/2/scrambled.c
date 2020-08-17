#include <stdio.h>

int scrambled(unsigned int arr1[], unsigned int arr2[], unsigned int len)
{
    if (len > 0)
    {
        int copy1[len];
        int copy2[len];

        for (int i = 0; i < len; i++)
        {
            copy1[i] = arr1[i];
            copy2[i] = arr2[i];
        }

        for (int j = 0; j < len; j++)
        {
            for (int k = j + 1; k < len; k++)
            {
                if (copy1[j] > copy1[k])
                {
                    copy1[j] ^= copy1[k];
                    copy1[k] ^= copy1[j];
                    copy1[j] ^= copy1[k];
                }

                if (copy2[j] > copy2[k])
                {
                    copy2[j] ^= copy2[k];
                    copy2[k] ^= copy2[j];
                    copy2[j] ^= copy2[k];
                }
            }
        }

        for(int l = 0; l < len; l++) {
            if(copy1[l] != copy2[l]) {
                return 0;
            }
        }
    }

    return 1;
}