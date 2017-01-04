typedef struct users {
	long id;
	char * name;
	int level;

	int porj_id;
	int task_id;
	char lang[2];

	int salery;
	bool online;

	int comments[];

}users;

typedef struct proj {


}proj;


typedef struct user_node {
	users * ptr;
	user_node * next;
}user_node;

typedef struct tasks {
	long id;
	char * name;

	int user_id;
	int category_id;

	int salary;
	bool status;
	char * tags;
	char * deadLine;

	int comments[];

}tasks;

typedef struct task_node {
	tasks * ptr;
	task_node * next;
}task_node;

typedef struct comments {
	char* head_line;
	int comment_id;
	int user_id;
	int task_id;
	int porj_id;
}comments;


Eli