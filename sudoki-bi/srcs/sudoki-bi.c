/*
** sudoki-bi.c for sudoki-bi in /home/rigaud_b/rendu/sudoki-bi/srcs
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Fri Feb 26 20:52:01 2016 Matthias RIGAUD
** Last update Sat Feb 27 21:11:38 2016 Matthias RIGAUD
*/

#include <sudoki-bi.h>

int		main()
{
  t_list	list;
  t_node	*node;

  list_init(&list);
  parser_init(&list);
  while ((node = list_pop(&list)))
    {
      if (node->sudoku.valid)
	{
	  if (resolver(node->sudoku.tab, node->sudoku.nb_void))
	    affichage_sudoku(&node->sudoku);
	  else
	    affichage_unsolve();
	}
      else
	affichage_unsolve();
      (list.nb_element > 0) ? fprintf(stdout, "####################\n") : 0;
      free(node);
    }
  return (0);
}
