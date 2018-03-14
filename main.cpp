
/*
 * code stolen from openGL-RPi-tutorial-master/encode_OGL/
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <linux/input.h>
#include <GLES2/gl2.h>

#include "./display.hpp"


void cleanup(int s) 
{
    cleanup_display();
    exit(s);
}

int main(int argc, char *argv[])
{ 
    signal(SIGINT, cleanup);
    
    int fd = open("/dev/input/event2", O_RDONLY);
    if (fd < 0) {
        fprintf(stderr, "failed to open input device: %s\n", strerror(errno));
        exit(-1);
    }
    char name[256] = "Unknown";
    ioctl(fd, EVIOCGNAME(sizeof(name)), name);
    printf("Input device name: \"%s\"\n", name);

    init_display();

    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    
    present_display();
    
    sleep(4);
    
    cleanup(0);
    return 0;
}
