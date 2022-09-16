HEADER			=	includes/minishell.h

NAME			=	minishell

MAIN			=	main.c

SRCS			=	srcs/ft_initvars.c\
					srcs/ft_lstfx.c\
					srcs/ft_signal_handler.c\
					srcs/ft_cmd_fx.c\
					srcs/ft_getenv.c\
					srcs/ft_free_program.c\
					srcs/ft_parse_cmds.c\
					srcs/ft_tokenization.c\
					srcs/ft_verify_syntax.c\
					exec/pipe.c\
					exec/exec.c\
					built-in/exec_echo.c\
					built-in/exec_exit.c\
					built-in/exec_cd.c\
					built-in/exec_env.c\
					built-in/exec_pwd.c\
					

OBJS			=	$(SRCS:.c=.o)\
					$(MAIN:.c=.o)

LIBFT			=	./libft

LIB				=	./libft/libft.a

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror #-fsanitize=address

RM				=	rm -f

%.o:%.c			$(HEADER) 
				$(CC) $(CFLAGS) -I$(shell brew --prefix readline)/include -c $< -o $@ 

$(NAME):		$(HEADER) $(LIB) $(OBJS)
				$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME) -lreadline -L /opt/homebrew/opt/readline/lib/  -I /opt/homebrew/opt/readline/include/

all:			$(NAME)

$(LIB):
				make -C $(LIBFT)

clean:
				$(RM) $(OBJS)
				make clean -C Libft

fclean:			clean
				$(RM) $(NAME)
				make fclean -C Libft

re:				fclean all
