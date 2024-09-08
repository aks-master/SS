/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
2 -> C program to run infinite loop in background and check its info using
proc dir: less /proc/<process-id>/status.
date: 15/8/24 (date first pushed)
*/

#include <stdio.h>
int main()
{
    while (100)
        ;
    return 0;
}
/*note. run program in background using &, this will gives its pid. now check the file /proc/<process-id>/status using less.
eg.
Name:   2.out
Umask:  0002
State:  R (running)
Tgid:   2926
Ngid:   0
Pid:    2926
PPid:   2918
TracerPid:      0
Uid:    1000    1000    1000    1000
Gid:    1000    1000    1000    1000
FDSize: 256
Groups: 4 24 27 30 46 122 134 137 1000
NStgid: 2926
NSpid:  2926
NSpgid: 2926
NSsid:  2918
Kthread:        0
VmPeak:     2708 kB
VmSize:     2644 kB
VmLck:         0 kB
VmPin:         0 kB
VmHWM:      1024 kB
VmRSS:      1024 kB
*/
