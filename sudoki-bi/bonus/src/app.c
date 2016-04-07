/*
** app.c for  in /home/bonett_w/Documents/rendu/sudoki-bi/bonus/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Feb 28 22:00:07 2016 Walter Bonetti
** Last update Sun Feb 28 22:00:10 2016 Walter Bonetti
*/

#include "nsudoku.h"

void	app_game(t_nc_window *win)
{
  init_nrcuses();
  init_windows(win);
  srand(time(NULL));
  refresh();
  wrefresh(win->grid);
  wrefresh(win->infobox);
  win->x = GRID_START_X;
  win->y = GRID_START_Y;
  wmove(win->grid, win->y, win->x);
  init_game_loop(win);
}

void	app_load_map(t_nc_window *win)
{
  int	row;
  int	col;

  row = 0;
  while (row < 9)
    {
      col = 0;
      while (col < 9)
	{
	  win->unsolved.tab[col][row] = 0;
	  win->solved.tab[col][row] = 0;
	  win->player.tab[col][row] = 0;
	  col++;
	}
      row++;
    }
}
