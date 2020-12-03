#include "new_puzzel.h"

void new_puzzel(GtkWidget *wid , gpointer *ptr)
{
	struct new_p_data *n_p_data = ptr ;
	for (int i=0;i<9;i++)
	{
        for(int j=0;j<9;j++)
        {
            gtk_button_set_label(n_p_data->puzzel[i][j],"");
        }
	}
}
