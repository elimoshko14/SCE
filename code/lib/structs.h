typedef struct users {
	long id;
	char * name;
	int level;

	int porj_id;
	int task_id;
	char lang[2];

	int salery;
	bool online;

	int * comments;

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

typedef struct tasks {
	long id;
	char * title;

	int user_id;
	int category_id;

	int cost;
	bool status;
	char * tags;
	char deadLine[10];

	int * comments;

}task;

typedef struct task_node {
	struct task * ptr;
	struct task_node * next;
}task_node;

typedef struct comments {
	char * title;
	char * body;
	int comment_id;
	int user_id;
	int task_id;
	int porj_id;
}comment;

typedef struct comments_node {
	struct comment * ptr;
	struct comment_node * next;
}comment_node;

typedef struct categories {
	int * task;
	char * name;
	int proj_id;
}category;

typedef struct category_node {
	struct category * ptr;
	struct category_node * next;
}category_node;

