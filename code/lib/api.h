void printTask(task * node);
void printTaskTree();
void pushTask(task * node);
bool deleteTask(int id);
task * findTaskById(int id);
void getTasks();
void setTask(task *node);
void addTask(int id, char title[], int user_id, int cat_id, int cost, int status, char tags[], char due[], char comments[]);
void updateTask(int id, char title[], int user_id, int cat_id, int cost, int status, char tags[], char due[], char comments[]);
void unSetTask(int id);
proj * findProjById(int id);
void printProj(proj * proj_struct);
void printProjTree();
void pushProj(proj * node);
bool deleteProj(int id);
void getProjs();
void setProjs(proj *node);
void updateProj(int id, char name[], int manager_id , char due[],bool status,int cost);
void unSetProj(int id);
comment * findcomentById(int id);
void printComment(comment * node);
void pushComent(comment * node);
bool deleteComent(int id);
void getComments();
void setComment(comment *node);
void addComment(int id,char title[],char body[],int porj_id,int task_id ,int user_id);
void updateComment(int id, char title[], char body[], int porj_id, int task_id, int user_id);
void unSetComment(int id);
void printCat(category * node);
void printCatTree();
void pushCat(category * node);
bool deleteCat(int id);
void getCategories();
void setCat(category *node);
void addCat(int id, char name[], int proj_id, char comment_arr[]);
category * findCatById(long id);
void UpdateCat(int id, char name[], int proj_id, char comment_arr[]);
void unSetCat(int id);
user * findUserById(long id);
void printUser(user * node);
void printUserTree();
void pushUser(user * node);
bool deleteUser(int id);
void getUsers();
void setUser(user *node);
void addUser(int id, char name[], char lang[], char due[], int level, int proj_id, int  task_id, int salery, int online, char comments[]);
void updateUser(int id, char name[], char lang[], char due[], int level, int proj_id, int  task_id, int salery, int online, char comments[]);
void unSetUser(int id);

#include "lib/rw-task.h"
#include "lib/rw-proj.h"
#include "lib/rw_usr.h"
#include "lib/rw-ctgry.h"
#include "lib/rw-cmnt.h"