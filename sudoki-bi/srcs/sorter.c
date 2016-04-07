/*
** sorter.c for sudoki-bi in /home/rigaud_b/rendu/sudoki-bi/srcs
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Fri Feb 26 23:23:11 2016 Matthias RIGAUD
** Last update Sat Feb 27 16:46:51 2016 Walter Bonetti
*/

#include <sudoki-bi.h>

void	swap(int ***nb_case, int a, int b)
{
  int	tmp[3];

  tmp[0] = (*nb_case)[a][0];
  tmp[1] = (*nb_case)[a][1];
  tmp[2] = (*nb_case)[a][2];
  (*nb_case)[a][0] = (*nb_case)[b][0];
  (*nb_case)[a][1] = (*nb_case)[b][1];
  (*nb_case)[a][2] = (*nb_case)[b][2];
  (*nb_case)[b][0] = tmp[0];
  (*nb_case)[b][1] = tmp[1];
  (*nb_case)[b][2] = tmp[2];
}

void		case_sorter(int ***nb_case, int nb_void)
{
  register int	i;
  register int	j;
  register int	min;

  i = -1;
  while (++i < nb_void)
    {
      j = i - 1;
      min = i;
      while (++j < nb_void)
	if ((*nb_case)[j][0] < (*nb_case)[min][0])
	  min = j;
      swap(nb_case, i, min);
    }
}
