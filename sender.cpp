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
	if(argc < 2){
		std::cout << "Please Enter Queue Name\n";
		exit(1);
	}
	if((mqid = mq_open(argv[1],O_CREAT|O_WRONLY,0,0)) == -1){
		std::cout << "Error While Opening Queue[Server]\n";
		exit(1);
	}
	char data[50];
	std::cout << "Please Enter the Data to send..\n";
	scanf("%s",data);
	std::cout << data;
	if(mq_send(mqid,data,strlen(data),0) == -1){
		std::cout << "Error While Sending Message[Server]\n";
		exit(1);		
	}
	else{
		std::cout << "sent successful " << errno << std::endl;
	}
	mq_close(mqid);
	return 0;
}