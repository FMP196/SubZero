/**
 * substruct.h
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

#ifndef _SUBSTRUCT_H_
#define _SUBSTRUCT_H_


struct vma_t
{
    unsigned long start;   // virtual memory address start
    unsigned long length;  // virtual memory address length
    int perms;             // access rights (r w x s p)
    int device;            // device number in hex (major:minor)
    long offset;           // offset where mapping begins
    int inode;             // inode on the device
    char* pathname;        // pathname of the file
    void* data;            // if stored real data, else NULL
};


#endif /* _SUBSTRUCT_H_ */
