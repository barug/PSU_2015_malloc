/*
** malloc.c for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jan 26 23:51:05 2016 Erwan Dupard
** Last update Tue Feb  9 14:13:15 2016 Erwan Dupard
*/

#include <errno.h>
#include <unistd.h>
#include "ressources.h"

extern t_block		*g_data;
extern pthread_mutex_t	g_mutex;
extern char		g_mutex_initialized;

void			*my_extend_memory(size_t size)
{
  t_block	*new;
  t_block	*iterator;

  if ((new = sbrk(0)) == (void *) -1)
    return (NULL);
  if (sbrk(NODE_SIZE + size) == (void *) -1)
    return (NULL);
  new->size = size;
  new->free = STATUS_NFREE;
  new->next = NULL;
  if (g_data == NULL)
    {
      g_data = new;
      new->prev = NULL;
      return (new->data);
    }
  iterator = g_data;
  while (iterator->next)
    iterator = iterator->next;
  iterator->next = new;
  new->prev = iterator;
  return (new->data);
}

static void		*find_free_block(size_t size)
{
  t_block	*iterator;

  if (g_data == NULL)
    return (NULL);
  iterator = g_data;
  while (iterator)
    {
      if (iterator->free == STATUS_FREE && iterator->size >= size)
	{
	  iterator->free = STATUS_NFREE;
	  return (iterator->data);
	}
      iterator = iterator->next;
    }
  return (NULL);
}

void			*malloc(size_t size)
{
  void		*allocated_block;

  if (g_mutex_initialized == 0)
    {
      g_mutex_initialized = 1;
      g_mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    }
  size = align4(size);
  if (size <= 0)
    return (NULL);
  pthread_mutex_lock(&g_mutex);
  if ((allocated_block = find_free_block(size)) == NULL)
    {
      pthread_mutex_unlock(&g_mutex);
      return (my_extend_memory(size));
    }
  pthread_mutex_unlock(&g_mutex);
  return (allocated_block);
}
