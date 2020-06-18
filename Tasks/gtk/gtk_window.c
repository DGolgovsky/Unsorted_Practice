#include <gtk/gtk.h>

static void destroy(GtkWidget *, gpointer);

static gboolean delete_event(GtkWidget *, GdkEvent *, gpointer);

int main(int argc, char **argv) {
	GtkWidget *window, *label, *button;

	/* Initialize GTK+ and all of its supporting libraries. */
	gtk_init(&argc, &argv);

	/* Create a new window, give it a title and display it to the user. */
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "GTK Window");
	gtk_container_set_border_width(GTK_CONTAINER(window), 25);
	gtk_widget_set_size_request(window, 200, 100);

	/* Connect the main window to the destroy and delete-event signals. */
	g_signal_connect(G_OBJECT(window), "destroy",
					 G_CALLBACK(destroy), NULL);
	g_signal_connect(G_OBJECT(window), "delete_event",
					 G_CALLBACK(delete_event), NULL);

	label = gtk_label_new("Hello, world!");
	gtk_label_set_selectable(GTK_LABEL(label), TRUE);

	/* Add the label as a child widget of the window. */
//  gtk_container_add (GTK_CONTAINER (window), label);

	button = gtk_button_new_with_mnemonic("_Close");
	gtk_button_set_relief(GTK_BUTTON(button), GTK_RELIEF_NONE);

	/**
	 * Connect the button to the clicked signal. The callback function
	 * recieves the window followed by the button because the arguments
	 * are swapped.
	 */
	g_signal_connect_swapped(G_OBJECT(button), "clicked",
							 G_CALLBACK(gtk_widget_destroy),
							 (gpointer) window);
	gtk_container_add(GTK_CONTAINER(window), button);

	gtk_widget_show_all(window);

	/* Hand control over to the main loop. */
	gtk_main();

	return 0;
}

/* Stop the GTK+ main loop function when the window is destroyed. */
static void destroy(GtkWidget *window, gpointer data) {
	gtk_main_quit();
}

/**
 * Return FALSE to destroy the widget. By returning TRUE, yiu can cancel
 * a delete-event. This can be used to confirm quitting the application.
 */
static gboolean delete_event(GtkWidget *window,
							 GdkEvent *event,
							 gpointer data) {
	return FALSE;
}
