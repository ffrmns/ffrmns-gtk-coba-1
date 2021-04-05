/// Header Cursorback
/// Sumber kode dari https://stackoverflow.com/questions/33025599/move-the-cursor-in-a-c-program
///
#ifndef CURSORBACK
#define CURSORBACK
#include <sys/ioctl.h>

int main_cursorback()
{
  char *string = "this is a string";
  char input[1024] = { 0 };
  fflush(stdout);

  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int num=w.ws_col-8; /// variabel kolom yang dikurangi karakter pinggir
  int m;
  
  for (int x=1;x<num;x++) {

    /// Pindah kursor ke kiri sejauh num+7
    for(int y=0;y<num+7;y++){
      printf("\033[D");
    }
    
    /// Warna berulang untuk x kelipatan 100, berubah setiap 10 warna
    /// Menampilkan angka persen di depan.
    /// Vertical tab
    m=x%100/10;
    printf("\x1B[3%dm%d \033[K", m,x);
    
    /// Mencetak garis
    for(int y=0;y<x;y++){
      printf("—");
    }

    /// Reset warna dan menampilkan panah serta persentase dalam warna invers
    printf("\x1B[0m➜ \x1B[7m%d%%\x1B[0m",x*100/num);       
    fflush(stdout);
    usleep(100000);
      
    /// ini jadi comment agar tidak terjadi pengulangan
    ///if (x==num-1){x=0;}
  }

  printf("\n");
  return 0;
}
#endif
