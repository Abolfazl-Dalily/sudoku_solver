#include "sudoku_solver.h"

void solve_sudoku(GtkWidget *wid , gpointer *ptr)
{
	int x , y ;
	gchar *btn_text;
	int puzzel[9][9];
	char str[2];

	struct solve_data *s_data = ptr ;

	for (int i=0;i<9;i++)
	{
        for(int j=0; j<9; j++)
        {
             btn_text = gtk_button_get_label(s_data->puzzel[i][j]);
             if (strlen(btn_text) == 0)
             {
                puzzel[i][j]= 0 ;
             }
             else
             {
                sscanf(btn_text, "%d", &puzzel[i][j]);


             }

        }
	}
	if (solve(puzzel))
    {
        for (int i=0;i<9;i++)
        {
            for(int j=0 ; j<9;j++)
            {
                sprintf(str, "%d", puzzel[i][j]);
                gtk_button_set_label(s_data->puzzel[i][j],str);
//                printf("%d,",puzzel[i][j]);
            }
            // printf("\n");
        }
    }
    else
    {
        show_error(s_data->main_wid);
        printf("I Can not solve it ! wow ... \n");
    }

}
//
char find_free(int (*puzzel)[9],int *x , int *y)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (puzzel[i][j] == 0){
				*x = i ;
				*y = j ;
				return 1 ;
			}
		}

	}
	return 0 ;
}
//
char is_valid(int (*puzzel)[9],int n , int x , int y)
{
	for (int i= 0 ; i<9 ; i++)
	{
		if (puzzel[x][i] == n || puzzel[i][y] == n)
			return 0 ;
	}
	int x_square = (x/3)*3;
	int y_square = (y/3)*3;
	for (int i=x_square ; i<x_square+3;i++)
	{
		for(int j=y_square; j<y_square+3;j++)
		{
			if(puzzel[i][j] == n )
			{
				return 0 ;
			}
		}
	}
	return 1 ;
}

int solve(int (*puzzel)[9])
{
	int x , y ;
	if (find_free(puzzel,&x,&y)==0)
	{
		return 1 ;
	}
	for (int i =1 ; i<=9;i++)
	{
		if(is_valid(puzzel,i,x,y))
		{
			puzzel[x][y] = i  ;
			if (solve(puzzel))
			{
				return 1 ;
			}
			puzzel[x][y] = 0 ;
		}
	}
	return 0 ;
}
void show_error(gpointer *window) {

  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(GTK_WINDOW(window),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_ERROR,
            GTK_BUTTONS_OK,
            "Sorry ! Your Sudoku Puzzel Is Invalid \nCan Not Solve It !");
  gtk_window_set_title(GTK_WINDOW(dialog), "Error");
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}
