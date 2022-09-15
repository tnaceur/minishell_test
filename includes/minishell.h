/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-moum <yel-moum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:51:39 by sergio            #+#    #+#             */
/*   Updated: 2022/09/12 23:44:52 by yel-moum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <errno.h>
# include <signal.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "../libft/libft.h"

# define PROMPT "minishell-> "

enum e_type
{
	WORD,
	S_QUOTE,
	D_RED_IN,
	D_RED_OUT,
	RED_IN,
	RED_OUT,
	PIPE
};

typedef struct s_list 
{
	char				*content;
	int					type;
	struct s_list		*next;
}	t_list;

typedef struct s_cmd 
{
	char				**cmd;
	int					type;
	int					*subsh_lvl;
	t_list				*redirect;
	struct s_cmd		*next;
}	t_cmd;

typedef struct s_vars 
{
	char				*cmdline;
	char				*last_cmdline;
	char				**envp;
	char				**path_cmd;
	t_list				*tokens;
	t_cmd				*cmds;
	struct sigaction	sa;
	
}	t_vars;

typedef struct s_syntax 
{
	int		s_quotes;
}	t_syntax;

typedef struct s_glob
{
	pid_t				pid;
	int					heredoc;
	int					exit_status;
	int					is_child;
	char				**env;
}	t_glob;

t_glob	g_glob;

void	signals_handler(int sign);
int		ft_init_vars(t_vars *vars, char *envp[]);
void	*ft_free(void *ptr);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(char *content, int type);
void	ft_cmd_lstclear(t_cmd **lst);
t_cmd	*ft_cmd_lstlast(t_cmd *lst);
void	ft_cmd_lstadd_back(t_cmd **lst, t_cmd *new);
t_cmd	*ft_cmd_lstnew(char **cmd, int type, int *subsh_lvl, t_list *redirect);
void	ft_free_program(t_vars *vars);
char	*ft_getenv(char *var, char **envp);
int		ft_tokenization(t_vars *vars);
int		ft_parse_cmds(t_vars *vars);
int		ft_verify_syntax(t_vars *vars);
void	exec_pipe(t_vars *vars);
void	exec(t_vars *vars);
void	exec_cmd(t_vars *vars);
int		builtin_exit(char **cmd);
int		builtin_env(char **envp);
int		builtin_echo(char **cmd);
void	exec_cd(char **path);
int		is_builtin(t_cmd *vars);

# endif