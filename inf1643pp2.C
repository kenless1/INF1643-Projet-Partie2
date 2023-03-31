#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
    Auteur: Ken Lessard-Gerber
    Code permanent : LESK26269809
    Date de création: 22/03/2023
    Date de mise à jour: 22/03/2023
    ******************************************************************************
    But du programme: Le but de ce programme consiste a implémenter un jeux 
    de démineur où le but du joueur est de localiser toutes les mines dans 
    un plan de jeu à deux dimensions sans les faire exploser. Le plan de 
    jeu est représenté par un tableau à deux dimensions, où chaque case 
    peut contenir soit une mine (représentée par le caractère "M") soit un 
    chiffre de 0 à 8 qui représente le nombre de mines adjacentes à cette case. 
    Le jeu est initialisé aléatoirement en plaçant des mines dans certaines 
    cases. Le joueur doit découvrir les cases en entrant leurs coordonnées et 
    en évitant de cliquer sur une case qui contient une mine. Le plan de jeu est 
    affiché à l'écran avec des cases non découvertes représentées par le caractère 
    "x", des cases potentiellement piégées représentées par "*" et des cases 
    potentiellement risquées représentées par "?". Le joueur gagne la partie en 
    découvrant toutes les cases qui ne contiennent pas de mines.
    ******************************************************************************
*/
typedef struct{
    int lignes;
    int colonnes;
}Coordonnes;

/******************************************************************************
    Fonction : afficher_jeux
*******************************************************************************
    Description : Affiche le plan du jeux afficher.
*******************************************************************************
    Pré-condition :
*******************************************************************************
    Paramètres :
        - tab_plan_afficher: tableau du plan affiché du jeux contenant des 
            caracteres.
        - nombre_mines: Valeur du nombre de mines dans le plan du jeux.
        - lignes: Valeur contenant le nombre de ligne du tableau du jeux.
        - colonnes: Valeur contenant le nombre de colonnes du tableau du jeux.
        valide.
*******************************************************************************        
    Retour : Le nombre aléatoire.
*******************************************************************************
*/
void afficher_jeux(char *tab_plan_afficher,int lignes, int colonnes,int nombre_mines){
    int compteur_ligne = 10*colonnes;
    for(int i=1;i<=colonnes;i++){
        printf("       %d ",i);
    }
    printf("\n");
    for(int i=0;i<lignes;i++){
        // Affichage lignes
        if(i==0){
            printf(" ");
        }
        printf(" %d ",i+1);
        // Affichage colonnes
        for(int j=0;j<colonnes;j++){
            printf("  | %c |  ",tab_plan_afficher[i*colonnes+j]);
        }
        // -------------------------------
        printf("\n   ");
        for(int i=0;i<compteur_ligne;i++){
            printf("-");
        }
        printf(" \n ");
        // -------------------------------
    }
}
/******************************************************************************
    Fonction : afficher_operation
*******************************************************************************
    Description :Afficher le message du choix d'operations. 
*******************************************************************************
    Pré-condition : -
*******************************************************************************
    Paramètres :
        - 
*******************************************************************************        
    Retour : - 
*******************************************************************************
*/
void afficher_operation(){
    printf("\nVeuillez choisir une option: D - devoiler case");
    printf("\n                             M - marquer case mine");
    printf("\n                             ? - marquer case");
    printf("\n                             Q - quitter le jeux\n");
}

/******************************************************************************
    Fonction : lecture_char
*******************************************************************************
    Description :Permet de lire un caractere en input et renvoyer la valeur.
*******************************************************************************
    Pré-condition : -
*******************************************************************************
    Paramètres :
        -.
*******************************************************************************        
    Retour : - caracteres: Valeur du caracteres lut.
*******************************************************************************
*/
char lecture_char(){
    char operation;
    scanf("%c",&operation);
    return operation;
}
/******************************************************************************
    Fonction : est_mine
*******************************************************************************
    Description : Renvoi un nombre, 1 si il y a presence de mine et 0 si non.
*******************************************************************************
    Pré-condition :
*******************************************************************************
    Paramètres :
        -tab_plan_jeux: Tableau contenant le plan du jeux. 
        - cordonnes: Cordonnes contenant la valeur de lignes et colonnes a 
        verifier.
*******************************************************************************        
    Retour : Le nombre aléatoire.
*******************************************************************************
*/
int est_mine(int *tab_plan_jeux,Coordonnes cordonnes,int colonnes){
    int valeur =0;
    int i = cordonnes.lignes;
    int j = cordonnes.colonnes;
    int case_jouer = tab_plan_jeux[i*colonnes+j];
    if(case_jouer == 99){
        valeur = 1;
    }
    return valeur;
}
/******************************************************************************
    Fonction : nombre_aleatoire
*******************************************************************************
    Description : Renvoi un nombre aléatoire entre un minimum et maximum 
    donné. 
*******************************************************************************
    Pré-condition :
*******************************************************************************
    Paramètres :
        - min : Valeur minimum de l'intervalle.
        - max : Valeur maximum de l'intervalle.
*******************************************************************************        
    Retour : Le nombre aléatoire.
*******************************************************************************
*/
int nombre_aleatoire(int min, int max){
    return min + rand() % (max+1 - min);
}
/******************************************************************************
    Fonction : valider_charachtere
*******************************************************************************
    Description : Vérifie si un caractère saisi au clavier appartient à un 
    ensemble de caractères valides.
*******************************************************************************
    Pré-condition :
*******************************************************************************
    Paramètres :
        - message : message de sollicitation pour saisir un caractère.
        - caracteres_valides : ensemble des caractères valides.
        - message_erreur : message à afficher si le caractère saisi n'est pas 
        valide.
*******************************************************************************        
    Retour : le caractère valide saisi au clavier.
*******************************************************************************
*/
char valider_caractere(char message[], char caracteres_valides[],
                                                        char message_erreur[]){
    char c;
    int est_valide;
    do {
        printf("%s", message);
        scanf(" %c", &c);
        est_valide = strchr(caracteres_valides, c) != NULL;
        if (!est_valide) {
            printf("%s\n", message_erreur);
        }
    } while (!est_valide);
    return c; 
}
/******************************************************************************
    Fonction : valider_entier
*******************************************************************************
    Description : La fonction permet de valider un entier entre une intervalle
    minimum et maximum. Elle va demander a l'utilisateur un entier tant et 
    aussi longtemps que l'entier sera invalide.
*******************************************************************************
    Pré-condition :
*******************************************************************************
    Paramètres :
        - message : message de sollicitation pour saisir un entier.
        - min : valeur minimal que peut prendre l'entier.
        - max : valeur maximal que peut prendre l'entier.
*******************************************************************************        
    Retour : l'entier valide saisi au clavier.
*******************************************************************************
*/
int valider_entier(char message_sollicitation[], int min, int max){
    int i;
    int est_valide;
    char message_erreur[] = "Erreur!!! : Veuillez entrer un entier valide. \n";
    do {
        printf("%s", message_sollicitation);
        if (scanf("%d", &i) == 1 && i >= min && i <= max) {
            est_valide = true;
            printf("Entier valide. \n");
        } else {
            est_valide = false;
            printf("%s\n", message_erreur);
        }
    } while (!est_valide);
    return i; 
}
/******************************************************************************
    Fonction : initialiser_plan_afficher
*******************************************************************************
    Description : Initialise le plan du jeux affiché.
*******************************************************************************
    Pré-condition : -
*******************************************************************************
    Paramètres :
        - tab_plan_jeux: tableau du plan affiché du jeux contenant des 
            caracteres.
        - lignes: Valeur contenant le nombre de ligne du tableau du jeux.
        - colonnes: Valeur contenant le nombre de colonnes du tableau du jeux.
        valide.
*******************************************************************************        
    Retour : -
*******************************************************************************
*/
void initialiser_plan_afficher(char *tab_plan_afficher,int lignes, int colonnes){    
    for(int i=0;i<lignes;i++){
        for(int j=0;j<colonnes;j++){
            tab_plan_afficher[i*colonnes+j] = 'x';
        }
    }
}

/******************************************************************************
    Fonction : trouver_case_contigues
*******************************************************************************
    Description : Trouver les cases contigues a cette case. Un tableau de
        9 case sera remplit par l'indice des cases contigues. Le case du milieu
        sera la case 4 dans le tableau de 9 cases.
*******************************************************************************
    Pré-condition : tableau non null. 
*******************************************************************************
    Paramètres :
        - tab_case: tableau que on veux remplir d'indice de case.
        - lignes: Valeur contenant le nombres de lignes.
        - colonnes: Valeur contenant le nombres de colonnes.
        - case_courante: Valeur contenant l'indice de la case courante.
*******************************************************************************        
    Retour : -
*******************************************************************************

case_courante-(colonnes-1)   case_courante-(colonnes)   case_courante-(colonnes+1)
                         \             |             /
                          \            |            /
                    case_courante-1----case_courante----case_courante+1
                        /               |           \
                       /                |            \
    case_courante+(colonne-1) case_courante+colonne case_courante+(colonne+1)
*/
void remplir_case_contigues(int* tab_case, int lignes,int colonnes,
                                                        Coordonnes cordonnes){

    int case_courante = (cordonnes.lignes*colonnes+cordonnes.colonnes);
    int i = cordonnes.lignes;
    int j = cordonnes.colonnes;
    if(i == lignes-1 && j != 0 && j != colonnes - 1){
        tab_case[0] = case_courante-(colonnes+1);
        tab_case[1] = case_courante-(colonnes);
        tab_case[2] = case_courante-(colonnes-1);
        tab_case[3] = case_courante+(colonnes-1);
        tab_case[4] = case_courante;
        tab_case[5] = case_courante+(colonnes+1);
        tab_case[6] = -1;
        tab_case[7] = -1;
        tab_case[8] = -1;
    }else if(i == 0 && j != 0 && j != colonnes - 1){
        tab_case[0] = -1;
        tab_case[1] = -1;
        tab_case[2] = -1;
        tab_case[3] = case_courante-1;
        tab_case[4] = case_courante;
        tab_case[5] = case_courante+1;
        tab_case[6] = case_courante+(colonnes-1);
        tab_case[7] = case_courante+(colonnes);
        tab_case[8] = case_courante+(colonnes+1);
    }else if(j==0){
        tab_case[0] = -1;
        tab_case[1] = case_courante-(colonnes);
        tab_case[2] = case_courante-(colonnes-1);
        tab_case[3] = -1;
        tab_case[4] = case_courante;
        tab_case[5] = case_courante+1;
        tab_case[6] = -1;
        tab_case[7] = case_courante+(colonnes);
        tab_case[8] = case_courante+(colonnes+1); 
    }else if(j==colonnes-1){
        tab_case[0] = case_courante-(colonnes+1);
        tab_case[1] = case_courante-(colonnes);
        tab_case[2] = -1;
        tab_case[3] = case_courante-1;
        tab_case[4] = case_courante;
        tab_case[5] = -1;
        tab_case[6] = case_courante+(colonnes-1);
        tab_case[7] = case_courante+(colonnes);
        tab_case[8] = -1; 
    }
    else{
        tab_case[0] = case_courante-(colonnes+1);
        tab_case[1] = case_courante-(colonnes);
        tab_case[2] = case_courante-(colonnes-1);
        tab_case[3] = case_courante-1;
        tab_case[4] = case_courante;
        tab_case[5] = case_courante+1;
        tab_case[6] = case_courante+(colonnes-1);
        tab_case[7] = case_courante+(colonnes);
        tab_case[8] = case_courante+(colonnes+1); 
        }
}
/******************************************************************************
    Fonction : remplir_case_contigues
*******************************************************************************
    Description : Remplir les cases qui ne contient pas de mines avec des
        le nombres de mines qui sont contiguë a cette case. 
*******************************************************************************
    Pré-condition : tableau non null. 
*******************************************************************************
    Paramètres :
        - tab_plan_jeux: tableau du plan du jeux contenant des 
            caracteres.
        - nombre_mines: Valeur du nombre de mines dans le plan du jeux.
        - lignes: Valeur contenant le nombre de ligne du tableau du jeux.
        - colonnes: Valeur contenant le nombre de colonnes du tableau du jeux.
        valide.
*******************************************************************************        
    Retour : -
*******************************************************************************
*/
void remplir_case_mines(int *tab_plan_jeux,int lignes,int colonnes){
    for(int i=0;i<=lignes-1;i++){
        for(int j=0;j<=colonnes-1;j++){
            int case_courante = (i*colonnes+j);
            int tab_case[9];
            int taille = sizeof(tab_case)/ sizeof(int);
            if(tab_plan_jeux[case_courante] != 99){
                int compteur_mines = 0;
                // Cas limites
                Coordonnes cordonnes;
                cordonnes.lignes =i;
                cordonnes.colonnes=j;
                remplir_case_contigues(tab_case,lignes,colonnes,cordonnes);
                // Verifier le nombre de mine entre les 8 case.
                for(int c=0;c<taille;c++){
                    compteur_mines += (tab_plan_jeux[tab_case[c]] == 99) ? 1:0;
                }
                // Mettre le chiffre entre 0 et 8 dans la case selon 
                // le nombre de mines.
                tab_plan_jeux[case_courante] = compteur_mines; 
            }
        }
    }
}
/******************************************************************************
    Fonction : initialiser_plan_jeux
*******************************************************************************
    Description : Initialise le plan du jeux.
*******************************************************************************
    Pré-condition : -
*******************************************************************************
    Paramètres :
        - tab_plan_jeux: tableau du plan du jeux contenant des 
            caracteres.
        - nombre_mines: Valeur du nombre de mines dans le plan du jeux.
        - lignes: Valeur contenant le nombre de ligne du tableau du jeux.
        - colonnes: Valeur contenant le nombre de colonnes du tableau du jeux.
        valide.
*******************************************************************************        
    Retour : -
*******************************************************************************            
*/
void initialiser_plan_jeux(int *tab_plan_jeux,int nombre_mines,int lignes, 
                                                                int colonnes){
    int nombre_case = lignes * colonnes;
    // Mettre les mines dans le plan.
    for(int i=0;i<nombre_mines;i++){
        tab_plan_jeux[nombre_aleatoire(0,nombre_case-1)] = 99;
    }
    // Mettre les compteurs dans le plan.
    remplir_case_mines(tab_plan_jeux,lignes,colonnes);
}

/*
******************************************************************************
    Fonction : valider_coup
*******************************************************************************
    Description : Valide un coup que l'utilisateur peut jouer.
*******************************************************************************
    Pré-condition : -
*******************************************************************************
    Paramètres :
        - tab_plan_afficher: Tableau du plan afficher
        - lignes: Valeurs contenant le nombre de lignes.
        - colonnes: Valeurs contenant le nombre de colonnes
*******************************************************************************        
    Retour : - Coordonnes: Valeurs contenant la lignes et colonnes choisi.
*******************************************************************************
*/
Coordonnes valider_coup(char *tab_plan_afficher,int lignes, int colonnes){
    Coordonnes cordonnes;
    bool est_valide;
    char message_lignes[]="\n Veullez entrer le numero de ligne: ";
    char message_colonnes[]="\n Veullez entrer le numero de colonne: ";
    int min=1;
    char case_jouer;
    int lignes_choisi;
    int colonnes_choisi;
    do{

        lignes_choisi = valider_entier(message_lignes,min,lignes);
        colonnes_choisi = valider_entier(message_colonnes,min,colonnes);
        case_jouer = tab_plan_afficher[(lignes_choisi-1)*colonnes+(colonnes_choisi-1)];
        if(case_jouer == '*' || case_jouer != 'x'){
            printf("\nCase deja jouer !!!-Veuillez en choisir un autre\n");
        }
    }while(case_jouer != 'x' && case_jouer !='?');
    cordonnes.lignes = lignes_choisi-1;
    cordonnes.colonnes = colonnes_choisi-1;
    return cordonnes;
}

/******************************************************************************
    Fonction : jouer_coup
*******************************************************************************
    Description :Permet de jouer un coup dans le jeux.
*******************************************************************************
    Pré-condition : -
*******************************************************************************
    Paramètres :
        - tab_plan_jeux: Tableau du plan du jeux.
        - tab_plan_afficher: Tableau du plan afficher du jeux.
        - lignes: Valeurs contenant le nombre de lignes.
        - colonnes: Valeurs contenant le nombre de colonnes.
        - cordonnes: Valeurs contenant les cordonnes du coup a jouer.
*******************************************************************************        
    Retour : - nombre_coup_possible: valeur contenant le nombre de coup possible.
*******************************************************************************
*/
int jouer_coup(int *tab_plan_jeux,char *tab_plan_afficher,
                    int lignes,int colonnes,Coordonnes cordonnes){
    int nombre_coup_possible =1;
    int coup_jouer = (cordonnes.lignes*colonnes+cordonnes.colonnes);
    if(tab_plan_jeux[coup_jouer]==99){
        tab_plan_afficher[coup_jouer] = 'M';
        nombre_coup_possible = 0;
    }else{
        int valeur_trouver = tab_plan_jeux[coup_jouer];
        tab_plan_afficher[coup_jouer] = valeur_trouver+'0';
        if(valeur_trouver == 0){
            int nombre_case_decouvrir = 8;
            // Remplacer le X par nombre mine contigues pour les 8 
            // case au tour de la case contenant le chiffre 0. 
            int tab_indice[9];
            int nombre_valeurs = sizeof(tab_indice) / sizeof(int);
            remplir_case_contigues(tab_indice, lignes,colonnes,cordonnes);
            for(int i=0;i<nombre_valeurs;i++){
                tab_plan_afficher[tab_indice[i]] = tab_plan_jeux[tab_indice[i]]+'0';
            }
        }else{
            tab_plan_afficher[coup_jouer] = tab_plan_jeux[coup_jouer]+'0'; 
        }
    }
    return nombre_coup_possible;
}

/******************************************************************************
    Fonction : compter_nombres_coups
*******************************************************************************
    Description :Permet de compteur le nombre de coup possible restant dans 
    le jeux.
*******************************************************************************
    Pré-condition : -
*******************************************************************************
    Paramètres :
        - tab_plan_afficher: Tableau du plan afficher du jeux.
        - lignes: Valeurs contenant le nombre de lignes.
        - colonnes: Valeurs contenant le nombre de colonnes.
*******************************************************************************        
    Retour : - nombre_coup_possible: valeur contenant le nombre de coup possible.
*******************************************************************************
*/
int compter_nombres_coups(char *tab_plan_afficher,int lignes,int colonnes){
    int nombre_coup =0;    
    for(int i=0;i<lignes;i++){
        for(int j=0;j<colonnes;j++){
            char case_char = tab_plan_afficher[(i*colonnes+j)];
            if(case_char == 'x' || case_char == '?'){
                nombre_coup++;
            }
        }
    }
    return nombre_coup;
}

/******************************************************************************
    Fonction : verifier_etat_partie
*******************************************************************************
    Description :Permet de verifier l'etat de la partie. 
*******************************************************************************
    Pré-condition : -
*******************************************************************************
    Paramètres :
        - tab_plan_afficher: Tableau du plan du jeux.
        - cordonnes: Cordonnes contenant la valeur de la ligne et colonne du
        coup dernier jouer.
*******************************************************************************        
    Retour : - etat_partie: Valeur contenant l'etat de la partie,-1 si contient
    une mine, 1 s'il y a 0 coup possible et 0 pour indiquer que la partie 
    continue.
*******************************************************************************
*/
int verifier_etat_partie(int *tab_plan_jeux,Coordonnes cordonnes,
                                int nombre_coup_possible,int colonnes){
    int valeur =0;
    if(est_mine((int *)tab_plan_jeux,cordonnes,colonnes)){
        valeur = -1;
        printf("\n Boom !!! - Partie Terminer \n");
    }else if(nombre_coup_possible==0){
        valeur =1;
        printf("Partier Terminer !!!");
    }
    return valeur;
}

/*
******************************************************************************
    Fonction : 
*******************************************************************************
    Description : 
*******************************************************************************
    Pré-condition : -
*******************************************************************************
    Paramètres :
        - 
*******************************************************************************        
    Retour : 
*******************************************************************************
*/
int traiter_opertation(int *tab_plan_jeux ,char *tab_plan_afficher,int lignes, int colonnes){
    int nombre_coup_possible;
    int etat_partie;
    char message[] = "\nVeuillez entrer un choix: ";
    char caracteres_valides[] = "dDmM?qQ";
    char message_erreur[] = "Votre choix n'est pas valide";

    char choix_operation = valider_caractere((char *)message,(char *)caracteres_valides,(char *)message_erreur);
    Coordonnes cordonnes;
    if(choix_operation == 'd'|| choix_operation == 'D'){
        cordonnes = valider_coup((char *)tab_plan_afficher,lignes,colonnes);

        nombre_coup_possible = jouer_coup((int *)tab_plan_jeux,(char *)tab_plan_afficher,lignes,colonnes,cordonnes);
        etat_partie = verifier_etat_partie((int *)tab_plan_jeux,cordonnes,nombre_coup_possible,colonnes);
    }else if(choix_operation == 'M'|| choix_operation == 'm'){
        cordonnes = valider_coup((char *)tab_plan_afficher,lignes,colonnes);

        tab_plan_afficher[cordonnes.lignes*colonnes+cordonnes.colonnes] = '*';
        etat_partie = 0;
    }else if(choix_operation == '?'){
        cordonnes = valider_coup((char *)tab_plan_afficher,lignes,colonnes);

        tab_plan_afficher[cordonnes.lignes*colonnes+cordonnes.colonnes] = '?';
        etat_partie= 0;
    }else{
        etat_partie = 1;
    }
    
    

    return etat_partie;
}


/*
******************************************************************************
    Fonction : jouer_partie
*******************************************************************************
    Description : 
*******************************************************************************
    Pré-condition : -
*******************************************************************************
    Paramètres :
        - 
*******************************************************************************        
    Retour : 
*******************************************************************************
*/
void jouer_partie(int *tab_plan_jeux,int lignes,int colonnes){
    int nombre_mines =4;
    int tab_plan_afficher[9];
    int possible;

    initialiser_plan_afficher((char *)tab_plan_afficher,lignes,colonnes);
    initialiser_plan_jeux((int *)tab_plan_jeux,nombre_mines,lignes,colonnes);
                                                
    do{
        afficher_jeux((char *)tab_plan_afficher,lignes, colonnes,nombre_mines);
        afficher_operation();
        possible = traiter_opertation((int *)tab_plan_jeux ,(char *)tab_plan_afficher,lignes, colonnes);
    }while(possible ==0);

    afficher_jeux((char *)tab_plan_afficher,lignes, colonnes,nombre_mines);                                        
}

// ----------------------------------------------------------------------------
// -------------------------------------MAIN-----------------------------------
//-----------------------------------------------------------------------------
int main() {    
    int tabINT[5][5];
    jouer_partie((int *)tabINT,5,5);
    
    system("pause");
    return 0;
}