/*
** check.c for  in /home/bonett_w/Documents/rendu/sudoki-bi/bonus/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Feb 28 18:33:29 2016 Walter Bonetti
** Last update Sun Feb 28 22:39:54 2016 Matthias RIGAUD
*/

#include "nsudoku.h"

int	notification_color(t_nc_window *win, char *message, int color)
{
  wattron(win->grid, A_BOLD | COLOR_PAIR(color));
  mvwprintw(win->infobox, 8, 0, message);
  wattroff(win->grid, A_BOLD | COLOR_PAIR(color));
  return (0);
}

int	check_is_okay(t_nc_window *window)
{
  int	row;
  int	col;
  int	win;

  row = 0;
  win = 1;
  while (row < 9)
    {
      col = 0;
      while (col < 9)
	{
	  if (window->unsolved.tab[col][row] == 0)
	    {
	      if (window->solved.tab[col][row] != window->player.tab[col][row]
		  && !(win = 0))
		return (notification_color(window, "Grid Invalid", 2));
	    }
	  col++;
	}
      row++;
    }
  if (win)
    notification_color(window, "Grid Valid  ", 4);
  return (0);
}
