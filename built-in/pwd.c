#include "../includes/minishell.h"

void	ft_pwd(char *arg)
{
	char	cwd[PATH_MAX];

	if (!arg)
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
			printf("%s\n", cwd);
	}
}

int main()
{
	ft_pwd(NULL);
	return (0);
}
