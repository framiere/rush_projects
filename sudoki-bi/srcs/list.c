/*
** list.c for  in /home/bonett_w/Documents/rendu/sudoki-bi/srcs/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sat Feb 27 10:51:23 2016 Walter Bonetti
** Last update Sat Feb 27 21:04:15 2016 Matthias RIGAUD
*/

#include "sudoki-bi.h"

void	list_init(t_list *list)
{
  list->first = NULL;
  list->last = NULL;
  list->nb_element = 0;
}

void		list_push(t_list *list, t_sudoku *sudoku)
{
  t_node	*tmp;

  tmp = NULL;
  if (list->first == NULL && list->last == NULL
      && (list->first = malloc(sizeof(t_node))) == NULL)
    my_puterror("Erreur Malloc", -1);
  else if ((list->last) != NULL
	   && (tmp = malloc(sizeof(t_node))) == NULL)
    my_puterror("Erreur Malloc", -1);
  if (tmp)
    {
      list->last->next = tmp;
      list->last = tmp;
    }
  else
    {
      list->last = list->first;
    }
  list->last->sudoku = *sudoku;
  list->nb_element++;
}

t_node		*list_pop(t_list *list)
{
  t_node	*tmp;

  if (list_is_empty(list))
    return (NULL);
  tmp = list->first;
  list->first = list->first->next;
  list->nb_element--;
  return (tmp);
}

int	list_is_empty(t_list *list)
{
  return (list->nb_element <= 0);
}
