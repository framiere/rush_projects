/*
** clean.c for  in /home/bonett_w/Documents/rendu/ncurses/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Feb 28 12:44:18 2016 Walter Bonetti
** Last update Sun Feb 28 22:43:40 2016 Matthias RIGAUD
*/

#include "nsudoku.h"

void	cleanup(void)
{
  endwin();
}

int	reset_player(t_nc_window *win)
{
  int	col;
  int	row;

  row = 0;
  while (row < 9)
    {
      col = 0;
      while (col < 9)
	{
	  win->player.tab[col][row] = win->unsolved.tab[col][row];
	  col++;
	}
      row++;
    }
  draw_fill_grid(win);
  return (0);
}

int	reset_game(t_nc_window *win)
{
  win->help = 1;
  wclear(win->grid);
  mvwprintw(win->infobox, 8, 0, "            ");
  wrefresh(win->grid);
  app_load_map(win);
  maps_random(win);
  draw_grid(win);
  return (0);
}
