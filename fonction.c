#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void jeulogo(){
    char tab1[] = {" Jeu des allumettes "};
    int j = strlen(tab1);
    printf("%*s", 30, "");
    for (int i = 0; i < j+2; ++i) {
        printf("*");
    }
    printf("\n");
    printf("%*s", 30, "");
    printf("*");
    for (int k = 0; k < j; ++k) {
        printf("%c", tab1[k]);
    }
    printf("*\n");
    printf("%*s", 30, "");
    for (int i = 0; i < j+2; ++i) {
        printf("*");
    }
    printf("\n");
}
void slogan(){
    printf("%*s", 20, "");
    printf("Bonjour et bienvenue dans le jeu des allumettes\n");
}


int rando3(){
    int a;
    srand((unsigned)time(NULL));
    a = rand()%3 + 1;//1,2,3

    return a;
}
int rando2(){
    int a;
    srand((unsigned)time(NULL));
    a = rand()%2 + 1;//1,2

    return a;
}

void niveau_naif_joueur(){
    int rest = 30;
    printf("Commence!\n");

    while(1){
        int i, j;
        printf("Combien prenez-vous d'allumettes ?\n");
        a:
        scanf("%d", &i);
        if (i > 3 || i <= 0) {
            printf("Erreur! Prise invalide: %d\nRecommencer\n"
                   "Combien prenez-vous d'allumettes ?\n", i);
            goto a;
        } else {
            printf("Vous prennez %d allumettes\n", i);
            rest -= i;
            printf("Il rest: %d\n", rest);
            if (rest <= 0) {
                printf("Vous perdez!\n");
                break;
            }
        }
        if(rest >= 3){
            j = rando3();
            printf("Ordinateur prend %d allumettes\n", j);
        }
        else if(rest ==2){
            j = rando2();
            printf("Ordinateur prend %d allumettes\n", j);
        }
        else{
            j = 1;
            printf("Ordinateur prend %d allumettes\n", j);
        }
        rest -= j;
        printf("Il rest: %d\n", rest);
        if(rest <= 0){
            printf("Vous gagnez!\n");
            break;
        }
    }
}
void niveau_naif_ordi(){
    int rest = 30;
    printf("Commence!\n");
    while(1){
        int i, j;
        if (rest >= 3) {
            j = rando3();
            printf("Ordinateur prend %d allumettes\n", j);
        } else if (rest == 2) {
            j = rando2();
            printf("Ordinateur prend %d allumettes\n", j);
        } else {
            j = 1;
            printf("Ordinateur prend %d allumettes\n", j);
        }
        rest -= j;
        printf("Il rest: %d\n", rest);
        if (rest <= 0) {
            printf("Vous gagnez!\n");
            break;
        }
        printf("Combien prenez-vous d'allumettes ?\n");
        e:
        scanf("%d", &i);
        if (i > 3 || i <= 0) {
            printf("Erreur! Prise invalide: %d\nRecommencer\n"
                   "Combien prenez-vous d'allumettes ?\n", i);
            goto e;
        } else {
            printf("Vous prennez %d allumettes\n", i);
            rest -= i;
            printf("Il rest: %d\n", rest);
            if (rest <= 0) {
                printf("Vous perdez!\n");
                break;
            }
        }

    }
}
void niveau_expert_joueur(){
    int rest = 30;
    printf("Commence!\n");

    while(1){
        int i, j;
        printf("Combien prenez-vous d'allumettes ?\n");
        a:
        scanf("%d", &i);
        if (i > 3 || i <= 0) {
            printf("Erreur! Prise invalide: %d\nRecommencer\n"
                   "Combien prenez-vous d'allumettes ?\n", i);
            goto a;
        } else {
            printf("Vous prennez %d allumettes\n", i);
            rest -= i;
            printf("Il rest: %d\n", rest);
            if (rest <= 0) {
                printf("Vous perdez!\n");
                break;
            }
        }
        if(rest % 4 == 0){
            j = 3;
            printf("Ordinateur prend %d allumettes\n", j);
        }
        else if((rest + 1) % 4 == 0){
            j = 2;
            printf("Ordinateur prend %d allumettes\n", j);
        }
        else if((rest + 2) % 4 == 0){
            j = 1;
            printf("Ordinateur prend %d allumettes\n", j);
        }
        else{
            j = rando2();
            printf("Ordinateur prend %d allumettes\n", j);
        }
        rest -= j;
        printf("Il rest: %d\n", rest);
        if(rest <= 0){
            printf("Vous gagnez!\n");
            break;
        }
    }
}
void niveau_expert_ordi(){
    int rest = 30;
    printf("Commence!\n");
    printf("Ordinateur prend 1 allumette\n");
    rest = rest - 1;
    printf("Il rest: %d\n", rest);
    while(1){
        int i, j;
        printf("Combien prenez-vous d'allumettes ?\n");
        a:
        scanf("%d", &i);
        if (i > 3 || i <= 0) {
            printf("Erreur! Prise invalide: %d\nRecommencer\n"
                   "Combien prenez-vous d'allumettes ?\n", i);
            goto a;
        } else {
            printf("Vous prennez %d allumettes\n", i);
            rest -= i;
            printf("Il rest: %d\n", rest);
            if (rest <= 0) {
                printf("Vous perdez!\n");
                break;
            }
        }
        if (rest > 3) {
            j = 4 - i;
            printf("Ordinateur prend %d allumettes\n", j);
        } else if (rest == 3) {
            j = 2;
            printf("Ordinateur prend %d allumettes\n", j);
        } else {
            j = 1;
            printf("Ordinateur prend %d allumettes\n", j);
        }
        rest -= j;
        printf("Il rest: %d\n", rest);
        if (rest <= 0) {
            printf("Vous gagnez!\n");
            break;
        }
    }
}