##
## Makefile for  in /home/bonett_w/Documents/rendu/ncurses/
##
## Made by Walter Bonetti
## Login   <bonett_w@epitech.eu>
##
## Started on  Sun Feb 28 09:49:27 2016 Walter Bonetti
## Last update Sun Feb 28 22:51:02 2016 Matthias RIGAUD
##

CC	=	gcc -g

RM	=	rm -f

SRC	=	src/main.c \
		src/init.c \
		src/clean.c \
		src/event.c \
		src/draw.c \
		src/check.c \
		src/generator.c \
		src/app.c \
		src/demo.c \
		../srcs/get_case.c \
		../srcs/get_next_line.c \
		../srcs/list.c \
		../srcs/parser.c \
		../srcs/puterror.c \
		../srcs/regex.c \
		../srcs/resolver.c \
		../srcs/sorter.c

OBJ	=	$(SRC:.c=.o)

NAME	=	sudoki-bi

FLAG	=	-Wall -W -Werror -I./../include -I./include

LIB	=	-lncurses

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIB) -o $(NAME)
	@echo -e "\e[32mAll done !\e[39m"

clean:
	@echo -n "Cleaning .o files..."
	@$(RM) $(OBJ)
	@echo -e "\t [\e[32mOk !\e[39m]"
	@echo -e "\e[32mAll done !\e[39m"

fclean:	clean
	@echo -n "Cleaning executable..."
	@$(RM) $(NAME)
	@echo -e "\t [\e[32m0k !\e[39m]"


re: fclean all

.c.o: %.c
	@echo -e "\e[32m->\e[39m" $<
	@$(CC) -c $< -o $@ $(FLAG)

.PHONY: all re fclean clean
