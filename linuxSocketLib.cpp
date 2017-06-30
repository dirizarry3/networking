#include "linuxSocketLib.h"

using namespace std;

int createSocket(string type) {
   int sockfd;
   if (type == "UDP" or type == "udp") {
      sockfd = socket(AF_INET, SOCK_DGRAM, 0);
   } else if (type == "TCP" or type == "tcp") {
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
   } else {
      perror("failed to create socket.");
      exit(1);
   }
   return sockfd;
}

void makeSocketNonBlocking(int sockfd) {
   if( fcntl(sockfd, F_SETFL, O_NONBLOCK) == -1) {
      perror("fcntl");
      exit(1);
   }
   return;
}

int udpSendto(int sockfd, const void* dataToSend, struct sockaddr dest) {
   int bytes;
   if((bytes = sendto(sockfd, dataToSend, sizeof(dataToSend), 0, (struct sockaddr*)dest, sizeof(dest))) == -1) {
      perror("sendto");
      exit(1);
   }
   return bytes;
}

int udpRecvfrom(int sockfd, void* getData, int expectedLength, struct sockaddr fromAdder) {
   int bytes;
   if((bytes = recvfrom(sockfd, getData, expectedLength, 0, (struct sockaddr*)fromAdder, sizeof(struct sockaddr))) == -1) {
      perror("recvfrom");
      exit(1);
   }
   return bytes;
}

void printIpAndPort(struct sockaddr_in addr) {
   cout << "This is my IP:PORT = " << inet_ntoa(addr.sin_addr) << ":" << addr.sin_port << endl;
   return;
}

void initInetAddr(struct sockaddr_in* addr, string ip, int port) {
   addr.sin_family = AF_INET;         // host byte order
   addr.sin_port = htons(MYPORT);     // short, network byte order
   addr.sin_addr.s_addr = inet_addr(ip.c_str()); //ip address
   return;
}

void setNonBlockingTimeout(struct timeval* tv, int sec, int usec) {
   tv->tv_sec = sec;
   tv->tv_usec = usec;
   return;   
}
