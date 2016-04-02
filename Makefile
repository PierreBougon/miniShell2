##
## Makefile for MINISHELL in /home/bougon_p/rendu/PSU_2015_minisell2
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Mon Mar 28 11:55:21 2016 bougon_p
## Last update Fri Apr  1 20:50:48 2016 bougon_p
##

# USEFUL VARIABLES

RM      =	rm -rf

GREEN	=	\033[1;32m

WHITE	=	\033[0m

ECHO	=	echo -e


# MINISHELL VARIABLES

MAIN		=	src/main/

BUILTIN		=	src/builtin/

TOOLS		=	src/tools/

FREE		=	src/free/

SRC		=	$(MAIN)main.c \
			$(MAIN)cmd.c \
			$(MAIN)err.c \
			$(TOOLS)init.c \
			$(TOOLS)epur.c \
			$(TOOLS)get_var.c \
			$(FREE)free_tab.c \
			$(BUILTIN)cd.c \
			$(BUILTIN)setenv.c \
			$(BUILTIN)unsetenv.c \
			$(BUILTIN)env.c \
			$(BUILTIN)exit.c \
			$(BUILTIN)builtins.c \

OBJS    	=	$(SRC:.c=.o)


# LIBRARY VARIABLES

LIBPATH =       lib/

LIB	=	lib/libmy.a

SRCLIB	=	$(LIBPATH)my/get_next_line.c \
		$(LIBPATH)my/my_getnbr.c \
		$(LIBPATH)my/my_power_rec.c \
		$(LIBPATH)my/my_putchar.c \
		$(LIBPATH)my/my_put_nbr.c \
		$(LIBPATH)my/my_putstr.c \
		$(LIBPATH)my/my_revstr.c \
		$(LIBPATH)my/my_strcmp.c \
		$(LIBPATH)my/my_strcat.c \
		$(LIBPATH)my/my_strdup.c \
		$(LIBPATH)my/my_strlen.c \
		$(LIBPATH)my/my_strcpy.c \
		$(LIBPATH)my/my_bzero.c \
		$(LIBPATH)my/my_realloc.c \

LDFLAGS =       -lmy -L$(LIBPATH)

OBJSLIB	=	$(SRCLIB:.c=.o)


# PROJECT VARIABLES

NAME	=	mysh

IFLAG	=	-Iinclude/

CFLAGS  =	-W -Wall -Wextra

CC      =	gcc -g $(CFLAGS) $(IFLAG)


# PROJECT RULES

$(NAME)		: 	$(LIB) $(OBJS)
			@$(ECHO) "$(GREEN)\n>>>>>>>>>>>>>>>>\n\n> Linking \"$(NAME)\"\n\twith \
\"$(CC)\"\n\n>>>>>>>>>>>>>>>\t DONE\n$(WHITE)"
			@$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(LIB)          :       $(OBJSLIB)
			@ar rc $(LIB) $(OBJSLIB)
			@ranlib $(LIB)
			@$(ECHO) "$(GREEN)\n> Compiling Library\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

all		:	$(NAME)

clean		:
			@$(RM) $(OBJS)
			@$(RM) $(OBJSLIB)
			@$(ECHO) "$(GREEN)\n> Cleaning repository\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

fclean		: 	clean
			@$(RM) $(NAME)
			@$(RM) $(LIB)
			@$(ECHO) "$(GREEN)\n> Cleaning exec\t\t >>>>>>>>>>>>>>> \t DONE\n$(WHITE)"

re		:	fclean all

.c.o		:
			@$(CC) -c $< -o $@
			@$(ECHO) "$(GREEN)[OK] > $<\t \t $(WHITE)"
