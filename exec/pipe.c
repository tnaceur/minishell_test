# include "../includes/minishell.h"

// int ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char	*str;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	while (s1[i])
// 		str[j++] = s1[i++];
// 	i = 0;
// 	while (s2[i])
// 		str[j++] = s2[i++];
// 	str[j] = '\0';
// 	return (str);
// }

char	*get_path(char **path, char *cmd)
{
	int	i;

	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd);
		if (access(path[i], F_OK) == 0)
			return (path[i]);
		i++;
	}
	return (path[i]);
}

void ft_execute(char *cmd, char **env)
{
	int	i = 0;
	char **path, *cmd_path;
	while (env[i])
	{
		if (env[i][0] == 'P')
		{
			if (env[i][1] == 'A')
				break;
		}
		i++;
	}
	path = ft_split(env[i] + 5, ':');
	cmd_path = get_path(path, cmd);
}

void	exec_pipe(char **cmd, char **env)
{
    char	*input;
	int		i;
	int		count;

	(void)cmd;
    input = readline("$pipex ");
	if (input[0] == '|')
	{
		printf("zsh: parse error near `|' \n");
		exit(0);
	}
	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '|')
			count++ ;
		i++ ;
	}
	if (count == 0)
		ft_execute(input, env);
}