#include <gtk/gtk.h>

// Global variables
GtkWidget *drawing_area;
gboolean is_drawing = FALSE;

// Event handler for drawing area expose event
gboolean on_drawing_area_expose_event(GtkWidget *widget, GdkEventExpose *event, gpointer data) {
    cairo_t *cr = gdk_cairo_create(widget->window);

    // Draw something on the drawing area (example: a line)
    cairo_move_to(cr, 50, 50);
    cairo_line_to(cr, 200, 200);
    cairo_set_line_width(cr, 2);
    cairo_stroke(cr);

    cairo_destroy(cr);
    return FALSE;
}

// Event handler for mouse button press event
gboolean on_drawing_area_button_press_event(GtkWidget *widget, GdkEventButton *event, gpointer data) {
    if (event->button == 1) { // Left mouse button
        is_drawing = TRUE;
    }
    return TRUE;
}

// Event handler for mouse button release event
gboolean on_drawing_area_button_release_event(GtkWidget *widget, GdkEventButton *event, gpointer data) {
    if (event->button == 1) { // Left mouse button
        is_drawing = FALSE;
    }
    return TRUE;
}

// Event handler for mouse motion event
gboolean on_drawing_area_motion_notify_event(GtkWidget *widget, GdkEventMotion *event, gpointer data) {
    if (is_drawing) {
        cairo_t *cr = gdk_cairo_create(widget->window);
        cairo_move_to(cr, event->x, event->y);
        cairo_line_to(cr, event->x, event->y);
        cairo_set_line_width(cr, 2);
        cairo_stroke(cr);
        cairo_destroy(cr);
    }
    return TRUE;
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *vbox;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "delete-event", G_CALLBACK(gtk_main_quit), NULL);

    drawing_area = gtk_drawing_area_new();
    gtk_widget_set_size_request(drawing_area, 400, 400);
    g_signal_connect(drawing_area, "expose-event", G_CALLBACK(on_drawing_area_expose_event), NULL);
    g_signal_connect(drawing_area, "button-press-event", G_CALLBACK(on_drawing_area_button_press_event), NULL);
    g_signal_connect(drawing_area, "button-release-event", G_CALLBACK(on_drawing_area_button_release_event), NULL);
    g_signal_connect(drawing_area, "motion-notify-event", G_CALLBACK(on_drawing_area_motion_notify_event), NULL);

    vbox = gtk_vbox_new(FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), drawing_area, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
