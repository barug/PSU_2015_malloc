#include "ressources.h"
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

int main()
{
  int	limit;
  int	i;
  void	*ptr_tab[10000];

  struct timeval tm;
  gettimeofday(&tm, NULL);
  srandom(tm.tv_sec + tm.tv_usec * 1000000ul);
  for (limit = 100; limit <= 10000; limit *= 10) {
    for (i = 1; i <= limit; i++) {
      if ((ptr_tab[i] = malloc(i)) == NULL) {
	printf("MALLOC FAILED!!!!!!!!!!!!!!!!!!!!\n");
	return (0);
      }
      memset(ptr_tab[i], 0, i);
    }
    show_alloc_mem();
    for (i = 1; i <= limit; i++) {
      if ((rand() % 2) == 1) {
	free(ptr_tab[i]);
      }
    }
    /* for (i = 1; i <= limit; i++) { */
    /*   ptr_tab[i] = realloc(ptr_tab[i], i + 10); */
    /*   memset(ptr_tab[i], 0, i + 10); */
    /* } */
  }

  return (0);
}
