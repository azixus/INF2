/*
 -----------------------------------------------------------------------------------
 Laboratoire : 10
 Fichier     : main.c
 Auteur(s)   : Müller Robin, Stéphane Teixeira Carvalho
 Date        : 03.06.2019

 But         : Initialiser une chaine de caractère sous forme de texte.
               Le texte sera ensuite donner à une fonction qui va indexer les mots contenus dans celui-ci. 
               Les mots et les numéros des lignes dans lesquel il ont été trouvés vont être affiché.
               La liste des mots doit être sous forme alphabétique.

 Remarque(s) :  -

 Compilateur : MinGW-gcc 6.3.0
 -----------------------------------------------------------------------------------
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book_index.h"

#define FICHER_A_INDEXER 1
#define FICHIER_INDEX 2
#define FICHER_STOPWORDS 3
#define OPTION_AIDE "-h"


int main(int argc, char* argv[]) {
    //Affichage de l'aide
    if (argc == 2 && strcmp(OPTION_AIDE, argv[1]) == 0) {
        printf("Aide");
        return EXIT_SUCCESS;
    } else if (argc < 3) {
        return EXIT_FAILURE;
    }

    //arg[1] == fichier à indexer
        //arg[2] == fichier d'index
        //arg[3] == fichier stopwords, optionnel

//        char* fichierAIndexer = argv[FICHER_A_INDEXER];
//        char* fichierIndex = argv[FICHIER_INDEX];

    FILE* fichierAIndexer = fopen(argv[FICHER_A_INDEXER], "r");
    FILE* fichierIndex    = fopen(argv[FICHIER_INDEX], "w"); //Confirmer ecrasement si le fichier existe
    //        char* fichierStopwords = argv[3];

    fseek(fichierAIndexer, 0, SEEK_END);

    const size_t NB_OCTETS = (size_t)ftell(fichierAIndexer) + 1;
    char* texte = calloc(NB_OCTETS, sizeof(char));

    if (texte != NULL) {
        rewind(fichierAIndexer);

        fread(texte, NB_OCTETS, 1, fichierAIndexer);

        Index* index = remplirIndex(texte);
        afficherIndex(index);
        saveToFileIndex(index, fichierIndex);
        detruireIndex(index);

        free(texte);
    }

    fclose(fichierAIndexer);
    fclose(fichierIndex);

    return EXIT_SUCCESS;
}

