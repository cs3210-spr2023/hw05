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

Examples:
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

```bash
$ ./bin/proc
^Z
```


