#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
 
typedef struct
{
    double x;
    double y;
}Building;
 
// �������н���������
Building* creatCoordinate(int iBuilNum)
{
    int i, j;
    double x, y;
    srand((int)time(NULL));
    Building* bBuil = (Building*)malloc(sizeof(Building)*iBuilNum);
    for(i=0; i<iBuilNum; i++)
    {
        x = (rand()%10000)*0.01;
        y = (rand()%10000)*0.01;
        for(j=0; j<i; j++)
        {
            if(x == bBuil[j].x && y == bBuil[j].y)
            {
                i --;
                continue;
            }
        }
        bBuil[i].x = x;
        bBuil[i].y = y;
    }
 
    return bBuil;
}
 
// �������ľ���
double getDis(Building bA, Building bB)
{
    double dDifferenceX = bA.x - bB.x;
    double dDifferenceY = bA.y - bB.y;
    return sqrt(dDifferenceX*dDifferenceX + dDifferenceY*dDifferenceY);
}
 
// �����е��ľ���
double* getAllDis(Building* abCoordinate, int iBuilNum, int iDisNum, int* aiMinIndex)
{
    int i, j, k;
    double dMin = 1000.0;
    double* adDis = (double*)malloc(sizeof(double)*iDisNum);
    for(i=iBuilNum-1, k=0; i>0; i--)
    {
        for(j=i; j>0; j--)
        {
            //printf("%d %d\n", iBuilNum-i-1, iBuilNum-j);
            adDis[k] = getDis(abCoordinate[iBuilNum-i-1], abCoordinate[iBuilNum-j]);
            // ��ȡ��С����
            if(adDis[k] < dMin)
            {
                dMin = adDis[k];
                // ��ȡ��С������Ӧ����������±�
                aiMinIndex[0] = iBuilNum-i-1;
                aiMinIndex[1] = iBuilNum-j;
            }
            k++;
        }
    }
 
    return adDis;
}
 
int main(void)
{
    int iBuilNum, iDisNum = 0, aiMinIndex[2], i;
    printf("%s\n", "�����뽨����������");
    scanf("%d", &iBuilNum);
    for(i=1; i<iBuilNum; i++)
        iDisNum += i;
 
    Building* abCoordinate = creatCoordinate(iBuilNum);
    double* adDis = getAllDis(abCoordinate, iBuilNum, iDisNum, aiMinIndex);
 
    // �����������
    printf("%s\n", "���н����������Ϊ��");
    for(i=0; i<iBuilNum; i++)
        printf("x: %0.2lf    y: %0.2lf\n", abCoordinate[i].x, abCoordinate[i].y);
 
    // ���������������������
    printf("%s\n", "����������������������Ϊ��");
    printf("x: %0.2lf    y: %0.2lf\n", abCoordinate[aiMinIndex[0]].x, abCoordinate[aiMinIndex[0]].y);
    printf("x: %0.2lf    y: %0.2lf\n", abCoordinate[aiMinIndex[1]].x, abCoordinate[aiMinIndex[1]].y);
 
    // ����������������ľ���
    printf("%s\n", "�����������������ľ���Ϊ��");
    printf("%0.2lf\n", getDis(abCoordinate[aiMinIndex[0]], abCoordinate[aiMinIndex[1]]));
 
    // ������о���
    //printf("%s\n", "���н�����ľ���Ϊ��");
    //for(i=0; i<iDisNum; i++)
    //    printf("%0.2lf\n", adDis[i]);
 
    free(abCoordinate);
    free(adDis);
 
    return 0;
}
