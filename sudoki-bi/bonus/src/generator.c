/*
** generator.c for  in /home/bonett_w/Documents/rendu/sudoki-bi/bonus/src/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Feb 28 21:59:51 2016 Walter Bonetti
** Last update Sun Feb 28 22:00:14 2016 Walter Bonetti
*/

#include "nsudoku.h"

void	maps_random(t_nc_window *win)
{
  int	col;
  int	row;
  int	rd;

  win->solved.nb_void = 80;
  win->solved.tab[0][0] = rand() % 9 + 1;
  resolver(win->solved.tab, win->solved.nb_void);
  row = 0;
  while (row < 9)
    {
      col = 0;
      rd = 2 + rand() % 2;
      while (col < 9)
	{
	  if (!(col % rd) | !((row + 1) % rd))
	    win->unsolved.tab[col][row] = win->solved.tab[col][row];
	  col++;
	}
      row++;
    }
}
