//standard includes and shit
#include <string>
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//socket stuff and shit
#include <sys/types.h>
#include <sys/socket.h>

//ip address structs and shit
#include <netinet/in.h>
#include <arpa/inet.h>

//needed to make sockets nonblocking and shit
#include <unistd.h>
#include <fcntl.h>

//for select and shit
#include <sys/time.h>

//functions and shit
int makeSocket(std::string type);
void makeSocketNonBlocking(int sockfd);
int udpRecvfrom(int sockfd, void* getData, int expectedLength);
int udpSendto(int sockfd, const void* dataToSend, struct sockaddr dest);
void printIpAndPort(struct sockaddr_in addr);
void initInetAddr(struct sockaddr_in* addr, string ip, int port);
void setNonBlockingTimeout(struct timeval* tv, int sec, int usec);

//wrappers for file descriptor manip
void clearFileDescriptorSet(fd_set* set);
void addNewFileDescriptorToSet(int fd, fd_set* set);
void removeFileDescriptorFromSet(int fd, fd_set* set);
void checkIfFileDescriptorInSet(int fd, fd_set* set);

//need to do some interface for TCP next
