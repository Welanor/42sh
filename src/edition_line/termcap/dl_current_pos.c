/*
** dl_current_pos.c for dl_current_pos.c in /home/remi/Projet/edition_line/termcap
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Apr  8 16:36:04 2013 remi robert
** Last update Tue Apr 30 11:38:24 2013 remi robert
*/

#include "my_func.h"

void	delete_line_curser(int fd)
{
  char	*s;

  s = tgetstr("dl", NULL);
  my_putstr(s, fd, -1);
}

void	dl_current_pos(t_param *param)
{
  int	indice;
  int	size;
  int	x;

  size = (param->len_string + my_strlen(param->buff_copy))
         / return_x(param->fd_tty);
  indice = 0;
  x = param->begin_pos.x;
  while (indice != size + 1)
    {
      curseur(x, param->begin_pos.y + indice, param->fd_tty);
      delete_line_curser(param->fd_tty);
      x = 0;
      indice = indice + 1;
    }
  curseur(param->current_pos.x, param->current_pos.y, param->fd_tty);
  delete_line_curser(param->fd_tty);
  curseur(param->begin_pos.x, param->begin_pos.y, param->fd_tty);
  delete_line_curser(param->fd_tty);
}
