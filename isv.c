////////////////////////////////
/*
// Main File:        537ps.c
// This File:        isv.c
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
We create function isv to verify the input string s is valid or not
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern int isv(char* in);
int isv(char* in){
int s=0;
if (strcmp(in,"-s")==0) s=1;
if (strcmp(in,"-s-")==0) s=1;
if (strcmp(in,"-v")==0) s=1;
if (strcmp(in,"-v-")==0) s=1;
if (strcmp(in,"-c")==0) s=1;
if (strcmp(in,"-c-")==0) s=1;
if (strcmp(in,"-S")==0) s=1;
if (strcmp(in,"-S-")==0) s=1;
if (strcmp(in,"-U")==0) s=1;
if (strcmp(in,"-U-")==0) s=1;
if (strcmp(in,"-s")==0) s=1;
if (strcmp(in,"-s")==0) s=1;
//Above are all the valid input
return s;

}
