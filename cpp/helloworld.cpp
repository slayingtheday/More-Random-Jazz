// copied from https://developer.gnome.org/gtk3/stable/gtk-getting-started.html
#include <gtk/gtk.h>
#include <iostream>

using namespace std;

static void activate (GtkApplication* app, gpointer user_data){
  GtkWidget *window;
  GtkWidget *label;

  window = gtk_application_window_new (app);
  label = gtk_label_new("Hello World");
  gtk_label_set_text(GTK_LABEL(), "Hello World");
  gtk_window_set_title (GTK_WINDOW (window), "Hello World gtk");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
  gtk_widget_show_all (window);
  gtk_widget_show_all (label);
}

int main (int argc, char **argv){
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}