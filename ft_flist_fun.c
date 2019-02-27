#include "ft_printf.h"
#include <stdlib.h>
#include "libft.h"

t_flist	*flist_new_pf()
{
	t_flist		*new;

	new = (t_flist*)malloc(sizeof(t_flist));
	if (new == NULL)
		return (NULL);
	new->accu_l = 0;
	new->dot = 0;
	new->accu_r = 0;
	new->flag = NULL;
	new->spec = 0;
	new->hash = 0;
	new->minus = 0;
	new->plus = 0;
	new->space = 0;
	new->zero = 0;
	return (new);
}

void    flist_free(t_flist *elem)
{
	free(elem->flag);
	elem->flag = NULL;
	free(elem);
}
