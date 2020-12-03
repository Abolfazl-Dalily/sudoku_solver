#include "virtual_keyboard.h"

void open_virtula_keyboard(GtkWidget *wid,gpointer *ptr){

    struct custom_data *c_data = ptr;

    const gchar *title  = "KeyBoard";
    GtkWidget *vir_keyboard = gtk_dialog_new_with_buttons(title,
        GTK_WINDOW(c_data->wid),
        GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,NULL);
        gtk_window_set_resizable(GTK_WINDOW(vir_keyboard),FALSE);
        GtkWidget *keys_tbl = gtk_table_new (3,3,TRUE);


    GtkWidget* keys_button[9];
    char str_counter[3];
    int j=0 ;
    for (int i=0; i<9 ; i++)
    {

        sprintf(str_counter,"%d",i+1);
        // TODO (abolfazl#1#): improve int to str function !

        keys_button[i] = gtk_button_new_with_label(str_counter);
        gtk_widget_set_size_request(keys_button[i],50,50);

        gtk_table_attach_defaults (GTK_TABLE (keys_tbl),keys_button[i],i%3,(i%3)+1,j,j+1);
        j = ((i+1)%3 == 0 ) ? j+1 : j ;

    }

    GtkWidget *cancel_btn = gtk_button_new_with_label("Cancel");
    gtk_container_add(GTK_CONTAINER(gtk_dialog_get_content_area(GTK_DIALOG(vir_keyboard))),keys_tbl);
    gtk_container_add(GTK_CONTAINER(gtk_dialog_get_content_area(GTK_DIALOG(vir_keyboard))),cancel_btn);
    gtk_widget_show_all(vir_keyboard);


    // Add Response To Keys !
    struct virtual_keyboard_response v_k_r[10];
    v_k_r[0].id = 0;
    v_k_r[0].wid = vir_keyboard;
    for (int i = 1 ; i<=9; i++)
    {
        v_k_r[i].id = i;
        v_k_r[i].wid = vir_keyboard;
    }
    for (int i = 0 ; i<9 ; i++)
    {
        g_signal_connect(GTK_OBJECT(keys_button[i]),"clicked",G_CALLBACK(emit_virtual_keyboard_response),&v_k_r[i+1]);
    }
    g_signal_connect(GTK_OBJECT(cancel_btn),"clicked",G_CALLBACK(emit_virtual_keyboard_response),&v_k_r[0]);



    int res = gtk_dialog_run(GTK_DIALOG(vir_keyboard));

    switch(res)
    {
        case 0 :
            gtk_button_set_label(c_data->btn,"");
//            printf("0\n");
            break;
        case 1 :
            gtk_button_set_label(c_data->btn,"1");
//            printf("1\n");
            break;
        case 2 :
            gtk_button_set_label(c_data->btn,"2");
//            printf("2\n");
            break;
        case 3 :
            gtk_button_set_label(c_data->btn,"3");
//            printf("3\n");
            break;
        case 4 :
            gtk_button_set_label(c_data->btn,"4");
//            printf("4\n");
            break;
        case 5 :
            gtk_button_set_label(c_data->btn,"5");
//            printf("5\n");
            break;
        case 6 :
            gtk_button_set_label(c_data->btn,"6");
//            printf("6\n");
            break;
        case 7 :
            gtk_button_set_label(c_data->btn,"7");
//            printf("7\n");
            break;
        case 8 :
            gtk_button_set_label(c_data->btn,"8");
//            printf("8\n");
            break;
        case 9 :
            gtk_button_set_label(c_data->btn,"9");
//            printf("9\n");
            break;
        default :
            printf("Unknown response ! \n");
            break ;

    }

    gtk_widget_destroy(vir_keyboard);

}

void emit_virtual_keyboard_response(GtkWidget* wid,gpointer* ptr)
{
    struct virtual_keyboard_response *v_k_r = ptr;
    gtk_dialog_response(v_k_r->wid,v_k_r->id);
}
