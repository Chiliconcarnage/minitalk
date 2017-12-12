/*
** client2.c for client2 in /home/oem/home/PSU_2015_minitalk/server
**
** Made by OEM Configuration (temporary user)
** Login   <oem@epitech.net>
**
** Started on  Mon Feb  8 15:51:16 2016 OEM Configuration (temporary user)
** Last update Sun Feb 21 18:37:11 2016 OEM Configuration (temporary user)
*/
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int	my_putchar(unsigned char a)
{
  write(1, &a, 1);
}

int	convert_bin(unsigned char str, int father_proc, int c)
{
  if (c < 8)
    {
      convert_bin(str >> 1, father_proc, c + 1);
      if ((str % 2) == 0)
	kill(father_proc, SIGUSR1);
      else
	kill(father_proc, SIGUSR2);
      usleep(200);
    }
  return (0);
}

int	main(int ac, char **av)
{
  int	father_proc;
  int	nb;
  int	i;

  i = 0;
  father_proc = my_getnbr(av[1]);
  if (ac == 3)
    {
      while (av[2][i] != '\0')
	{
	  convert_bin(av[2][i], father_proc, 0);
	  i++;
	}
    }
}
