/*
** parser.h for  in /home/bonett_w/Documents/rendu/sudoki-bi/include/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Fri Feb 26 21:07:16 2016 Walter Bonetti
** Last update Sat Feb 27 14:17:56 2016 Walter Bonetti
*/

#ifndef PARSER_H_
# define PARSER_H_

# define _GNU_SOURCE
# include <stdio.h>
# include <string.h>
# include <regex.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

# define ERR_LINE_SIZE 2
# define REGEX_PARSER "^[|](([ ][1-9])+||([ ][ ]))+[|]$"
# define REGEX_PARSER_HEAD "^[|][-]+[|]$"

typedef struct	s_sudoku
{
 int		tab[9][9];
 int		nb_void;
 int		valid;
}		t_sudoku;

typedef struct	s_params
{
  regex_t	line;
  regex_t	head;
}		t_params;

typedef struct		s_node
{
  t_sudoku		sudoku;
  struct s_node		*next;
}			t_node;

typedef struct	s_list
{
  struct	s_node	*first;
  struct	s_node	*last;
  int		nb_element;
}		t_list;

void	list_init(t_list *list);
void	list_push(t_list *list, t_sudoku *sudoku);
t_node	*list_pop(t_list *list);
int	list_is_empty(t_list *list);

int	put_line_tab(t_sudoku *sudoku, char *line, int nb_line);
int	parser(t_params *params, t_sudoku *sudoku);
int	parser_init(t_list *list);
int	check(char *str, regex_t *regex);
int	regex_compilation(regex_t *regex, char *pattern);
void	regex_set_all(regex_t *a, regex_t *b, char *pattrn_a, char *pattrn_b);
void	regex_free_all(regex_t *a, regex_t *b);

#endif /* !PARSER_H_ */
