#include <bits/stdc++.h>
#include <iostream>
#include <assert.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <cstdlib>



int main(int argc,char **argv){
	int mqid = 0;
	fd_set readfds;
	char data[50];
	struct mq_attr attr;
	attr.mq_flags = 0;
	attr.mq_curmsgs  = 0;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 40;
	if(argc < 2){
		std::cout << "Please Enter Queue Name\n";
		exit(1);
	}
	if((mqid = mq_open(argv[1],O_CREAT|O_RDONLY,0660,&attr)) == -1){
		std::cout << "Error While Opening Queue[Recvr]\n";
		exit(1);
	}
	std::cout << "mqid is " << mqid << std::endl;
	while(1){
		FD_ZERO(&readfds);
		FD_SET(mqid,&readfds);
		std::cout << "Waiting on Select ()\n";
		select(mqid+1,&readfds,NULL,NULL,NULL);
		if(FD_ISSET(mqid,&readfds)){
			std::cout << "message rcvd on queue " << argv[1] << std::endl;
			memset(data,0,50);
			if(mq_receive(mqid,data,50,0) == -1){
				std::cout << "Error While rcving message\n" << errno << std::endl;
				exit(1);
			}
			std::cout << "data rcvd from the Queue is ->" << data << std::endl;
		}
	}
	mq_close(mqid);
	return 0;
}