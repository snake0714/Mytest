#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main(){
	int fd[2];
	pipe(fd);
	pid_t pid=fork();
	if(pid==-1){
		exit(-1);
	}else if(pid==0){
		printf("son\n");
		close(fd[0]);
		write(fd[1],"hello",sizeof("hello"));
	}else{
		printf("father\n");
		close(fd[1]);
		char buf[20];
		read(fd[0],buf,sizeof(buf));
		printf("%s\n",buf);
	}
}
