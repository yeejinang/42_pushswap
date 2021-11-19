#include <unistd.h>
#include <fcntl.h>


int main()
{
    int i;
    char buffer[8];

    i = -1;
    int fd = open("testest.txt", O_CREAT);
    write(1, "Hello\n", 7);
    read(fd, buffer, 7);
    while (buffer[++i])
        write(1, &buffer[i], 1);

}