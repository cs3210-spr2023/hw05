#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
  char   buf[100];

  while(1) {
    time_t t = time(NULL);

    strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", localtime(&t));

    if (getpgrp() == tcgetpgrp(STDOUT_FILENO)) {
      printf("%s - foreground\n", buf);
    } else {
      printf("%s - background\n", buf);
    }

    sleep(10);
  }

  return 0;
}
