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
	if(mq_unlink(argv[1]) == -1){
		std::cout << "Error in Unlinking " << errno << std::endl;
	}
	else{
		std::cout << "Successful\n";
	}
	return 0;
}