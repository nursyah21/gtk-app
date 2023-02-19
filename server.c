#include <gtk/gtk.h>
#include <microhttpd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define PAGE "<html><head><title>libmicrohttpd demo</title>"\
             "</head><body>libmicrohttpd demo</body></html>"

#define PORT 5000

static enum MHD_Result ahc_echo(
  void *cls, 
  struct MHD_Connection *connection,
  const char *url,
  const char *method,
  const char *version,
  const char *upload_data,
  size_t *upload_data_size,
  void **ptr
){
  static int dummy;
  const char *page = cls;
  struct MHD_Response *response;
  int ret;

  if (0 != strcmp(method, "GET")) 
  {
    return MHD_NO;
  }
  if (&dummy != *ptr)
  {
    *ptr = &dummy;
    return MHD_YES;
  }
  if (0 != *upload_data_size)
  {
    return MHD_NO;
  }

  *ptr = NULL;
  response = MHD_create_response_from_buffer (
    strlen(page), (void*) page, MHD_RESPMEM_PERSISTENT
  );

  ret = MHD_queue_response (
    connection, MHD_HTTP_OK, response
  );
  MHD_destroy_response(response);

  return ret;
}
  

static void run_server (GtkWidget *widget, gpointer data)
{
  g_print("run server in localhost:%d\n", PORT);

  struct MHD_Daemon *d;
  d = MHD_start_daemon(
    MHD_USE_THREAD_PER_CONNECTION,
    PORT,
    NULL,
    NULL,
    &ahc_echo,
    PAGE, 
    MHD_OPTION_END
  );

  if (d == NULL)
  {
    g_print("error: run server in localhost:%d\n", PORT);
  }

  (void) getc (stdin);
  MHD_stop_daemon(d);
}

static void activate (GtkApplication *app, gpointer user_data)
{
  GtkWidget *window;
  GtkWidget *button;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "window");
  gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

  button = gtk_button_new_with_label ("run server");
  g_signal_connect (button, "clicked", G_CALLBACK (run_server), NULL);
  gtk_window_set_child (GTK_WINDOW (window), button);

  gtk_window_present (GTK_WINDOW (window));
}

int main (int argc, char **argv)
{
  GtkApplication *app;
  int status;

  app = gtk_application_new ("org.example", G_APPLICATION_DEFAULT_FLAGS);
  g_print ("application run\n");
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref(app);

  return status;
}
