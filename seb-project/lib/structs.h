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
<<<<<<< HEAD

<<<<<<< HEAD

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
=======
typedef struct comments {
	char* head_line;
	int comment_id;
	int user_id;
	int task_id;
	int porj_id;
}comments;
>>>>>>> 99bec297b2545c711b27da3cc76c17dfd353172b
=======
>>>>>>> fe58fb9e85c84708bedaf379f2e697ec08dc6942
