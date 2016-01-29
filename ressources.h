/*
** ressources.h for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jan 28 10:25:45 2016 Erwan Dupard
// Last update Fri Jan 29 15:18:53 2016 Erwan Dupard
*/

#ifndef RESSOURCES_H_
# define RESSOURCES_H_

# include <stdio.h>
# include <unistd.h>

# define RETURN_SUCCESS (0)
# define RETURN_FAILURE (1)

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
 * Definition of memory block (set in malloc , used for free)
 * We can call this "Meta-data"
 * 
 * Heap representation
 */
typedef struct		s_block
{
  size_t		size;    /* Size of allocated block */
  char			free;
  struct s_block	*next;   /* Next memory block */
  struct s_block	*prev;	 /* Prev memory block */
  void			*data;   /* Pointer on s_block + sizeof(s_block) to have data pointer */
}			t_block;

/*
 * Heap Linked list ((META-DATA) DATA ) ---> ((META-DATA) DATA ) ---> NIL
 */
extern void		*g_data;

/*
 * Size to jump at block to get data pointer
 */
# define NODE_SIZE	((sizeof(struct s_block)))

#endif /* ! RESSOURCES_H_ */
