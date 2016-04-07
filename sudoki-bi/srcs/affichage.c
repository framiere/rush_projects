/*
** affichage.c for  in /home/bonett_w/Documents/rendu/sudoki-bi/srcs/
**
** Made by Walter Bonetti
** Login   <bonett_w@epitech.eu>
**
** Started on  Sat Feb 27 09:52:41 2016 Walter Bonetti
** Last update Sat Feb 27 14:32:58 2016 Walter Bonetti
*/

#include <sudoki-bi.h>

void	affichage_sudoku(t_sudoku *s)
{
  fprintf(stdout, "|------------------|\n");
  fprintf(stdout, "| %d %d %d %d %d %d %d %d %d|\n", A[0][0], A[0][1], A[0][2]
	  , A[0][3], A[0][4], A[0][5], A[0][6], A[0][7], A[0][8]);
  fprintf(stdout, "| %d %d %d %d %d %d %d %d %d|\n", A[1][0], A[1][1], A[1][2]
	  , A[1][3], A[1][4], A[1][5], A[1][6], A[1][7], A[1][8]);
  fprintf(stdout, "| %d %d %d %d %d %d %d %d %d|\n", A[2][0], A[2][1], A[2][2]
	  , A[2][3], A[2][4], A[2][5], A[2][6], A[2][7], A[2][8]);
  fprintf(stdout, "| %d %d %d %d %d %d %d %d %d|\n", A[3][0], A[3][1], A[3][2]
	  , A[3][3], A[3][4], A[3][5], A[3][6], A[3][7], A[3][8]);
  fprintf(stdout, "| %d %d %d %d %d %d %d %d %d|\n", A[4][0], A[4][1], A[4][2]
	  , A[4][3], A[4][4], A[4][5], A[4][6], A[4][7], A[4][8]);
  fprintf(stdout, "| %d %d %d %d %d %d %d %d %d|\n", A[5][0], A[5][1], A[5][2]
	  , A[5][3], A[5][4], A[5][5], A[5][6], A[5][7], A[5][8]);
  fprintf(stdout, "| %d %d %d %d %d %d %d %d %d|\n", A[6][0], A[6][1], A[6][2]
	  , A[6][3], A[6][4], A[6][5], A[6][6], A[6][7], A[6][8]);
  fprintf(stdout, "| %d %d %d %d %d %d %d %d %d|\n", A[7][0], A[7][1], A[7][2]
	  , A[7][3], A[7][4], A[7][5], A[7][6], A[7][7], A[7][8]);
  fprintf(stdout, "| %d %d %d %d %d %d %d %d %d|\n", A[8][0], A[8][1], A[8][2],
	  A[8][3], A[8][4], A[8][5], A[8][6], A[8][7], A[8][8]);
  fprintf(stdout, "|------------------|\n");
}

void	affichage_unsolve()
{
  fprintf(stdout,
	  "|------------------|\n"
	  "| X X X X X X X X X|\n"
	  "| X X X X X X X X X|\n"
	  "| X X X X X X X X X|\n"
	  "| X X X X X X X X X|\n"
	  "| X X X X X X X X X|\n"
	  "| X X X X X X X X X|\n"
	  "| X X X X X X X X X|\n"
	  "| X X X X X X X X X|\n"
	  "| X X X X X X X X X|\n"
	  "|------------------|\n");
}
