/*
** main.c for  in /home/bonett_w/Documents/rendu/ncurses/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sun Feb 28 09:51:35 2016 Walter Bonetti
** Last update Sun Feb 28 23:42:09 2016 Matthias RIGAUD
*/

#include "nsudoku.h"

int		main(int ac, char **av)
{
  t_nc_window	win;

  (void) av;
  (void) ac;
  srand(time(NULL));
  app_load_map(&win);
  maps_random(&win);
  app_game(&win);
  return (0);
}
