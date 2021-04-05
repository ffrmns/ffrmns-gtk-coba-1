///
/// main source https://steemit.com/utopian-io/@cuthamza/steps-to-create-animated-text-in-c-programming-language
///

#include <stdio.h>
#include <unistd.h>
#include "c-columns.h"
#include "c-tekswarna.h"
#include "c-teksgerak.h"
#include "c-cursorback.h"
#include "c-gtkwindow.h"
#include "c-gtkhelloworld.h"
#include "c-gtk3demo-assistant.h"
#include "c-gtksimple.h"
#include "c-gtk-borderless.h"
///
/// Program utama
///

int main()
{
  /// 1. Program columns mengecek jumlah kolom dan baris di terminal
  /// 2. Program tekswarna menampilkan huruf berwarna
  /// 3. Program teksgerak menampilkan teks yang bergerak per karakter
  /// 4. Program cursorback menampilkan pergeseran kursor untuk presentase
  /// 5. Program gtkwindow untuk menampilkan jendela kosong
  /// 6. Program gtkhelloworld menampilkan tombol hello world
  /// 7. Program gtk3demo-assistant mencoba demo bawaan gtk3
  /// 8. Program gtksimple menampilkan jumlah klik
  /// 9. Program gtk-borderless menampilkan foto yang bisa diketik
  main_columns();
  main_tekswarna();
  main_teksgerak();
  main_cursorback();
  main_gtkwindow();
  main_gtkhelloworld();
  main_gtk3demo_assistant();
  main_gtksimple();
  main_gtk_borderless();
  return 0;
}
