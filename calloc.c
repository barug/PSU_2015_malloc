/*
** calloc.c for calloc in /home/barthe_g/rendu/tek2/unix_Reseau/PSU_2015_malloc
** 
** Made by Barthelemy Gouby
** Login   <barthe_g@epitech.net>
** 
** Started on  Tue Feb  2 17:53:21 2016 Barthelemy Gouby
** Last update Tue Feb  2 18:01:54 2016 Barthelemy Gouby
*/

#include <stdio.h>
#include <string.h>
#include "ressources.h"

void		*calloc(size_t nmemb, size_t size)
{
  void		*newPtr;

  newPtr = malloc(nmemb * size);
  memset((char*)newPtr, 0, nmemb * size);
  return (newPtr);
}
