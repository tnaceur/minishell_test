#include "../includes/minishell.h"

void	exec_cd(char **path)
{

	if (!path[1] || path[1][0] == '~' )
	{
		char *usr = "/Users/$USER";
		path[1] = ft_strjoin(usr, path[1]);
	}
	if (chdir(path[1]) == -1)
		perror(NULL);
}
