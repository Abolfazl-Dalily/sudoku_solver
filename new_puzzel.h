#ifndef NEW_PUZZEL_H_INCLUDED
#define NEW_PUZZEL_H_INCLUDED

#include <gtk-2.0/gtk/gtk.h>


struct new_p_data {
        GtkWidget *puzzel[9][9];
};

void new_puzzel(GtkWidget*,gpointer*);


#endif // NEW_PUZZEL_H_INCLUDED
