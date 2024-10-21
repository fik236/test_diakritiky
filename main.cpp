#include <gtk/gtk.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <vector>

using namespace std;


void CloseWin (GtkWidget* wid, GtkWidget* data) {
    cout << "CloseWin" << endl;

    //do something

  gtk_window_close (GTK_WINDOW(data));
}

void OpenNewWin (GtkWidget* wid, GtkWidget* data) {
    cout << "opening"<< endl;

    GtkWidget *windowDetail = gtk_window_new ();
    gtk_widget_set_size_request (windowDetail, 220, 220);

    GtkWidget  *vBox = gtk_box_new (GTK_ORIENTATION_VERTICAL,10);
    gtk_window_set_child (GTK_WINDOW (windowDetail), vBox);

    GtkWidget *labText = gtk_label_new("příšerně žluťoučký kůň úpěl ďábelské ódy");
    gtk_box_append (GTK_BOX (vBox), labText);
    GtkWidget *labText2 = gtk_label_new("prasečí hody šmakovaly ťapínkovy");
    gtk_box_append (GTK_BOX (vBox), labText2);

    GtkWidget *btnClose = gtk_button_new_with_label("Close");
    gtk_box_append  (GTK_BOX (vBox), btnClose);
    g_signal_connect(G_OBJECT(btnClose), "clicked", G_CALLBACK(CloseWin), windowDetail);

    //gtk_window_set_focus(GTK_WINDOW(windowDetail),windowDetail);

    gtk_widget_show (windowDetail);
}


static void appActivate (GApplication *app, gpointer user_data) {
    GtkWidget *win = gtk_application_window_new (GTK_APPLICATION (app));
    gtk_window_set_title (GTK_WINDOW (win), "Title");
    gtk_window_set_default_size (GTK_WINDOW (win), 400, 300);

    GtkWidget  *vBox = gtk_box_new (GTK_ORIENTATION_VERTICAL,10);

    gtk_window_set_child (GTK_WINDOW (win), vBox);

    GtkWidget *labText = gtk_label_new("příšerně žluťoučký kůň úpěl ďábelské ódy");
    gtk_box_append (GTK_BOX (vBox), labText);
    GtkWidget *labText2 = gtk_label_new("prasečí hody šmakovaly ťapínkovy");
    gtk_box_append (GTK_BOX (vBox), labText2);

    GtkWidget *btnOpen = gtk_button_new_with_label("Open new win");
    gtk_box_append  (GTK_BOX (vBox), btnOpen);
    g_signal_connect_swapped(GTK_BUTTON(btnOpen), "clicked", G_CALLBACK(OpenNewWin), win);

    GtkWidget *btnBack = gtk_button_new_with_label("Close");
    gtk_box_append  (GTK_BOX (vBox), btnBack);
    g_signal_connect_swapped(GTK_BUTTON(btnBack), "clicked", G_CALLBACK(gtk_window_destroy), win);

    gtk_widget_show (win);
}


int main(int argc, char **argv) {
    GtkApplication *app;
    app = gtk_application_new ("testing.app", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (appActivate), NULL);
    return g_application_run (G_APPLICATION (app), NULL, NULL);
    g_object_unref (app);

    return 0;
}
