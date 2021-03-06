/**
 * support.c
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
#include <errno.h>

#include <support.h>


/* show program arguments */
void usage(char *progname)
{
    fprintf(stderr,
            "SubZero - a simple freezer for Linux\n"
            "Usage:  %s <pid> <output> [options] ...\n"
            " Where options are:\n"
            "   -h, --help      display this message and exit\n"
            "   -l, --library   include proc. library into the image [todo]\n"
            "   -k, --kill      kill process when called [todo]\n"
            , progname);
    exit(EXIT_FAILURE);
}


/* print an error message description and exit */
void errquit(char *str)
{
    fprintf(stderr, "%s: %s.\n", str, strerror(errno));
    exit(EXIT_FAILURE);
}
