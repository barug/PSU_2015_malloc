/*
** realloc.c for realloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Feb  1 14:44:26 2016 Erwan Dupard
** Last update Mon Feb  1 14:45:14 2016 Erwan Dupard
*/

#include "ressources.h"

void		*realloc(void *ptr, size_t size)
{
  if (ptr == NULL)
    return (malloc(size));
  return (NULL);
}
