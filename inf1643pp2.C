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
#include <stdio.h>
#include <string.h>

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
char valider_caractere(char message[], char caracteres_valides[],char message_erreur[]){
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
            printf("Entier valide.");
        } else {
            est_valide = false;
            printf("%s\n", message_erreur);
        }
    } while (!est_valide);
    return i; 
}

// Exemple d'utilisation de la fonction
int main() {
    /* Test valider_caractere
    char message[] = "Saisissez un caractere parmi [abcde] : ";
    char caracteres_valides[] = "abcdert";
    char message_erreur[] = "Le caractere saisi n'est pas valide.";
    char c = valider_caractere(message, caracteres_valides, message_erreur);
    printf("Le caractere saisi est : %c", c);
    */
    /* Test valider_entier
    char message[] = "Entrer un int: ";
    int min = 0;
    int max = 100;
    int i = valider_entier(message,min,max);
    printf("Entier valider: %d \n",i);
    */
    scanf("%c");
    return 0;
}