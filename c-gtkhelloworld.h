#ifndef GTKHELLOWORLD
#define GTKHELLOWORLD
#include <gtk/gtk.h>

/// Fungsi untuk menampilkan 'Hello World' di terminal
static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}

/// Fungsi untuk menjalankan jendela
static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *button_box;
  /// Membuat window
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  /// Membuat tombol
  button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_container_add (GTK_CONTAINER (window), button_box);

  button = gtk_button_new_with_label ("Hello World");

  /// 1. Memanggil fungsi print_hello yang terdefinisi di atas
  /// 2. Keluar ketika tombol diklik
  g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
  g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
  
  gtk_container_add (GTK_CONTAINER (button_box), button);
  gtk_widget_show_all (window);
}

///
/// Variabel dihilangkan, argc diisi 0, argv diisi null
///
int
main_gtkhelloworld ()
{
  GtkApplication *app;
  int status;

  /// Mengaktifkan Jendela
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);

  /// Membaca status untuk mengakhiri sesi
  status = g_application_run (G_APPLICATION (app), 0, NULL);
  g_object_unref (app);
  return status;
}
#endif
