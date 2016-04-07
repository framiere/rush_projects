/*
** init.c for  in /home/bonett_w/Documents/rendu/ncurses/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Feb 28 12:41:13 2016 Walter Bonetti
** Last update Sun Feb 28 23:34:07 2016 Matthias RIGAUD
*/

#include "nsudoku.h"

void	init_nrcuses(void)
{
  initscr();
  clear();
  atexit(cleanup);
  cbreak();
  noecho();
  if (has_colors())
    {
      start_color();
      init_pair(1, COLOR_BLUE, COLOR_BLACK);
      init_pair(2, COLOR_RED, COLOR_BLACK);
      init_pair(3, COLOR_CYAN, COLOR_BLACK);
      init_pair(4, COLOR_GREEN, COLOR_BLACK);
    }
  else
    {
      printw("Your terminal doesn't support colors.\n");
      getch();
      exit(EXIT_FAILURE);
    }
}

void	init_windows(t_nc_window *window)
{
  keypad(stdscr, true);
  window->status = newwin(STATUS_LINES, STATUS_COLS, STATUS_Y, STATUS_X);
  window->grid = newwin(GRID_LINES, GRID_COLS, GRID_Y, GRID_X);
  draw_grid(window);
  window->infobox = newwin(STATS_LINES, STATS_COLS, STATS_Y, STATS_X);
  wbkgd(window->infobox, COLOR_PAIR(2));
  wattron(window->infobox, A_BOLD | COLOR_PAIR(2));
  wprintw(window->infobox, "Sudoki\n");
  wattroff(window->infobox, A_BOLD | COLOR_PAIR(2));
  wattron(window->infobox, COLOR_PAIR(1));
  wprintw(window->infobox, "Delete input [BS-d]\n");
  wprintw(window->infobox, "New Game     [n]\n");
  wprintw(window->infobox, "Solve        [s]\n");
  wprintw(window->infobox, "Reset        [r]\n");
  wprintw(window->infobox, "Help         [h]\n");
  wprintw(window->infobox, "Backtracking [m]\n");
  wprintw(window->infobox, "Quit         [ESC-Q]\n");
  wattroff(window->infobox, COLOR_PAIR(1));
}

void	init_game_loop(t_nc_window *window)
{
  window->run = 1;
  window->help = 1;
  while (window->run == 1)
    {
      refresh();
      wrefresh(window->grid);
      window->key = getch();
      werase(window->status);
      listen_event(window);
      wmove(window->grid, window->y, window->x);
      refresh();
      wrefresh(window->status);
      wrefresh(window->grid);
      wrefresh(window->infobox);
    }
}
