

#include "function_platform.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* tolower_name(char* name){
    int len = strlen(name);
    char* temp = malloc(sizeof(name));
    for(int i= 0; i<len;i++){
        temp[i] = tolower(name[i]);
    }
    return temp;
}
void init_user(LLuser user){
    user_ptr head = malloc(sizeof(struct user));
    user->head =  head;
    head->next = NULL;
    user->tail = head;
    user->leftcnt =0;
    user->rightcnt = 0;
    user->fence = head;
    strcpy(user->head->name,"Head_User");
}

void init_film(LLfilm film){
    film_ptr head = malloc(sizeof(struct film));
    film->head = head;
    head->next = NULL;
    film->tail = head;
    film->fence = head;
    film->rightcnt =0;
    film->leftcnt = 0;
    strcpy(film->head->name,"Head_Film");

}
void init_genre(LLgenre genre){
    genre_ptr head = malloc(sizeof(struct genre));
    genre->fence =genre->head = genre->tail = head;
    head->next = NULL;
    genre->leftcnt = genre->rightcnt = 0;
    genre->total_genre = 0;
    strcpy(genre->head->genre_name,"Head_Genre");
}
Bool set_genre_fence(char* name, LLgenre genre){
    genre_ptr temp = genre->head->next;
    int len = genre->leftcnt+genre->rightcnt;
    int left = 1;
    int state = 0;
    while (temp!=NULL){
        if(strcmp(tolower_name(name),tolower_name(temp->genre_name))==0){
            state = 1;
            genre->fence = temp;
            genre->leftcnt = left;
            genre->rightcnt = len-left;

        }
        temp = temp->next;
        left++;
    }
    if(state==0){//printf("Error Search\n");
        return False;} else{return True;}
}
void create_genre(char* name,LLgenre genre){
    genre_ptr temp =malloc(sizeof(struct genre));
    strcpy(temp->genre_name,name);
    temp->numer = 0;
    temp->next =  genre->fence->next;
    genre->fence->next = temp;
    genre->total_genre++;
    genre->rightcnt++;
    if(genre->fence==genre->tail){
        genre->tail = genre->fence->next;
    }
}
void classification(film_ptr film, LLgenre genre){
    char temp_genre[maxName];
    strcpy(temp_genre,tolower_name(film->genre));
    int state = 0;
    genre_ptr temp_genre_ptr = genre->head;
    while (temp_genre_ptr->next!=NULL){
        temp_genre_ptr = temp_genre_ptr->next;
        if(strcmp(temp_genre,tolower_name(temp_genre_ptr->genre_name))==0){
            temp_genre_ptr->array[temp_genre_ptr->numer] = film;
            temp_genre_ptr->numer++;
            state = 1;
            break;
        }
    }
    if(state==0){
        create_genre(film->genre,genre);
        classification(film,genre);
    }


}
void next_film(LLfilm listlink){
    if(listlink->fence!=listlink->tail){
        listlink->fence = listlink->fence->next;
        listlink->leftcnt++;
        listlink->rightcnt--;
    }
}
void back_film(LLfilm listlink){
    while (listlink->fence!=listlink->head){
        film_ptr temp = listlink->head;
        while(temp->next!=listlink->fence){
            temp = temp->next;
        }
        listlink->fence = temp;            // 诺，call by reference
    }
}
void next_user(LLuser listlink){
    if(listlink->fence!=listlink->tail){
        listlink->fence = listlink->fence->next;
        listlink->leftcnt++;
        listlink->rightcnt--;
    }
}
void back_user(LLuser listlink){
    while (listlink->fence!=listlink->head){
        user_ptr temp = listlink->head;
        while(temp->next!=listlink->fence){
            temp = temp->next;
        }
        listlink->fence = temp;            // 诺，call by reference
    }
}
void insert_film(LLfilm linklist,char* name,char* director,char* itsgenre,int release_year,LLgenre genre){
    film_ptr temp = malloc(sizeof(struct film));
    strcpy(temp->name,name);
    strcpy(temp->director,director);
    strcpy(temp->genre,itsgenre);
    temp->release_year = release_year;
    temp->its_note = NULL;
    temp->next = linklist->fence->next;
    classification(temp,genre);
    linklist->fence->next = temp;
    if(linklist->tail==linklist->fence){
        linklist->tail = linklist->fence->next;// 这是在尾部插item，需要改变尾部
    }
    linklist->rightcnt++;

}
void insert_user(LLuser linklist,char* name){
    user_ptr temp = malloc(sizeof(struct user));
    strcpy(temp->name,name);
    temp->his_note = NULL;
    temp->next = linklist->fence->next;
    linklist->fence->next = temp;
    if(linklist->tail==linklist->fence){
        linklist->tail = linklist->fence->next;// 这是在尾部插item，需要改变尾部
    }
    linklist->rightcnt++;

}
void set_start_film(LLfilm listlink){
    listlink->fence = listlink->head;
    listlink->rightcnt = listlink->rightcnt+listlink->leftcnt;
    listlink->leftcnt =0;
}
void set_end_film(LLfilm listlink){
    listlink->fence = listlink->tail;
    listlink->leftcnt +=listlink->rightcnt;
    listlink->rightcnt = 0;
}
void set_start_user(LLuser listlink){
    listlink->fence = listlink->head;
    listlink->rightcnt = listlink->rightcnt+listlink->leftcnt;
    listlink->leftcnt =0;
}
void set_end_user(LLuser listlink) {
    listlink->fence = listlink->tail;
    listlink->leftcnt += listlink->rightcnt;
    listlink->rightcnt = 0;
}
void add_user(char* name,LLuser user){
    if(set_user_fence(name,user)==False){
    set_start_user(user);
    if(user->fence==user->tail){
        insert_user(user,name);
        //printf("Successfully Added!\n");
    } else{
        while ((user->fence!=user->tail) && (strcmp(name,user->fence->next->name)>0)){

            next_user(user);

        }
        insert_user(user,name);
        //printf("Successfully Added!\n");
    }} else{printf(" Already included in the platform\n");}

}
void add_film(char* name,char* director,char* itsgenre,int release_year ,LLfilm film,LLgenre genre){
    if(set_film_fence(name,film) == False || strcmp(tolower_name(film->fence->director),tolower_name(director))!=0){
    set_start_film(film);
    if(film->fence==film->tail){
        insert_film(film,name,director,itsgenre,release_year,genre);
        //printf("Successfully Added!\n");
    } else{
        while ((film->fence!=film->tail) && (strcmp(name,film->fence->next->name)>0)){

                next_film(film);

        }
        insert_film(film,name,director,itsgenre,release_year,genre);
        //printf("Successfully Added!\n");
    }} else{printf("This film with the same director has already existed\n");}

}
Bool set_user_fence(char* name, LLuser user){
    set_start_user(user);
    int state = 0;
    while (user->fence!=user->tail){
        next_user(user);
        if(strcmp(tolower_name(user->fence->name),tolower_name(name))==0){
            state = 1;
            break;
        }
    }
    if(state==0){//printf("Error Search:No such user\n");
        return False;} else{ return True;}
}
Bool set_film_fence(char* name,LLfilm film){
    set_start_film(film);
    int  state =0;
    while (film->fence!=film->tail){
        next_film(film);
        if(strcmp(tolower_name(film->fence->name),tolower_name(name))==0){
            state = 1;
            break;
        }
    }

    if(state==0){
       // printf("Error Search: No such film\n");
        return False;
    } else{
        return True;
    }
}

void print_film_name(LLfilm film)
{
    if(film->head==film->tail){
        printf("Print Error\n");
    } else{
        film_ptr temp = film->head;
        while (temp!=film->tail){
            temp = temp->next;
            printf("%s\n",temp->name);

        }

    }
}
void print_user_name(LLuser user)
{
    if(user->head==user->tail){
        printf("Print Error\n");
    } else{
        user_ptr temp = user->head;
        while (temp!=user->tail){
            temp = temp->next;
            printf("%s\n",temp->name);

        }

    }
}


float aver_note_of_film(char* film_name,LLfilm film){
    float sum=0;
    int num = 0;
    set_film_fence(film_name,film);
    re_note_ptr temp = film->fence->its_note;
    if(temp!=NULL){
        while (temp!=NULL){
            num++;
            sum+=temp->note;
            temp = temp->film_next_note;
        }
        return sum/num;


    }else{
        printf("No Notes\n");
        return 0;

    }

}
void add_note_review(char* user_name, char*film_name, int note,char review[],LLfilm film,LLuser user){
    if(set_user_fence(user_name,user)==True&&set_film_fence(film_name,film)==True){
    re_note_ptr temp = malloc(sizeof(struct re_note));
    temp->note = note;
    strcpy(temp->review,review);
    temp->note_for_user = user->fence;
    temp->note_for_film = film->fence;
    temp->user_next_note = user->fence->his_note;
    user->fence->his_note = temp;
    temp->film_next_note = film->fence->its_note;
    film->fence->its_note = temp;
    film->fence->aver_note = aver_note_of_film(film_name,film);
    //printf("Successfully Added!\n");
    } else{
        printf("Fail to add reviews and notes\n");
    }
}

void print_basic_info_film(char* film_name,LLfilm film){
    if(set_film_fence(film_name,film) == True){
    re_note_ptr temp = film->fence->its_note;
    if(strcmp(tolower_name(film_name),tolower_name(film->fence->name))==0){
        printf("Name: %s \n",film->fence->name);
        printf("Director: %s\n",film->fence->director);
        printf("Genre: %s\n",film->fence->genre);
        printf("Release Year: %d\n",film->fence->release_year);
        while (temp!=NULL){

            printf("User: %s give %d points, and recommend:%s\n",temp->note_for_user->name,temp->note,temp->review);
            temp = temp->film_next_note; // ATTENTION I DONT MAKE THE HEAD FOR THE NOTE!!! WE READ FROM THE HEAD!!!!!!!!
        }
        printf("Average Notes: %f\n",aver_note_of_film(film_name,film));

    }} else{
        printf("No such film!\n");
    }
}
void print_basic_info_user(char* user_name,LLuser user){
    if(set_user_fence(user_name,user)==True){

    re_note_ptr temp = user->fence->his_note;
    if(temp!=NULL){
        printf("User: %s has seen\n",user->fence->name);
        while (temp!=NULL){
            printf("Film Name:%s , %s gives %d and recommand %s\n",temp->note_for_film->name,user->fence->name,temp->note,temp->review);
            temp = temp->user_next_note;

        }
    }} else{
        printf("Fail to show the information\n");
    }
}
void swap(film_ptr array[],int i, int j){
    film_ptr temp = array[i];
    array[i] = array[j];
    array[j] = temp;

}
void sort_film(LLfilm film){
    int len =film->rightcnt+film->leftcnt;
    film_ptr temp[len];
    film->fence = film->head->next;
    int m,n;
    float val;
    if (film->fence!=NULL) {

        for (int i = 0; i < len; i++) {
            temp[i] = film->fence;
            film->fence = film->fence->next;
        }
        for( m =1;m<len;m++){
            n = m-1;
            val = temp[m]->aver_note;
            while (n>=0&&temp[n]->aver_note<val){  // 正序或者倒序
                swap(temp,n,n+1);
                n--;
            }


        }
        for(int i =0;i<len;i++){
            printf("%s , %f\n",temp[i]->name,temp[i]->aver_note);
        }
    } else{printf("Sort Error");}


}

void print_director_film(char* name, LLfilm film){
    set_start_film(film);
    int i = 0;
    if(film->fence==film->tail){
        printf("Not Included\n4");
    }else{
        while (film->fence!=film->tail){
            next_film(film);
            if(strcmp(tolower_name(name),tolower_name(film->fence->director))==0){
                i++;
                printf("%s\n",film->fence->name);
            }
        }
        printf("%s has directed %d films\n",name,i);
    }
}
void find_favor(char* name,LLuser user,LLgenre genre){
    if(set_user_fence(name,user) == True){
    int array[genre->total_genre-1] ;

    re_note_ptr temp = user->fence->his_note;
    while (temp->user_next_note!=NULL){
        set_genre_fence(temp->note_for_film->genre,genre);
        array[genre->leftcnt-1]++;
        temp = temp->user_next_note;
    }
    set_genre_fence(temp->note_for_film->genre,genre);
    array[genre->leftcnt-1]++;
    int max = 0;
    int max_indice = 0;
    for(int i =0; i<genre->total_genre;i++){
        if(array[i]>=i){
            max_indice = i;
            max = array[i];
        }
    }
    genre_ptr fav_genre = genre->head;
    for(int j = 0;j<=max_indice;j++){
        fav_genre = fav_genre->next;
    }
    printf("Favourite genre: %s\n",fav_genre->genre_name);
    int n;
    float val;
    for( int m =1;m<fav_genre->numer;m++){
        n = m-1;
        val = fav_genre->array[m]->aver_note;
        while (n>=0&&fav_genre->array[n]->aver_note<val){  // 正序或者倒序
            swap(fav_genre->array,n,n+1);
            n--;
        }
    }
    for(int i =0;i<fav_genre->numer;i++){
        printf("%s , %f\n",fav_genre->array[i]->name,fav_genre->array[i]->aver_note);
    }} else{
        printf("Fail to recommend\n");
    }

}
void get_input(char array[]){
    char c;
    int i =0;
    c= getchar();
    while (c!='\n'&& c!=EOF){
        array[i] = c;
        c = getchar();
        i++;
    }
    array[i] = '\0';

}
int interaction(int choice, LLfilm film,LLuser user,LLgenre genre){
    char user_name[maxName];
    char film_name[maxName];
    char director_name[maxName];
    char genre_name[maxName];
    char review_name[maxfilm];
    int release_year;
    int film_note;
    switch (choice){

        case 1:

            printf("Enter the User name:\n");
            get_input(user_name);
            add_user(user_name,user);
            //free(review);free(user_name);free(film_name);free(director_name);free(itsgenre);

            return 1;
        case 2:
            printf("Enter the Film name:\n");
            get_input(film_name);
            printf("Enter the Director name:\n");
            get_input(director_name);
            printf("Enter the Genre:\n");
            get_input(genre_name);
            printf("Enter the Film's release year:\n");
            scanf("%d",&release_year);
            getchar();
            add_film(film_name,director_name,genre_name,release_year,film,genre);
            //free(review);free(user_name);free(film_name);free(director_name);free(itsgenre);

            return 1;
        case 3:
            printf("Enter the User's name:\n");
            get_input(user_name);
            printf("Enter the Film's name:\n");
            get_input(film_name);
            printf("PLease note the film from 0 to 10\n");
            scanf("%d",&film_note);
            getchar();
            printf("Now write down the review for this film\n");
            get_input(review_name);
            add_note_review(user_name,film_name,film_note,review_name,film,user);
            //free(review);free(user_name);free(film_name);free(director_name);free(itsgenre);

            return 1;
        case 4:
            printf("Which film do you want to check ?\n");
            get_input(film_name);
            print_basic_info_film(film_name,film);
            //free(review);free(user_name);free(film_name);free(director_name);free(itsgenre);
            return 1;
        case 5:
            sort_film(film);
            return 1;
        case 6:
            printf("Which user do you want to check? \n");
            get_input(user_name);
            print_basic_info_user(user_name,user);
            //free(review);free(user_name);free(film_name);free(director_name);free(itsgenre);
            return 1;
        case 7:
            printf("Which director do you want to Check?\n");
            get_input(director_name);
            print_director_film(director_name,film);
            //free(review);free(user_name);free(film_name);free(director_name);free(itsgenre);
            return 1;
        case 8:
            printf("To whom do you want to recommend ? Enter his name: \n");
            get_input(user_name);
            find_favor(user_name,user,genre);
            //free(review);free(user_name);free(film_name);free(director_name);free(itsgenre);
            return 1;
        case 9:
            return 0;
        default:
            printf("Please Enter a number from 1 to 9 for choosing a function!\n");
            return 1;

    }
}

