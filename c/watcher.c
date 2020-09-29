#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <argp.h>
#include <sys/inotify.h>

#define EVENT_SIZE (sizeof (struct inotify_event))
#define BUFF_LEN (1024 * (EVENT_SIZE + 16))

int main(int argc, char **argv)
{
    int fd;
    int watch;
    int length;
    struct inotify_event *event;
    char buffer[BUFF_LEN];
    char *path = argv[1];
    char *buffer_pointer;

    if (argc != 2)
    {
        printf("Usage: %s [directory]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    printf("Watching %s for contacts.\n", path);

    fd = inotify_init();
    watch = inotify_add_watch(fd, path, IN_CREATE | IN_MODIFY | IN_DELETE);

    while (1)
    {
        length = read(fd, buffer, BUFF_LEN);

        if (length < 0)
        {
            fprintf(stderr, "Error reading into file descriptor\n");
            exit(EXIT_FAILURE);
        }

        for (buffer_pointer = buffer; buffer_pointer < buffer + length; )
        {
            event = (struct inotify_event *) buffer_pointer;

            if (event->mask & IN_CREATE)
            {
                printf("%s created\n", event->name);
            }
            else if (event->mask & IN_MODIFY)
            {
                printf("%s modified\n", event->name);
            }
            else if (event->mask & IN_DELETE)
            {
                printf("%s deleted\n", event->name);
            }

            buffer_pointer += sizeof (struct inotify_event) + event->len;
        }
    }

    inotify_rm_watch(fd, watch);
    close(fd);

    return EXIT_SUCCESS;
}
