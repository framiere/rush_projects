/*
** draw.c for  in /home/bonett_w/Documents/rendu/ncurses/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Feb 28 12:43:31 2016 Walter Bonetti
** Last update Sun Feb 28 21:17:05 2016 Walter Bonetti
*/

#include "nsudoku.h"

void	draw_concat(t_nc_window *w, int *i, int *j)
{
  while (++(*j) < 10)
    {
      if (*i % 3 == 0)
	wattron(w->grid, A_BOLD | COLOR_PAIR(2));
      if (*j % 3 == 0)
	wattron(w->grid, A_BOLD | COLOR_PAIR(2));
      wprintw(w->grid, GRID_SYMBOLE_DELIM);
      if ((*j % 3 == 0) && (*i % 3 != 0))
	wattron(w->grid, A_BOLD | COLOR_PAIR(1));
      if (*j < 9)
	wprintw(w->grid, GRID_SYMBOLE_MIDDLE);
      if ((*i % 3 == 0))
	wattron(w->grid, A_BOLD | COLOR_PAIR(1));
    }
}

void	draw_symbole(t_nc_window *w, int *i, int *j)
{
  while (++(*j) < 10 && *i < 9)
    {
      if ((*j % 3 == 0))
	wattron(w->grid, A_BOLD | COLOR_PAIR(2));
      if (*j > 0)
	wprintw(w->grid, GRID_SYMBOLE_CONTACT_E);
      else
	wprintw(w->grid, GRID_SYMBOLE_CONTACT_S);
      if ((*j % 3 == 0))
	wattron(w->grid, A_BOLD | COLOR_PAIR(1));
    }
}

void	draw_fill_help(t_nc_window *w)
{
  int	row;
  int	col;
  int	x;
  int	y;

  ((y = GRID_START_Y) || 1) ? row = -1 : 0;
  while (++row < 9)
    {
      ((x = GRID_START_X) || 1) ? (col = -1) : 0;
      while (++col < 9)
	{
	  if (w->unsolved.tab[col][row] == 0)
	    {
	      wattron(w->grid, A_BOLD | COLOR_PAIR(4));
	      if (w->help)
		mvwprintw(w->grid, y, x + 1, "%d", w->solved.tab[col][row]);
	      else
		mvwprintw(w->grid, y, x + 1, " ");
	      wattroff(w->grid, A_BOLD | COLOR_PAIR(4));
	    }
	  x += GRID_LINE_DELTA;
	}
      y += GRID_COL_DELTA;
    }
  w->help = !w->help;
}

void	draw_fill_grid(t_nc_window *w)
{
  int	row;
  int	col;
  int	x;
  int	y;
  int	c;

  wstandend(w->grid);
  y = GRID_START_Y;
  row = -1;
  while (++row < 9)
    {
      x = GRID_START_X;
      col = -1;
      while (++col < 9)
	{
	  c = w->unsolved.tab[col][row];
	  if (c == 0)
	    mvwprintw(w->grid, y, x, EMPTY_SYMBOL);
	  else
	    mvwprintw(w->grid, y, x, "%d", c);
	  x += GRID_LINE_DELTA;
	}
      y += GRID_COL_DELTA;
    }
}

void	draw_grid(t_nc_window *w)
{
  int	i;
  int	j;

  i = -1;
  while (++i < 10)
    {
      j = -1;
      draw_concat(w, &i, &j);
      j = -1;
      draw_symbole(w, &i, &j);
    }
  draw_fill_grid(w);
}
