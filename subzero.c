/**
 * subzero.c
 *
 * SubZero - a process freezer for linux
 * Copyright (C) 2012 Paolo De Luca <teugon@gmail.com>
 * Copyright (C) 2012 Fabian Priftaj <fmp196@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <getopt.h>

#include <process.h>
#include <support.h>

int main(int argc, char *argv[])
{
    bool tokill = false;    // do we have to kill the target process?

    // check option args
    while (true)
    {
        int index = 0;
        int choice = -1;
        static struct option long_options[] = ARG_LONG_OPTIONS;

        if ((choice = getopt_long(argc, argv, "hl:k ", long_options, &index)) == -1)
            break;

        switch (choice)
        {
            case 'l':
                break;
            case 'k':
                tokill = true;
                break;
            case 'h':
            case '?':
            default:
                usage(argv[0]);
        }
    }


    if (argc < 3)
        usage(argv[0]);

    // check if PID is valid
    pid_t pid = atoi(argv[1]);
    if (pid <= 2)
    {
        fprintf(stderr, "SubZero: invalid <pid %d>\n", pid);
        exit(EXIT_FAILURE);
    }

    // get pathname for output image
    char *pathname = argv[2];
    printf("PID: %d\nPath: %s\n", pid, pathname);

    // TODO: create a process image and save it
    process_create_image(pid, pathname, tokill);

    // TODO: get the process image
    process_get_image();

    // TODO: load process image into memory
    process_load_image();

    return (EXIT_SUCCESS);
}
