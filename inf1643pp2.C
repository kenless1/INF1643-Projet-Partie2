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