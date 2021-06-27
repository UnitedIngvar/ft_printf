#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int	ft_printf(const char *format, ...);
void	ft_printstr(char *str);
void	ft_decToHex(unsigned int n, char *base, size_t *counter);
void	ft_printP(void *arg, char *base, size_t *counter);
char	*ft_uItoa(unsigned int n, int *wid_pre);
#endif
