#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int divide(char* ch, char* buf, int offset){
	int i,count=0;
	for(i=offset;*(ch+i)!=' ';i++){
		if(*(ch+i)=='\0') break;
		*(buf + count) = *(ch+i);
		count++;
	}
	return i+1;
}
int main(int argc, char* argv[]) {
	int rfd, n;
	char* ch;
	char buf[55]={'\0'};
	int offset=0;
	rfd = open("junk.txt", O_RDONLY);
	if(rfd == -1){
		perror("Error");
		exit(1);
	}
	printf("%s\n",*(argv+1));

	size_t fileSize = lseek(rfd, 0, SEEK_END);
	printf("%zu\n",fileSize);
	ch=(char*)malloc(sizeof(char)*fileSize);

	n = read(rfd, ch, fileSize);

	while(*(ch+offset)!='\0'){
		offset = divide(ch,buf,offset);
		printf("%s : ",buf);
		if(**(argv+1)==*buf){
			printf("match!!\n");
		}
		for(int i=0;i<55;i++) buf[i]='\0';
	}


	close(rfd);
	return 0;
}


