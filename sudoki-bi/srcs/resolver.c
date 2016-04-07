/*
** resolver.c for sudoki-bi in /home/rigaud_b/rendu/sudoki-bi/srcs
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Fri Feb 26 20:55:00 2016 Matthias RIGAUD
** Last update Sun Feb 28 16:53:42 2016 Matthias RIGAUD
*/

#include <sudoki-bi.h>

void		get_case_tab(int (*sudoku)[9], int i, int j, int (*c)[9])
{
  register int   i2;
  register int   j2;

  memset(c, 1, 9 * sizeof(int));
  i2 = -1;
  while (++i2 < 9)
    {
      if (sudoku[i2][j])
	(*c)[sudoku[i2][j] - 1] = 0;
      if (sudoku[i][i2])
	(*c)[sudoku[i][i2] - 1] = 0;
    }
  i = i / 3 * 3;
  j = j / 3 * 3;
  i2 = i - 1;
  while (++i2 < i + 3)
    {
      j2 = j - 1;
      while (++j2 < j + 3)
	if (sudoku[i2][j2])
	  (*c)[sudoku[i2][j2] - 1] = 0;
    }
}

int		resolver_rec(int **nb_case, int (*sudoku)[9], int nb_void)
{
  register int	i;
  int		c[9];

  get_case_tab(sudoku, (*nb_case)[1], (*nb_case)[2], &c);
  i = 9;
  while (--i >= 0)
    if (c[i])
      {
	sudoku[(*nb_case)[1]][(*nb_case)[2]] = i + 1;
	if (nb_void == 1 || resolver_rec(&nb_case[1], sudoku, nb_void - 1))
	  return (1);
      }
  sudoku[(*nb_case)[1]][(*nb_case)[2]] = 0;
  return (0);
}

int		resolver(int (*sudoku)[9], int nb_void)
{
  register int	i;
  int		**nb_case;
  int		resolvable;

  nb_case = get_nb_case(sudoku, nb_void);
  case_sorter(&nb_case, nb_void);
  resolvable = resolver_rec(nb_case, sudoku, nb_void);
  i = -1;
  while (++i < nb_void)
    free(nb_case[i]);
  free(nb_case);
  return (resolvable);
}
