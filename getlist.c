////////////////////////////////////////////////////////////////////////////////
// Main File:        537ps.c
// This File:        getlist.c
// Other Files:      537ps.c, parser.c
// Semester:         CS 537 Fall 2018
// Lecture:          Lec 001
//
// Authors:          Zhengqi Liu, Tian Zheng
// CS Login:         zhengqi, tian
// NetID:            mliu292, tzheng24
//
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

extern int* getlist(int uid);

/*
 * getlist - if there is no -p option, look through /proc to find the list of
 * processes belonging to the user, return a list of pids
 */
int* getlist(int uid) {
    // Pointer for directory and file
    DIR *dir;
    struct dirent *de;
    
    // Pointers for file and buffer
    FILE *fp;
    int BUFFER_SIZE = 1000;
    char buffer[BUFFER_SIZE];
    
    // Pointers for string and outputs
    char *string;
    //char pid_value[64];
    char *pid_value;
    char *read_uid;
    //int uid_value;
    int *list = (int*) malloc(sizeof(int) * 1000);//
    int count = 0;
    // Open current directory
    dir = opendir("/proc/");
    if (dir == NULL) {
        printf("Cannot open directory\n");
        exit(1);
    }
    // Read files in current directory
    while ((de = readdir(dir)) != NULL) {
        // If a subdirectory name can be converted to an int, then it is a pid
        // we need to read this directory and status file to find its uid
        char place[20];
        //char pid_value[100];
        //pid_value = strdup(de -> d_name);
        pid_value = strdup(de -> d_name);
        //if (atoi(pid_value) != 0) {
        if (atoi(pid_value) != 0) {
            //printf("FIND A PID DIRECTORY\n");
            //printf("%s\n", de -> d_name);
            //printf("%d\n", atoi(de -> d_name));
            //printf("%s\n", pid_value);
            //printf("%d\n", atoi(pid_value));
            strcpy(place, "/proc/");
            strcat(place, de -> d_name);
            //strcat(place, pid_value);
            /*
            dir = opendir(place);        
            if (dir == NULL) {
                printf("Cannot open directory\n");
            }
            */
            // Open status file to find uid
            strcat(place,"/status"); 
            fp = fopen(place, "r");
            if(fp == NULL){
                printf("Cannnot open file\n");
                exit(1);
            }
            
            //printf("SUCCESS ON OPENING FILE\n");
            // When there is a line to read, find the uid
            int loop = 0; 
            while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                loop++;
                if (loop == 9) {
                    break;
                }
            }
            
            if (loop == 9) {
                //printf("SEARCHING FOR UID ON LINE 9\n");
                // Get information on the uid line
                string = strtok(buffer, ":");
                //printf("%s", string);
                string = strtok(NULL, "\t");
    //            printf("\n The uid for this pid is:");
      //          printf("%s", string);
        //        printf("\n The actual uid to match is:");
         //       printf("%d", uid);
                read_uid = strdup(string);
                char uid_string[20];
                sprintf(uid_string, "%d", uid);
                // If uid matches the input uid, then return current pid
                if (strcmp(uid_string, read_uid) == 0) {
                    //printf("A MATCH IS FOUND\n");
                    list[count] = atoi(pid_value);
           //         printf("List[count]=");
            //        printf("%d", list[count]);
                    count++;
                } 
            }                   
        }
    }
    closedir(dir);
    return list;
    printf("数量=");
    printf("%d",count);
}
