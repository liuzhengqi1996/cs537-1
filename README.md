Course: CS 537
Project: ps command 537ps
Instructor: Barton Miller
Semester: Fall 2018
Lecture: Lec 001
Authors: Zhengqi Liu, Tian Zheng
CS Login: zhengqi, tian
NetID: mliu292, tzheng24

This project is divided into 3 modules.
The main file is 537ps. It reads options from command line and determines the value of 
flags to enable or disable options. Each flag is used to control the display of specific
information. If there is a pid input, then use function printflag to print the information
of this pid. If there is no pid input from command line, then it will get current uid number
to call function getlist to get all the possible pid numbers. Then print the required 
information for every pid of this uid.

The getlist file includes the function that can return all the possible pids that matching
the input uid.

The parser file includes the function that can return specific information of the pid for
each option.
