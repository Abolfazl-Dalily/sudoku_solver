#include <gtk-2.0/gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <stdio.h>
#include "virtual_keyboard.h"
#include "sudoku_solver.h"
#include "new_puzzel.h"
#include "help.h"




void end_program(GtkWidget *wid , gpointer *ptr)
{
    gtk_main_quit();
}
//void key_board_handler(GtkWidget *wid,GdkEventKey *event , gpointer *ptr)
//{
//    printf("A key pressed !\n");
//}





int main (int argc, char *argv[])
{
    GtkWidget *vbox;
    GtkWidget *main_win ;


    GtkAccelGroup *accel_group = NULL;
    GtkWidget *sep;

    GtkWidget *menu_bar ;

    GtkWidget *file_menu ;
    GtkWidget *file_mi;
    GtkWidget *quit_mi;
    GtkWidget *open_sudoku_mi;

    GtkWidget *help_menu ;
    GtkWidget *help_mi;
    GtkWidget *guide_mi;
    GtkWidget *about_mi;


    GtkWidget *main_h_box ;
    GtkWidget *main_v_box ;
    GtkWidget *sudoku_tbl ;
    GtkWidget *sudoku_button[9][9];
    GtkWidget *v_controller_box ;
    GtkWidget *new_puzzle_btn ;
    GtkWidget *solve_btn ;

    gtk_init (&argc, &argv);


    main_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(main_win),GTK_WIN_POS_CENTER);
//    g_signal_connect(G_OBJECT(main_win),"key_press_event",G_CALLBACK(key_board_handler),NULL);
    g_signal_connect(G_OBJECT(main_win),"delete_event",G_CALLBACK(end_program),NULL);

    gtk_widget_set_size_request(main_win,750,625);
    gtk_window_set_resizable(GTK_WINDOW (main_win),FALSE);


    // Add Menu Bar
    menu_bar = gtk_menu_bar_new();

    file_menu = gtk_menu_new();
    help_menu = gtk_menu_new();

    vbox = gtk_vbox_new(FALSE,0);
    accel_group = gtk_accel_group_new();
    sep = gtk_separator_menu_item_new();
    gtk_window_add_accel_group(GTK_WINDOW(main_win),accel_group);

    file_mi = gtk_menu_item_new_with_mnemonic("_File");


    open_sudoku_mi = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW,NULL);
    sep = gtk_separator_menu_item_new();
    quit_mi = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, accel_group);
    gtk_widget_add_accelerator(quit_mi, "activate", accel_group,
                               GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);


    gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_mi),file_menu);

    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu),open_sudoku_mi);
    gtk_image_menu_item_set_always_show_image(open_sudoku_mi,TRUE);

    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu),sep);

    gtk_menu_shell_append(GTK_MENU_SHELL(file_menu),quit_mi);
    gtk_image_menu_item_set_always_show_image(quit_mi,TRUE);

    // ***************
    help_mi = gtk_menu_item_new_with_mnemonic("_Help");

    guide_mi = gtk_image_menu_item_new_from_stock(GTK_STOCK_HELP,NULL);
    about_mi = gtk_image_menu_item_new_from_stock(GTK_STOCK_ABOUT,NULL);


    gtk_menu_item_set_submenu(GTK_MENU_ITEM(help_mi),help_menu);

    gtk_menu_shell_append(GTK_MENU_SHELL(help_menu),guide_mi);
    gtk_image_menu_item_set_always_show_image(guide_mi,TRUE);

    gtk_menu_shell_append(GTK_MENU_SHELL(help_menu),about_mi);
    gtk_image_menu_item_set_always_show_image(about_mi,TRUE);

    // ***************


    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),file_mi);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar),help_mi);
    gtk_box_pack_start(GTK_BOX(vbox),menu_bar,FALSE,FALSE,0);



    g_signal_connect(about_mi,"activate",G_CALLBACK(about_dialog),NULL);
    g_signal_connect(quit_mi,"activate",G_CALLBACK(end_program),NULL);

    // ***************




    main_h_box = gtk_hbox_new(FALSE,10);
    main_v_box = gtk_vbox_new(FALSE,10);
    sudoku_tbl = gtk_table_new (9, 9,TRUE);



    // sudoku_number[0][0] = gtk_label_new("sdsd");
    struct custom_data c_data[9][9];
    struct solve_data s_data;
    s_data.main_wid = main_win;
    struct new_p_data n_p_data;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            sudoku_button[i][j] = gtk_button_new_with_label("");
            c_data[i][j].wid = main_win ;
            c_data[i][j].btn = sudoku_button[i][j];
            s_data.puzzel[i][j] = sudoku_button[i][j];
            n_p_data.puzzel[i][j] = sudoku_button[i][j];
            gtk_widget_set_size_request(sudoku_button[i][j],65,65);
            // gtk_widget_override_background_color(GTK_WIDGET(sudoku_button[i][j]), GTK_STATE_NORMAL, &color);
            gtk_table_attach_defaults (GTK_TABLE (sudoku_tbl),sudoku_button[i][j],j,j+1,i,i+1);
            g_signal_connect(GTK_OBJECT(sudoku_button[i][j]),"clicked",G_CALLBACK(open_virtula_keyboard),&c_data[i][j]);

        }

    }





    v_controller_box = gtk_vbox_new(TRUE,5);
    new_puzzle_btn = gtk_button_new_with_label("New Puzzel");
    solve_btn = gtk_button_new_with_label("Solve");

    gtk_widget_set_size_request(solve_btn,120,60);
    gtk_widget_set_size_request(new_puzzle_btn,120,60);

    gtk_widget_set_uposition(solve_btn,610,430);
    gtk_widget_set_uposition(new_puzzle_btn,610,500);

    gtk_box_pack_start(GTK_BOX (v_controller_box),solve_btn,TRUE,FALSE,10);
    gtk_box_pack_end(GTK_BOX (v_controller_box),new_puzzle_btn,TRUE,FALSE,10);




    g_signal_connect(GTK_OBJECT(solve_btn),"clicked",G_CALLBACK(solve_sudoku),&s_data);
    g_signal_connect(GTK_OBJECT(new_puzzle_btn),"clicked",G_CALLBACK(new_puzzel),&n_p_data);


    gtk_box_pack_start(GTK_BOX (main_v_box),sudoku_tbl,FALSE,FALSE,10);


    gtk_box_pack_start(GTK_BOX (main_h_box),main_v_box,TRUE,FALSE,10);
    gtk_box_pack_start(GTK_BOX (main_h_box),v_controller_box,FALSE,FALSE,10);




    gtk_container_add(GTK_CONTAINER (vbox),main_h_box);
    gtk_container_add(GTK_CONTAINER(main_win),vbox);
    gtk_widget_show_all(main_win);

    gtk_main ();


    return 0 ;
}
