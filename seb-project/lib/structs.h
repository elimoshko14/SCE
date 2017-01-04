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
