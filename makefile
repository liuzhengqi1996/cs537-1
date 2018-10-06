ample makefile updated to include the commands to run the Clang Static Analyzer
#
#    scan-build will "make" your program and run CSA at the same time.
#
#    scan-view will do a scan-build (if necessary) and then open a web browser
#      window to review the results.
#
CC = gcc
WARNING_FLAGS = -Wall -Wextra
EXE = 537ps
SCAN_BUILD_DIR = scan-build-out
  
all: 537ps.o parser.o getlist.o
	$(CC) -o $(EXE) 537ps.o parser.o getlist.o

537ps.o: 537ps.c parser.h getlist.h
	$(CC) $(WARNING_FLAGS) -c 537ps.c
    
parser.o: parser.c parser.h
	$(CC) $(WARNING_FLAGS) -c parser.c
    
getlist.o: getlist.c getlist.h
	$(CC) $(WARNING_FLAGS) -c getlist.c
    
clean:
	rm -f $(EXE) *.o
	rm -rf $(SCAN_BUILD_DIR)

#
# Run the Clang Static Analyzer
#
scan-build: clean
	scan-build -o $(SCAN_BUILD_DIR) make

#
# View the one scan available using firefox
#
scan-view: scan-build
	firefox -new-window $(SCAN_BUILD_DIR)/*/index.html 
