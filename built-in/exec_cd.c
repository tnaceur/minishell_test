#include "../includes/minishell.h"

void	exec_cd(char **path)
{
   	char cwd[PATH_MAX];
	if (path[0][0] == '~')
	{
		char *usr = "/Users/$USER";
		path[0] = ft_strjoin(usr, path[0] + 1);
	}
	if (chdir(path[0]) == -1)
		perror(NULL);
	getcwd(cwd, sizeof(cwd));
	// printf("%s\n", cwd);
}
