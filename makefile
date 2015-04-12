# Copyrigth © 2015, All rights reserved.
# makefile
# Author: Fernando Segovia Salgado
FILES = Source/main_server.c Source/fileManager.c Source/cpuScheduler.c Source/queue.c Source/process.c Source/node.c Source/timer.c
CLIENT_FILES = Source/main.c Source/socket.c Source/client.c Source/fileManager.c Source/queue.c Source/process.c Source/node.c Source/timer.c
SERVER_FILES = Source/servertest.c Source/socket.c Source/queue.c Source/process.c Source/node.c Source/timer.c
CFLAGS = -I ../Hearders #-Wall
CC = gcc
PROG_NAME = bin/server
CLIENT_NAME = bin/client
SERVER_NAME =bin/server
LIBS = -lpthread -lm

clear_screen: program
	clear

program: 
	$(CC) $(CFLAGS) $(FILES) -o $(PROG_NAME) $(LIBS)

start_client:
	$(CC) $(CFLAGS) $(CLIENT_FILES) -o $(CLIENT_NAME) $(LIBS)

start_server:
	$(CC) $(CFLAGS) $(SERVER_FILES) -o $(SERVER_NAME) $(LIBS)