#ifndef SUDOKU_SOLVER_H_INCLUDED
#define SUDOKU_SOLVER_H_INCLUDED

#include <gtk-2.0/gtk/gtk.h>


struct solve_data {
        GtkWidget *main_wid;
        GtkWidget *puzzel[9][9];
};

void solve_sudoku(GtkWidget*,gpointer*);

char find_free(int(*)[9],int*,int*);
int solve(int (*)[9]);

char is_valid(int(*)[9],int n , int x , int y);

void show_error(gpointer *);




#endif // SUDOKU_SOLVER_H_INCLUDED
