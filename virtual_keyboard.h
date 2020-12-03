#ifndef VIRTUAL_KEYBOARD_H_INCLUDED
#define VIRTUAL_KEYBOARD_H_INCLUDED

#include <gtk-2.0/gtk/gtk.h>

struct virtual_keyboard_response
{
    int id ;
    GtkWidget* wid ;
};
struct custom_data {
        GtkWidget *wid;
        GtkWidget *btn;
};

void open_virtula_keyboard(GtkWidget*,gpointer*);
void emit_virtual_keyboard_response(GtkWidget*,gpointer*);


#endif // VIRTUAL_KEYBOARD_H_INCLUDED
