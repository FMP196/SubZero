/**
 * support.h
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

#ifndef _SUPPORT_H_
#define _SUPPORT_H_

#define ARG_LONG_OPTIONS {{"help",    no_argument, 0, 'h'},\
                          {"library", required_argument, 0, 'l'},\
                          {"kill",    no_argument, 0, 'k'},\
                          {0,0,0,0}};

void usage(char *progname);
void errquit(char *str);


#endif /* _SUPPORT_H */
