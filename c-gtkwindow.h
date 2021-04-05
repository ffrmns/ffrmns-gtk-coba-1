#include <gtk/gtk.h>

static void
activatoe (GtkApplication* app,
          gpointer        user_data)
{
  GtkWidget *window;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  gtk_widget_show_all (window);
}
///
/// Variabel dihilangkan, argc diisi 0, argv diisi null
///
int
main_gtkwindow ()
{
  GtkApplication *app;
  int status;

  /// Mengaktifkan Jendela
  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activatoe), NULL);

  /// Membaca status untuk mengakhiri sesi
  status = g_application_run (G_APPLICATION (app), 0, NULL);
  g_object_unref (app);
  return status;
}
