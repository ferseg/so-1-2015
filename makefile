# Copyrigth © 2015, All rights reserved.
# makefile
# Author: Fernando Segovia Salgado
FILES = Source/main_server.c Source/fileManager.c Source/cpuScheduler.c Source/queue.c Source/process.c Source/node.c Source/timer.c 
CFLAGS = -I ../includes #-Wall
CC = gcc
PROG_NAME = bin/server

clear_screen: program
	clear

program: 
	$(CC) $(CFLAGS) $(FILES) -o $(PROG_NAME)