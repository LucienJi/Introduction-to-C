#include <stdio.h>
#include <stdlib.h>
#include "function_platform.h"

int main(){
    LLuser user = malloc(sizeof(struct Linkedlist_user));
    init_user(user);
    LLfilm film = malloc(sizeof(struct Linkedlist_film));
    init_film(film);
    LLgenre genre = malloc(sizeof(struct Linkedlist_genre));
    init_genre(genre);

   create_film(film,genre);
   creat_user(user);
   creat_note(user,film);
   int state = 1;
    while (state){
        int choice;
        printf(" 1.Add user\n 2.Add film\n 3.Add note and review\n 4.Film information\n 5.Rank of film\n 6.User information\n 7.Director information\n 8.Recommendation for user\n 9.Exit\n");
        scanf("%d",&choice);
        getchar();
        state = interaction(choice,film,user,genre);
    }



}