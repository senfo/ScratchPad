/*
 * Implmentation of a simple program to demonstrate how we could use
 * the Linux inotify subsystem for monitoring a dropbox
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <unistd.h>

#define EVENT_SIZE (sizeof (struct inotify_event))
#define BUFFER_LEN (1024 * (EVENT_SIZE + 16))

int main(int argc, char **argv)
{
    int x = 0;
    int inotifyFileDescriptor = inotify_init();
    int watchDescriptor;
    char *path;
    char buffer[BUFFER_LEN];
    ssize_t length;
    struct inotify_event *event;

    if (argc < 2)
    {
        printf("Syntax: %s <path>\n", argv[0]);
	exit(EXIT_FAILURE);
    }

    path = argv[1];

    if (inotifyFileDescriptor < 0)
    {
        perror("Error initializing inotify");
	exit(EXIT_FAILURE);
    }

    watchDescriptor = inotify_add_watch(inotifyFileDescriptor, path, IN_CREATE | IN_MODIFY | IN_DELETE);

    while (1)
    {
        length = read(inotifyFileDescriptor, buffer, BUFFER_LEN);

        if (length < 0)
        {
            perror("Error reading inotify file descriptor into buffer");
        }

        while (x < length)
        {
            event = (struct inotify_event *)&buffer[x];

            if (event->mask & IN_CREATE)
            {
                 printf("File named '%s' created.\n", event->name);
            }
            else if (event->mask & IN_MODIFY)
            {
                printf("File named '%s' modified.\n", event->name);
            }
            else if (event->mask & IN_DELETE)
            {
                printf("File named '%s' deleted.\n", event->name);
            }
            else
            {
                fprintf(stderr, "Catching event we didn't listen for: %d.\n", event->mask);
            }

            x += EVENT_SIZE + event->len;
        }

	x = 0;
    }

    inotify_rm_watch(inotifyFileDescriptor, watchDescriptor);
    close(inotifyFileDescriptor);

    return 0;
}
