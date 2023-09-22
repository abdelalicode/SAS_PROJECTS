#include <stdio.h>
#include <string.h>
#include <time.h>

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
int statutMenu;

void Ajouter(void)
{
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
        printf("\t\t\tEntrer Le jour: ");
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
                printf("\t\tchoix invalide!\n");

        } while (statutMenu != 1 && statutMenu != 2 && statutMenu != 3);

        compt++;
        NombreDeTaches++;
    }
}
int Deadline(int ind)
{
    /* time_t Horraire_Current = time(NULL);
    struct tm dated;

    dated.tm_mday = tache[ind].deadline.jour;
    dated.tm_mon = tache[ind].deadline.mois - 1;
    dated.tm_year = tache[ind].deadline.annee - 1900;

    time_t dated = mktime(&deadline); */
}
void TrierAlphabet(void)
{

    Taches tritask;

    for (int i = 0; i < compt; i++)
    {
        for (int j = i + 1; j < compt; j++)
        {
            int result = strcmp(tache[i].titre, tache[j].titre);
            if (result > 0)
            {

                tritask = tache[j];
                tache[j] = tache[i];
                tache[i] = tritask;
            }
        }
    }
    printf("\n\n\t\t\tLes taches triés d'orde alphabetique\n\n\n");
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
void Modifier(void)
{
    int choixmodif, choix2;

    printf("__________________________________________________________________________________________________\n\n");
    printf("| Id |\n");
    printf("__________________________________________________________________________________________________\n\n");

    for (int i = 0; i < compt; i++)
    {

        printf("| %d | %20s | %20s\t| %20s\t| %d/%d/%d |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
        printf("_________________________________________________________________________________________________\n\n");
    }

    printf("\n\n");
    printf("\t\tChoisis l'id du task à modifier: ");
    scanf("%d", &choixmodif);

    for (int i = 0; i < compt; i++)
    {
        if (choixmodif == tache[i].id)
        {
            printf("\t\tEntrer votre choix à modifier.\n");
            printf("\t\t\t.1. Modifier La description\n");
            printf("\t\t\t.2. Modifier Le Statut\n");
            printf("\t\t\t.3. Modifier Deadline\n");
            scanf("%d", &choix2);

            // Modification de description
            if (choix2 == 1)
            {
                printf("\t\tEntrer Le texte: \n");
                getchar();
                gets(tache[i].description);
                system("cls");
                printf("\t\tModification avec succes!");
                sleep(1);
            }
            else if (choix2 == 2)
            {

                do
                {
                    printf("\n\t\t> Statut:\n");
                    printf("\t\t\t.1. à realiser.\n");
                    printf("\t\t\t.2. en cours.\n");
                    printf("\t\t\t.3. finalisé\n");
                    printf("\t\tEntrer Le nombre de votre choix: ");

                    scanf("%d", &statutMenu);
                    if (statutMenu == 1)
                    {
                        strcpy(tache[i].status, "à realiser");
                        system("cls");
                        printf("\t\tModification avec succes!");
                        sleep(1);
                    }
                    else if (statutMenu == 2)
                    {
                        strcpy(tache[i].status, "En cours");
                        system("cls");
                        printf("\t\tModification avec succes!");
                        sleep(1);
                    }
                    else if (statutMenu == 3)
                    {
                        strcpy(tache[i].status, "finalisé");
                        system("cls");
                        printf("\t\tModification avec succes!");
                        sleep(1);
                    }
                    else
                        printf("\tchoix invalide!");

                } while (statutMenu != 1 && statutMenu != 2 && statutMenu != 3);
            }
            else if (choix2 == 3)
            {

                printf("\n\t\t> Deadline:\n");
                printf("\t\t\tEntrer Le jour: ");
                scanf("%d", &tache[i].deadline.jour);

                printf("\t\t\tEntrer Le mois: ");
                scanf("%d", &tache[i].deadline.mois);

                printf("\t\t\tEntrer L'annee: ");
                scanf("%d", &tache[i].deadline.annee);

                system("cls");
                printf("\t\tModification avec succes!");
                sleep(1);
            }
        }
    }
}
void Rechercher(void)
{
    int choixrech, choixid;
    char rech[100];

    printf("__________________________________________________________________________________________________\n\n");
    printf("| Id |\n");
    printf("__________________________________________________________________________________________________\n\n");

    for (int i = 0; i < compt; i++)
    {

        printf("| %d | %20s | %20s| %20s | %d/%d/%d |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
        printf("_________________________________________________________________________________________________\n\n");
    }

    printf("\t\tRechercher par:\n");
    printf("\t\t\t.1. Id\n");
    printf("\t\t\t.2. Titre\n");
    scanf("%d", &choixrech);

    if (choixrech == 1)
    {
        printf("Entrer l'id à rechercher:\n");
        scanf("%d", &choixid);

        printf("__________________________________________________________________________________________________\n\n");
        printf("| Id |\n");
        printf("__________________________________________________________________________________________________\n\n");

        for (int i = 0; i < NombreDeTaches; i++)
        {
            if (choixid == tache[i].id)
            {
                printf("| %d | %20s | %20s| %20s | %d/%d/%d |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
                printf("_________________________________________________________________________________________________\n\n");
            }
        }
    }
    else if (choixrech == 2)
    {
        printf("Entrer le titre à rechercher:\n");
        scanf("%s", rech);
        printf("__________________________________________________________________________________________________\n\n");
        printf("| Id |\n");
        printf("__________________________________________________________________________________________________\n\n");
        for (int i = 0; i < NombreDeTaches; i++)
        {

            if (strcmp(rech, tache[i].titre) == 0)
            {
                printf("| %d | %20s | %20s| %20s | %d/%d/%d |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
                printf("_________________________________________________________________________________________________\n\n");
            }
        }
    }
}
void Supprimer(void)
{
    int choixid;

    printf("__________________________________________________________________________________________________\n\n");
    printf("| Id |\n");
    printf("__________________________________________________________________________________________________\n\n");

    for (int i = 0; i < compt; i++)
    {

        printf("| %d | %20s | %20s| %20s | %d/%d/%d |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
        printf("_________________________________________________________________________________________________\n\n");
    }

    printf("Entrer l'id à supprimer: \n");
    scanf("%d", &choixid);

    int indice;

    // check all indices of tasks
    for (int i = 0; i < compt; i++)
    {

        if (choixid == tache[i].id)
        {
            indice = i;
        }
    }

    for (int j = indice; j < compt - 1; j++)
    {
        tache[j] = tache[j + 1];
    }
    compt--;
    NombreDeTaches--;
    printf("\t\t\tSupprimé!\n\n");

    printf("__________________________________________________________________________________________________\n\n");
    printf("| Id |\n");
    printf("__________________________________________________________________________________________________\n\n");

    for (int i = 0; i < compt; i++)
    {

        printf("| %d | %20s | %20s| %20s | %d/%d/%d |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
        printf("_________________________________________________________________________________________________\n\n");
    }
}
void Stats(void)
{
    // counter finished /unfinished
    int statsC = 0;

    printf("\t\t\t***STATISTIQUES***\n\n");
    printf("\t> Nombre Total des Taches: %d\n\n", NombreDeTaches);
    printf("\t> Statut des Taches\n");

    for (int i = 0; i < compt; i++)
    {
        int OuiNon = strcmp(tache[i].status, "finalisé");

        if (OuiNon = 0)
        {
            statsC++;
        }
    }
    int complete = statsC + 1;

    printf("\t\t* %d Taches completes.\n", complete);
    printf("\n");
    printf("\t\t* %d Taches imcompletes.\n", NombreDeTaches - complete);
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
        case 3:
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
            break;
        case 0:
            printf("Project SAS out!");
            break;
        default:
            printf("Erreur! Choix invalide.\n");
            break;
        }
    } while (menu != 0);
}