/*
** server2.c for server in /home/oem/home/PSU_2015_minitalk/server
**
** Made by OEM Configuration (temporary user)
** Login   <oem@epitech.net>
**
** Started on  Mon Feb  8 15:38:52 2016 OEM Configuration (temporary user)
** Last update Sun Feb 21 22:44:22 2016 OEM Configuration (temporary user)
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int	my_putchar(unsigned char a)
{
  write(1, &a, 1);
}

void	handler(int signum)
{
  static unsigned char	str = '\0';
  static int		i = 0;
  int			a;

  a = 1;
  if (signum == SIGUSR1)
    {
      if (i < 7)
	str = str << 1;
      i++;
    }
  if (signum == SIGUSR2)
    {
      str = str | a;
      if (i < 7)
	str = str << 1;
      i++;
    }
  if (i == 8)
    {
      my_putchar(str);
      i = 0;
      str = '\0';
      a = 1;
    }
}

int	server()
{
  int	i;

  i = getpid();
  if (i == - 1)
    return (0);
  my_put_nbr(i);
  my_putchar('\n');
  return (i);
}

int	main(int ac, char **av)
{
  int	i;
  char	*str;

  str = av[2];
  i = server();
  signal(SIGUSR1, handler);
  signal(SIGUSR2, handler);
  while (1)
    {
    }
}
