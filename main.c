#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fonction.h"
int main() {
    jeulogo();
    slogan();
    int niveau;
    char nom[20];
    char premier;

    printf("\nVous allez voir le menu.\n"
           "Selon le menu, vous pouvez selectionner les informations que vous souhaitez, \n"
           "notamment les regles du jeu et les niveaux\n ");

    int num;
    a:
    printf("\nVeuillez selectionner:\n\n");
    printf("*1-- Voir les regles\n");
    printf("*2-- Jouer\n");
    printf("*3-- Quitter\n");
    printf("\nVotre choix:\n");
    scanf("%d", &num);

    switch (num) {
        case 1:
            printf("\nLes regles:\n");
            printf("\n**Le jeu des 30 allumettes se joue a deux joueurs qui, a tour de role, \n"
                   "prennent 1, 2 ou 3 allumettes d'un tas qui en contient initialement 30.\n");
            printf("\n**Le joueur qui prend la derniere allumette perd.\n");
            printf("\n**Il permettre a deux joueurs de s'affronter. C'est l'o'rdinateur qui est \n"
                   "l'arbitre de la partie. Il affiche le nombre d'allumettes restant en jeu, \n"
                   "donne la main a tour de role a chaque joueur et verifie que les joueurs \n"
                   "respectent les regles du jeu.\n");
            printf("\n**Ainsi, si un joueur veut prendre trop ou trop peu d'allumettes, le coup \n"
                   "est refuse et le joueur doit rejour. Un joueur dooit retirer \n"
                   "entre 1 et 3 allumettes\n");
            printf("\n**En fin de partie, l'arbitre affiche le resultat. Chaque joueur choisit \n"
                   "le coup a jouer en fonction d'une strategie.\n");
            goto a;

        case 2:
            printf("Veuillez saisir votre nom:\n");
            scanf("%s", nom);
            printf("Bonjour %s, veuiller choisir le niveau(saisir le numero):\n",nom);
        b:
            printf("1--Niveau naif\n");
            printf("2--Niveau expert\n");
            printf("3--Quittez le jeu\n");
            scanf("%d", &niveau);

            if(niveau == 1){
                c:
                printf("Voulez-vous passer en premier?[y/n]\n");
                scanf("%s", &premier);
                if(premier == 'y'){
                    niveau_naif_joueur();
                    getch();
                    break;
                }
                else if(premier == 'n'){
                    niveau_naif_ordi();
                    getch();
                    break;
                }
                else{
                    printf("Veuillez rechoisir l'ordre!\n");
                    goto c;
                }
            }
            else if(niveau == 2){
                d:
                printf("Voulez-vous passer en premier?[y/n]\n");
                scanf("%s", &premier);
                if(premier == 'y'){
                    niveau_expert_joueur();
                    getch();
                    break;
                }
                else if(premier == 'n'){
                    niveau_expert_ordi();
                    getch();
                    break;
                }
                else{
                    printf("Veuillez rechoisir l'ordre!\n");
                    goto d;
                }
            }
            else if(niveau == 3){
                printf("Quitter!");
                exit(0);
            }
            else{
                printf("Rechoisir\n");
                goto b;
            }
            break;

        case 3:
            printf("Quitter");
            exit(0);
        default:
            printf("Erreur! Refaire le choix svp!");
            goto a;

    }
}

