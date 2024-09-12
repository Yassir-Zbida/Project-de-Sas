#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Depatement1 "Math"
#define Depatement2 "Physique"
#define Depatement3 "Informatique"
#define Depatement4 "Economie"
#define Depatement5 "Francais"
#define max_etudiants 100

typedef struct{
    int jours, mois, annee;
} date;

typedef struct{
    int  id;
    char nom[100];
    char prenom[100];
    date date_naissance;
    char depatement[100];
    float note;
} etudiants;

etudiants etudiant[max_etudiants];
int nb_etudiant = 0;

// Ajouter Seul Eudiant //
void ajouterSeulEtudiant(){
    int choix;
    etudiant[nb_etudiant].id = nb_etudiant + 1 ;
    printf("Identifiant d'etudiant est : %d \n", nb_etudiant + 1);
    printf("Entrer Le nom d'etudiant : ");
    scanf(" %[^\n]", etudiant[nb_etudiant].nom);
    printf("Entrer Le prenom d'etudiant : ");
    scanf(" %[^\n]", etudiant[nb_etudiant].prenom);
    do{
        printf("Entrer le jour de naissance d'etudiant (JJ) : ");
        scanf("%d", &etudiant[nb_etudiant].date_naissance.jours);

        printf("Entrer le mois de naissance d'etudiant (MM) : ");
        scanf("%d", &etudiant[nb_etudiant].date_naissance.mois);

        printf("Entrer l'annee de naissance d'etudiant (AAAA) : ");
        scanf("%d", &etudiant[nb_etudiant].date_naissance.annee);

        if (etudiant[nb_etudiant].date_naissance.jours <= 0 || etudiant[nb_etudiant].date_naissance.jours > 31 ||
            etudiant[nb_etudiant].date_naissance.mois <= 0 || etudiant[nb_etudiant].date_naissance.mois > 12 ||
            etudiant[nb_etudiant].date_naissance.annee < 1900 || etudiant[nb_etudiant].date_naissance.annee > 2008) {
            printf("Date invalide. Veuillez reessayer.\n");
        }
    } while (etudiant[nb_etudiant].date_naissance.jours <= 0 || etudiant[nb_etudiant].date_naissance.jours > 31 ||
             etudiant[nb_etudiant].date_naissance.mois <= 0 || etudiant[nb_etudiant].date_naissance.mois > 12 ||
             etudiant[nb_etudiant].date_naissance.annee < 1900 || etudiant[nb_etudiant].date_naissance.annee > 2008);
    do{
        printf("Departements :\t 1- Math \t 2- Physique \t 3- Informatique \t 4- Economie \t  5- Francais \n");
        printf("Entrer Departement : ");
        scanf("%d", &choix);

    } while (choix <= 0 || choix >= 6);
    switch (choix){
    case 1:
        strcpy(etudiant[nb_etudiant].depatement, Depatement1);
        break;
    case 2:
        strcpy(etudiant[nb_etudiant].depatement, Depatement2);
        break;
    case 3:
        strcpy(etudiant[nb_etudiant].depatement, Depatement3);
        break;
    case 4:
        strcpy(etudiant[nb_etudiant].depatement, Depatement4);
        break;
    case 5:
        strcpy(etudiant[nb_etudiant].depatement, Depatement5);
        break;

    default:
        printf("choix invalide ");
        break;
    }
    printf("La note d'etudiant : ");
    scanf("%f", &etudiant[nb_etudiant].note);
    nb_etudiant++;
};

// Ajouter plusieurs  Etudiants //
void ajoutePlusieursEtudiant(){
    int nb, i;
    printf("Combien de etudiants voulez-vous ajouter ? ");
    scanf("%d", &nb);
    if (nb > 0 && (nb_etudiant + nb) < max_etudiants){
        for (i = 0; i < nb; i++){
            printf("\nAjout de l'etudiant %d:\n", i + 1);
            ajouterSeulEtudiant();
        }
    }
    else{
        printf("Erreur : Vous ne pouvez pas ajouter plus de %d etudiants.\n", max_etudiants - nb_etudiant);
    }
}

// Modifier Etudiant //
void modifierEtudiant(){
    int id , choix , choix1;
    if (nb_etudiant == 0){
        printf("Aucun Etudiant a modifie");
    }
    else{
        printf("Entrer l'id d'etudiant : ");
    scanf("%d", &id);
    if (id < 0 || id > nb_etudiant){
        printf("ID invalid");
    }
    id--;
    printf("Vous voulez modifie : \n");
    printf("1.Nom\n");
    printf("2.Prenom\n");
    printf("3.Date de naissance\n");
    printf("4.Departement\n");
    printf("5.Note\n");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        printf("Entrer le nouveau nom a modifie : ");
        scanf(" %s[^/n]", etudiant[id].nom);
        printf("Le nom est modifie avec succes.\n");
        break;
    case 2:
        printf("Entrer le nouveau prenom a modifie : ");
        scanf("%s[^/n]", etudiant[id].prenom);
        printf("Le prenom est modifie avec succes.\n");
        break;
    case 3:
        printf("Entrer la date a modifie : ");
       do{
        printf("Entrer le jour de naissance d'etudiant (JJ) : ");
        scanf("%d", &etudiant[id].date_naissance.jours);

        printf("Entrer le mois de naissance d'etudiant (MM) : ");
        scanf("%d", &etudiant[id].date_naissance.mois);

        printf("Entrer l'annee de naissance d'etudiant (AAAA) : ");
        scanf("%d", &etudiant[id].date_naissance.annee);

        if (etudiant[id].date_naissance.jours <= 0 || etudiant[id].date_naissance.jours > 31 ||
            etudiant[id].date_naissance.mois <= 0 || etudiant[id].date_naissance.mois > 12 ||
            etudiant[id].date_naissance.annee < 1900 || etudiant[id].date_naissance.annee > 2008) {
            printf("Date invalide. Veuillez reessayer.\n");
        }
    } while (etudiant[id].date_naissance.jours <= 0 || etudiant[id].date_naissance.jours > 31 ||
             etudiant[id].date_naissance.mois <= 0 || etudiant[id].date_naissance.mois > 12 ||
             etudiant[id].date_naissance.annee < 1900 || etudiant[id].date_naissance.annee > 2008);
        printf("La date est modifie avec succes.\n");
        break;
    case 4:
        printf("Entrer la nouvelle departement a modifie : \n");
        do{
        printf("Departements :\t 1- Math \t 2- Physique \t 3- Informatique \t 4- Economie \t  5- Francais \n");
        printf("Entrer Departement : ");
        scanf("%d", &choix1);

    } while (choix1 <= 0 || choix1 >= 6);
      switch (choix1){
      case 1:
        strcpy(etudiant[id].depatement, Depatement1);
        break;
      case 2:
        strcpy(etudiant[id].depatement, Depatement2);
        break;
      case 3:
        strcpy(etudiant[id].depatement, Depatement3);
        break;
      case 4:
        strcpy(etudiant[id].depatement, Depatement4);
        break;
      case 5:
        strcpy(etudiant[id].depatement, Depatement5);
        break;

      default:
        printf("choix invalide ");
        break;
    }
    }
    }
}
// temp for departement recherche //
void afficherEtd(etudiants e) {
    printf("ID : %d \t Nom : %s \t Prenom : %s \t Date de naissance : %d/%d/%d \t Departement : %s  \t Note generale : %.2f\n",
           e.id, e.nom, e.prenom, e.date_naissance.jours, e.date_naissance.mois, e.date_naissance.annee, e.depatement, e.note);
}

void rechercheeEtudiant() {
    int choix, depachoix;
    char nomRecherche[100];

    if (nb_etudiant == 0) {
        printf("Aucun etudiant dans la liste.\n");
        return;
    }

    printf("Choisissez une methode de recherche :\n");
    printf("1. Rechercher par nom\n");
    printf("2. Afficher les etudiants d'un departement specifique\n");
    scanf("%d", &choix);
    int trouve;

    switch (choix) {
        case 1: {
            printf("Entrez le nom de l'etudiant : ");
            scanf(" %[^\n]", nomRecherche);
            trouve = 0;
            for (int i = 0; i < nb_etudiant; i++) {
                if (strcasecmp(etudiant[i].nom, nomRecherche) == 0) {
                    printf("Etudiant trouve :\n");
                    afficherEtd(etudiant[i]);
                    trouve = 1;
                }
            }
            if (!trouve) {
                printf("Aucun etudiant trouve avec le nom '%s'.\n", nomRecherche);
            }
            break;
        }
        case 2: {
            printf("Entrez le departement de l'etudiant : \n");
            printf("1. Math\n");
            printf("2. Physique\n");
            printf("3. Informatique\n");
            printf("4. Economie\n");
            printf("5. Francais\n");
            scanf("%d", &depachoix);

            switch (depachoix) {
                case 1:
                    trouve = 0;
                    printf("Liste des etudiants dans le departement '%s':\n", Depatement1);
                    for (int i = 0; i < nb_etudiant; i++) {
                        if (strcmp(etudiant[i].depatement, Depatement1) == 0) {
                            afficherEtd(etudiant[i]);
                            trouve = 1;
                        }
                    }
                    if (!trouve) {
                        printf("Aucun etudiant trouve dans le departement '%s'.\n", Depatement1);
                    }
                    break;

                case 2:
                    trouve = 0;
                    printf("Liste des etudiants dans le departement '%s':\n", Depatement2);
                    for (int i = 0; i < nb_etudiant; i++) {
                        if (strcmp(etudiant[i].depatement, Depatement2) == 0) {
                            afficherEtd(etudiant[i]);
                            trouve = 1;
                        }
                    }
                    if (!trouve) {
                        printf("Aucun etudiant trouve dans le departement '%s'.\n", Depatement2);
                    }
                    break;

                case 3:
                    trouve = 0;
                    printf("Liste des etudiants dans le departement '%s':\n", Depatement3);
                    for (int i = 0; i < nb_etudiant; i++) {
                        if (strcmp(etudiant[i].depatement, Depatement3) == 0) {
                            afficherEtd(etudiant[i]);
                            trouve = 1;
                        }
                    }
                    if (!trouve) {
                        printf("Aucun etudiant trouve dans le departement '%s'.\n", Depatement3);
                    }
                    break;

                case 4:
                    trouve = 0;
                    printf("Liste des etudiants dans le departement '%s':\n", Depatement4);
                    for (int i = 0; i < nb_etudiant; i++) {
                        if (strcmp(etudiant[i].depatement, Depatement4) == 0) {
                            afficherEtd(etudiant[i]);
                            trouve = 1;
                        }
                    }
                    if (!trouve) {
                        printf("Aucun etudiant trouve dans le departement '%s'.\n", Depatement4);
                    }
                    break;

                case 5:
                    trouve = 0;
                    printf("Liste des etudiants dans le departement '%s':\n", Depatement5);
                    for (int i = 0; i < nb_etudiant; i++) {
                        if (strcmp(etudiant[i].depatement, Depatement5) == 0) {
                            afficherEtd(etudiant[i]);
                            trouve = 1;
                        }
                    }
                    if (!trouve) {
                        printf("Aucun etudiant trouve dans le departement '%s'.\n", Depatement5);
                    }
                    break;

                default:
                    printf("Choix invalide.\n");
                    return;
            }
            break;
        }
        default:
            printf("Choix invalide.\n");
            break;
    }
}

// Moyenne ogenerale //
void moyenneGeneral (){
int i , nbr=0 , countDv=0 ;
float sum=0 , moyenne1 , moyenne2 , moyenne3 , moyenne4 , moyenne5 ;
printf("la moyenne generale de chaque departement :\n");
for(i=0 ; i<nb_etudiant;i++){
    if(strcmp(etudiant[i].depatement,Depatement1)==0){
        sum += etudiant[i].note ;
        nbr++ ;
    }
}
moyenne1 = sum / nbr ;
if(nbr>0){
    printf("Moyenne de Depatement Math : %.2f \n",moyenne1);
}

sum = 0 ;
nbr = 0 ;
for(i=0 ; i<nb_etudiant;i++){
    if(strcmp(etudiant[i].depatement,Depatement2)==0){
        sum += etudiant[i].note ;
        nbr++;
    }
}
moyenne2 = sum / nbr ;
if(nbr>0){
    printf("Moyenne de Depatement Physique : %.2f \n",moyenne2);
}
sum = 0 ;
nbr = 0 ;
for(i=0 ; i<nb_etudiant;i++){
    if(strcmp(etudiant[i].depatement,Depatement3)==0){
        sum += etudiant[i].note ;
        nbr++ ;
    }
}
moyenne3 = sum / nbr ;
if(nbr>0){
    printf("Moyenne de Depatement Informatique : %.2f \n",moyenne3);
}
sum = 0 ;
nbr = 0 ;
for(i=0 ; i<nb_etudiant;i++){
    if(strcmp(etudiant[i].depatement,Depatement4)==0){
        sum += etudiant[i].note ;
    }
}
moyenne4 = sum / nbr ;
if(nbr>0){
    printf("Moyenne de Departement Economie : %.2f \n",moyenne4);
}
sum = 0 ;
nbr = 0 ;
for(i=0 ; i<nb_etudiant;i++){
    if(strcmp(etudiant[i].depatement,Depatement5)==0){
        sum += etudiant[i].note ;
        nbr++ ;
    }
}
moyenne5 = sum / nbr ;
if(nbr>0){
    printf("Moyenne de Departement Francais : %.2f \n",moyenne5);
}

}
// Moyenne Entiere d'universite //
void moyenneEntiere(){
int i , count=0 ;
float sum=0 , moyenne_entiere=0 ;
for(i=0 ; i< nb_etudiant; i++){
   sum= sum+ etudiant[i].note ;
   count++ ;
}
moyenne_entiere = sum / count ;
if(count>0){
    printf("la moyenne generale de l'universite entiere est : %.2f \n",moyenne_entiere);
}
else{
    printf("Pas d'etudiants dans l'universite.\n");
}

}
// moyenne generale supérieure à un certain seuil //
void EtudiantSeuil() {
    float seuil;
    int trouve = 0;
    printf("Entrez le seuil : ");
    scanf("%f",&seuil);
    if (seuil<=0 || seuil>20) {
        printf("Erreur de saisie.\n");
    }

    printf("Liste des etudiants ayant une note generale superieure a %.2f :\n", seuil);
    for (int i = 0; i < nb_etudiant; i++) {
        if (etudiant[i].note > seuil) {
            afficherEtd(etudiant[i]);
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucun etudiant trouve avec une note superieure a %.2f.\n", seuil);
    }
}
// Tri croissant par note//
void trierEtudiantsParNote() {
    for (int i = 0; i < nb_etudiant - 1; i++) {
        for (int j = i + 1; j < nb_etudiant; j++) {
            if (etudiant[i].note < etudiant[j].note) {
                etudiants temp = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = temp;
            }
        }
    }
}
// Top 3 Etudiant //
void afficherTop3Etudiants() {
    if (nb_etudiant == 0) {
        printf("Aucun etudiant dans la liste.\n");
        return;
    }
    trierEtudiantsParNote();
    printf("Les 3 etudiants ayant les meilleures notes :\n");
    for (int i = 0; i < 3 && i < nb_etudiant; i++) {
        afficherEtd(etudiant[i]);
    }
}
// Supprimer Etudiant //
void supprimerEtudiant() {
    int id, found = 0;

    if (nb_etudiant == 0) {
        printf("Aucun Etudiant a supprimer.\n");
        return;
    }

    printf("Entrer l'ID de l'etudiant a supprimer : ");
    scanf("%d", &id);

    if (id <= 0 || id > nb_etudiant) {
        printf("ID invalide.\n");
        return;
    }
    id--;
    for (int i = id; i < nb_etudiant - 1; i++) {
        etudiant[i] = etudiant[i + 1];
    }

    nb_etudiant--;

    printf("L'etudiant a ete supprime avec succes.\n");
}
// Tri Par Moyenne //
void trierParMoyenne(int ordre) {
    int i, j;
    etudiants temp;
    for (i = 0; i < nb_etudiant - 1; i++) {
        for (j = 0; j < nb_etudiant - i - 1; j++) {
            int cmp = 0;
            if (ordre == 1) {
                if (etudiant[j].note < etudiant[j + 1].note) {
                    cmp = 1;
                }
            } else if (ordre == 2) {
                if (etudiant[j].note > etudiant[j + 1].note) {
                    cmp = 1;
                }
            }

            if (cmp == 1) {
                temp = etudiant[j];
                etudiant[j] = etudiant[j + 1];
                etudiant[j + 1] = temp;
            }
        }
    }
    affiche();
}
// Tri Par Nom //
void trierEtdParNom(int ordre) {
    int i, j;
    etudiants temp;
    for (i = 0; i < nb_etudiant - 1; i++) {
        for (j = 0; j < nb_etudiant - i - 1; j++) {
            int cmp = 0;
            if (ordre == 1) {
                if (strcmp(etudiant[j].nom, etudiant[j + 1].nom) > 0) {
                    cmp = 1;
                }
            } else if (ordre == 2) {
                if (strcmp(etudiant[j].nom, etudiant[j + 1].nom) < 0) {
                    cmp = 1;
                }
            }

            if (cmp == 1) {
                temp = etudiant[j];
                etudiant[j] = etudiant[j + 1];
                etudiant[j + 1] = temp;
            }
        }
    }
    affiche();
}
// Tri Par Status Reussite //
void trierParStatutReussite() {
    int i;
    printf("etudiants ayant une moyenne generale superieure ou egale a 10/20 (reussite) :\n");

    int found = 0;
    for (i = 0; i < nb_etudiant; i++) {
        if (etudiant[i].note >= 10) {
            printf("ID : %d \t Nom : %s \t Prenom : %s \t Moyenne : %.2f \n", etudiant[i].id, etudiant[i].nom, etudiant[i].prenom, etudiant[i].note);
            found = 1;
        }
    }

    if (!found) {
        printf("Aucun etudiant n'a une moyenne superieure ou egale a 10/20.\n");
    }
}



//  Affichage D'etudiants //
void afficheMenu() {
    int choix , i, ordre;
    printf("Choisissez une option pour trier les etudiants :\n\n");
    printf("1. Tri alphabetique des etudiants par leur nom \n");
    printf("2. Tri des etudiants par moyenne generale (du plus eleve au plus faible)\n");
    printf("3. Tri des etudiants selon leur statut de reussite\n");
    printf("choix : ");
    scanf("%d", &choix);
     switch (choix) {
        case 1:
            system("cls");
            printf("Choisissez l'ordre (1 pour A-Z, 2 pour Z-A) : ");
            scanf("%d", &ordre);
            trierEtdParNom(ordre);
            break;
        case 2:
            printf("Choisissez l'ordre (1 pour du plus eleve au plus faible, 2 pour du plus faible au plus eleve) : ");
            scanf("%d", &ordre);
            trierParMoyenne(ordre);
            break;
        case 3:
            system("cls");
            trierParStatutReussite();
            break;
        default:
            printf("Choix invalide.\n");
            break;
    }


    /*if(nb_etudiant == 0){
        printf("Aucun Etudiant en Liste.\n");
    }
    else{
       for(i=0 ; i<nb_etudiant ; i++){
                printf("ID : %d \t Nom : %s \t Prenom : %s \t Date de naissance : %d/%d/%d \t Departement : %s  \t Note generale : %.2f\n",etudiant[i].id, etudiant[i].nom, etudiant[i].prenom, etudiant[i].date_naissance.jours, etudiant[i].date_naissance.mois, etudiant[i].date_naissance.annee, etudiant[i].depatement, etudiant[i].note);
            }
    }*/

}
// Affiche function //
void affiche() {
    int i;
    if (nb_etudiant == 0) {
        printf("Aucun etudiant en liste.\n");
    } else {
        for (i = 0; i < nb_etudiant; i++) {
            printf("ID : %d \t Nom : %s \t Prenom : %s \t Date de naissance : %d/%d/%d \t Departement : %s \t Note generale : %.2f\n",
                   etudiant[i].id, etudiant[i].nom, etudiant[i].prenom, etudiant[i].date_naissance.jours, etudiant[i].date_naissance.mois, etudiant[i].date_naissance.annee, etudiant[i].depatement, etudiant[i].note);
        }
    }
}
// Statistiques Function //
Statistiques(){
int choix;
    do {
        printf("****************************** Statistiques Menu ***********************************\n");
        printf("\n1. Afficher le nombre total d'etudiants inscrits\n");
        printf("2. Afficher le nombre d'etudiants dans chaque departement\n");
        printf("3. Afficher les etudiants ayant une note generale superieure a un certain seuil\n");
        printf("4. Afficher les 3 etudiants ayant les meilleures notes\n");
        printf("5. Afficher le nombre d'etudiants ayant reussi dans chaque departement\n\n");
        printf("************************************************************************************\n");
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                system("cls");
                afficherTotalEtudiants();
                break;
            case 2:
                system("cls");
                AfficheNombreDepartement();
                break;
            case 3:
                system("cls");
                EtudiantSeuil();
                break;
            case 4:
                system("cls");
                afficherTop3Etudiants();
                break;
            case 5:
                system("cls");
                nbReussiteDepartement();
                break;

            default:
                printf("Option invalide, veuillez reessayer.\n");
                break;
        }
    } while (choix != 6);
}
// Nombre Total D'etudiant //
void afficherTotalEtudiants() {
    if (nb_etudiant == 0) {
        printf("Aucun etudiant dans la liste.\n");
    } else {
        printf("Le nombre total d'etudiants est : %d\n", nb_etudiant);
    }
}
// //
void nbReussiteDepartement() {
    int i;
    int countMath = 0, countPhysique = 0, countInformatique = 0, countEconomie = 0, countFrancais = 0;

    for (i = 0; i < nb_etudiant; i++) {
        if (etudiant[i].note >= 10) {
            if (strcmp(etudiant[i].depatement, Depatement1) == 0) {
                countMath++;
            } else if (strcmp(etudiant[i].depatement, Depatement2) == 0) {
                countPhysique++;
            } else if (strcmp(etudiant[i].depatement, Depatement3) == 0) {
                countInformatique++;
            } else if (strcmp(etudiant[i].depatement, Depatement4) == 0) {
                countEconomie++;
            } else if (strcmp(etudiant[i].depatement, Depatement5) == 0) {
                countFrancais++;
            }
        }
    }

    printf("Nombre d'etudiants ayant reussi dans chaque departement :\n");
    printf("Math : %d\n", countMath);
    printf("Physique : %d\n", countPhysique);
    printf("Informatique : %d\n", countInformatique);
    printf("Economie : %d\n", countEconomie);
    printf("Francais : %d\n", countFrancais);
}

// Afficher le nombre des etudiants par departement
void AfficheNombreDepartement() {
    int countMath = 0, countPh = 0, countInfo = 0, countEco = 0, countFr = 0;

    for (int i = 0; i < nb_etudiant; i++) {
        if (strcmp(etudiant[i].depatement, Depatement1) == 0) {
            countMath++;
        }
        else if (strcmp(etudiant[i].depatement, Depatement2) == 0) {
            countPh++;
        }
        else if (strcmp(etudiant[i].depatement, Depatement3) == 0) {
            countInfo++;
        }
        else if (strcmp(etudiant[i].depatement, Depatement4) == 0) {
            countEco++;
        }
        else if (strcmp(etudiant[i].depatement, Depatement5) == 0) {
            countFr++;
        }
    }

    if (countMath > 0) {
        printf("Le nombre des etudiants dans le departement Math : %d \n", countMath);
    } else {
        printf("Pas d'etudiants en Math\n");
    }

    if (countPh > 0) {
        printf("Le nombre des etudiants dans le departement Physique : %d \n", countPh);
    } else {
        printf("Pas d'etudiants en Physique\n");
    }

    if (countInfo > 0) {
        printf("Le nombre des etudiants dans le departement Informatique : %d \n", countInfo);
    } else {
        printf("Pas d'etudiants en Informatique\n");
    }

    if (countEco > 0) {
        printf("Le nombre des etudiants dans le departement Economie : %d \n", countEco);
    } else {
        printf("Pas d'etudiants en Economie\n");
    }

    if (countFr > 0) {
        printf("Le nombre des etudiants dans le departement Francais : %d \n", countFr);
    } else {
        printf("Pas d'etudiants en Francais\n");
    }
}

// Programme Menu //
void programmeMenu() {
    int choix;
    do {
        printf("\n**************** l'universite Youcode ***************\n");
        printf("\n1. Ajouter un etudiant\n");
        printf("2. Modifier un etudiant\n");
        printf("3. Supprimer un etudiant\n");
        printf("4. Afficher la moyenne generale par departement\n");
        printf("5. Afficher la moyenne de l'universite\n");
        printf("6. Afficher les details des etudiants\n");
        printf("7. Rechercher un etudiant\n");
        printf("8. Afficher les statistiques\n");
        printf("9. Quitter\n\n");
        printf("*****************************************************\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                system("cls");
                ajoutePlusieursEtudiant();
                break;
            case 2:
                system("cls");
                modifierEtudiant();
                break;
            case 3:
                system("cls");
                supprimerEtudiant();
                break;
            case 4:
                system("cls");
                moyenneGeneral();
                break;
            case 5:
                system("cls");
                moyenneEntiere();
                break;
            case 6:
                system("cls");
                afficheMenu();
                break;
            case 7:
                system("cls");
                rechercheeEtudiant();
                break;
            case 8:
                system("cls");
                Statistiques();
            case 9:
                printf("Programme terminer.");
                return ;
                break;
            default:
                printf("Option invalide. Veuillez reessayer.\n");
                break;
        }
    } while (choix != 9);
}

int main()
{

    etudiant[0].id = 1;
    strcpy(etudiant[0].nom, "Ahmed");
    strcpy(etudiant[0].prenom, "alaoui");
    etudiant[0].date_naissance.jours = 15;
    etudiant[0].date_naissance.mois = 6;
    etudiant[0].date_naissance.annee = 1995;
    strcpy(etudiant[0].depatement, Depatement1);
    etudiant[0].note = 15;
    nb_etudiant++;
    etudiant[1].id = 2;
    strcpy(etudiant[1].nom, "Sara");
    strcpy(etudiant[1].prenom, "Zahra");
    etudiant[1].date_naissance.jours = 3;
    etudiant[1].date_naissance.mois = 9;
    etudiant[1].date_naissance.annee = 1997;
    strcpy(etudiant[1].depatement, Depatement2);
    etudiant[1].note = 19;
    nb_etudiant++;
    etudiant[2].id = 3;
    strcpy(etudiant[2].nom, "Omar");
    strcpy(etudiant[2].prenom, "Ibrahim");
    etudiant[2].date_naissance.jours = 22;
    etudiant[2].date_naissance.mois = 2;
    etudiant[2].date_naissance.annee = 1996;
    strcpy(etudiant[2].depatement, Depatement3);
    etudiant[2].note = 17;
    nb_etudiant++;
    etudiant[3].id = 4;
    strcpy(etudiant[3].nom, "Mouna");
    strcpy(etudiant[3].prenom, "Hanaoui");
    etudiant[3].date_naissance.jours = 8;
    etudiant[3].date_naissance.mois = 2;
    etudiant[3].date_naissance.annee = 1998;
    strcpy(etudiant[3].depatement, Depatement4);
    etudiant[3].note = 18;
    nb_etudiant++;
    etudiant[4].id = 5;
    strcpy(etudiant[4].nom, "Youssef");
    strcpy(etudiant[4].prenom, "Mohamed");
    etudiant[4].date_naissance.jours = 10;
    etudiant[4].date_naissance.mois = 4;
    etudiant[4].date_naissance.annee = 1995;
    strcpy(etudiant[4].depatement, Depatement5);
    etudiant[4].note = 9;
    nb_etudiant++;
    etudiant[5].id = 6;
    strcpy(etudiant[5].nom, "Lina");
    strcpy(etudiant[5].prenom, "Sofia");
    etudiant[5].date_naissance.jours = 19;
    etudiant[5].date_naissance.mois = 1;
    etudiant[5].date_naissance.annee = 1996;
    strcpy(etudiant[5].depatement, Depatement1);
    etudiant[5].note = 12;
    etudiant[6].id = 7;
    strcpy(etudiant[6].nom, "Karim");
    strcpy(etudiant[6].prenom, "Zakaria");
    etudiant[6].date_naissance.jours = 28;
    etudiant[6].date_naissance.mois = 7;
    etudiant[6].date_naissance.annee = 1997;
    strcpy(etudiant[6].depatement, Depatement2);
    etudiant[6].note = 13;
    nb_etudiant++;
    etudiant[7].id = 8;
    strcpy(etudiant[7].nom, "Fatima");
    strcpy(etudiant[7].prenom, "Meryem");
    etudiant[7].date_naissance.jours = 12;
    etudiant[7].date_naissance.mois = 3;
    etudiant[7].date_naissance.annee = 1996;
    strcpy(etudiant[7].depatement, Depatement3);
    etudiant[7].note = 14;
    nb_etudiant++;
    etudiant[8].id = 9;
    strcpy(etudiant[8].nom, "Amine");
    strcpy(etudiant[8].prenom, "Hicham");
    etudiant[8].date_naissance.jours = 25;
    etudiant[8].date_naissance.mois = 5;
    etudiant[8].date_naissance.annee = 1995;
    strcpy(etudiant[8].depatement, Depatement4);
    etudiant[8].note = 9;
    nb_etudiant++;
    programmeMenu();

    return 0;
}
