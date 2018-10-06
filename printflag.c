////////////////////////////////
/*
// Main File:        printflag.c
// This File:        537ps.c
// Other Files:      getlist.c, parser.c,isv.c,printflag.c
// Semester:         CS 537 Fall 2018
// Lecture:          Lec 001
//
// Authors:          Zhengqi Liu, Tian Zheng
// CS Login:         zhengqi, tian
// NetID:            mliu292, tzheng24
//

*/

/*
In this file,we create function printflag, it can outpprint the information of given pid and falgs 
*/
#include<stdio.h>
#include<stdlib.h>
#include"parser.h"

extern void printflag(int pid,int flag1, int flag2,int flag3,int flag4,int flag5);

void printflag(int pid,int flag1, int flag2,int flag3,int flag4,int flag5)
{

printf("%d",pid);
printf(": ");
if(flag1==1) {

        printf("%s ",parser_s(pid));
        printf(" ");
}

if(flag2==1) {printf("Utime=");
        printf("%s",parser_u(pid));
        printf(" ");
}
if(flag3==1) {printf("stime=");
        printf("%s",parser_S(pid));
        printf(" ");
}

if(flag4==1) {printf("vmemory=");
        printf("%s",parser_v(pid));
        printf(" ");
}
if(flag5==1) {printf("[");
        printf("%s",parser_c(pid));
        printf("]");
 }


}



