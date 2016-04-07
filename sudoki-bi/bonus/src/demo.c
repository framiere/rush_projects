/*
** demo.c for nsudoki-bi in /home/rigaud_b/rendu/sudoki-bi/bonus/src
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Sun Feb 28 19:17:24 2016 Matthias RIGAUD
** Last update Sun Feb 28 23:31:59 2016 Matthias RIGAUD
*/

#include <nsudoku.h>

void	errasor(t_nc_window *win, int **nb_case, int (*sudoku)[9])
{
  sudoku[(*nb_case)[1]][(*nb_case)[2]] = 0;
  refresh();
  wrefresh(win->grid);
  werase(win->status);
  mvprintw(((*nb_case)[2] - 1) * 2 + 6, ((*nb_case)[1] - 1) * 4 + 34,
	   " ");
  wrefresh(win->status);
  wrefresh(win->grid);
  wrefresh(win->infobox);
}

void	puttor(int **nb_case, int i)
{
  attron(COLOR_PAIR(42));
  mvprintw(((*nb_case)[2] - 1) * 2 + 6, ((*nb_case)[1] - 1) * 4 + 34,
	   "%i", i + 1);
  attroff(COLOR_PAIR(42));
}

int		nresolver_rec(int		**nb_case,
			      int		(*sudoku)[9],
			      int		nb_void,
			      t_nc_window	*win)
{
  register int	i;
  int		c[9];

  usleep(50000);
  get_case_tab(sudoku, (*nb_case)[1], (*nb_case)[2], &c);
  i = 9;
  while (--i >= 0)
    if (c[i])
      {
	refresh();
	wrefresh(win->grid);
	werase(win->status);
	init_pair(42, COLOR_GREEN, COLOR_BLACK);
	puttor(nb_case, i);
	wrefresh(win->status);
	wrefresh(win->grid);
	wrefresh(win->infobox);
	sudoku[(*nb_case)[1]][(*nb_case)[2]] = i + 1;
	if (nb_void == 1 || nresolver_rec(&nb_case[1], sudoku,
					  nb_void - 1, win))
	  return (1);
      }
  errasor(win, nb_case, sudoku);
  return (0);
}

void		resolver_demo(int (*sudoku)[9], int nb_void, t_nc_window *win)
{
  register int	i;
  register int	j;
  int		**nb_case;

  nb_void = 0;
  i = -1;
  while (++i < 9 && (j = -1))
    while (++j < 9)
      if (!sudoku[i][j])
	nb_void++;
  nb_case = get_nb_case(sudoku, nb_void);
  case_sorter(&nb_case, nb_void);
  nresolver_rec(nb_case, sudoku, nb_void, win);
  i = -1;
  while (++i < nb_void)
    free(nb_case[i]);
  free(nb_case);
}
