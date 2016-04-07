/*
** event.c for  in /home/bonett_w/Documents/rendu/ncurses/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Feb 28 12:42:44 2016 Walter Bonetti
** Last update Sun Feb 28 22:03:23 2016 Walter Bonetti
*/

#include "nsudoku.h"

void	list_input_event(t_nc_window *w)
{
  if (w->key >= 49 && w->key <= 57)
    {
      w->posy = (w->y - GRID_START_Y) / GRID_COL_DELTA;
      w->posx = (w->x - GRID_START_X) / GRID_LINE_DELTA;
      if (w->unsolved.tab[w->posx][w->posy] == 0)
	{
	  wattron(w->grid, COLOR_PAIR(3));
	  wprintw(w->grid, "%c", w->key);
	  wattroff(w->grid, COLOR_PAIR(3));
	  w->player.tab[w->posx][w->posy] = w->key - 48;
	}
    }
  if (w->key == KEY_DC || w->key == KEY_BACKSPACE
      || w->key == 127 || w->key == 'd')
    {
      w->posy = (w->y - GRID_START_Y) / GRID_COL_DELTA;
      w->posx = (w->x - GRID_START_X) / GRID_LINE_DELTA;
      if (w->unsolved.tab[w->posx][w->posy] == 0)
      {
	  w->player.tab[w->posx][w->posy] = 0;
	  wprintw(w->grid, EMPTY_SYMBOL);
      }
    }
}

void	listen_event(t_nc_window *w)
{
  (w->key == KEY_LEFT) ? ((w->x > 5) ? (w->x -= GRID_LINE_DELTA) : 0) : 0;
  (w->key == KEY_RIGHT) ? ((w->x < 34) ? (w->x += GRID_LINE_DELTA) : 0) : 0;
  (w->key == KEY_UP) ? ((w->y > 2) ? (w->y -= GRID_COL_DELTA) : 0) : 0;
  (w->key == KEY_DOWN) ? ((w->y < 17) ? (w->y += GRID_COL_DELTA) : 0) : 0;
  (w->key == 'r') ? reset_player(w) : 0;
  if (w->key == 'h')
    draw_fill_help(w);
  if (w->key == 's')
    check_is_okay(w);
  (w->key == 'n') ? reset_game(w) : 0;
  if (w->key == 'm')
    resolver_demo(w->unsolved.tab, w->unsolved.nb_void, w);
  (w->key == 'Q' || w->key == 27) ? (w->run = 0) : 0;
  if (w->key == KEY_RESIZE)
    {
      redrawwin(w->grid);
      redrawwin(w->infobox);
    }
  list_input_event(w);
}
