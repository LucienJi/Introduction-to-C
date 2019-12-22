//
// Created by Lucien on 2019/12/13.
//

#ifndef PROJECT_FUNCTION_PLATFORM_H
#define PROJECT_FUNCTION_PLATFORM_H
#define maxfilm  100
#define maxName 20
typedef struct film *film_ptr;
typedef struct re_note *re_note_ptr;
typedef struct user *user_ptr;
typedef struct genre* genre_ptr;
typedef struct Linkedlist_film* LLfilm;
typedef struct Linkedlist_user* LLuser;
typedef struct Linkedlist_genre* LLgenre;
#define Bool int
#define True 1
#define False 0
struct genre{
    char genre_name[maxName];
    int numer;
    genre_ptr next;
    film_ptr array[maxfilm];
};
struct user{
    char name[maxfilm];
    re_note_ptr  his_note;
    user_ptr next;
};
struct re_note{
    int note;
    char review[maxfilm];
    film_ptr note_for_film;
    user_ptr note_for_user;
    re_note_ptr user_next_note;
    re_note_ptr film_next_note;
};
struct film
{   int id;
    char name[maxName];
    char director[maxName];
    int release_year;
    char genre[maxName];
    float aver_note;
    film_ptr next;
    re_note_ptr its_note;
};

struct Linkedlist_film{
    film_ptr head;
    film_ptr tail;
    film_ptr fence;
    int leftcnt;
    int rightcnt;

};
struct Linkedlist_user{
    user_ptr head;
    user_ptr tail;
    user_ptr fence;
    int rightcnt;
    int leftcnt;
};
struct Linkedlist_genre{
    genre_ptr head;
    int total_genre;
    genre_ptr tail;
    genre_ptr fence;
    int rightcnt;
    int leftcnt;
};


char* tolower_name(char* name);

void init_user(LLuser user);
void init_film(LLfilm film);
void init_genre(LLgenre genre);


Bool set_genre_fence(char* name, LLgenre genre);
void create_genre(char* name,LLgenre genre);
void classification(film_ptr film, LLgenre genre);

Bool set_user_fence(char* name, LLuser user);
Bool set_film_fence(char* name,LLfilm film);

float aver_note_of_film(char* film_name,LLfilm film);
void add_note_review(char* user_name, char*film_name, int note,char* review,LLfilm film,LLuser user);
void print_basic_info_film(char* film_name,LLfilm film);
void print_basic_info_user(char* user_name,LLuser user);

void swap(film_ptr array[],int i, int j);
void sort_film(LLfilm film);

void next_film(LLfilm film);
void back_film(LLfilm);

void next_user(LLuser listlink);
void back_user(LLuser listlink);


void insert_film(LLfilm linklist,char* name,char* director,char* genre,int release_year,LLgenre);
void insert_user(LLuser linklist,char* name);

void set_start_film(LLfilm listlink);
void set_end_film(LLfilm listlink);
void set_start_user(LLuser listlink);
void set_end_user(LLuser listlink);

void add_user(char* name,LLuser user);
void add_film(char* name,char* director,char* itsgenre ,int release_year,LLfilm film,LLgenre);

void print_film_name(LLfilm film);
void print_user_name(LLuser user);
void print_director_film(char* name, LLfilm film);
void find_favor(char* name,LLuser user,LLgenre genre);

void create_film(LLfilm film, LLgenre genre);
void creat_user(LLuser user);
void creat_note(LLuser user,LLfilm film);
int interaction(int choice, LLfilm film, LLuser user,LLgenre genre);
void get_input(char[]);
#endif //PROJECT_FUNCTION_PLATFORM_H
