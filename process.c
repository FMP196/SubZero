/**
 * process.c
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

#include <fcntl.h>
#include <signal.h>
#include <sys/ptrace.h>

#include <support.h>
#include <process.h>


static long
attach_process(pid_t pid)
{
    return (ptrace(PTRACE_ATTACH, pid, 0, 0));
}


static long
detach_process(pid_t pid)
{
    return (ptrace(PTRACE_DETACH, pid, 0, 0));
}


void
process_create_image(pid_t pid, char *pathname, bool tokill)
{
    int fd;
    if ((fd = open(pathname, O_CREAT|O_WRONLY|O_TRUNC, 0777)) < 0)
        errquit("open()");

    if (attach_process(pid) < 0)
        errquit("attach_process()");

    // TODO

    if (detach_process(pid) < 0)
        errquit("detach_process()");
}


void
process_get_image()
{
    // TODO
}


void
process_load_image()
{
    // TODO
}
