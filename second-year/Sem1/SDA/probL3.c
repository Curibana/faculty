/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<stdio.h>

typedef enum
{ medii, superioare, doctorat } studii;
typedef enum
{ economic, tehnic } profil;
typedef struct
{
  int zi, luna, an;
} data_nastere;
typedef struct
{
  float nota_bac, medie_4;
} info_medii;
typedef union
{
  info_medii info_m;
  float nota_l;
  profil p;
} informatii;
typedef struct
{
  char nume[20], prenume[20];
  float salariu;
  data_nastere d_n;
  studii st;
  informatii info;
} persoana;

int
load_file (persoana a[])
{
  int i = 0;
  FILE *f;
  if ((f = fopen ("ang.txt", "rt")) == NULL)
    {
      printf (".........");
    }
  else
    {
      while (!feof (f))
	{
	  fscanf (f, "%s%s%f%d.%d.%d%d", a[i].nume, a[i].prenume,
		  &a[i].salariu, &a[i].d_n.zi, &a[i].d_n.luna, &a[i].d_n.an,
		  &a[i].st);
	  switch (a[i].st)
	    {
	    case medii:
	      fscanf (f, "%f%f", &a[i].info.info_m.nota_bac,
		      &a[i].info.info_m.medie_4);
	      break;
	    case superioare:
	      fscanf (f, "%f", &a[i].info.nota_l);
	      break;
	    case doctorat:
	      fscanf (f, "%d", &a[i].info.p);
	      break;
	    }
	  i++;
	}
      fclose (f);
      return i;
    }

}

void
afisare (persoana a[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    {
      printf ("%s %s %f %d.%d.%d %d ", a[i].nume, a[i].prenume, a[i].salariu,
	      a[i].d_n.zi, a[i].d_n.luna, a[i].d_n.an, a[i].st);
      switch (a[i].st)
	{
	case medii:
	  printf ("%f %f\n", a[i].info.info_m.nota_bac,
		  a[i].info.info_m.medie_4);
	  break;
	case superioare:
	  printf ("%f\n", a[i].info.nota_l);
	  break;
	case doctorat:
	  printf ("%d\n", a[i].info.p);
	  break;
	}
    }

}

int
cautare (persoana a[], int n, char nume[])
{

}

void
afisare_conditionata (... .....)
{


}

int
stergere (persoana a[], int n, char nume[])
{
  int i;
  i = cautare (a, n, nume);
  if (i == n)
    printf ("\nNumele nu se gaseste in evidenta!\n");
  else
    {
      a[i] = a[n - 1];
      n--;
    }
  return n;
}
