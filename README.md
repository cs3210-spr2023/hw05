# Homework 05 - Process Management


## Last name, first name

`Github username`

## Get Started

- Run `$ make bld`.  Afterwards you should have a binary file in `./bin` directory.

Please take a screenshot of every step you take in the Terminal application.  Please include these screenshots when you turn in the homework.

### What is a process?

An instance of a program is called a *process*. In simple terms, any command that you issue in Linux starts a new process. You can have multiple processes for the same program.  Processes can be divided into two types:

- **Foreground**: a program runs on the screen and may require input from the user. Such as a word processor.
- **Background**: a program that runs but does not require user input.  Such as an antivirus application.

[YouTube: Managing Linux Processes](https://youtu.be/P8GrPOpD8Sk)

### Running a foreground process

To start a foreground process, you can either run it from the UI dashboard or from the terminal.  When using the terminal you will have to wait for the foreground process to run.

Example:
```bash
home@linux:~$ ./bin/proc
```

Example Output:
```bash
Mon 2022-12-12 14:50:37 MST - foreground
Mon 2022-12-12 14:50:47 MST - foreground
Mon 2022-12-12 14:50:57 MST - foreground
Mon 2022-12-12 14:51:07 MST - foreground
```

### Running a background process

When you start a foreground process from the terminal then you cannot work on the terminal until the process is up and running. Some data intensive tasks take a lot of processing resources and may even take hours to complete. In that case you do not want to the terminal held up for such a long time.  In Linux to avoid such a situation you can send the process to the background so that the terminal remains available.  Here is how you accomplish this:

Example:
```bash
Mon 2022-12-12 14:54:41 MST - foreground
^Z
[1]  + 7398 suspended  ./bin/proc
```

### Review running processes

A basic way to see all the running processes under the current user use the `ps aux` command.

Example Output:
```bash
USER               PID  %CPU %MEM      VSZ    RSS   TT  STAT STARTED      TIME COMMAND
root               369  62.9  0.2 35864868  69088   ??  Rs   Fri03PM  66:31.04 /Library/SystemExtensions/D42696E4-442F-418D-878C-6ADDC38D2BEB/com.sophos.endpoint.scanextension.systemextension/Contents/MacOS/com.sophos.endpoint.scanextension
_sophos            470  29.3  0.1 35701176  23016   ??  Rs   Fri03PM  23:46.77 SophosCryptoGuard
_sophos            462  20.3  2.8 36512916 924044   ??  Rs   Fri03PM  34:05.21 SophosEventMonitor
stringhamdb       1212  19.3  0.7 1211535488 228404   ??  R    Fri03PM   8:31.82 /Applications/1Password.app/Contents/Library/LoginItems/1Password Launcher.app/../../../../Contents/MacOS/1Password
stringhamdb       3122  16.5  1.1 36422588 372004   ??  R     2:30PM   2:23.37 /Applications/iTerm.app/Contents/MacOS/iTerm2
_windowserver      185  15.0  0.5 39305868 184204   ??  Ss   Fri03PM  70:37.33 /System/Library/PrivateFrameworks/SkyLight.framework/Resources/WindowServer -daemon
stringhamdb      46135  12.3  1.6 60822820 540024   ??  S     9:14AM  29:25.38 /Applications/Microsoft Teams.app/Contents/Frameworks/Microsoft Teams Helper (Renderer).app/Contents/MacOS/Microsoft Teams Helper (Renderer) --type=renderer --user-data-dir=/Users/stringhamdb/Library/Application Support/Microsoft/Teams --ms-teams-less-cors=522133263 --app-path=/Applications/Microsoft Teams.app/Contents/Resources/app.asar --no-sandbox --no-zygote --autoplay-policy=no-user-gesture-required --disable-background-timer-throttling --field-trial-handle=1718379636,13849370343342076882,6943287138813528039,131072 --enable-features=ContextBridgeMutability,SharedArrayBuffer --disable-features=CalculateNativeWinOcclusion,ExtraCookieValidityChecks,ForcedColors,MediaFoundationAsyncH264Encoding,PlzServiceWorker,SpareRendererForSitePerProcess --lang=en-US --num-raster-threads=4 --enable-zero-copy --enable-gpu-memory-buffer-compositor-resources --enable-main-frame-before-activation --renderer-client-id=8 --shared-files --msteams-process-type=pluginHost
```

A better way to review all running processes under the current user use the command `top`.

Example Output:
```bash
Processes: 662 total, 2 running, 660 sleeping, 2893 threads                                                                                            15:01:07
Load Avg: 3.05, 2.96, 3.30  CPU usage: 4.70% user, 2.77% sys, 92.51% idle   SharedLibs: 837M resident, 119M data, 118M linkedit.
MemRegions: 199936 total, 6694M resident, 430M private, 3466M shared. PhysMem: 29G used (3274M wired), 2827M unused.
VM: 25T vsize, 3153M framework vsize, 0(0) swapins, 0(0) swapouts. Networks: packets: 5274893/5181M in, 2370403/1635M out.
Disks: 6566247/66G read, 4665453/97G written.

PID    COMMAND      %CPU  TIME     #TH    #WQ  #PORT MEM    PURG   CMPR PGRP  PPID  STATE    BOOSTS           %CPU_ME %CPU_OTHRS UID  FAULTS    COW
185    WindowServer 16.2  67:52.15 15     6    2520- 432M   5312K  0B   185   1     sleeping *0[1]            0.24438 0.79879    88   7002979+  111336
46135  Microsoft Te 13.2  27:06.31 52     4    545   121M   47M    0B   45929 45929 sleeping *1[37]           0.00000 0.00000    502  821335    14018
0      kernel_task  9.6   50:12.65 292/12 0    0     79M    0B     0B   0     0     running   0[0]            0.00000 0.00000    0    26606     8125
3122   iTerm2       9.4   01:38.86 15     12/1 526   198M-  24M+   0B   3122  1     sleeping *0[700]          0.46868 0.18289    502  554224+   2027
8284   top          7.0   00:06.95 1/1    0    34    7508K  0B     0B   8284  4850  running  *0[1]            0.00000 0.00000    0    45074+    135
```

The best and more versatile command is `htop`.  On some Linux version `htop` is not always install by default.  You should be able to quickly install it using the distribution's application install tool.

Example Output:
```bash
    1[|||||||||||||||||||||                                              28.0%] Tasks: 654, 1682 thr, 0 kthr; 1 running
    2[                                                                    0.0%] Load average: 3.11 3.04 3.28
    3[|||||||||||||||||                                                  22.5%] Uptime: 2 days, 23:23:41
    4[                                                                    0.0%]
    5[||||||||||                                                         13.3%]
    6[                                                                    0.0%]
    7[||||||||                                                           10.7%]
    8[|                                                                   0.7%]
    9[||||                                                                4.6%]
   10[|                                                                   0.7%]
   11[||||                                                                4.0%]
   12[                                                                    0.0%]
  Mem[|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||16.7G/32.0G]
  Swp[                                                                   0K/0K]

  PID△USER       PRI  NI  VIRT   RES S  CPU% MEM%   TIME+  Command
    0 root         8   0     0     0 ?   0.0  0.0  0:00.00 kernel_task
    1 root        40   0     0     0 ?   0.0  0.0  0:00.00 launchd
  103 root        17   0     0     0 ?   0.0  0.0  0:00.00 logd
  104 root        17   0     0     0 ?   0.0  0.0  0:00.00 UserEventAgent
  107 root        17   0     0     0 ?   0.0  0.0  0:00.00 uninstalld
  108 root        50   0     0     0 ?   0.0  0.0  0:00.00 fseventsd
  109 root        17   0     0     0 ?   0.0  0.0  0:00.00 mediaremoted
  111 root        17   0     0     0 ?   0.0  0.0  0:00.00 systemstats
  113 root        24   0     0     0 ?   0.0  0.0  0:00.00 configd
  115 root        17   0     0     0 ?   0.0  0.0  0:00.00 endpointsecurity
  116 root        17   0     0     0 ?   0.0  0.0  0:00.00 powerd
  117 root        24   0     0     0 ?   0.0  0.0  0:00.00 JamfDaemon
  121 root        17   0     0     0 ?   0.0  0.0  0:00.00 remoted
  123 root        17   0     0     0 ?   0.0  0.0  0:00.00 keybagd
  125 _softwareu  17   0     0     0 ?   0.0  0.0  0:00.00 softwareupdated
  126 _fpsd       22   0     0     0 ?   0.0  0.0  0:00.00 distnoted
  128 root        17   0     0     0 ?   0.0  0.0  0:00.00 watchdogd
  132 root        50   0     0     0 ?   0.0  0.0  0:00.00 mds
  133 root        17   0     0     0 ?   0.0  0.0  0:00.00 SophosCBR
  134 _iconservi  17   0     0     0 ?   0.0  0.0  0:00.00 iconservicesd
  135 root        17   0     0     0 ?   0.0  0.0  0:00.00 kernelmanagerd
  136 root        17   0     0     0 ?   0.0  0.0  0:00.00 diskarbitrationd
  140 root        17   0     0     0 ?   0.0  0.0  0:00.00 coreduetd
  141 root        17   0     0     0 ?   0.0  0.0  0:00.00 syslogd
  144 root        17   0     0     0 ?   0.0  0.0  0:00.00 thermalmonitord
  145 root         0   0     0     0 ?   0.0  0.0  0:00.00 opendirectoryd
  146 root         8   0     0     0 ?   0.0  0.0  0:00.00 apsd
  147 root        17   0     0     0 ?   0.0  0.0  0:00.00 launchservicesd
  148 _timed      17   0     0     0 ?   0.0  0.0  0:00.00 timed
  149 root        17   0     0     0 ?   0.0  0.0  0:00.00 log
  150 _usbmuxd    24   0     0     0 ?   0.0  0.0  0:00.00 usbmuxd
  151 root        24   0     0     0 ?   0.0  0.0  0:00.00 securityd
F1Help  F2Setup F3SearchF4FilterF5Tree  F6SortByF7Nice -F8Nice +F9Kill  F10Quit
```

### Killing a process

Though it doesn't happen a lot but sometimes an application crashes or locks up. If an application becomes completely unresponsive we can easily kill the process.  First, we need to identify the process id, using the tools described above. Second, we use the `kill` command with the process id.

Example:

```bash
$ pgrep proc
13144
$ kill 13144
[1]  + 13144 terminated  ./bin/proc
```

Sometimes a process can be difficult and NOT terminate.  In that case you can use `-9` argument to force termination.

Example:

```bash
$ kill -9 13144
```

