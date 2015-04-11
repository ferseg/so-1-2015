# Copyrigth © 2015, All rights reserved.
# makefile
# Author: Fernando Segovia Salgado
FILES = Source/main_server.c Source/fileManager.c Source/cpuScheduler.c Source/queue.c Source/process.c Source/node.c Source/timer.c
CLIENT_FILES = Source/main.c Source/client.c Source/queue.c Source/process.c Source/node.c Source/timer.c 
CFLAGS = -I ../Hearders #-Wall
CC = gcc
PROG_NAME = bin/server
CLIENT_NAME = bin/client
LIBS = -lpthread -lm

clear_screen: program
	clear

program:
	$(CC) $(CFLAGS) $(FILES) -o $(PROG_NAME) $(LIBS)

start_client:
	$(CC) $(CFLAGS) $(CLIENT_FILES) -o $(CLIENT_NAME) $(LIBS)