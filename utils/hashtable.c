#include "utils.h"
#include "../src/ft_printf.h"

/* hash: form hash value for string s */
unsigned	hash(char *s)
{
	unsigned	hashval;
	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return (hashval % HASHSIZE);
}

/* lookup: look for s in hashtab */
t_dict *lookup(char *s, t_dict **hashtab)
{
	t_dict	*np;

	np = hashtab[hash(s)];
	while (np)
	{
		if (strcmp(s, np->name) == 0)
			return (np);
		np = np->next;
	}
	return (NULL);
}

/* install: put (name, defn) in hashtab */
t_dict *install(char *name, void (*func_defn)(char *), t_dict **hashtab)
{
	t_dict	*np;
	unsigned		hashval;

	np = lookup(name, hashtab);
	if (np == NULL)
	{
		np = (t_dict *)malloc(sizeof(*np));
		if(np == NULL)
			return (NULL);
		np->name = strdup(name);
		if (np->name == NULL)
			return (NULL);
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	}
	np->func_defn = func_defn;
	if (np->func_defn == NULL)
		return (NULL);
	return (np);
}

t_dict **ft_dict_setup()
{
	static t_dict *hashtab[HASHSIZE];

	install("c", ft_char_handler, hashtab);
	return (hashtab);
}
