/*
** show_alloc_mem.c for show_alloc_mem in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Fri Jan 29 15:27:29 2016 Erwan Dupard
** Last update Fri Feb 12 14:19:13 2016 Barthelemy Gouby
*/

#include "ressources.h"

t_block			*g_data;

/* void			show_alloc_mem() */
/* { */
/*   t_block		*iterator; */
/*   int			i = 0; */

/*   printf("break : %p\n", sbrk(0)); */
/*   iterator = g_data; */
/*   while (iterator) */
/*     { */
/*       printf("%p - %p : %lu bytes\n", */
/* 	     iterator->data, */
/* 	     (iterator->next ? iterator->next : sbrk(0)), */
/* 	     iterator->size); */
/*       iterator = iterator->next; */
/*       i++; */
/*     } */
/* } */

void			show_alloc_mem()
{
  t_block		*iterator;
  int			i = 0;

  printf("break : %p\n", sbrk(0));
  iterator = g_data;
  while (iterator)
    {
      printf("block at %p data from %p to %p : %lu bytes free:%i\n",
	     iterator,
	     iterator->data,
	     iterator->data + iterator->size - 1,
	     iterator->size,
	     iterator->free);
      iterator = iterator->next;
      i++;
    }
  printf("heap size: %li\n", (char*)sbrk(0) - (char*) g_data);
  printf("maybe: %li\n", (char*) g_last->data - (char*) g_data + g_last->size);
  printf("heap end: %p\n", sbrk(0));
  printf("expected heap end: %p\n", g_last->data + g_last->size);
}
