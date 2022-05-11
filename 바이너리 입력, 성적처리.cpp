#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct student {
    char name[10];
    int num, kor, eng, math, tot;
    double ave;
};
int main(void)
{
    int i = 0;
    srand(time(NULL));
    student stnum[100], temp;
    student total = { "",0,0,0,0,0,0. };
    string inFileName = "StName.bin";
    ifstream inFile;
    inFile.open(inFileName);

    if (inFile.is_open()) {

        string line;

        for (i = 0;i < 6;i++) {
            getline(inFile, line);
            strcpy(stnum[i].name, line.c_str());
        }

        inFile.close();
    }
    else {
        cout << "파일을 열수 없습니다." << endl;
    }

    for (i = 0; i < 6;i++) {

        stnum[i].num = 2015000000 + rand() % 1000000;
        stnum[i].kor = rand() % 101;
        stnum[i].eng = rand() % 101;
        stnum[i].math = rand() % 101;
        stnum[i].tot = stnum[i].kor + stnum[i].eng + stnum[i].math;
        stnum[i].ave = stnum[i].tot / 3.;
        total.kor = total.kor + stnum[i].kor;
        total.eng = total.eng + stnum[i].eng;
        total.math = total.math + stnum[i].math;
        total.tot = total.tot + stnum[i].tot;
        total.ave = total.ave + stnum[i].ave;    
    }

    for (int n = 0;n < i - 1;n++)
    {
        for (int m = n + 1;m < i;m++)
        {
            if (stnum[n].tot < stnum[m].tot)
            {
                temp = stnum[n];
                stnum[n] = stnum[m];
                stnum[m] = temp;
            }
        }
    }

    printf(" \n");
    printf("                            평균성적기준등수                                \n");
    printf(" \n");
    printf("-----------------------------------------------------------------------\n");
    printf("    학번\t    이름\t국어\t영어\t수학\t총점\t평균\n");
    printf("-----------------------------------------------------------------------\n");

    for (int j = 0;j < i;j++)
    {
        printf("%10d\t%10s\t%3d\t%3d\t%3d\t%3d\t%7.2lf\n", stnum[j].num, stnum[j].name, stnum[j].kor, stnum[j].eng, stnum[j].math, stnum[j].tot, stnum[j].ave);
    }
    printf("-----------------------------------------------------------------------\n");
    printf("         TOTAL AVER           %7.2f\t%7.2f\t%7.2f\t%7.2f\t%7.2lf\n", total.kor / (double)i, total.eng / (double)i, total.math / (double)i, total.tot / (double)i, total.ave / (double)i);
    printf("-----------------------------------------------------------------------\n");
    return 0;
}
