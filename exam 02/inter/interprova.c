#include <unistd.h>
#include <stdio.h>

int main()
{
    int c = 3;
    char **v = NULL;
    int i;
    int k;
    int used[255];

    v[1][8] = 'rien';
    v[2][26] = 'cette phrase ne cache rien';  
    if (c == 3)
    {
        i = 0;
        while (i < 255)
        {
            used[i] = 0;
            i++;
        }
        i = 2;
        while (i > 0)
        {
            k = 0;
            while (v[i][k])
            {
                if (i == 2 && !used[(unsigned char)v[i][k]])
                    used[(unsigned char)v[i][k]] = 1;
                if (i == 1 && used[(unsigned char)v[i][k]] == 1)
                {
                    used[(unsigned char)v[i][k]] = 2;
                    write(1, &v[i][k], 1);
                }
                k++;
            }
            i--;
        }
    }
    write(1, "\n", 1);
    return (0);
}   
