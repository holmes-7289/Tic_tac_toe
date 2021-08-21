#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int createBoard ();
int play1 ();
int play2 ();
int checkWin ();
int remove_da (int);

int i;
//char s[10]={'5'};
int ai_mod_ran[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int ai_index = 10;
char s[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

int flag = 0;

int
main ()
{
  int times = 1;
  createBoard ();
  while (times < 10)
    {
      if (times % 2)
	play1 ();
      else
	play2 ();
      if (times >= 5)
	{
	  checkWin ();
	  if (flag)
	    break;
	}
      times++;
    }
  if (flag == 0)
    printf ("***** Match was DRAW *****");
  return 0;
}

int
createBoard ()
{
  printf ("    |    |    \n");
  printf ("  %c |  %c |  %c \n", s[1], s[2], s[3]);
  printf ("____|____|____\n");
  printf ("    |    |    \n");
  printf ("  %c |  %c |  %c \n", s[4], s[5], s[6]);
  printf ("____|____|____\n");
  printf ("    |    |    \n");
  printf ("  %c |  %c |  %c \n", s[7], s[8], s[9]);
  printf ("    |    |    \n");
  //system("clear");
  return 0;
}

int
play1 ()
{
  printf ("****** For 1st player ******\n\n");
  printf ("    Enter the index you want to enter:\t");
label:
  scanf ("%d", &i);
  if (s[i] == ' ')
    {
      if (i <= 9 && i >= 1)
	{
	  s[i] = 'X';

	  remove_da (i);
	}
      else
	{
	  printf ("Enter your choice form 1 to 9\t");
	  goto label;
	}
    }
  else
    {
      printf ("Index Occupied Enter again:\t");
      goto label;
    }
  printf ("\n");
  system ("clear");
  createBoard ();
  return 0;
}

int play2 ()
{
  printf ("For 2nd player");
  printf ("Enter the index you want to enter:\t");
label:
  srand (time (NULL));
  //scanf("%d",&i);
  i = -1;
  while (1)
    {
      if (ai_mod_ran[i] > 0 && i > 0)
	{
	  break;
	}
      i = rand () % ai_index;
    }
  if (s[ai_mod_ran[i]] == ' ')
    {
      s[ai_mod_ran[i]] = 'O';

      remove_da (ai_mod_ran[i]);

    }
  else
    {
      printf ("Index Occupied Enter again:\t");
      goto label;
    }
  printf ("\n");
  system ("clear");
  createBoard ();
  return 0;
}


int checkWin ()
{
  if ((s[1] == s[5] && s[5] == s[9]) && (s[1] == 'X' || s[1] == 'O'))
    {
      if (s[1] == 'X')
	printf ("\n***** 1st player won ******");
      else
	printf ("\n***** Random player won ******");
      flag++;
    }
  else if ((s[3] == s[5] && s[5] == s[7]) && (s[3] == 'X' || s[3] == 'O'))
    {
      if (s[3] == 'X')
	printf ("\n***** 1st player won ******");
      else
	printf ("\n***** Random player won ******");
      flag++;
    }
  else if ((s[1] == s[4] && s[4] == s[7]) && (s[1] == 'X' || s[1] == 'O'))
    {
      if (s[1] == 'X')
	printf ("\n***** 1st player won ******");
      else
	printf ("\n***** Random player won ******");
      flag++;
    }
  else if ((s[1] == s[2] && s[2] == s[3]) && (s[1] == 'X' || s[1] == 'O'))
    {
      if (s[1] == 'X')
	printf ("\n***** 1st player won ******");
      else
	printf ("\n***** Random player won ******");
      flag++;
    }
  else if ((s[3] == s[6] && s[6] == s[9]) && (s[3] == 'X' || s[3] == 'O'))
    {
      if (s[3] == 'X')
	printf ("\n***** 1st player won ******");
      else
	printf ("\n***** Random player won ******");
      flag++;
    }
  else if ((s[4] == s[5] && s[5] == s[6]) && (s[4] == 'X' || s[4] == 'O'))
    {
      if (s[4] == 'X')
	printf ("\n***** 1st player won ******");
      else
	printf ("\n***** Random player won ******");
      flag++;
    }
  else if ((s[7] == s[8] && s[8] == s[9]) && (s[8] == 'X' || s[8] == 'O'))
    {
      if (s[7] == 'X')
	printf ("\n***** 1st player won ******");
      else
	printf ("\n***** Random player won ******");
      flag++;
    }
  else if ((s[2] == s[5] && s[5] == s[8]) && (s[2] == 'X' || s[2] == 'O'))
    {
      if (s[2] == 'X')
	printf ("\n***** 1st player won ******");
      else
	printf ("\n***** Random player won ******");
      flag++;
    }
  return 0;
}

int remove_da (int da)
{
  int j = 0;
  for (j = 0; j < ai_index; j++)
    {
      if (ai_mod_ran[j] == da)
	{
	  break;
	}
    }
  for (int i = j; i < ai_index; i++)
    {
      ai_mod_ran[i] = ai_mod_ran[i + 1];
    }
  ai_index--;
  return 0;

}

