
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "menu.h"
#include <string.h>
#include <time.h>

#include <stdio.h>



void ajouter_nb(nutri A)
{
    FILE *F=NULL;

F=fopen("menu.txt","a");
if(F!=NULL)
{

    fprintf(F,"%0.2s %s %s %s %s %d %s %s \n",A.id,A.type,A.plat,A.ing,A. date,A.nb,A.groupetr,A.modetr);
    fclose(F);
    

}

}

void supp_nb(char id[])
{
  
   FILE *F, *FW;
  nutri D ;
  
F = fopen ("menu.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL))
 {


  while (fscanf (F, "%s %s %s %s %s %d %s %s",D.id,D.type,D.plat,D.ing,D. date,&D.nb,D.groupetr,D.modetr) == 8)
    if (strcmp (D.id, id) != 0) 
      fprintf (FW, "%s %s %s %s %s %d %s %s \n", D.id,D.type,D.plat,D.ing,D. date,D.nb,D.groupetr,D.modetr);
}
  fclose (F);
  fclose (FW);
remove("menu.txt");
rename("tr.txt", "menu.txt");




}

nutri rech_nb(char id[])
{

FILE *F;
  nutri Q;
  nutri A;
  
F = fopen ("menu.txt", "r");


  if (F!=NULL)
{
  while (fscanf (F, "%s %s %s %s %s %d %s %s", Q.id,Q.type,Q.plat,Q.ing,Q. date, &Q.nb,Q.groupetr,Q.modetr) != EOF)
    if (strcmp (Q.id, id) == 0) 
        {
        strcpy(A.type,Q.type); 
        strcpy(A.plat,Q.plat);
        strcpy(A.ing,Q.ing);
        strcpy(A.date,Q.date);
	strcpy(A.groupetr,Q.groupetr);
	strcpy(A.modetr,Q.modetr);
	
        }

  }
  return (A);
  fclose (F);  
}


///////////////  MODIFICATION   /////////////////
void modi_nb(char id [] , nutri U) 
{
   FILE *F, *FW;
  nutri c; 
  
F = fopen ("menu.txt", "r");
FW = fopen ("tr.txt", "w");

  if ((F!=NULL)&&(FW!=NULL)) 
{
  while (fscanf (F, "%s %s  %s %s %s %d %s %s",c.id,c.type,c.plat,c.ing,c. date,&c.nb,c.groupetr,c.modetr) ==8) 
	
    if (strcmp (c.id, id) == 0)
     {

fprintf (FW, "%s %s %s %s %s %d %s %s\n",id,U.type,U.plat,U.ing,U.date,U.nb,U.groupetr,U.modetr);
     }
     else
     {

       fprintf (FW, "%s %s %s %s %s %d %s %s\n", c.id,c.type,c.plat,c.ing,c. date,c.nb,c.groupetr,c.modetr);
     }
}    

  fclose (F);
  fclose (FW);
remove("menu.txt");
rename("tr.txt", "menu.txt");

}


//////////////////   AFFICHER    ///////////////////
void afficher_nb (GtkWidget *treeviewkhouloud, char*l )

{
GtkListStore *adstore;      
GtkTreeViewColumn *adcolumn;      
GtkCellRenderer *cellad;  
FILE *f;

        int m;
	char id[30];
	char type[30];
	char nb[30];
	char plat[30];
	char ing[30];
	char date[30];
	char groupetr[30];
	char modetr [30];

        /* Creation du modele de type liste*/
        adstore = gtk_list_store_new(8,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s %s %s\n",id,type,plat,ing,date,nb,groupetr ,modetr)!= EOF)
        {
         GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,id,
                            1,type,
                            2,plat,
                            3,ing,
                            4,date,
			    5,nb,
                            6,groupetr,
                            7,modetr,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(m==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewkhouloud), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("nom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewkhouloud), adcolumn);




	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Ingrédient",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewkhouloud), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Plat",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewkhouloud), adcolumn);


        /* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewkhouloud), adcolumn);

	/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Quantite",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);

	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewkhouloud), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("dessert",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);

	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewkhouloud), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("type",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);

	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewkhouloud), adcolumn);


	m++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeviewkhouloud),
                                  GTK_TREE_MODEL(adstore)  );

}
//
/*
void meilleur_menu(GtkWidget *treeviewkhouloud)
    {
        FILE *f=NULL;
FILE *meill=NULL;
        int a,b,c,j1,m1,j2,m2,j3,m3,cmp1=1000,cmp2=1000,cmp3=1000,x,y,z;
        f=fopen("dechets.txt","r");
        if(f!=NULL)
        {

            while(fscanf(f,"%d %d %d \n",&a,&b,&c)!=EOF)
            {
                 if(cmp1>c&&b==1)
                 {
                    cmp1=c;
                    j1=a;
                    m1=b;
                 }
if(cmp2>c&&b==2)
                 {
                    cmp2=c;
                    j2=a;
                    m2=b;
                 }
if(cmp3>c&&b==3)
                 {
                    cmp3=c;
                    j3=a;
                    m3=b;
                 }
            }
}
            fclose(f);
        meill=fopen("meill.txt","w");
fprintf(f,"%d %d %d \n%d %d %d \n%d %d %d \n",j1,m1,cmp1,j2,m2,cmp2,j3,m3,cmp3);
        fclose(meill);
GtkListStore *store;
 store=NULL;
 store=gtk_tree_view_get_model(treeviewkhouloud);
adstore = gtk_list_store_new(3,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_INT);
meill=fopen("meill.txt","r");
while (fscanf(meill,"%d %d %d \n",&x,&y,&z)!=EOF)
{
GtkTreeIter pIter;
         gtk_list_store_append(adstore, &pIter);
gtk_list_store_set(adstore, &pIter,
                            0,x,
                            1,y,
   2,z,-1);}
        fclose(meill);
if(store==0)
{
cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("jj",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewkhouloud), adcolumn);
cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("dd",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(treeviewkhouloud), adcolumn);
cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("mm",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
}
gtk_tree_view_set_model ( GTK_TREE_VIEW (treeviewkhouloud),
                                  GTK_TREE_MODEL(adstore)  );

}



//
void
on_button_meill_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *affiche;
affiche=lookup_widget(button,"affichage");
meilleur_menu(lookup_widget(affiche,"treeviewkhouloud"));

}

*/
