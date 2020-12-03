#include "help.h"

void about_dialog(GtkWidget *widget, gpointer data)
{
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("sudoku.png", NULL);
    GtkWidget *dialog = gtk_about_dialog_new();
    gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dialog), "Sudoku Solver");
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "1.0");



    gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog),
                                "Ya Heidar\n sudoku solver is a simple tool for solve 9*9 sudoku puzzel\n By Abolfazl Dalily\nContact Me : abolfazldalily@zohomail.com");
    gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog),
                                "https://github.com/Abolfazl-Dalily/sudoku_solver");

    gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), pixbuf);
    g_object_unref(pixbuf), pixbuf = NULL;
    gtk_dialog_run(GTK_DIALOG (dialog));
    gtk_widget_destroy(dialog);

}
