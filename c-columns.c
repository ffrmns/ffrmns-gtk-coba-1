/// File Header
///
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>

/// Program Utama
///
int main (int argc, char **argv)
{
    /// Inisiasi Variabel
    ///
    struct winsize w;	
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    /// Menampilkan Jumlah Baris dan Kolom
    ///
    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);
    return 0;
}
