##
## Makefile for Makefile in /home/oem/home/PSU_2015_minitalk
## 
## Made by OEM Configuration (temporary user)
## Login   <oem@epitech.net>
## 
## Started on  Mon Feb  8 08:55:53 2016 OEM Configuration (temporary user)
## Last update Tue Feb  9 11:08:38 2016 OEM Configuration (temporary user)
##

CC = gcc

RM = rm -f

SRC1 = ./server/server.c \
       ./server/my_put_nbr.c

SRC2 = ./client/client.c \
       ./client/my_put_nbr.c \
       ./client/my_getnbr.c

NAME1 = ./server/server

NAME2 = ./client/client

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)	


$(NAME1): $(OBJ1) $(NAME2)
	$(CC) $(OBJ1) -o $(NAME1)

$(NAME2): $(OBJ2)
	$(CC) $(OBJ2) -o $(NAME2)

all: $(NAME1) $(NAME2)

clean:
	$(RM) $(OBJ1) $(OBJ2)

fclean: clean
	$(RM) $(OBJ1) $(OBJ2) $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re
