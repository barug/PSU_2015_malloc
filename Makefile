##
## Makefile for MallocMakefile in /home/dupard_e/rendus/PSU_2015_malloc
## 
## Made by Erwan Dupard
## Login   <dupard_e@epitech.net>
## 
## Started on  Tue Jan 26 23:48:36 2016 Erwan Dupard
## Last update Wed Feb  3 17:45:13 2016 Erwan Dupard
##

CC		= gcc

RM		= rm -f

NAME		= libmy_malloc.so

SRCS		= malloc.c		\
		  free.c		\
		  show_alloc_mem.c	\
		  memory_dump.c		\
	 	  realloc.c		\

OBJS		= $(SRCS:.c=.o)

CFLAGS		+= -g3 -fPIC -Wall -Werror -Wextra

LDFLAGS		+= -shared

all: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
