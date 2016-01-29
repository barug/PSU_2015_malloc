/*
** free.c for free in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jan 29 14:24:02 2016 Erwan Dupard
** Last update Fri Jan 29 14:46:12 2016 Erwan Dupard
*/

#include "ressources.h"

static t_block		*get_elem_by_ptr(void *ptr)
{
  //  return ((t_block *)ptr - NODE_SIZE);
  (void)ptr;
  return (NULL);
}

void			free(void *ptr)
{
  t_block		*currentElem;

  currentElem = get_elem_by_ptr(ptr);
  (void)currentElem;
}
