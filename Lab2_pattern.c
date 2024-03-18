#include <stdio.h>
char STR[100], PAT[100], REP[100], ans[100];
int i, j, k, c, m, flag = 0;
void read_string()
{
    printf("Enter the main string :\n");
    gets(STR);
    printf("Enter the pattern string :\n");
    gets(PAT);
    printf("Enter a replace string :\n");
    gets(REP);
}
void pattern_match()
{
    i = m = c = j = 0;
    while (STR[c] != '\0')
    {
        if (STR[m] == PAT[i])
        {
            i++;
            m++;
            flag = 1;
            if (PAT[i] == '\0')
            {
                for (k = 0; REP[k] != '\0'; k++, j++)
                {
                    ans[j] = REP[k];
                }
                i = 0;
                c = m;
            }
        }
        else
        {
            ans[j] = STR[c];
            j++;
            c++;
            m = c;
            i = 0;
        }
    }
    if (flag == 0)
    {
        printf("Pattern string does not exist!\n");
    }
    else
    {
        ans[j] = '\0';
        printf("The Resultant String is : %s \n", ans);
    }
}
int main()
{
    read_string();
    pattern_match();
}
