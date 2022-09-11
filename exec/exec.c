#include "../includes/minishell.h"

void	exec(t_vars *vars)
{
	int	pipe;
	int	herdoc;
	t_list	*tmp;

	herdoc = 0;
	pipe = 0;
	tmp = vars->tokens;
	while (tmp)
	{
		if (tmp->content[0] == '|')
			pipe++;
		tmp = tmp->next;
	}
	if (pipe == 0)
		exec_cmd(vars);
	else
		exec_pipe(vars);
}