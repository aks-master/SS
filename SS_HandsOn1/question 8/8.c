/*
Name: Abhishek Kumar Singh
Roll#: MT2024006
8-> WAP to read a file line by line.
date: 17/8/24 (date first pushed)
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    char buffer[1024];
    int fd = open("file8.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("error: ");
        exit(0);
    }

    while (read(fd, buffer, 1))
    {
        if (buffer[0] == '\n')
        {
            getchar();
        }
        else
        {
            printf("%c", buffer[0]);
        }
    }
    close(fd);
    return 0;
}
/*note
to use just create a file with lots of line eg. <ls -l output>. here I have precreated that file as file8.txt and reading it line by line
eg output:
cat file8.txt
total 1152
drwxr-xr-x  3 root root    4096 May  5  2022 acpi
-rw-r--r--  1 root root    3028 May  5  2022 adduser.conf
drwxr-xr-x  3 root root    4096 May  5  2022 alsa
drwxr-xr-x  2 root root    4096 Aug 11 11:17 alternatives
-rw-r--r--  1 root root     335 Mar 23  2022 anacrontab
-rw-r--r--  1 root root     433 Mar 23  2022 apg.conf
drwxr-xr-x  5 root root    4096 May  5  2022 apm
drwxr-xr-x  3 root root    4096 Aug  9 18:34 apparmor
drwxr-xr-x  8 root root    4096 Aug  9 18:36 apparmor.d
drwxr-xr-x  4 root root    4096 Aug  9 18:35 apport
-rw-r--r--  1 root root     769 Feb 22  2022 appstream.conf
drwxr-xr-x  8 root root    4096 Aug  9 18:31 apt
drwxr-xr-x  3 root root    4096 Aug  9 18:35 avahi
-rw-r--r--  1 root root    2319 Jan  6  2022 bash.bashrc
-rw-r--r--  1 root root      45 Nov 11  2021 bash_completion
drwxr-xr-x  2 root root    4096 Aug  9 18:35 bash_completion.d
-rw-r--r--  1 root root     367 Dec 16  2020 bindresvport.blacklist
drwxr-xr-x  2 root root    4096 Apr  8  2022 binfmt.d
drwxr-xr-x  2 root root    4096 Aug  9 18:35 bluetooth
-rw-r-----  1 root root      33 May  5  2022 brlapi.key
drwxr-xr-x  7 root root    4096 May  5  2022 brltty
-rw-r--r--  1 root root   29219 Mar 18  2022 brltty.conf
drwxr-xr-x  3 root root    4096 May  5  2022 ca-certificates
-rw-r--r--  1 root root    6253 Aug  9 18:35 ca-certificates.conf
-rw-r--r--  1 root root    5529 May  5  2022 ca-certificates.conf.dpkg-old
drwxr-s---  2 root dip     4096 May  5  2022 chatscripts
drwxr-xr-x  2 root root    4096 Aug  9 18:25 console-setup
drwxr-xr-x  2 root root    4096 May  5  2022 cracklib
drwxr-xr-x  2 root root    4096 Aug  9 18:35 cron.d
drwxr-xr-x  2 root root    4096 Aug  9 18:35 cron.daily
drwxr-xr-x  2 root root    4096 May  5  2022 cron.hourly
drwxr-xr-x  2 root root    4096 May  5  2022 cron.monthly
-rw-r--r--  1 root root    1136 Mar 23  2022 crontab
drwxr-xr-x  2 root root    4096 May  5  2022 cron.weekly
drwxr-xr-x  2 root root    4096 May  5  2022 cryptsetup-initramfs
-rw-r--r--  1 root root      54 May  5  2022 crypttab
drwxr-xr-x  5 root lp      4096 Aug 13 13:21 cups
drwxr-xr-x  2 root root    4096 May  5  2022 cupshelpers
drwxr-xr-x  4 root root    4096 May  5  2022 dbus-1
drwxr-xr-x  4 root root    4096 May  5  2022 dconf
-rw-r--r--  1 root root    2969 Feb 20  2022 debconf.conf
-rw-r--r--  1 root root      13 Aug 22  2021 debian_version
drwxr-xr-x  3 root root    4096 Aug  9 18:35 default
-rw-r--r--  1 root root     604 Sep 16  2018 deluser.conf
drwxr-xr-x  2 root root    4096 May  5  2022 depmod.d
drwxr-xr-x  4 root root    4096 Aug  9 18:34 dhcp
drwxr-xr-x  2 root root    4096 May  5  2022 dictionaries-common
drwxr-xr-x  4 root root    4096 Aug  9 18:32 dpkg
-rw-r--r--  1 root root     685 Jan  9  2022 e2scrub.conf
drwxr-xr-x  3 root root    4096 May  5  2022 emacs
-rw-r--r--  1 root root     106 Aug  9 18:25 environment
drwxr-xr-x  2 root root    4096 May  5  2022 environment.d
-rw-r--r--  1 root root    1816 Dec 27  2019 ethertypes
drwxr-xr-x  3 root root    4096 May  5  2022 firefox
drwxr-xr-x  4 root root    4096 May  5  2022 fonts
-rw-r--r--  1 root root      20 Feb 24  2022 fprintd.conf
-rw-r--r--  1 root root     120 May  5  2022 fstab
-rw-r--r--  1 root root     694 Mar 23  2022 fuse.conf
drwxr-xr-x  3 root root    4096 Aug  9 18:35 fwupd
-rw-r--r--  1 root root    2584 Feb  3  2022 gai.conf
drwxr-xr-x  2 root root    4096 Aug  9 18:26 gamin
drwxr-xr-x  3 root root    4096 Aug  9 18:35 gdb
drwxr-xr-x  8 root root    4096 Aug  9 18:36 gdm3
drwxr-xr-x  2 root root    4096 May  5  2022 geoclue
drwxr-xr-x  4 root root    4096 May  5  2022 ghostscript
drwxr-xr-x  3 root root    4096 May  5  2022 glvnd
drwxr-xr-x  2 root root    4096 May  5  2022 gnome
drwxr-xr-x  2 root root    4096 May  5  2022 groff
-rw-r--r--  1 root root    1091 Aug  9 18:35 group
-rw-r--r--  1 root root    1070 Aug  9 18:25 group-
drwxr-xr-x  2 root root    4096 Aug  9 18:35 grub.d
-rw-r-----  1 root shadow   901 Aug  9 18:35 gshadow
-rw-r-----  1 root shadow   883 Aug  9 18:25 gshadow-
drwxr-xr-x  3 root root    4096 Feb 22  2022 gss
drwxr-xr-x  2 root root    4096 Aug  9 18:34 gtk-2.0
drwxr-xr-x  2 root root    4096 Aug  9 18:35 gtk-3.0
-rw-r--r--  1 root root    4436 Dec 16  2020 hdparm.conf
-rw-r--r--  1 root root      92 Oct 15  2021 host.conf
-rw-r--r--  1 root root      20 Aug  9 18:25 hostname
-rw-r--r--  1 root root     234 Aug  9 18:25 hosts
-rw-r--r--  1 root root     411 May  5  2022 hosts.allow
-rw-r--r--  1 root root     711 May  5  2022 hosts.deny
drwxr-xr-x  2 root root    4096 May  5  2022 hp
drwxr-xr-x  3 root root    4096 May  5  2022 ifplugd
drwxr-xr-x  2 root root    4096 Aug  9 18:34 init
drwxr-xr-x  2 root root    4096 Aug  9 18:36 init.d
drwxr-xr-x  5 root root    4096 Aug  9 18:35 initramfs-tools
-rw-r--r--  1 root root    1748 Jan  6  2022 inputrc
drwxr-xr-x  2 root root    4096 Aug  9 18:36 insserv.conf.d
drwxr-xr-x  2 root root    4096 Aug  9 18:35 ipp-usb
drwxr-xr-x  4 root root    4096 May  5  2022 iproute2
-rw-r--r--  1 root root      26 Feb 14 20:17 issue
-rw-r--r--  1 root root      19 Feb 14 20:17 issue.net
drwxr-xr-x  6 root root    4096 May  5  2022 kernel
-rw-r--r--  1 root root     110 May  5  2022 kernel-img.conf
-rw-r--r--  1 root root    1308 Mar 24  2022 kerneloops.conf
drwxr-xr-x  2 root root    4096 Aug  9 18:34 ldap
-rw-r--r--  1 root root   63939 Aug 11 11:18 ld.so.cache
-rw-r--r--  1 root root      34 Dec 16  2020 ld.so.conf
drwxr-xr-x  2 root root    4096 Aug  9 18:32 ld.so.conf.d
-rw-r--r--  1 root root     267 Oct 15  2021 legal
-rw-r--r--  1 root root      27 Mar 13  2022 libao.conf
-rw-r--r--  1 root root     191 Mar 17  2022 libaudit.conf
drwxr-xr-x  3 root root    4096 May  5  2022 libblockdev
drwxr-xr-x  2 root root    4096 May  5  2022 libnl-3
drwxr-xr-x  2 root root    4096 Mar 24  2022 libpaper.d
drwxr-xr-x  3 root root    4096 Aug  9 18:35 libreoffice
-rw-r--r--  1 root root    2996 Mar  4  2022 locale.alias
-rw-r--r--  1 root root    9458 Aug  9 18:34 locale.gen
lrwxrwxrwx  1 root root      32 Aug  9 18:34 localtime -> /usr/share/zoneinfo/Asia/Kolkata
drwxr-xr-x  4 root root    4096 May  5  2022 logcheck
-rw-r--r--  1 root root   10734 Nov 11  2021 login.defs
-rw-r--r--  1 root root     592 Jan 24  2022 logrotate.conf
drwxr-xr-x  2 root root    4096 Aug  9 18:36 logrotate.d
-rw-r--r--  1 root root     104 Feb 14 20:17 lsb-release
drwxr-xr-x  3 root root    4096 May  5  2022 lvm
-r--r--r--  1 root root      33 Aug  9 18:23 machine-id
-rw-r--r--  1 root root     111 Mar 24  2022 magic
-rw-r--r--  1 root root     111 Mar 24  2022 magic.mime
-rw-r--r--  1 root root   28084 Aug  9 19:07 mailcap
-rw-r--r--  1 root root     449 Dec 11  2021 mailcap.order
-rw-r--r--  1 root root    5217 Mar 18  2022 manpath.config
-rw-r--r--  1 root root   72029 Mar 21  2022 mime.types
-rw-r--r--  1 root root     744 Jan  9  2022 mke2fs.conf
drwxr-xr-x  4 root root    4096 Aug  9 18:33 ModemManager
drwxr-xr-x  2 root root    4096 Aug  9 18:34 modprobe.d
-rw-r--r--  1 root root     195 May  5  2022 modules
drwxr-xr-x  2 root root    4096 Aug  9 18:35 modules-load.d
lrwxrwxrwx  1 root root      19 Aug  9 18:25 mtab -> ../proc/self/mounts
-rw-r--r--  1 root root   11204 Feb  9  2022 nanorc
-rw-r--r--  1 root root     767 Mar 24  2022 netconfig
drwxr-xr-x  2 root root    4096 May  5  2022 netplan
drwxr-xr-x  6 root root    4096 May  5  2022 network
drwxr-xr-x  8 root root    4096 May  5  2022 networkd-dispatcher
drwxr-xr-x  7 root root    4096 Aug  9 18:35 NetworkManager
-rw-r--r--  1 root root      91 Oct 15  2021 networks
drwxr-xr-x  2 root root    4096 May  5  2022 newt
-rwxr-xr-x  1 root root     228 Mar 23  2022 nftables.conf
-rw-r--r--  1 root root     582 May  5  2022 nsswitch.conf
drwxr-xr-x  4 root root    4096 Aug  9 18:35 openvpn
drwxr-xr-x  2 root root    4096 May  5  2022 opt
lrwxrwxrwx  1 root root      21 Feb 14 20:17 os-release -> ../usr/lib/os-release
drwxr-xr-x  2 root root    4096 May  5  2022 PackageKit
-rw-r--r--  1 root root     552 Aug 12  2020 pam.conf
drwxr-xr-x  2 root root    4096 Aug  9 18:36 pam.d
-rw-r--r--  1 root root    2925 Aug  9 18:35 passwd
-rw-r--r--  1 root root    2904 Aug  9 18:35 passwd-
drwxr-xr-x  2 root root    4096 May  5  2022 pcmcia
drwxr-xr-x  3 root root    4096 May  5  2022 perl
drwxr-xr-x  4 root root    4096 May  5  2022 pki
drwxr-xr-x  3 root root    4096 May  5  2022 pm
-rw-r--r--  1 root root    7649 May  5  2022 pnm2ppa.conf
drwxr-xr-x  4 root root    4096 May  5  2022 polkit-1
drwxr-xr-x  8 root dip     4096 May  5  2022 ppp
lrwxrwxrwx  1 root root      18 Aug  9 18:35 printcap -> /run/cups/printcap
-rw-r--r--  1 root root     582 Oct 15  2021 profile
drwxr-xr-x  2 root root    4096 Aug  9 18:35 profile.d
-rw-r--r--  1 root root    2932 Apr  2  2013 protocols
drwxr-xr-x  4 root root    4096 Aug  9 18:35 pulse
drwxr-xr-x  2 root root    4096 May  5  2022 python3
drwxr-xr-x  2 root root    4096 Aug  9 18:32 python3.10
drwxr-xr-x  2 root root    4096 Aug  9 18:26 rc0.d
drwxr-xr-x  2 root root    4096 May  5  2022 rc1.d
drwxr-xr-x  2 root root    4096 May  5  2022 rc2.d
drwxr-xr-x  2 root root    4096 May  5  2022 rc3.d
drwxr-xr-x  2 root root    4096 May  5  2022 rc4.d
drwxr-xr-x  2 root root    4096 May  5  2022 rc5.d
drwxr-xr-x  2 root root    4096 Aug  9 18:26 rc6.d
drwxr-xr-x  2 root root    4096 Aug  9 18:26 rcS.d
lrwxrwxrwx  1 root root      39 May  5  2022 resolv.conf -> ../run/systemd/resolve/stub-resolv.conf
lrwxrwxrwx  1 root root      13 Dec  5  2023 rmt -> /usr/sbin/rmt
-rw-r--r--  1 root root     887 Apr  1  2013 rpc
-rw-r--r--  1 root root    1382 Dec 24  2021 rsyslog.conf
drwxr-xr-x  2 root root    4096 Aug  9 18:35 rsyslog.d
-rw-r--r--  1 root root    5620 Jan  9  2022 rygel.conf
drwxr-xr-x  3 root root    4096 May  5  2022 sane.d
drwxr-xr-x  4 root root    4096 Aug  9 18:34 security
drwxr-xr-x  2 root root    4096 May  5  2022 selinux
-rw-r--r--  1 root root   10593 Apr  1  2022 sensors3.conf
drwxr-xr-x  2 root root    4096 May  5  2022 sensors.d
-rw-r--r--  1 root root   12813 Mar 28  2021 services
drwxr-xr-x  3 root root    4096 May  5  2022 sgml
-rw-r-----  1 root shadow  1488 Aug  9 18:35 shadow
-rw-r-----  1 root shadow  1488 Aug  9 18:35 shadow-
-rw-r--r--  1 root root     128 May  5  2022 shells
drwxr-xr-x  2 root root    4096 Aug  9 18:32 skel
drwxr-xr-x  2 root root    4096 Aug  9 18:34 snmp
drwxr-xr-x  4 root root    4096 Aug  9 18:35 speech-dispatcher
drwxr-xr-x  3 root root    4096 Aug  9 18:34 ssh
drwxr-xr-x  4 root root    4096 Aug  9 18:34 ssl
drwx--x--x  3 root root    4096 May  5  2022 sssd
-rw-r--r--  1 root root      17 Aug  9 18:26 subgid
-rw-r--r--  1 root root      34 Aug  9 18:25 subgid-
-rw-r--r--  1 root root      17 Aug  9 18:26 subuid
-rw-r--r--  1 root root      34 Aug  9 18:25 subuid-
-rw-r--r--  1 root root    4573 Feb 14  2022 sudo.conf
-r--r-----  1 root root    1671 Feb  8  2022 sudoers
drwxr-xr-x  2 root root    4096 Aug  9 18:34 sudoers.d
-rw-r--r--  1 root root    9390 Feb 14  2022 sudo_logsrvd.conf
-rw-r--r--  1 root root    2355 Feb 25  2022 sysctl.conf
drwxr-xr-x  2 root root    4096 Aug  9 18:35 sysctl.d
drwxr-xr-x  5 root root    4096 Aug  9 18:35 systemd
drwxr-xr-x  2 root root    4096 Aug  9 18:32 terminfo
drwxr-xr-x  2 root root    4096 Aug  9 18:35 thermald
drwxr-xr-x  2 root root    4096 Aug  9 18:35 thunderbird
-rw-r--r--  1 root root      13 Aug  9 18:34 timezone
drwxr-xr-x  2 root root    4096 Apr  8  2022 tmpfiles.d
drwxr-xr-x  2 root root    4096 Aug  9 18:36 ubuntu-advantage
-rw-r--r--  1 root root    1260 Jun 16  2020 ucf.conf
drwxr-xr-x  4 root root    4096 Aug  9 18:34 udev
drwxr-xr-x  2 root root    4096 May  5  2022 udisks2
drwxr-xr-x  3 root root    4096 Aug  9 18:35 ufw
drwxr-xr-x  3 root root    4096 Aug  9 18:35 update-manager
drwxr-xr-x  2 root root    4096 Aug  9 18:36 update-motd.d
drwxr-xr-x  2 root root    4096 Mar 30  2022 update-notifier
drwxr-xr-x  2 root root    4096 May  5  2022 UPower
-rw-r--r--  1 root root    1523 Mar 25  2022 usb_modeswitch.conf
drwxr-xr-x  2 root root    4096 Sep  6  2021 usb_modeswitch.d
drwxr-xr-x  2 root root    4096 Aug  9 18:35 vim
lrwxrwxrwx  1 root root      23 May  5  2022 vtrgb -> /etc/alternatives/vtrgb
drwxr-xr-x  5 root root    4096 May  5  2022 vulkan
-rw-r--r--  1 root root    4942 Jan 24  2022 wgetrc
drwxr-xr-x  2 root root    4096 Aug  9 18:35 wpa_supplicant
drwxr-xr-x 13 root root    4096 May  5  2022 X11
-rw-r--r--  1 root root     681 Mar 23  2022 xattr.conf
drwxr-xr-x  7 root root    4096 Aug  9 18:26 xdg
drwxr-xr-x  2 root root    4096 May  5  2022 xml
drwxr-xr-x  3 root root    4096 May  5  2022 xrdp
-rw-r--r--  1 root root     460 Dec  8  2021 zsh_command_not_found
aks@aks-Virtual-Machine:~/SS/handson 1/question 8$
*/
