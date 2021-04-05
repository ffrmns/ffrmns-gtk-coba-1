// main source https://steemit.com/utopian-io/@cuthamza/steps-to-create-animated-text-in-c-programming-language
#include <stdio.h>
#include <unistd.h>

int main()
{
   int x; double y;
   char text1[]=    "\n\t Halo! Selamat Datang! ";
   char text2[]=    "\n\t Senang berjumpa dengan Anda!";
   char text3[]=    "\n\t :)\n\n";
   for(x=0; text1[x]!='\0'; x++) {
     printf("\x1B[5;33m%c\x1B[0m",text1[x]);
     fflush(stdout);
     usleep(60000);
   }

   for(x=0; text2[x]!='\0'; x++) {
     printf("%c",text2[x]);
     fflush(stdout);
     usleep(40000);
   }

   for(x=0; text3[x]!='\0'; x++) {
     printf("%c",text3[x]);
     fflush(stdout);
     usleep(100000);
   }
 
   while (1)
     { 
       printf("Hello world");
       fflush(stdout);
       sleep(1);//delay the control flow
       for(x=0;x<15;x++){printf("\033[D");}
     } 
   return 0;
}
