////////////////////////////////
/*
// Main File:        537ps.c
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
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<getopt.h>
#include<unistd.h>
#include"parser.h"
#include"getlist.h"
#include"printflag.h"
#include"isv.h"

extern int isv(char* in);
extern void printflag(int pid,int flag1, int flag2,int flag3,int flag4,int flag5);

int main(int argc,char * argv[]){
char *optstring;
optstring="p:s::S::U::v::c::";

int opt;
int pid;
int flag0 = 0;
//flag1 control the display of status,default is 0
int flag1 = 0;
//flag2 control the display of Utime,default is 1
int flag2 = 1;
//flag3 control the display of Stime,default is 0
int flag3 = 0;
//flag4 control the display of virtual memory,default is 0
int flag4 =0 ;
//flag4 control the display of command line,default is 1
int flag5 =1 ;

//read command line by getopt,deal with different kind of option
while ( (opt=getopt(argc,argv,optstring))!=-1 ){
 
	switch(opt){

		default: printf("invaid input\n");
	 	exit(1);
          	break;
	 
	       
		case'p': 
		         //there is pid input
	         	 flag0 = 1;
			 //read the input pid
	        	 pid = atoi(optarg);
			 if( pid <= 0 ){
			 printf("invalid input");
			 exit(1);	 
				   }
			 else if ( argv[optind] == NULL) flag0 = 1;
 		        
			 else if ( isv(argv[optind]) == 1) flag0 = 1;
			
			 else   { printf("invalid input");
        			   exit(1);
 			        }
			break;


		case's':
			//default is false. turn on flag1 when "-s". do nothing when "-s-" . any other case is invalid 
	       	        if ( optarg == NULL ) {
	               		 if ( argv[optind] == NULL) {
                                 flag1=1;
                                 break;
                                                           }
                                 else if ( isv(argv[optind]) == 1) flag1 = 1;
	                         else{
		                       printf("invalid input\n");
		                       exit(1);
	                             }
                                             }
                        if ( optarg != NULL && strcmp(optarg,"-" ) == 0){
       				if ( argv[optind] == NULL ){
               		        flag1=flag1;
                                break;
 		                        		  }
		            	else if ( isv(argv[optind]) == 1 ) flag1=flag1;
        	      	        else{
                	                printf("invalid input\n");
                        	        exit(1);
                           	    }
                                                                       }

		       if ( optarg != NULL && strcmp(optarg,"-") != 0 ) {
 					 printf("invalid input\n");
					 exit(1);
								       }	  
                       break;



		case'U':
		        //default is true. do nothing when "-U".turn off flag2 when "-U-" . any other case is invalid 
			 if ( optarg == NULL ) {
        			  if( argv[optind] == NULL){
               			  flag2=flag2;
               			  break;
  							 }
				  else if( isv(argv[optind]) == 1 ) flag2=flag2;
              			  else{
                   		         printf("invalid input\n");
                    		         exit(1);
              			      }
					 }
			 if ( optarg != NULL && strcmp(optarg,"-") == 0){
       				 if ( argv[optind] == NULL ) {
             		            	flag2=0;
               			    	break;
				  			     }
			      	 else if ( isv(argv[optind]) == 1 ) flag2=0;
                                 else{
                                        printf("invalid input\n");
                                        exit(1);
                                     }
                                                      	    }

			 if ( optarg !=NULL && strcmp(optarg,"-") != 0) {
     				 printf("invalid input\n");
        			 exit(1);
 								     }
                         break;


		case'S': 
			 //default is false. turn on flag3 when "-S". do nothing when "-S-" . any other case is invalid 
			  if ( optarg == NULL ) {
        			 if ( argv[optind] == NULL){
               			 flag3=1;
               			 break;
 						          }
          			else if ( isv(argv[optind]) == 1 ) flag3=1;
   			        else{
                      		 printf("invalid input\n");
                       		 exit(1);
              			    }
					      }

			 if ( optarg != NULL && strcmp(optarg,"-") == 0 ){
       				 if ( argv[optind] == NULL){
               			 flag3=flag3;
               			 break;
 							 }
				else  if ( isv(argv[optind]) == 1 ) flag3=flag3;
              			else{
                      	 		printf("invalid input\n");
                      		         exit(1);
             			     }
								    }

 			if ( optarg != NULL && strcmp(optarg,"-") != 0 ) {
         			printf("invalid input\n");
        		        exit(1);
 								       }
			break;



		case'v':
			//default is false. turn on flag4 when "-v". do nothing when "-v-" . any other case is invalid 
			 if ( optarg == NULL ) {
         			 if ( argv[optind] == NULL ){
               				 flag4=1;
               				 break;
						       }
		          else if ( isv(argv[optind]) == 1 ) flag4=1;
              		  else{
                      		 printf("invalid input\n");
                     		 exit(1);
              		      }
					  }

			 if ( optarg != NULL && strcmp(optarg,"-") == 0 ){
       				 if ( argv[optind] == NULL ){
                			flag4=flag4;
                			break;
 						        }
				else  if ( isv(argv[optind]) == 1 ) flag4=flag4;

               			else{
                     	  		 printf("invalid input\n");
                       			 exit(1);
                 		    }
								     }

 			if ( optarg != NULL && strcmp(optarg,"-") != 0 ) {
        			 printf("invalid input\n");
         			 exit(1);
    								   }
			break;

		case'c':
			 //default is true. do nothing when "-c".turn off flag5 when "-c-" . any other case is invalid 
			 if ( optarg == NULL ) {
          			if ( argv[optind] == NULL ){
               		        flag5=flag5;
                		break;
  						      }
          			else if ( isv(argv[optind]) == 1) flag5=flag5;
               			else{
                       			printf("invalid input\n");
                       			exit(1);
               			    }
					  }

			 if ( optarg != NULL && strcmp(optarg,"-") == 0 ){
        			if ( argv[optind] == NULL ){
                		flag5=0;
                		break;
  						      }
				else if ( isv(argv[optind]) == 1 ) flag5=0;
               			else{
                       			printf("invalid input\n");
                       			exit(1);
               			    }
								     }

			 if ( optarg != NULL && strcmp(optarg,"-") != 0 ) {	
         			printf("invalid input\n");
         			exit(1);
  								    }
			break; 
					}
		         }

//if there exits input pid					     
if ( flag0 == 1 ){
	//display the required information of this pid
	printflag(pid,flag1,flag2,flag3,flag4,flag5);
	    }
//if there is no input pid, find all the possible pid of your pid
else if ( flag0 == 0 ){
       	if ( argc == 1 ) {/* do nothing*/}
   	else if ( isv(argv[1]) == 0 ){
		printf("invalid input");
		exit(1);
				 }
int uid=getuid();
int* array=(int*)malloc(sizeof(int)*1000);
//get all the possible pid that meets the uid you have
array=getlist(uid);
int i=0;
//diplay the command information for every possible pid
while ( array[i] > 0 ){
	pid=array[i];
        printflag(pid,flag1,flag2,flag3,flag4,flag5);
        printf("\n");		
        i = i+1;
                     }
	free(array);

		}
else printf("error");

printf("\n");
return 0;
						}

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

//we create function printflag, it can outpprint the information of given pid and falgs 
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





