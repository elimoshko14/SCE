struct users_list {
	struct user * ptr;
	struct node * next;
};

struct users {
	long id;
	char * name;
	int level;

	int porj_id;
	int task_id;
	char lang[2];

	int salery;
	bool online;

	int comments[];
};