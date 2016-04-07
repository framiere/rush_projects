##
## Makefile for sudoki-bi in /home/rigaud_b/rendu/sudoki-bi
##
## Made by Matthias RIGAUD
## Login   <rigaud_b@epitech.net>
##
## Started on  Fri Feb 26 20:47:25 2016 Matthias RIGAUD
## Last update Sat Feb 27 17:33:22 2016 Walter Bonetti


RM		= rm -f

CC		= gcc

NAME		= bin/sudoki-bi

SRCS		= srcs/sudoki-bi.c \
		srcs/parser.c \
		srcs/get_next_line.c \
		srcs/resolver.c \
		srcs/puterror.c \
		srcs/regex.c \
		srcs/affichage.c \
		srcs/get_case.c \
		srcs/list.c \
		srcs/sorter.c

OBJS		= $(SRCS:.c=.o)

SHEETIES	= $(OBJS) \
		$(SRCS:.c=.c~) \
		Makefile~

CFLAGS		= -W -Wall -Wextra -Werror -Iinclude

all:		$(NAME)

$(NAME):	$(OBJS)
		rm -rf bin
		mkdir bin
		@echo -e "\e[0m"
		@$(CC) $(OBJS) $(LIB) -o $(NAME)
		@echo -e "\e[32mAll done ! ==>\e[33m" $(NAME) "\e[32mcreat !\e[0m"

clean:
		@echo -en "\e[0mCleaning .o && .c~ files..."
		@$(RM) $(SHEETIES)
		@echo -e "	 [\e[32mOk !\e[0m]"

fclean:		clean
		@echo -en "\e[39mCleaning executable..."
		@$(RM) $(NAME)
		@echo -e "		 [\e[32m0k !\e[0m]"

re:		fclean all

comp:		re
		@echo -en "\e[0mCleaning .o && .c~ files..."
		@$(RM) $(SHEETIES)
		@echo -e "	 [\e[32mOk !\e[0m]"

.c.o:		%.c
		@$(CC) -c $< -o $@ $(CFLAGS) && \
		echo -e "\e[32m[OK]" $< "\e[93m"|| \
		echo -e "\e[91;5m[ERR]\e[25m" $< "\e[93m"

.PHONY:		all clean fclean re comp
