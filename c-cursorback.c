// Sumber kode dari https://stackoverflow.com/questions/33025599/move-the-cursor-in-a-c-program
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main()
{
    char *string = "this is a string";
    char input[1024] = { 0 };
    fflush(stdout);

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int num=w.ws_col-8;
    int m;
    for (int x=1;x<num;x++) {
      
      for(int y=0;y<num+7;y++){printf("\033[D");}
      m= x%100/10;
      printf("\x1B[3%dm%d \033[K", m,x);  
      for(int y=0;y<x;y++){
	//printf("\033[D");
	//printf("\033[D");
	printf("—");
      }
      printf("\x1B[0m➜ \x1B[7m%d%%\x1B[0m",x*100/num);       
      fflush(stdout);
      usleep(100000);
      if (x==num-1){x=0;}
    }
   
    //    fgets(input, 1024, stdin);
    printf("\n");
    return 0;
}
