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

typedef struct comments {
	char* head_line;
	int comment_id;
	int user_id;
	int task_id;
	int porj_id;
}comments;
=======
>>>>>>> fe58fb9e85c84708bedaf379f2e697ec08dc6942
