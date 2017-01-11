typedef struct user{
	long id;
	char name[256];
	int level;
	int porj_id;
	int task_id;
	char lang[2];
	int salery;
	bool online;
	char coments[256];
	char deadLine[256];

}user;

typedef struct proj_node {
	struct proj * ptr;
	struct proj_node * next;
}proj_node;

typedef struct proj {
	int * users_arr;
	int * tasks_arr;
	int * cats_arr;
	int manager_id;
	time_t finish_date;
	bool status;
	int cost;
}proj;

typedef struct user_node {
	struct user * ptr;
	struct user_node * next;
}user_node;

typedef struct task {
	int id;
	char title[256];
	long user_id;
	int category_id;
	int cost;
	int status;
	char tags[256];
	char deadLine[256];
	char comments[256];

}task;

typedef struct task_node {
	struct task * ptr;
	struct task_node * next;
}task_node;

typedef struct comment {
	char title[256];
	char body[256];
	int comment_id;
	int user_id;
	int task_id;
	int porj_id;
}comment;

typedef struct comment_node {
	struct comment * ptr;
	struct comment_node * next;
}comment_node;

typedef struct category {
	int id;
	char name[256];
	int proj_id;
	char comment_arr[1000];
}category;

typedef struct category_node {
	struct category * ptr;
	struct category_node * next;
}category_node;


typedef struct tree_node {
	void * ptr;
	void * next;
}tree_node;