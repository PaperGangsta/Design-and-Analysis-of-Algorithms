#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void LCS(char *s1, char *s2, int len1, int len2, int c[][MAXLEN], int dir[][MAXLEN]){
    int i, j;
    for(i = 0; i <= len1; i++)    
        c[i][0] = 0;
    for(j = 1; j <= len2; j++)     
        c[0][j] = 0;
    for(i = 1; i<= len1; i++){     
        for(j = 1; j <= len2; j++){
            if(s1[i-1] == s2[j-1]){ 
                c[i][j] = c[i-1][j-1] + 1;
                dir[i][j] = 1;
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                dir[i][j] = 0;
            }
            else{
                c[i][j] = c[i][j-1];
                dir[i][j] = -1;
            }
        }
    }
}

void Print(int dir[][MAXLEN], char *s1, int i, int j)
{
    if(i == 0 || j == 0)      
        return;
    if(dir[i][j] == 1){
        Print(dir, s1, i-1, j-1);
        printf("%c ", s1[i-1]);
    }
    else if(dir[i][j] == 0)
        Print(dir, s1, i-1, j);
    else
        Print(dir, s1, i, j-1);
}

int main()
{
    char s1[MAXLEN];// = {"ABCBDAB"};
    char s2[MAXLEN] ;//= {"BDCABA"};
    scanf("%s",s1);
    scanf("%s",s2);
    int  dir[MAXLEN][MAXLEN];            
    int  c[MAXLEN][MAXLEN];              
    int len1, len2;
    len1 = strlen(s1);
    len2 = strlen(s2);
    LCS(s1, s2, len1, len2, c, dir);
    Print(dir, s1, len1, len2);
    return 0;
}
