#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
    int RemainingDays;
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
int id = 0;

void Ajouter(void)
{
    int N;
    tache[compt].id = id;

    // Prendre le nombre de task à ajouter
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

        int inputJour, inputMois, inputAnnee;

        do
        {
            printf("\t\t\tEntrer Le jour: ");
            scanf("%d", &inputJour);
            if (inputJour < 1 || inputJour > 31)
            {
                printf("\t\t\t\tFormat du Jour incorrecte!\n");
            }
        } while (inputJour < 1 || inputJour > 31);

        tache[compt].deadline.jour = inputJour;

        do
        {
            printf("\t\t\tEntrer Le mois: ");
            scanf("%d", &inputMois);
            if (inputMois < 1 || inputMois > 12)
            {
                printf("\t\t\t\tFormat du Mois incorrecte!\n");
            }
        } while (inputMois < 1 || inputMois > 12);

        tache[compt].deadline.mois = inputMois;

        do
        {
            printf("\t\t\tEntrer L'annee: ");
            scanf("%d", &inputAnnee);
            if (inputAnnee < 2020 || inputAnnee > 2030)
            {
                printf("\t\t\t\tFormat d'an incorrecte!\n");
            }
        } while (inputAnnee < 2020 || inputAnnee > 2030);

        tache[compt].deadline.annee = inputAnnee;

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
        id++;

        Taches trideadln;

        int daysResult, monthResult, yearResult;
    }

    // Calcul de Deadline
    time_t t = time(NULL);
    struct tm datenow = *localtime(&t);

    int daysResult, monthResult, yearResult;

    for (int i = 0; i < compt; i++)
    {
        daysResult = tache[i].deadline.jour - datenow.tm_mday;
        monthResult = tache[i].deadline.mois - (datenow.tm_mon + 1);
        yearResult = tache[i].deadline.annee - (datenow.tm_year + 1900);

        tache[i].deadline.RemainingDays = daysResult + (monthResult * 30) + (yearResult * 365);
    }

    system("cls");
    printf("\t\tAjouté avec succes!\n");
    sleep(1);
}
void TrierAlphabet(void)
{

    Taches tritask;

    for (int i = 0; i < compt; i++)
    {
        for (int j = i + 1; j < compt; j++)
        {
            int result = strcasecmp(tache[i].titre, tache[j].titre);
            if (result > 0)
            {

                tritask = tache[j];
                tache[j] = tache[i];
                tache[i] = tritask;
            }
        }
    }
    printf("\n\n\t\t\tLes taches triés d'orde alphabetique\n\n\n");
    printf("___________________________________________________________________________________________________\n\n");
    printf("| Id |      Titre          |      Description           |      Statut       |   Date   |  Deadline  |\n");
    printf("___________________________________________________________________________________________________\n\n");

    for (int i = 0; i < compt; i++)
    {

        printf("| %d | %20s | %20s\t| %15s | %d/%d/%d |  %d jours  |\n\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee, tache[i].deadline.RemainingDays);
    }
    printf("____________________________________________________________________________________________________\n\n");

    printf("\tAppuyez sur une touche, Pour aller au menu principal");
    getch();
    system("cls");
}
void TrierDeadline(void)
{
    Taches trideadln;

    int daysResult, monthResult, yearResult;

    time_t t = time(NULL);
    struct tm datenow = *localtime(&t);
    for (int i = 0; i < compt; i++)
    {
        daysResult = tache[i].deadline.jour - datenow.tm_mday;
        monthResult = tache[i].deadline.mois - (datenow.tm_mon + 1);
        yearResult = tache[i].deadline.annee - (datenow.tm_year + 1900);

        tache[i].deadline.RemainingDays = daysResult + (monthResult * 30) + (yearResult * 365);
    }

    // le Tri des Deadline
    for (int i = 0; i < compt; i++)
    {
        for (int j = i + 1; j < compt; j++)
        {
            if (tache[i].deadline.RemainingDays > tache[j].deadline.RemainingDays)
            {
                trideadln = tache[j];
                tache[j] = tache[i];
                tache[i] = trideadln;
            }
        }
    }

    // Affichage des taches triés
    printf("\n\n\t\t\tLes taches triés Par Deadline\n\n\n");
    printf("_____________________________________________________________________________________________________\n\n");
    printf("| Id |      Titre          |      Description           |      Statut       |   Date   |  Deadline  |\n");
    printf("_____________________________________________________________________________________________________\n\n");

    for (int i = 0; i < compt; i++)
    {
        printf("| %d | %20s\t | %20s \t| %15s | %d/%d/%d | %d jours |\n\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee, tache[i].deadline.RemainingDays);
    }
    printf("____________________________________________________________________________________________________\n\n");

    printf("\tAppuyez sur une touche, Pour aller au menu principal");
    getch();
    system("cls");
}
void ThreeDeadline(void)
{
    int c = 0;
    printf("\t\t\t > Taches triés De moins de 3 jours!\n\n");

    printf("_________________________________________________________________________________________________________\n\n");
    printf("| Id |          Titre            |      Description           |      Statut       |   Date   |  Deadline  |\n");
    printf("__________________________________________________________________________________________________________\n\n");

    // Verification Des taches
    for (int i = 0; i < compt; i++)
    {

        if (tache[i].deadline.RemainingDays <= 3 && tache[i].deadline.RemainingDays > 0)
        {
            printf("| %d | %20s | %20s\t | %15s | %d/%d/%d | %d jours |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee, tache[i].deadline.RemainingDays);
            printf("_________________________________________________________________________________________________\n\n");
            c++;
        }
    }

    if (c == 0)
    {
        printf("\t\tAucune tache <= 3 jours\n");
    }

    printf("\tAppuyez sur une touche, Pour aller au menu principal");
    getch();
    system("cls");
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
        printf("\t\t\t > 0 . Aller au menu principal.\n");
        scanf("%d", &trichoix);

        if (trichoix == 1)
        {
            TrierAlphabet();
        }
        else if (trichoix == 2)
        {
            TrierDeadline();
        }
        else if (trichoix == 3)
        {
            ThreeDeadline();
        }
        else if (trichoix == 0)
        {
        }

    } while (trichoix != 1 && trichoix != 2 && trichoix != 3 && trichoix != 0);
}
void Afficher(void)
{
    if (NombreDeTaches == 0)
    {
        printf("Aucune tache pour le moment!");
    }
    else
    {
        printf("___________________________________________________________________________________________________\n\n");
        printf("| Id |      Titre          |      Description           |      Statut       |   Date   | Deadline |\n");
        printf("___________________________________________________________________________________________________\n\n");

        for (int i = 0; i < compt; i++)
        {

            printf("| %2d | %20s | %20s\t | %15s | %d/%d/%d | %d jours |\n\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee, tache[i].deadline.RemainingDays);
        }
        printf("___________________________________________________________________________________________________\n\n");
        Trier();
    }
}
void Modifier(void)
{
    if (NombreDeTaches == 0)
    {
        printf("Aucune tache pour le moment!");
    }
    else
    {
        int choixmodif, choix2;

        printf("___________________________________________________________________________________________________\n\n");
        printf("| Id |      Titre          |        Description              |      Statut       |   Date   |  Deadline  |\n");
        printf("___________________________________________________________________________________________________\n\n");

        for (int i = 0; i < compt; i++)
        {

            printf("| %d | %20s | %30s | %20s\t| %d/%d/%d |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
            printf("_________________________________________________________________________________________________\n\n");
        }

        printf("\n\n");
        printf("\t\tChoisis l'id du task à modifier: ");
        scanf("%d", &choixmodif);

        for (int i = 0; i < compt; i++)
        {
            if (choixmodif == tache[i].id)
            {
                // Chercher l'id à modifier
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
                // Modification du statut
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

        // Calcul de Deadline
        time_t t = time(NULL);
        struct tm datenow = *localtime(&t);

        int daysResult, monthResult, yearResult;

        for (int i = 0; i < compt; i++)
        {
            daysResult = tache[i].deadline.jour - datenow.tm_mday;
            monthResult = tache[i].deadline.mois - (datenow.tm_mon + 1);
            yearResult = tache[i].deadline.annee - (datenow.tm_year + 1900);

            tache[i].deadline.RemainingDays = daysResult + (monthResult * 30) + (yearResult * 365);
        }
    }
}
void Rechercher(void)
{

    if (NombreDeTaches == 0)
    {
        printf("Aucune tache pour le moment!");
    }
    else
    {

        int choixrech, choixid;
        char rech[100];

        printf("___________________________________________________________________________________________________\n\n");
        printf("| Id |      Titre          |          Description           |      Statut       |   Date   |  Deadline  |\n");
        printf("___________________________________________________________________________________________________\n\n");

        for (int i = 0; i < compt; i++)
        {

            printf("| %d | %20s | %30s| %20s | %d/%d/%d |\n\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee);
        }
        printf("___________________________________________________________________________________________________\n\n");

        printf("\t\tRechercher par:\n");
        printf("\t\t\t.1. Id\n");
        printf("\t\t\t.2. Titre\n");
        scanf("%d", &choixrech);

        if (choixrech == 1)
        {
            printf("Entrer l'id à rechercher:\n");
            scanf("%d", &choixid);

            printf("___________________________________________________________________________________________________\n\n");
            printf("| Id |      Titre          |      Description           |      Statut       |   Date   |  Deadline  |\n");
            printf("___________________________________________________________________________________________________\n\n");

            for (int i = 0; i < NombreDeTaches; i++)
            {
                if (choixid == tache[i].id)
                {
                    printf("| %d | %20s | %20s | %20s | %d/%d/%d | %d jours |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee, tache[i].deadline.RemainingDays);
                }
            }
            printf("___________________________________________________________________________________________________\n\n");
        }
        else if (choixrech == 2)
        {
            printf("Entrer le titre à rechercher:\n");
            scanf("%s", rech);
            printf("\n\n");
            printf("___________________________________________________________________________________________________\n\n");
            printf("| Id |      Titre          |      Description           |      Statut       |   Date   |  Deadline  |\n");
            printf("___________________________________________________________________________________________________\n\n");

            for (int i = 0; i < NombreDeTaches; i++)
            {

                if (strcmp(rech, tache[i].titre) == 0)
                {
                    printf("| %d | %20s | %20s| %20s | %d/%d/%d | %d jours |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee, tache[i].deadline.RemainingDays);
                }
            }
            printf("_________________________________________________________________________________________________\n\n");
        }
    }

    printf("\tAppuyez sur une touche, Pour aller au menu principal");
    getch();
    system("cls");
}
void Supprimer(void)
{

    if (NombreDeTaches == 0)
    {
        printf("Aucune tache pour le moment!");
    }
    else
    {

        int choixid;

        printf("___________________________________________________________________________________________________\n\n");
        printf("| Id |      Titre          |         Description           |      Statut       |   Date   |  Deadline  |\n");
        printf("___________________________________________________________________________________________________\n\n");

        for (int i = 0; i < compt; i++)
        {

            printf("| %d | %20s | %30s | %20s \t| %d/%d/%d | %d jours |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee, tache[i].deadline.RemainingDays);
        }
        printf("___________________________________________________________________________________________________\n\n");

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

        system("cls");
        printf("\t\t\tSupprimé!\n\n");
        sleep(1);

        printf("___________________________________________________________________________________________________\n\n");
        printf("| Id |      Titre          |      Description           |      Statut       |   Date   |  Deadline  |\n");
        printf("___________________________________________________________________________________________________\n\n");

        for (int i = 0; i < compt; i++)
        {

            printf("| %d | %25s | %25s| %20s | %d/%d/%d | %d jours |\n", tache[i].id, tache[i].titre, tache[i].description, tache[i].status, tache[i].deadline.jour, tache[i].deadline.mois, tache[i].deadline.annee, tache[i].deadline.RemainingDays);
        }
        printf("_________________________________________________________________________________________________\n\n");
    }
}
void Stats(void)
{
    if (NombreDeTaches == 0)
    {
        printf("Aucune tache pour le moment!");
    }
    else
    {

        // counter finished /unfinished
        int statsC = 0;

        printf("\n\n\n\n");
        printf("\t\t\t***STATISTIQUES***\n\n\n");
        printf("\t> Nombre Total des Taches: %d\n\n", NombreDeTaches);
        printf("\t> Statut des Taches\n\n");

        for (int i = 0; i < compt; i++)
        {
            int OuiNon = strcmp(tache[i].status, "finalisé");

            if (OuiNon == 0)
            {
                statsC++;
            }
        }
        int complete = statsC;

        // Stats complète / imcomplète
        printf("\t\t* %d Taches completes.\n", complete);
        printf("\n");
        printf("\t\t* %d Taches imcompletes.\n\n\n\n", NombreDeTaches - complete);

        printf("\t> Deadline des Taches\n");
        printf("________________________________________________________________________________________\n\n");
        printf("| Id |  Deadline  |      Titre          |      Description           |      Statut     |\n");
        printf("________________________________________________________________________________________\n\n");

        for (int i = 0; i < compt; i++)
        {
            printf("| %d | %d jours | %20s | %20s\t | %20s |\n\n", tache[i].id, tache[i].deadline.RemainingDays, tache[i].titre, tache[i].description, tache[i].status);
        }
        printf("_________________________________________________________________________________________\n\n");
    }

    printf("\tAppuyez sur une touche, Pour aller au menu principal");
    getch();
    system("cls");
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

    return 0;
}