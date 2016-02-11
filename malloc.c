/*
** malloc.c for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Tue Jan 26 23:51:05 2016 Erwan Dupard
** Last update Thu Feb 11 11:18:55 2016 Barthelemy Gouby
*/

#include <errno.h>
#include <unistd.h>
#include "ressources.h"

extern t_block		*g_data;
extern t_block		*g_last;
extern pthread_mutex_t	g_mutex;
extern char		g_mutex_initialized;

void			*my_extend_memory(size_t size)
{
  t_block		*new;
  size_t		page_size;
  size_t		allocated_size;

  page_size = getpagesize();
  allocated_size = ((NODE_SIZE + size) / page_size) * page_size + page_size;
  if ((new = sbrk(allocated_size)) == (void*) -1)
    return (NULL);
  if (!g_data)
    {
      g_data = new;
      new->prev = NULL;
    }
  else
    {
      g_last->next = new;
      new->prev = g_last;
    }
  g_last = new;
  new->next = NULL;
  new->free = STATUS_NFREE;
  new->size = allocated_size - NODE_SIZE;
  split_block(new, size);
  return (new->data);
}

void			split_block(t_block *block, size_t size)
{
  t_block		*new_block;

  if (block->size - size >= 56)
    {
      /* printf("-----------------\noriginal block size: %lu\n", block->size); */
      new_block = (void*) block->data + size;
      new_block->size = block->size - (size + NODE_SIZE);
      new_block->next = block->next;
      if (new_block->next)
	new_block->next->prev = new_block;
      new_block->prev = block;
      block->next = new_block;
      new_block->free = STATUS_FREE;
      block->size = size;
      if (new_block->next && new_block->next->free == STATUS_FREE)
	new_block = fusion_prev_block(new_block->next);
      if (block == g_last)
	g_last = new_block;
      /* printf("block size: %lu\n", block->size); */
      /* printf("new block size: %lu\n", new_block->size); */
      /* printf("sum of their size: %lu\n", new_block->size + block->size); */
      /* printf("with metadata size: %lu\n", new_block->size + block->size + NODE_SIZE); */
      /* printf("blocks distance: %li\n", (char*) new_block - (char*) block); */
    }
  /* printf("distance between start and end: %li\n", (char*)g_last - (char*)g_data); */
  /* printf("total size: %li\n", (char*)g_last->data - (char*)g_data + g_last->size); */
  /* printf("wtf: %li\n", (char*) sbrk(0) - (char*) g_data); */

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
	  split_block(iterator, size);
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
  size = align8(size);
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
