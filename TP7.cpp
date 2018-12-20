#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct personne{
  int sexe;
  int taille;
  int age;
  int poids;
};

//Sujet
void affiche(personne &p)
{
    cout<<p.sexe<<":"<<p.taille<<":"<<p.age<<":"<<p.poids<<endl;
}

void affiche(personne *T, int N)
{
    for(int i=0;i<N;i++) affiche(T[i]);
}

personne *lire_fichier(int & N)
{
    ifstream fichier("population.txt", ios::in);
    string contenu;
    personne *aux=new personne[1000000];
    int i=0;
    while(fichier)
    {
        if (getline(fichier, contenu))
        {
			const char *s=contenu.c_str();
			int a,b,c,d;
			sscanf(s,"%d %d %d %d",&(aux[i].sexe),&(aux[i].taille),&(aux[i].age),&(aux[i].poids));
			i++;
		}
    }
    N=i;
    personne *T=new personne[N];
    for (int j=0;j<N;j++) T[j]=aux[j];
    delete [] aux;
    return(T);
}

//Sexe

personne *Tri_Sexe(int s, personne *T, int & n)
{
//base
    int j = 0;
    personne *eT = new personne[n];
    for (int i = 0; i < n; i++)
    {
        if (T[i].sexe == s)
        {
            eT[j] = T[i];
            j++;
        }
    }
    n = j;
    personne *nT = new personne[n];
    for (int i = 0; i < n; i++)
    {
        nT[i] = eT[i];
    }
    delete[] eT;
    return nT;
}

//Encadrement

personne *Tri_Enc(int c,int t1, int t2, personne *T, int &n)
{
//set
  if (t1 > t2)
  {
    int e = t2;
    t2 = t1;
    t1 = e;
  }
//base
  int j = 0;
  personne *eT = new personne[n];
  for (int i = 0; i < n; i++)
  {
//taille
    if (c == 1)
    {
        if ((T[i].taille > t1) && (T[i].taille < t2))
        {
        eT[j] = T[i];
        j++;
        }
    }
//age
    else if (c == 2)
    {
        if ((T[i].age > t1) && (T[i].age < t2))
        {
        eT[j] = T[i];
        j++;
        }
    }
//poids
    else if (c == 3)
    {
        if ((T[i].poids > t1) && (T[i].poids < t2))
        {

        eT[j] = T[i];
        j++;
        }
    }
  }
  n = j;
  personne *nT = new personne[n];
  for (int i = 0; i < n; i++)
  {
    nT[i] = eT[i];
  }
  delete[] eT;
  return nT;
}

personne *Tri_Min_Max(int m,int c,int t, personne *T, int &n)
{
//base
  int j = 0;
  personne *eT = new personne[n];
  for (int i = 0; i < n; i++)
  {
//Ayant le minimum
	if (m == 0)
	{
//taille
		if (c == 1)
		{
			if (T[i].taille > t)
			{
				eT[j] = T[i];
				j++;
			}
		}
//age
		else if (c == 2)
		{
			if (T[i].age > t)
			{
				eT[j] = T[i];
				j++;
			}
		}
//poids
		else if (c == 3)
		{
			if (T[i].poids > t)
			{
				eT[j] = T[i];
				j++;
			}
		}
	}
//Ayant le maximum
	if (m == 1)
	{
//taille
		if (c == 1)
		{
			if (T[i].taille < t)
			{
				eT[j] = T[i];
				j++;
			}
		}
//age
		else if (c == 2)
		{
			if (T[i].age < t)
			{
				eT[j] = T[i];
				j++;
			}
		}
//poids
		else if (c == 3)
		{
			if (T[i].poids < t)
			{
				eT[j] = T[i];
				j++;
			}
		}
	}
  }
  n = j;
  personne *nT = new personne[n];
  for (int i = 0; i < n; i++)
  {
    nT[i] = eT[i];
  }
  delete[] eT;
  return nT;
}

// Moyenne

float Moyenne(int c, personne *T, int N)
{
  float t = 0;
  for (int i = 0; i < N; i++)
  {
//taille
    if (c == 1)
    {
      t = t + T[i].taille;
    }
//age
    if (c == 2)
    {
      t = t + T[i].age;
    }
//poids
    if (c == 3)
    {
      t = t + T[i].poids;
    }
  }
  float m = t / N;
  return m;
}

//Minimum ou maximum

int Min_Max(int M,int c, personne *T, int N)
{
  int m;
  if (M == 0)
  {
//taille
      if(c == 1)
      {
        m = T[0].taille;
        for (int i = 1; i < N; i++)
        {
          if (T[i].taille < m)
          {
            m = T[i].taille;
          }
        }
      }
//age
      if(c == 2)
      {
        m = T[0].age;
        for (int i = 1; i < N; i++)
        {
          if (T[i].age < m)
          {
            m = T[i].age;
          }
        }
      }
//poids
      if(c == 3)
      {
        m = T[0].poids;
        for (int i = 1; i < N; i++)
        {
          if (T[i].poids < m)
          {
            m = T[i].poids;
          }
        }
      }
  }
  if (M == 1)
  {
//taille
      if(c == 1)
      {
        m = T[0].taille;
        for (int i = 1; i < N; i++)
        {
          if (T[i].taille > m)
          {
            m = T[i].taille;
          }
        }
      }
//age
      if(c == 2)
      {
        m = T[0].age;
        for (int i = 1; i < N; i++)
        {
          if (T[i].age > m)
          {
            m = T[i].age;
          }
        }
      }
//poids
      if(c == 3)
      {
        m = T[0].poids;
        for (int i = 1; i < N; i++)
        {
          if (T[i].poids > m)
          {
            m = T[i].poids;
          }
        }
      }
  }
  return m;
}

int main()
{
    int N;
    personne *T = lire_fichier(N);


    // affiche(T,N);

    // personne *nT = Tri_Sexe(0,T,N);
    //// 0 == F and 1 == M
    //// T == Tableau
    //// N == Taille tableau
    
    // personne *nT = Tri_Enc(2,20,25,T,N);
    //// 1 == taille and 2 == age and 3 == poids
    //// Max
    //// Min
    //// T == Tableau
    //// N == Taille tableau
    
    // personne *nT = Tri_Min_Max(1,2,22,T,N);
    //// 0 == Min and 1 == Max
    //// 1 == taille and 2 == age and 3 == poids
    //// Valeur Min or Max
    //// T == Tableau
    //// N == Taille tableau
	
	
	personne *nT = Tri_Sexe(0,T,N);
    affiche(nT,N);
    
	// float m = Moyenne(2,T,N);
    //// 1 == taille and 2 == age and 3 == poids
    //// T == Tableau
    //// N == Taille tableau
	
	// int m = Min_Max(0,2,T,N);
    //// 0 == Min and 1 == Max
    //// 1 == taille and 2 == age and 3 == poids
    //// T == Tableau
    //// N == Taille tableau
	
    delete[] T;
    delete[] nT;

    return 0;
}


















