#include "../includes/minishell.h"

void	exec_cd(char **path)
{
   	char *new_path;

	if (!path[1] || (path[1][0] == '~' && !path[1][1]))
	{
		chdir("/Users/tahanaceur");
		return ;
	}
	if (path[1][0] == '~')
	{
		new_path = ft_strdup("/Users/tnaceur");
		int i = 2;
		new_path = ft_strjoin(new_path, path[1] + 1);
		if (path[i]){
			new_path = ft_strjoin(new_path, path[i]);
			i++;
		}
	}
	else
		new_path = path[1];
	if (chdir(new_path) == -1)
		perror(NULL);
}
