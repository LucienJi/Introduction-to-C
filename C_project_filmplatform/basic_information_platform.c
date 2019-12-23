#include "function_platform.h"
#include <stdlib.h>
#include <time.h>

void create_film(LLfilm film, LLgenre genre){
    srand((unsigned int)time(NULL));
    int year[] = {1998,1999,2000,2001,2002,2003,2004,2005,2006,2007};
    add_film("Film1","Rolland","Drama",year[rand()%10],film,genre);
    add_film("Film2","Rolland","Drama",year[rand()%10],film,genre);
    add_film("Film3","Rolland","Drama",year[rand()%10],film,genre);
    add_film("Film4","Rolland","Violent",year[rand()%10],film,genre);
    add_film("Film5","Rolland","Violent",year[rand()%10],film,genre);
    add_film("Film6","Liam","Violent",year[rand()%10],film,genre);
    add_film("Film7","Liam","Action",year[rand()%10],film,genre);
    add_film("Film8","Liam","Action",year[rand()%10],film,genre);
    add_film("Film9","Liam","Action",year[rand()%10],film,genre);
    add_film("Film10","Liam","Drama",year[rand()%10],film,genre);
    add_film("Film11","Lucien","Drama",year[rand()%10],film,genre);
    add_film("Film12","Lucien","Drama",year[rand()%10],film,genre);
    add_film("Film13","Lucien","Violent",year[rand()%10],film,genre);
    add_film("Film14","Lucien","Violent",year[rand()%10],film,genre);
    add_film("Film15","Lucien","Violent",year[rand()%10],film,genre);
    add_film("Film16","Arthur","Action",year[rand()%10],film,genre);
    add_film("Film17","Arthur","Action",year[rand()%10],film,genre);
    add_film("Film18","Arthur","Action",year[rand()%10],film,genre);
    add_film("Film19","Arthur","Action",year[rand()%10],film,genre);
    add_film("Film20","Arthur","Action",year[rand()%10],film,genre);
}
void creat_user(LLuser user){
    add_user("User1",user);
    add_user("User2",user);
    add_user("User3",user);
    add_user("User4",user);
    add_user("User5",user);
    add_user("User6",user);
    add_user("User7",user);
    add_user("User8",user);
    add_user("User9",user);
    add_user("User10",user);
    add_user("User11",user);
    add_user("User12",user);
    add_user("User13",user);
    add_user("User14",user);
    add_user("User15",user);
    add_user("User16",user);
    add_user("User17",user);
    add_user("User18",user);
    add_user("User19",user);
    add_user("User20",user);
    add_user("User21",user);
    add_user("User22",user);
    add_user("User23",user);
    add_user("User24",user);
    add_user("User25",user);

}

void creat_note(LLuser user,LLfilm film){
    srand((unsigned int)time(NULL));
    int  i;
    char* note[]= {"It's so terrible","Boring, waste of time","Not bad, just so so","It's a noteworthy film","Extraordinaire!! "};
    set_start_user(user);
    while (user->fence!=user->tail){
        next_user(user);
        set_start_film(film);
        while (film->fence!=film->tail){
            next_film(film);

            i = rand()%5;
            add_note_review(user->fence->name,film->fence->name,2*i,note[i],film,user);

        }

    }

}