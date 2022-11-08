
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <errno.h>
#include <malloc.h>

#define DEV_FILENAME "/dev/rwProcMemDemo" //当前驱动DEV文件名

int testData = 0x87654321;

int main(int argc, char *argv[])
{
    int nDriverLink = open(DEV_FILENAME, O_RDWR);
    if (nDriverLink < 0)
    {
        int last_err = errno;
        printf("open error():%s\n", strerror(last_err));
        return -last_err;
    }
    int bufSize = 16;

    char *buf = (char *)malloc(bufSize);
    memset(buf, 0, bufSize);
    *(uint64_t *)&buf[0] = (uint64_t)getpid();
    *(uint64_t *)&buf[8] = (uint64_t)&testData;
    printf("getpid():%d\n", getpid());
    printf("addr:%x\n", &testData);
    printf("test_value:%x\n", testData);

    // ssize_t realRead = read(nDriverLink, buf, 4);
    ssize_t res = write(nDriverLink, buf, 4);

    // printf("dirver_value:%x\n",*(int*)buf);
    printf("dirver_value:%x\n",testData);

    close(nDriverLink);
}