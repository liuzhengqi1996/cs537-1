////////////////////////////////////////////////////////////////////////////////
// Main File:        537ps.c
// This File:        parser.c
// Other Files:      537ps.c, getlist.c
// Semester:         CS 537 Fall 2018
// Lecture:          Lec 001
//
// Authors:          Zhengqi Liu, Tian Zheng
// CS Login:         zhengqi, tian
// NetID:            mliu292, tzheng24
//
////////////////////////////////////////////////////////////////////////////////

#include<ctype.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h> 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<getopt.h>

extern char* parser_s(int pid);
extern char* parser_u(int pid);
extern char* parser_S(int pid);
extern char* parser_v(int pid);
extern char* parser_c(int pid);

/*
 * parser - extracts strings from the space-separated lists that are read from
 * the stat and statm files
 */
char* parser_s(int pid) {
    int BUFFER_SIZE = 100;
    // Pointer for directory
    DIR *dir;
    struct dirent *de;
    
    // Pointers for file and buffer
    FILE *fp;
   
    char buffer[BUFFER_SIZE];
    
    // Pointers for string and outputs
    char* string;
    // Output for -s
    char* state;
    
    // Convert pid from int to char
    char which_pid[10];
    //itoa(pid,which_pid,10);
    sprintf(which_pid, "%d", pid);
    char place[20];
    strcpy(place, "/proc/");
    strcat(place, which_pid);
   
    // Open current directory
    dir = opendir(place);
    if (dir == NULL) {
        printf("Cannot open directory");
        exit(1);
    } else {
        // Read current directory and open stat file
        de = readdir(dir);
        if ((de = readdir(dir)) != NULL) {
		strcat(place,"/stat");
	    	fp = fopen(place,"r");
            if(fp == NULL){
                printf("Cannnot open file\n");
           }
            // When there is a line to read, store the required value
            if (fgets(buffer, sizeof(buffer), fp) != NULL) {
                string = strtok(buffer, " ");
                string = strtok(NULL, " ");
                // The 3rd value is for -s, single-character state
                string = strtok(NULL, " ");
                state = strdup(string);
            }
        }
        closedir(dir);
    }
    return state;
}

char* parser_u(int pid) {
    int BUFFER_SIZE = 100;
    // Pointer for directory
    DIR *dir;
    struct dirent *de;

    // Pointers for file and buffer
    FILE *fp;
  
    char buffer[BUFFER_SIZE];
    
    // Pointers for string and outputs
    char* string;
    // Output for -u
    char* utime;
    
    // Convert pid from int to char
    char which_pid[10];
    sprintf(which_pid, "%d", pid);
    char place[20];
    strcpy(place, "/proc/");
    strcat(place, which_pid);
    
    // Open current directory
    dir = opendir(place);
    if (dir == NULL) {
        printf("Cannot open directory\n");
        exit(1);
    } else {
        // Read current directory and open stat file
        de = readdir(dir);
        if ((de = readdir(dir)) != NULL) {
             strcat(place,"/stat");
                fp = fopen(place,"r");
            if(fp == NULL){
                printf("Cannnot open file\n");
            }
            // When there is a line to read, store the required value
            if (fgets(buffer, sizeof(buffer), fp) != NULL) {
                // The first string
                string = strtok(buffer, " ");
                // The second string
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                // The 14th value is for -U, amount of user time
                string = strtok(NULL, " ");
                utime = strdup(string);
            }
        }
        closedir(dir);
    }
    return utime;
}

char* parser_S(int pid) {
    int BUFFER_SIZE = 100;
    // Pointer for directory
    DIR *dir;
    struct dirent *de;

    // Pointers for file and buffer
    FILE *fp;

    char buffer[BUFFER_SIZE];
    
    // Pointers for string and outputs
    char* string;
    // Output for -S
    char* stime;
   
    
    // Convert pid from int to char
    char which_pid[10];
    sprintf(which_pid, "%d", pid);
    char place[20];
    strcpy(place, "/proc/");
    strcat(place, which_pid);
    
    // Open current directory
    dir = opendir(place);
    if (dir == NULL) {
        printf("Cannot open directory");
        exit(1);
    } else {
        // Read current directory and open stat file
        de = readdir(dir);
        if ((de = readdir(dir)) != NULL) {
             strcat(place,"/stat");
                fp = fopen(place,"r");
            if(fp == NULL){
                printf("Cannnot open file\n");
            }
            // When there is a line to read, store the required value
            if (fgets(buffer, sizeof(buffer), fp) != NULL) {
                // The first string
                string = strtok(buffer, " ");
                // The second string
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                string = strtok(NULL, " ");
                // The 15th value is for -S, amount of system time
                string = strtok(NULL, " ");
                stime = strdup(string);
            }
        }
        closedir(dir);
    }
    return stime;
}

char* parser_v(int pid) {
    int BUFFER_SIZE = 100;
    // Pointer for directory
    DIR *dir;
    struct dirent *de;

    // Pointers for file and buffer
    FILE *fp;

    char buffer[BUFFER_SIZE];

    // Pointers for string and outputs
    char *string;
    // Output for -v
    char *vmemory;

    // Convert pid from int to char
    char which_pid[10];
    sprintf(which_pid, "%d", pid);
    char place[20];
    strcpy(place, "/proc/");
    strcat(place, which_pid);

    // Open current directory
    dir = opendir(place);
    if (dir == NULL) {
        printf("Cannot open directory\n");
        exit(1);
    } else {
        // Read current directory and open stat file
        de = readdir(dir);
        if ((de = readdir(dir)) != NULL) {
             strcat(place,"/statm");
                fp = fopen(place,"r");
            if(fp == NULL){
                printf("Cannnot open file\n");
            }
            // When there is a line to read, store the required value
            if (fgets(buffer, sizeof(buffer), fp) != NULL) {
                // The first string is for -c, command-line
                string = strtok(buffer, " ");
                vmemory = strdup(string);
            }
        }
        closedir(dir);
    }
    return vmemory;
}

char* parser_c(int pid) {
    int BUFFER_SIZE = 100;
   
    // Pointer for directory
    DIR *dir;
    struct dirent *de;

    // Pointers for file and buffer
    FILE *fp;
  
    char buffer[BUFFER_SIZE];
    
    // Pointers for string and outputs
    char *string;
    // Output for -v
    char *command;
    
    // Convert pid from int to char
    char which_pid[10];
    sprintf(which_pid, "%d", pid);
    char place[20];
    strcpy(place, "/proc/");
    strcat(place, which_pid);
    
    // Open current directory
    dir = opendir(place);
    if (dir == NULL) {
        printf("Cannot open directory\n");
        exit(1);
    } else {
        // Read current directory and open stat file
        de = readdir(dir);
        if ((de = readdir(dir)) != NULL) {
             strcat(place,"/cmdline");
                fp = fopen(place,"r");
            if(fp == NULL){
                printf("Cannnot open file\n");
            }
            // When there is a line to read, store the required value
            if (fgets(buffer, sizeof(buffer), fp) != NULL) {
                // The first string is for -c, command-line
                string = strtok(buffer, "\n\t");
                command = strdup(string);
            }
        }
        closedir(dir);
    }
    return command;
}

