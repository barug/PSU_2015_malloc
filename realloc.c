/*
** realloc.c for realloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Mon Feb  1 14:44:26 2016 Erwan Dupard
** Last update Thu Feb 11 12:39:39 2016 Barthelemy Gouby
*/

#include "ressources.h"

extern t_block		*g_data;
extern pthread_mutex_t	g_mutex;
extern char		g_mutex_initialized;

static void	*copyBlock(t_block *d, t_block *s)
{
  size_t	i;

  i = 0;
  while (i < s->size)
    {
      d->data[i] = s->data[i];
      ++i;
    }
  free(s->data);
  return (d->data);
}

void		*realloc(void *ptr, size_t size)
{
  /* t_block	*iterator; */
  t_block	*original;
  t_block	*newBlock;

  if (g_mutex_initialized == 0)
    {
      g_mutex_initialized = 1;
      g_mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
    }
  pthread_mutex_lock(&g_mutex);
  if (ptr == NULL && size == 0)
    {
      free (ptr);
      pthread_mutex_unlock(&g_mutex);
      return (NULL);
    }
  if (ptr == NULL && size > 0)
    {
      pthread_mutex_unlock(&g_mutex);
      return (malloc(size));
    }
  original = get_elem_by_ptr(ptr);
  if (original->size >= size)
    {
        pthread_mutex_unlock(&g_mutex);
	return (original->data);
    }
  /* iterator = g_data; */
  /* while (iterator) */
  /*   { */
  /*     if (iterator->size >= size && iterator->free == STATUS_FREE) */
  /* 	{ */
  /* 	  iterator->free = STATUS_NFREE; */
  /* 	  split_block(iterator, size); */
  /* 	  return (copyBlock(iterator, original)); */
  /* 	} */
  /*     iterator = iterator->next; */
  /*   } */
  /* if ((newBlock = my_extend_memory(size)) == NULL) */
  /*   return (NULL); */
  if ((newBlock = malloc(size)) == (void*) -1)
    {
      pthread_mutex_unlock(&g_mutex);
      return (NULL);
    }
  newBlock = get_elem_by_ptr(newBlock);
  pthread_mutex_unlock(&g_mutex);
  return (copyBlock(newBlock, original));
}
