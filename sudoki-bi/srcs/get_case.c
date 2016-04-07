/*
** get_case.c for sudoki-bi in /home/rigaud_b/rendu/sudoki-bi
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Fri Feb 26 23:21:08 2016 Matthias RIGAUD
** Last update Sun Feb 28 02:25:49 2016 Matthias RIGAUD
*/

#include <sudoki-bi.h>

int     get_case(int (*sudoku)[9], int i, int j)
{
  int   i2;
  int   j2;
  int   c[9];

  memset(&c, 1, 9 * sizeof(int));
  i2 = -1;
  while (++i2 < 9)
    {
      if (sudoku[i2][j])
	c[sudoku[i2][j] - 1] = 0;
      if (sudoku[i][i2])
	c[sudoku[i][i2] - 1] = 0;
    }
  i = i / 3 * 3;
  j = j / 3 * 3;
  i2 = i - 1;
  while (++i2 < i + 3 && (j2 = j - 1) >= 0)
    while (++j2 < j + 3)
      if (sudoku[i2][j2])
	c[sudoku[i2][j2] - 1] = 0;
  return (c[0] + c[1] + c[2] + c[3] + c[4] + c[5] + c[6] + c[7] + c[8]);
}

int     **get_nb_case(int (*sudoku)[9], int nb_void)
{
  int   i;
  int   j;
  int   v;
  int   **nb_case;

  i = -1;
  v = 0;
  if (!(nb_case = malloc(nb_void * sizeof(int *))))
    my_puterror("Error Malloc", 1);
  while (++i < 9)
    {
      j = -1;
      while (++j < 9)
	if (!sudoku[i][j])
	  {
	    if (!(nb_case[v] = malloc(3 * sizeof(int))))
	      my_puterror("Error Malloc", 1);
	    nb_case[v][0] = get_case(sudoku, i, j);
	    nb_case[v][1] = i;
	    nb_case[v++][2] = j;
	  }
    }
  return (nb_case);
}
