#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main()
{
        int fd,rat;
        char buf[32];
        fd=open("ggg.txt",O_RDONLY);
        if(fd<0)
        {
                 printf("faild to open the file\n");
                 return;
        }
        rat=read(fd,buf,32);
        buf[rat]=NULL;
        printf("Data read from file:%s\n",buf);
        close(fd);



}
