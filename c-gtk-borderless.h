/*
   Kode Sumber    : https://stackoverflow.com/questions/23466947/how-to-create-gtk-windows-without-title-bar-with-resize-and-move-properties-wor
   https://developer.gnome.org/gtk3/stable/TextWidget.html
   Referensi      : https://developer.gnome.org/gtk3/stable/GtkApplication.html
   lokal          : ~/Dokumen/c-gtkwindow.c
*/

#ifndef GTK_BORDERLESS
#define GTK_BORDERLESS
#include <gtk/gtk.h>
#include <unistd.h>

/*
// ----------------------------------------------------------- //
// ----------------------------------------------------------- //
// ----------------------------------------------------------- //
*/

static void activatee (GtkApplication* app, gpointer user_data){

  int ww,wh;
  int posw (int w){ return (1366-ww)/2+w;}
  int posh (int w){ return (768-wh)/2+w;}
  GtkWidget *window;
  GtkWidget *view;
  GtkTextBuffer *buffer;
  GtkCssProvider *provider;
  GtkStyleContext *context;
  GtkWidget *overlay;
  GtkWidget *sw;
  GtkWidget *image;
  GtkWidget *frame;
  
   // ----------------------------------------------------------- //
  
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Window");
  gtk_window_set_default_size (GTK_WINDOW (window), ww=1366, wh=768);
  gtk_window_set_decorated (GTK_WINDOW (window), FALSE);
  gtk_window_move (GTK_WINDOW(window), posw(100),posh(-20));

  // ----------------------------------------------------------- //

  view = gtk_text_view_new ();
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (view));
  gtk_text_buffer_set_text (buffer, "Hello, this is some text", -1);
  gtk_text_view_set_left_margin (GTK_TEXT_VIEW (view), 20);
  gtk_text_view_set_top_margin (GTK_TEXT_VIEW (view), 20);

  provider = gtk_css_provider_new();
  gtk_css_provider_load_from_data (provider,
				   "textview {"
				   " font: 50px serif;"
				   "  color: green;"
				   "  background: transparent;"
				   "}"
				   "textview text {"
				   //"  background-color: #ff0000;"
				   "  background: transparent;"
				   "}",
				   -1,
				   NULL);
  context = gtk_widget_get_style_context (view);
  gtk_style_context_add_provider (context,
				  GTK_STYLE_PROVIDER (provider),
				  GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
  //gtk_widget_set_opacity(view,1);
  //  gtk_widget_override_background_color(view, 'blue');
  
  // ----------------------------------------------------------- //
  
  frame = gtk_frame_new (NULL);
  gtk_frame_set_shadow_type (GTK_FRAME (frame), GTK_SHADOW_IN);
  gtk_widget_set_opacity(frame,1);
  image = gtk_image_new_from_file ("/home/ffa/Gambar/Simulasi OFDM_2020-12-29_07-11-47.png");

  // ----------------------------------------------------------- //

  overlay = gtk_overlay_new ();  
  gtk_container_add (GTK_CONTAINER (window), overlay);
  gtk_container_add (GTK_CONTAINER (frame), image);
  gtk_container_add (GTK_CONTAINER (overlay), frame);
  gtk_overlay_add_overlay (GTK_OVERLAY (overlay), view);
  
  // ----------------------------------------------------------- //

  gtk_widget_show_all (overlay);
  if (!gtk_widget_get_visible (window))
    gtk_widget_show (window);
  else
    gtk_widget_destroy (window);

}

/*
// ----------------------------------------------------------- //
// ----------------------------------------------------------- //
// ----------------------------------------------------------- //
*/
///Menghapus paramter, langsung dimasukkan argc 0 dan argv NULL
int main_gtk_borderless () {

  g_print ("Hello World\n");
  
  GtkApplication *app;
  int status;
  
  /* Initialize GTK+ and all of its supporting libraries. */
  app = gtk_application_new (NULL, G_APPLICATION_FLAGS_NONE);

  /* Create a new window, give it a title and display it to the user. */
  g_signal_connect (app, "activate", G_CALLBACK (activatee), NULL);

 
  status = g_application_run (G_APPLICATION (app), 0, NULL);
  g_object_unref (app);
  return status;

}
#endif
