/*
** realloc.c for realloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Feb  1 14:44:26 2016 Erwan Dupard
** Last update Mon Feb  1 17:40:02 2016 Barthelemy Gouby
*/

#include "ressources.h"

void		*realloc(void *ptr, size_t size)
{
  t_block	*currentElem;

  if (ptr == NULL)
    return (malloc(size));
  currentElem = get_elem_by_ptr(ptr);
  if (currentElem->size >= size)
    return (currentElem);
  return (NULL);
}
