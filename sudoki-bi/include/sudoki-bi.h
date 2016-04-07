/*
** sudoki-bi.h for sudoki-bi in /home/rigaud_b/rendu/sudoki-bi/include
**
** Made by Matthias RIGAUD
** Login   <rigaud_b@epitech.eu>
**
** Started on  Fri Feb 26 20:49:30 2016 Matthias RIGAUD
** Last update Sun Feb 28 22:14:55 2016 Walter Bonetti
*/

#ifndef SUDOKI_BI_H_
# define SUDOKI_BI_H_

/*
** Include
*/

# define _GNU_SOURCE
# include <stdio.h>
# include <stdlib.h>
# include "parser.h"

# define A s->tab
# define B sudoku->tab
# define C(a, b) s->tab[a][b]

/*
** Functions
*/

int	resolver(int (*sudoku)[9], int nb_void);
void	my_puterror(char *str, int n_exit);
int	**get_nb_case(int (*sudoku)[9], int nb_void);
void	get_case_tab(int (*sudoku)[9], int i, int j, int (*c)[9]);
void	case_sorter(int ***nb_case, int nb_void);
void	affichage_sudoku(t_sudoku *s);
void	affichage_unsolve();

#endif /* !SUDOKI_BI_H_ */
