/*
** calloc.c for calloc in /home/barthe_g/rendu/tek2/unix_Reseau/PSU_2015_malloc
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Feb  2 17:53:21 2016 Barthelemy Gouby
** Last update Fri Feb  5 13:21:52 2016 Erwan Dupard
*/

#include <stdio.h>
#include <string.h>
#include "ressources.h"

t_block		*g_data;

void		*calloc(size_t nmemb, size_t size)
{
  void		*newPtr;

  if ((newPtr = malloc(nmemb * size)) == NULL)
    return (NULL);
  bzero (newPtr, nmemb * size);
  return (newPtr);
}
