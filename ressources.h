/*
** ressources.h for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jan 28 10:25:45 2016 Erwan Dupard
// Last update Fri Feb  5 12:44:05 2016 Barthelemy Gouby
*/

#ifndef RESSOURCES_H_
# define RESSOURCES_H_

# include <stdio.h>
# include <unistd.h>

# define RETURN_SUCCESS (0)
# define RETURN_FAILURE (1)


# define align4(x) (((((x) - 1) >> 2) << 2) + 4)

/*
 * Definition of memory block (set in malloc , used for free)
 * We can call this "Meta-data"
 * 
 * Heap representation
 */
typedef struct		s_block
{
  size_t		size;    /* Size of allocated block */
  int			free;
  struct s_block	*next;   /* Next memory block */
  struct s_block	*prev;	 /* Prev memory block */
  char			data[1];/* Pointer on s_block + sizeof(s_block) to have data pointer */
}			t_block;

/*
 * Malloc implementation
 */
void			*malloc(size_t size);

/*
 * Realloc implementation
 */
void			*realloc(void *ptr, size_t size);

/*
 * Free implementation
 */
void			free(void *ptr);

/*
 * User readable memory dump
 */
void			show_alloc_mem();

/*
 * Extend memory (Heap)
 */
void			*extend_memory(size_t size);

/*
 * Retreive Block by data pointer
 */
t_block			*get_elem_by_ptr(void *ptr);

void			my_memory_dump();

/*
 * Heap Linked list ((META-DATA) DATA ) ---> ((META-DATA) DATA ) ---> NIL
 */
extern t_block		*g_data;
extern void		*heap_start;

/*
 * Size to jump at block to get data pointer
 */
# define NODE_SIZE	(32)
#endif /* ! RESSOURCES_H_ */
