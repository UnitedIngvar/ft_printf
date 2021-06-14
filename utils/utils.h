#ifndef UTILS_H
# define UTILS_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	struct s_list	*next;
	char			*name;
	void			(*func_defn)(char *);
}				t_dict;

//define different num
# define HASHSIZE 101

unsigned	hash(char *s);
t_dict		*lookup(char *s, t_dict **hashtab);
t_dict		*install(char *name, void (*func_defn)(char *), t_dict **hashtab);
t_dict		**ft_dict_setup();


//static struct nlist *hashtab[HASHSIZE];

#endif
