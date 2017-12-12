/*
** my_put_nbr.c for my_put_nbr in /home/lauque_m/rendu/PSU_2015_my_printf_bootstrap/lib/my
**
** Made by maxence lauque
** Login   <lauque_m@epitech.net>
**
** Started on  Wed Nov  4 11:53:37 2015 maxence lauque
** Last update Mon Feb  8 14:07:00 2016 OEM Configuration (temporary user)
*/

int	my_put_nbr(int nb)
{
  int	a;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * - 1;
    }
  if (nb > 0)
    {
      a = nb % 10;
      nb = nb / 10;
      my_put_nbr(nb);
      my_putchar(48 + a);
    }
}
