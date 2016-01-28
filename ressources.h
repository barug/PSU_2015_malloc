/*
** ressources.h for malloc in /home/dupard_e/rendus/PSU_2015_malloc
** 
** Made by Erwan Dupard
** Login   <dupard_e@epitech.net>
** 
** Started on  Thu Jan 28 10:25:45 2016 Erwan Dupard
// Last update Thu Jan 28 14:17:45 2016 Erwan Dupard
*/

#ifndef RESSOURCES_H_
# define RESSOURCES_H_

# include <unistd.h>

/*
 * Align 32bits int
 */

# define align4(x) (((((x) - 1) >> 2) << 2) + 4)

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
  size_t		size; /* size of allocated block */
  struct s_block	*next; /* next memory block */
  int			free; /* Is the pointed byte is ready to be allocated */
}			t_block;

#endif /* ! RESSOURCES_H_ */
