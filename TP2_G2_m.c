  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/

  /*============================================================*/

  /* Générer un mot aléatoire de longueur comprise entre 1 et L */

  /* L’insérer dans un tableau Tab non ordonné                  */

  /*  L’insérer dans la structure s’il n’existe pas             */

  /*============================================================*/


  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  typedef int bool ;
  typedef char * string255 ;

  #define True 1
  #define False 0

  /** Implémentation **\: LISTE BIDIRECTIONNELLE DE ARBRES BINAIRES DE CHAINES DE CARACTERES**/

  /** Arbres de recherche binaire **/

  typedef string255 Typeelem_As   ;
  typedef struct Noeud_As * Pointeur_As ;

  struct Noeud_As
    {
      Typeelem_As  Val ;
      Pointeur_As Fg ;
      Pointeur_As Fd ;
      Pointeur_As Pere ;
     } ;

  Typeelem_As Info_As( Pointeur_As P )
    { return P->Val;   }

  Pointeur_As Fg_As( Pointeur_As P)
    { return P->Fg ; }

  Pointeur_As Fd_As( Pointeur_As P)
    { return P->Fd ; }

  Pointeur_As Pere_As( Pointeur_As P)
    { return P->Pere ; }

  void Aff_info_As ( Pointeur_As P, Typeelem_As Val)
    {
       strcpy( P->Val , Val );
    }

  void Aff_fg_As( Pointeur_As P, Pointeur_As Q)
    { P->Fg =  Q;  }

  void Aff_fd_As( Pointeur_As P, Pointeur_As Q)
    { P->Fd =  Q ; }

  void Aff_pere_As( Pointeur_As P, Pointeur_As Q)
    { P->Pere =  Q ; }

  void Creernoeud_As( Pointeur_As *P)
    {
      *P = (struct Noeud_As *) malloc( sizeof( struct Noeud_As))   ;
      (*P)->Val = malloc(255 * sizeof(string255));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_As( Pointeur_As P)
    { free( P ) ; }


  /** Listes bidirectionnelles **/

  typedef Pointeur_As Typeelem_RAs   ;
  typedef struct Maillon_RAs * Pointeur_RAs ;

  struct Maillon_RAs
    {
      Typeelem_RAs  Val ;
      Pointeur_RAs Suiv ;
      Pointeur_RAs Prec ;
    } ;

  Pointeur_RAs Allouer_RAs (Pointeur_RAs *P)
    {
    *P = (struct Maillon_RAs *) malloc( sizeof( struct Maillon_RAs))   ;
    (*P)->Suiv = NULL;
    (*P)->Prec = NULL;
    }

  void Aff_val_RAs(Pointeur_RAs P, Typeelem_RAs Val)
    {
     P->Val = Val ;
    }

  void Aff_adrd_RAs( Pointeur_RAs P,  Pointeur_RAs Q)
    { P->Suiv = Q; }

  void Aff_adrg_RAs( Pointeur_RAs P,  Pointeur_RAs Q)
    { P->Prec = Q; }

  Pointeur_RAs Suivant_RAs(  Pointeur_RAs P)
    { return( P->Suiv );  }

  Pointeur_RAs Precedent_RAs(  Pointeur_RAs P)
    { return( P->Prec );  }

  Typeelem_RAs Valeur_RAs( Pointeur_RAs P)
    { return( P->Val) ; }

  void Liberer_RAs ( Pointeur_RAs P)
   { free (P) ; }


  /** Implémentation **\: TABLEAU DE CHAINES DE CARACTERES**/

  /** Tableaux **/

  typedef string255 Typeelem_V1000s ;
  typedef Typeelem_V1000s * Typevect_V1000s ;

  Typeelem_V1000s Element_V1000s ( Typevect_V1000s V , int I1  )
    {
      return  *(V + I1-1 ) ;
    }

  void Aff_element_V1000s ( Typevect_V1000s V  , int I1 ,  Typeelem_V1000s Val )
    {
     strcpy( *(V + I1-1 ) , Val );
    }

  /** Variables du programme principal **/
  Pointeur_RAs Tete;
  Pointeur_RAs Maillon;
  Pointeur_RAs Suiv;
  Pointeur_RAs Prec;
  Pointeur_RAs P;
  Typevect_V1000s Tab;
  Pointeur_As N;
  bool Erreur;
  bool Stop;
  int Maxi , confirm=0 , pos=0;
  int I;
  int J;
  int L;
  int Long;
  string255 Mot;
  Pointeur_As _Px1;

  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }

  char  *Aleachaine ( int N )
    {
      int k;
      char  * Chaine = malloc(N+1);

      char Chr1[26] = "abcdefghijklmnopqrstuvwxyz";
      char Chr2[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

      for (k=0;k<N; k++)
        switch ( rand() % 2 ){
        case 0 :  *(Chaine+k) = Chr1[rand() % 26] ; break ;
        case 1 :  *(Chaine+k) = Chr2[rand() % 26] ; break ;
        }
      Chaine[k] =  '\0' ;

      return (Chaine);
    }

  int Longchaine ( string255 Ch  )
    {
      return strlen(Ch);
    }


  /** Prototypes des fonctions **/

  void Insert_arb (Pointeur_RAs *Mail , string255 *Moot , bool *Error);
  void Recherche_maillon (Pointeur_RAs *Head , string255 *Word , Pointeur_RAs *Qi , Pointeur_RAs *Suv , Pointeur_RAs *Prc);
  void Insert_maillon (Pointeur_RAs *Header , string255 *Ch , Pointeur_RAs *Pp , Pointeur_RAs *Siv , Pointeur_RAs *Pec);
  void Inordre (Pointeur_As *Rb);
  void Sup_maillon (Pointeur_RAs *Lis , Pointeur_RAs *Ras);
  void Existe (Pointeur_As *Tree , Pointeur_As *Ascendent , Pointeur_As *Nod , string255 *String);
  void Sup_noeud (Pointeur_RAs *Maillo , string255 *Chain , bool *Err);
  void Recherche_sup (Pointeur_RAs *Latete , string255 *Lemot , Pointeur_RAs *Qointe , Pointeur_RAs *Suivi , Pointeur_RAs *Prece);
  void Presentation();
  void verification (Pointeur_RAs Tete);

  /******************************************************************************/
  /* On lui donne le noeud à inserer                                            */
  /* ERREUR pour confirmer si l'insertion s'est bien déroulée                   */
  /******************************************************************************/
  void Insert_arb (Pointeur_RAs *Mail , string255 *Moot , bool *Error)
    {
      /** Variables locales **/
      Pointeur_As Noeud;
      Pointeur_As Res;
      Pointeur_As Father;
      Pointeur_As _Px1;

      /** Corps du module **/
     *Error  =  False ;
     Creernoeud_As(&Noeud ) ;
     Aff_info_As(Noeud , *Moot ) ;
     if( ( Valeur_RAs(*Mail ) == NULL )) {
       Aff_val_RAs(*Mail , Noeud ) ;
       }
     else
       {
       _Px1 =  Valeur_RAs(*Mail ) ;
       Existe ( &_Px1, & Father , & Res , & *Moot ) ;
       if( ( Res != NULL )) {
         *Error  =  True ;
         }
       else
         {
         if( (strcmp( Info_As(Noeud ), Info_As(Father )) < 0  )) {
           Aff_fg_As(Father , Noeud ) ;
           }
         else
           {
           Aff_fd_As(Father , Noeud ) ;

         } ;

       } ;

     } ;

    }
  /*=============================================================*/
  /*Recherche Q correspondant au maillon contenant l'arbre ayant */
  /*des chaines de longueur égale à celle de ch                  */
  /* Q = NIL : Elle renvoie le suivant et précédent              */
  /* Q # NIL : Elle renvoie Q                                    */
  /*=============================================================*/
  void Recherche_maillon (Pointeur_RAs *Head , string255 *Word , Pointeur_RAs *Qi , Pointeur_RAs *Suv , Pointeur_RAs *Prc)
    {
      /** Variables locales **/
      Pointeur_RAs Pi;
      string255 Chr;
      bool Existant;
      int Tail;

      /** Corps du module **/
     Chr = malloc(255 * sizeof(string255));
     Existant  =  False ;
     Allouer_RAs(&*Qi ) ;
     *Suv  =  NULL ;
     *Prc  =  NULL ;
     Tail  =  Longchaine(*Word ) ;
     if( ( *Head == NULL )) {
       *Qi  =  NULL; }
     else
       {
       Pi  =  *Head ;
       if( ( Suivant_RAs(*Head ) == NULL )) {
         if( ( Longchaine(Info_As(Valeur_RAs(Pi ) ) ) == Tail )) {
           *Qi  =  Pi ;
           }
         else
           {
           *Qi  =  NULL ;
           *Suv  =  Pi ;
           *Prc  =  Pi ;

         } ;
         }
       else
         {
         if( ( ( Tail < Longchaine(Info_As(Valeur_RAs(*Head ) ) ) ) || ( Tail > Longchaine(Info_As(Valeur_RAs(Precedent_RAs(*Head ) ) ) ) ) )) {
           *Qi  =  NULL ;
           *Suv  =  *Head ;
           *Prc  =  Precedent_RAs(*Head ) ;
           }
         else
           {
           if( ( Tail < ( L / 2 ) )) {
             *Prc  =  Pi ;
             *Suv  =  Suivant_RAs(Pi ) ;
             *Qi  =  NULL ;
             strcpy (Chr,   Info_As(Valeur_RAs(Pi ) )) ;
             while( ( ( ( Longchaine(Chr ) ) <= Tail ) && ( ! Existant ) )) {
               if( ( Longchaine(Chr ) == Tail )) {
                 Existant  =  True ;
                 *Qi  =  Pi ;
                 }
               else
                 {
                 *Qi  =  NULL ;
                 *Prc  =  Pi ;
                 Pi  =  Suivant_RAs(Pi ) ;
                 *Suv  =  Pi ;

               } ;
               strcpy (Chr,   Info_As(Valeur_RAs(Pi ) )) ;

             } ;
             }
           else
             {
             *Suv  =  Pi ;
             Pi  =  Precedent_RAs(Pi ) ;
             *Prc  =  Pi ;
             *Qi  =  NULL ;
             strcpy (Chr,   Info_As(Valeur_RAs(Pi ) )) ;
             while( ( ( Longchaine(Chr ) >= Tail ) && ( ! Existant ) )) {
               if( ( Longchaine(Chr ) == Tail )) {
                 Existant  =  True ;
                 *Qi  =  Pi ;
                 }
               else
                 {
                 *Qi  =  NULL ;
                 *Suv  =  Pi ;
                 Pi  =  Precedent_RAs(Pi ) ;
                 *Prc  =  Pi ;

               } ;
               strcpy (Chr,   Info_As(Valeur_RAs(Pi ) )) ;

             } ;

           } ;

         } ;

       } ;

     } ;

    }
  /******************************************************************************/
  /* Renvoie le maillon créé, dans P.                                           */
  /* Si la liste était vide, il sera dans Tete et Q sera à NIL                  */
  /******************************************************************************/
  void Insert_maillon (Pointeur_RAs *Header , string255 *Ch , Pointeur_RAs *Pp , Pointeur_RAs *Siv , Pointeur_RAs *Pec)
    {
      /** Variables locales **/
      Pointeur_As Racine;
      Pointeur_RAs Qq;

      /** Corps du module **/
     Creernoeud_As(&Racine ) ;
     Aff_info_As(Racine , *Ch ) ;
     Aff_fd_As(Racine , NULL ) ;
     Aff_fg_As(Racine , NULL ) ;
     if( ( *Pp == NULL )) {
       if( ( *Header == NULL )) {
         Allouer_RAs(&Qq ) ;
         Aff_adrd_RAs(Qq , NULL ) ;
         Aff_adrg_RAs(Qq , NULL ) ;
         Aff_val_RAs(Qq , Racine ) ;
         *Header  =  Qq ;
         }
       else
         {
         Allouer_RAs(&*Pp ) ;
         Aff_val_RAs(*Pp , Racine ) ;
         Aff_adrg_RAs(*Siv , *Pp ) ;
         Aff_adrd_RAs(*Pp , *Siv ) ;
         Aff_adrg_RAs(*Pp , *Pec ) ;
         Aff_adrd_RAs(*Pec , *Pp ) ;
         if( ( Longchaine(Info_As(Valeur_RAs(*Pp ) ) ) < Longchaine(Info_As(Valeur_RAs(*Header ) ) ) )) {
           *Header  =  *Pp ;

         } ;

       } ;

     } ;

    }
  /************************************************************************/
  /* Parcours innordre d'un arbre binaire de recherche                    */
  /************************************************************************/
  void Inordre (Pointeur_As *Rb)
    {
      /** Variables locales **/
      Pointeur_As _Px1;
      Pointeur_As _Px2;

      /** Corps du module **/
     if( ( *Rb != NULL )) {
       _Px1 =  Fg_As(*Rb ) ;
       Inordre ( &_Px1) ;
       printf ( " %s \n", Info_As(*Rb) ) ;
       _Px2 =  Fd_As(*Rb ) ;
       Inordre ( &_Px2) ;

     } ;

    }
  /************************************************************************/
  /*          Supprime le maillon "P" de la liste (Re-chainage)           */
  /************************************************************************/
 /* void Sup_maillon (Pointeur_RAs *Lis , Pointeur_RAs *Ras)
    {
*/
      /** Corps du module **/
   /*  if( ( *Lis == *Ras )) {
       *Ras  =  Suivant_RAs(*Lis ) ;

     } ;
     if( ( Suivant_RAs(*Lis ) != NULL )) {
       if( ( Suivant_RAs(Suivant_RAs(*Lis ) ) == *Lis )) {
         Aff_adrd_RAs(Suivant_RAs(*Lis ) , NULL ) ;
         Aff_adrg_RAs(Precedent_RAs(*Lis ) , NULL ) ;
         }
       else
         {
         if( ( Precedent_RAs(*Lis ) != NULL )) {
           Aff_adrd_RAs(Precedent_RAs(*Lis ) , Suivant_RAs(*Lis ) ) ;

         } ;
         if( ( Suivant_RAs(*Lis ) != NULL )) {
           Aff_adrg_RAs(Suivant_RAs(*Lis ) , Precedent_RAs(*Lis ) ) ;

         } ;

       } ;

     } ;
     Aff_adrd_RAs(*Lis , NULL ) ;
     Aff_adrg_RAs(*Lis , NULL ) ;
     Liberer_RAs(*Lis ) ;
     printf ( " %s", "" ) ;
     printf ( " %s", "* Racine a nil => Maillon correspondant supprimé" ) ;

    }*/
  /*===============================================================================*/
  /*Renvoie le noeud dont l'info = string (NIL s'il n'existe pas). En plus du pere */
  /*===============================================================================*/
  void Existe (Pointeur_As *Tree , Pointeur_As *Ascendent , Pointeur_As *Nod , string255 *String)
    {
      /** Variables locales **/
      bool Cherch;

      /** Corps du module **/
     Cherch  =  True ;
     *Nod  =  *Tree ;
     *Ascendent  =  NULL ;
     while( ( ( Cherch ) && ( *Nod != NULL ) )) {
       if( (strcmp( Info_As(*Nod ), *String) == 0  )) {
         Cherch  =  False ;
         }
       else
         {
         *Ascendent  =  *Nod ;
         if( (strcmp( Info_As(*Nod ), *String) > 0  )) {
           *Nod  =  Fg_As(*Nod ) ;
           }
         else
           {
           *Nod  =  Fd_As(*Nod ) ;

         } ;

       } ;

     } ;

    }

  /*************************************************************************/
  /*               Gère la suppression des noeuds de l'arbre               */
  /* Le parcours du tableau se fera à l'envers, donc on aura juste à suppr-*/
  /* -imer des feuilles.                                                   */
  /*************************************************************************/
 /* void Sup_noeud (Pointeur_RAs *Maillo , string255 *Chain , bool *Err)
    {*/
      /** Variables locales **/
     /* Pointeur_As Nd;
      Pointeur_As Padre;
      Pointeur_As Root;
      Pointeur_As Test;*/

      /** Corps du module **/
  /*   *Err  =  False ;
     Test  =  NULL ;
     Root  =  Valeur_RAs(*Maillo ) ;
     Existe ( & Root , & Padre , & Nd , & *Chain ) ;*/
    /*on recherche le noeud et son pere*/
    /* if( ( Nd != NULL )) {
       if( ( Padre == NULL )) {
         Aff_val_RAs(*Maillo , Test ) ;*/
        /*si le noeud a supprimer c'est la tete*/
    /*     }
       else
         {
         if( ( Fg_As(Padre ) == Nd )) {
           Aff_fg_As(Padre , Test ) ;
           }
         else
           {
           Aff_fd_As(Padre , Test ) ;

         } ;

       } ;
       Liberernoeud_As(Nd ) ;
       printf ( " %s", "" ) ;
       printf ( " %s", "* Mot supprime avec succes" ) ;
       }
     else
       {
       *Err  =  True ;

     } ;

    }*/
 /* void Recherche_sup (Pointeur_RAs *Latete , string255 *Lemot , Pointeur_RAs *Qointe , Pointeur_RAs *Suivi , Pointeur_RAs *Prece)
    {*/
      /** Variables locales **/
    /*  Pointeur_RAs Pointe;
      string255 Chn;
      bool Exis;
      int Tai;*/

      /** Corps du module **/
   /*  Chn = malloc(255 * sizeof(string255));
     Exis  =  False ;
     Allouer_RAs(&*Qointe ) ;
     *Suivi  =  NULL ;
     *Prece  =  NULL ;
     Tai  =  Longchaine(*Lemot ) ;
     if( ( *Latete == NULL )) {
       *Qointe  =  NULL; }
     else
       {
       Pointe  =  *Latete ;
       if( ( Suivant_RAs(*Latete ) == NULL )) {
         if( ( Longchaine(Info_As(Valeur_RAs(*Latete ) ) ) == Tai )) {
           *Qointe  =  Pointe ;

         } ;
         }
       else
         {
         if( ( Tai < ( L / 2 ) )) {
           *Prece  =  Precedent_RAs(Pointe ) ;
           *Suivi  =  Suivant_RAs(Pointe ) ;
           *Qointe  =  NULL ;
           strcpy (Chn,   Info_As(Valeur_RAs(Pointe ) )) ;
           while( ( ( ( Longchaine(Chn ) ) <= Tai ) && ( ! Exis ) )) {
             if( ( Longchaine(Chn ) == Tai )) {
               Exis  =  True ;
               *Prece  =  Precedent_RAs(Pointe ) ;
               *Qointe  =  Pointe ;
               *Suivi  =  Suivant_RAs(Pointe ) ;
               }
             else
               {
               *Qointe  =  NULL ;
               Pointe  =  Suivant_RAs(Pointe ) ;

             } ;
             strcpy (Chn,   Info_As(Valeur_RAs(Pointe ) )) ;

           } ;
           }
         else
           {
           *Suivi  =  Pointe ;
           Pointe  =  Precedent_RAs(Pointe ) ;
           *Prece  =  Precedent_RAs(Pointe ) ;
           *Qointe  =  NULL ;
           strcpy (Chn,   Info_As(Valeur_RAs(Pointe ) )) ;
           while( ( ( Longchaine(Chn ) >= Tai ) && ( ! Exis ) )) {
             if( ( Longchaine(Chn ) == Tai )) {
               Exis  =  True ;
               *Suivi  =  Suivant_RAs(Pointe ) ;
               *Qointe  =  Pointe ;
               *Prece  =  Precedent_RAs(Pointe ) ;
               }
             else
               {
               *Qointe  =  NULL ;
               Pointe  =  Precedent_RAs(Pointe ) ;

             } ;
             strcpy (Chn,   Info_As(Valeur_RAs(Pointe ) )) ;

           } ;

         } ;

       } ;

     } ;

    }*/
  void Presentation()
    {

      /** Corps du module **/
     printf ( " %s", "================================================================================================\n" ) ;
     printf ( " %s", "                       ECOLE NATIONALE SUPERIEURE D'INFORMATIQUE  \n" ) ;
     printf ( " %s", "                                           \n" ) ;
     printf ( " %s", "                   ALGORITHMIQUE ET STRUCTURES DE DONNEES DYNAMIQUES \n" ) ;
     printf ( " %s", "                          TP2:    Exploration de textes  \n" ) ;
     printf ( " %s", "================================================================================================\n" ) ;
     printf ( " %s", "          Realise par:                                                                \n" ) ;
     printf ( " %s", "                        - AOUAOUCHE Louiza                    GROUPE 02 1CPI-A 2017/2018    \n" ) ;
     printf ( " %s", "                        - MECHOUEK Lounes    \n" ) ;
     printf ( " %s", "                                                         \n" ) ;
     printf ( " %s", "          Encadres par:                                                       \n" ) ;
     printf ( " %s", "                  -Dr ZEGOUR                  -Dr KERMI                  -Dr HIDOUCI   \n" ) ;
     printf ( " %s", "                   \n" ) ;
     printf ( " %s", "================================================================================================\n" ) ;
     printf ( " %s", "\n\n" ) ;
     printf ( " %s", "-------------------------------------------------------------------------------------------- \n" ) ;
     printf ( " %s", "                        INSERTION A PARTIR D'UN FICHIER DE 5000 MOTS :\n" ) ;
     printf ( " %s", "--------------------------------------------------------------------------------------------\n" ) ;
     printf ( " %s", "\n\n" ) ;
     system("pause");
     printf ( " %s", "=========================================\n" ) ;

    }
    void verification (Pointeur_RAs Tete)
    /**                                                                                                                 **/
    /**RENVOIE 1 SI LA LISTE EST CIRCULAIRE ET QUE TOUS LES MAILLONS NE SONT PAS VIDES (INSERTION CORRECTE DES CHAINES)**/
    {
         Pointeur_RAs P;
         P=Tete;
          printf ( " %s", "\n\n-------------------------------------------------------------------------------------------- \n" ) ;
            printf ( " %s", "      VERIFICATION DES MOTS GENERES DANS LA STRUCTURE (par ordre lexicographique) :\n" ) ;
            printf ( " %s", "\n-------------------------------------------------------------------------------------------- \n" ) ;
            system("PAUSE");
            while( ( ( ! Stop ) && ( P != NULL ) )) {
                printf ( " %s", "-------> Maillon de taille :" );
                printf ( " %d \n\n", Longchaine(Info_As(Valeur_RAs(P))) ) ;
                _Px1 =  Valeur_RAs(P ) ;
                Inordre ( &_Px1) ;
                printf ( " %s", "=====================================================\n" ) ;
                P  =  Suivant_RAs(P ) ;
                if( ( P == Tete ))
                    {
                    printf("\n\n\t **** VERIFICATION ACHEVEE **** \n\n");
                    printf("\n * Reussite: la liste est bien circulaire. \n\n");
                    printf("\n * Reussite: aucun maillon vide. \n\n");
                    printf("\n * Reussite: toutes les chaines du fichier sont bien inserees. \n\n");

                    return ;
                    }

            }

    }


  int main(int argc, char *argv[])
    {

     Presentation() ;
     char chaine[25];
     Mot = malloc(255 * sizeof(string255));

     Stop  =  False ;
     Allouer_RAs(&Tete ) ;
     Allouer_RAs(&Maillon) ;
     Allouer_RAs(&Suiv ) ;
     Allouer_RAs(&Prec ) ;
     Tete  =  NULL ;

    FILE *Texte=fopen("lorem_ipsum.txt","r");
    if(Texte!=NULL)
    {
     while((confirm= fscanf(Texte,"%s",&chaine)) != EOF && confirm !=0)
        {
            for(pos=0;pos<=strlen(chaine);pos++)
            {
                if((chaine[pos]=='.' ) || ( chaine[pos]==',') || ( chaine[pos]==';') || ( chaine[pos]=='/')|| ( chaine[pos]=='!')|| ( chaine[pos]=='?')|| ( chaine[pos]=='-'))
                    chaine[pos]='\0';
            }

            strcpy(Mot,chaine);


            Recherche_maillon ( & Tete , & Mot , & Maillon , & Suiv , & Prec ) ;
             if( ( Maillon == NULL )) {
                    Insert_maillon ( & Tete , & Mot , & Maillon , & Suiv , & Prec ); }
            else
                {
                  Insert_arb ( & Maillon , & Mot , & Erreur ) ;
                  if( ( Erreur == True )) {
                        printf ( " %s", "\n INSERTION IMPOSSIBLE : CHAINE DEJA PRESENTE \n" ) ;
                        Erreur  =  False ;

            }
        }
        }


        verification(Tete);
    system("PAUSE");
      return 1;

    }

     else
     {
         printf("%s","Erreur ouverture fichier !");
         return 0;
     }



    }
