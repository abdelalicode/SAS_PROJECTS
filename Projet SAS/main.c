#include <stdio.h>
#include <string.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct
{
    int id;
    char titre[100];
    char description[100];
    char status[30];
    Date deadline;

} Taches;

Taches tache[1000];
int compt = 0;
int NombreDeTaches = 0;

void Ajouter(void)
{
    int statutMenu;
    int N;
    tache[compt].id = 0;

    printf("\n\n");
    printf("\t\tEntrer le nombre de tache à ajouter: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        tache[compt].id = compt + 1;

        printf("\n\t\tTache id: %d\n", compt + 1);
        printf("\t\t-----------");
        printf("\n\t\t> Entrer Le titre du tache: ");
        getchar();
        gets(tache[compt].titre);

        printf("\n\t\t> Entrer La description: ");
        getchar();
        gets(tache[compt].description);

        printf("\n\t\t> Deadline:\n");
        printf("\t\t\tEntrer Le jour:");
        scanf("%d", &tache[compt].deadline.jour);

        printf("\t\t\tEntrer Le mois: ");
        scanf("%d", &tache[compt].deadline.mois);

        printf("\t\t\tEntrer L'annee: ");
        scanf("%d", &tache[compt].deadline.annee);

        do
        {
            printf("\n\t\t> Statut:\n");
            printf("\t\t\t.1. à realiser.\n");
            printf("\t\t\t.2. en cours.\n");
            printf("\t\t\t.3. finalisé\n");
            printf("\t\tEntrer Le nombre de votre choix: ");

            scanf("%d", &statutMenu);
            if (statutMenu == 1)
                strcpy(tache[compt].status, "à realiser");
            else if (statutMenu == 2)
                strcpy(tache[compt].status, "En cours");
            else if (statutMenu == 3)
                strcpy(tache[compt].status, "finalisé");
            else
                printf("choix invalide!");

        } while (statutMenu != 1 && statutMenu != 2 && statutMenu != 3);

        compt++;
        NombreDeTaches++;
    }
}
void TrierAlphabet(void)
{
    for (int i = 0; i < NombreDeTaches; i++)
    {
        for (int j = i + 1; j < NombreDeTaches; j++)
        {

            int result = strcmp(tache[i].titre, tache[j].titre);
            if (result > 0)
            {
                int tempid = tache[j].id;
                tache[j].id = tache[i].id;
                tache[i].id = tempid;

                char temptri[50];
                strcpy(temptri, tache[j].titre);
                strcpy(tache[j].titre, tache[i].titre);
                strcpy(tache[i].titre, temptri);

                strcpy(temptri, tache[j].description);
                strcpy(tache[j].description, tache[i].description);
                strcpy(tache[i].description, temptri);

                strcpy(temptri, tache[j].status);
                strcpy(tache[j].status, tache[i].status);
                strcpy(tache[i].status, temptri);

                tempid = tache[j].deadline.jour;
                tache[j].deadline.jour = tache[i].deadline.jour;
                tache[i].deadline.jour = tempid;

                tempid = tache[j].deadline.mois;
                tache[j].deadline.mois = tache[i].deadline.mois;
                tache[i].deadline.mois = tempid;

                tempid = tache[j].deadline.annee;
                tache[j].deadline.annee = tache[i].deadline.annee;
                tache[i].deadline.annee = tempid;
            }
        }
    }
    printf("\n\n\t\t\tLes taches trié d'orde alphabetique\n\n\n");
    printf("______________________________________________________________________________________________________________\n\n");
    printf("| Id |\n");
    printf("______________________________________________________________________________________________________________\n\n");

    for (int i = 0; i < compt; i++)
    {

        printf("| %d | %20s | %20s| %20s | %d/%d/%d |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
        printf("______________________________________________________________________________________________________________\n\n");
    }
}

void Trier(void)
{
    int trichoix;

    do
    {
        printf("\t\tTrier Les Resultats:\n");
        printf("\t\t\t > 1 . Par ordre alphabetique\n");
        printf("\t\t\t > 2 . Par deadline\n");
        printf("\t\t\t > 3 . Afficher Toutes les taches de moins de 3 jours au deadline\n");
        scanf("%d", &trichoix);

        if (trichoix == 1)
        {
            TrierAlphabet();
        }

    } while (trichoix != 1 && trichoix != 2 && trichoix != 3);
}
void Afficher(void)
{
    printf("__________________________________________________________________________________________________\n\n");
    printf("| Id |\n");
    printf("__________________________________________________________________________________________________\n\n");

    for (int i = 0; i < compt; i++)
    {

        printf("| %d | %20s | %20s| %20s | %d/%d/%d |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
        printf("_________________________________________________________________________________________________\n\n");
    }

    Trier();
}
int main(void)
{

    int menu;

    do
    {
        printf("\n\n\n");
        printf("\t\t\tvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
        printf("\t\t\t\tGestion de Taches ToDo 1.0\n");
        printf("\t\t       Creé par: Abdelali TAHA - Projet fin SAS 2023\n\n\n");
        printf("\t\t\t---------------------------------------------\n");
        printf("\t\t\t---------------------------------------------\n");
        printf("\t\t\t1.  Ajouter une nouvelle tache\n");
        printf("\n");
        printf("\t\t\t2.  Afficher la liste de toutes les taches\n");
        printf("\n");
        printf("\t\t\t3.  Modifier une tache\n");
        printf("\n");
        printf("\t\t\t4.  Supprimer une tache\n");
        printf("\n");
        printf("\t\t\t5.  Rechercher une tache\n");
        printf("\n");
        printf("\t\t\t6.  Afficher les stats des taches\n");
        printf("\n");
        printf("\t\t\t0.  Quitter\n");
        printf("\t\t\t----------------------------------------------\n\n");
        printf("\t\tEntrer le nombre de votre choix:  ");

        scanf("%d", &menu);

        system("cls");

        switch (menu)
        {
        case 1:
            Ajouter();
            break;
        case 2:
            Afficher();
            break;
            /**  case 3:
                  Modifier();
                  break;
              case 4:
                  Supprimer();
                  break;
              case 5:
                  Rechercher();
                  break;
              case 6:
                  Stats();
                  break; */
        default:
            printf("Erreur! Choix invalide.\n");
            break;
        }
    } while (menu != 0);
}