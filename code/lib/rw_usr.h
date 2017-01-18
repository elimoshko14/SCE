void SetUser(user *node) {

	FILE * user_file;
	char filename[] = "../db/users.txt";
	user_file = fopen(filename, "a");

	if (user_file == NULL) {
		perror("Error");
		return;
	}

	char buffer[256];

	fprintf(user_file, "\n%ld\n %s\n %d\n %d\n %d\n %s\n %d\n %d %s\n %s\n",
		node->id,
		node->name,
		node->level,
		node->porj_id,
		node->task_id,
		node->lang,
		node->salery,
		node->online,
		node->coments,
		node->due);

	fclose(user_file);
}



user_node * findUserById(long id) {
	struct user_node * temp;
	temp = users_list;
	while (temp != NULL)
	{
		if (temp->ptr->id == id)
			return temp;
		else
			temp = temp->next;
	}
	return NULL;
}

void ChangeUserId(user * node) {
	long new_id;
	printf("please enter ID for user\n");
	scanf("%d", &new_id);
	node->id = new_id;
}

void ChangeUserName(user * node) {
	char new_name[256];
	printf("please enter name for user\n");
	scanf("%s", &new_name);
	*(node->name) = new_name;
}

void ChangeUserSalary(user * node) {
	int new_salary;
	printf("please enter salary for user\n");
	scanf("%d", &new_salary);
	node->salery = new_salary;
}

void ChangeUserDue(user * node) {
	char new_due[256];
	printf("please enter new dead line for user\n");
	scanf("%s", &new_due);
	*(node->due) = new_due;
}

void UpdateUser(long id) {
	user *node = findUserById(id);
	if (node!=NULL) {
		printf("User has been find!\n");
		int choice;
		do
		{
			printf("Menu\n\n");
			printf("1. change user ID\n");
			printf("2. change user name\n");
			printf("3. change user salary\n");
			printf("4. change user dead line\n");
			printf("5. Exit\n");
			scanf("%d", &choice);

			switch (choice)
			{
			case 1: ChangeUserId(node);
				break;
			case 2: ChangeUserName(node);
				break;
			case 3: ChangeUserSalary(node);
				break;
			case 4: ChangeUserDue(node);
				break;
			case 5: printf("exit from menu,bye!\n");
				break;
			default: printf("Invalid choice!\n");
				break;
			}

		} while (choice != 5);

	}
	else
	{
		printf("user has not been find,please try again!\n");
	}
	FILE * users_file;
	char filename[] = "../db/users.txt";
	users_file = fopen(filename, "w");
	if (users_file == NULL) {
		perror("Error");
		return;
	}
	fclose(users_file);

	user_node * u = users_list;
	while (u) {
		SetUser(u->ptr);
		u = u->next;
	}
}





void printUser(user * node) {
	printf("ID:\t%ld\n", node->id);
	printf("Name:\t%s\n", node->name);
	printf("Level:\t%d\n", node->level);
	printf("Project ID:\t%d\n", node->porj_id);
	printf("Task ID:\t%d\n", node->task_id);
	printf("Language:\t%s\n", node->lang);
	printf("Salary:\t%d\n", node->salery);
	printf("Online:\t%d\n", node->online);
	printf("Comments:\t%s\n", node->coments);
	printf("Due:\t%s\n", node->due);
	printf("\n\n");
}


void printUserTree() {
	user_node * u = users_list;
	if (!u)
		return;
	while (u)
	{
		printUser(u->ptr);
		u = u->next;
	}
}


void pushUser(user * node)
{
	struct user_node * temp;
	temp = (struct user_node *)malloc(sizeof(struct user_node));
	temp->ptr = node;
	if (users_list == NULL)
	{
		users_list = temp;
		users_list->next = NULL;
	}
	else
	{
		temp->next = users_list;
		users_list = temp;
	}
}


bool deleteUser(int id)
{
	struct user_node * temp, *prev = NULL;
	temp = users_list;
	while (temp != NULL)
	{
		if (temp->ptr->id == id)
		{
			if (temp == users_list)
			{
				users_list = temp->next;
				free(temp);
				return true;
			}
			else
			{
				prev->next = temp->next;
				free(temp);
				return true;
			}
		}
		else
		{
			prev = temp;
			temp = temp->next;
		}
	}
	return false;
}





void getUsers() {

	FILE * users_file;
	char filename[] = "../db/users.txt";
	users_file = fopen(filename, "r");

	if (users_file == NULL) {
		perror("Error");
		return;
	}
	// GET DATA FROM FILE //
	char ch; // See end of loop
	do {
		struct user * user_struct = (struct user *)malloc(sizeof(struct user));

		char buffer[256];
		// get id
		fscanf(users_file, "%ld", &(user_struct->id));
		fgets(buffer, 256, users_file);

		// get name
		fgets(user_struct->name, '256', users_file);
		strtok(user_struct->name, "\n");

		// get level
		fscanf(users_file, "%d", &(user_struct->level));
		fgets(buffer, 256, users_file);

		// get proj id
		fscanf(users_file, "%d", &(user_struct->porj_id));
		fgets(buffer, 256, users_file);

		// get task id
		fscanf(users_file, "%d", &(user_struct->task_id));
		fgets(buffer, 256, users_file);

		// get lang
		fgets(user_struct->lang, '256', users_file);
		strtok(user_struct->lang, "\n");

		// get salaty
		fscanf(users_file, "%d", &(user_struct->salery));
		fgets(buffer, 256, users_file);

		// get onlilne
		fscanf(users_file, "%d", &(user_struct->online));
		fgets(buffer, 256, users_file);

		// get coments array (strings)
		fscanf(users_file, "%s", user_struct->coments);
		fgets(buffer, 256, users_file);


		// get tags array (strings)
		fscanf(users_file, "%s[10]", user_struct->due);
		fgets(buffer, 256, users_file);

		pushUser(user_struct);

		/*******/
		// FEOF IS BUGGED == TRUE IF END OF FILE ()
		/*******/
		// FIX
		ch = fgetc(users_file);
		ungetc(ch, users_file);

	} while (!feof(users_file) && ch != EOF);

	fclose(users_file);
}

bool isEmptyFile(FILE *file) {
	long savedOffset = ftell(file);
	fseek(file, 0, SEEK_END);

	if (ftell(file) == 0) {
		return true;
	}

	fseek(file, savedOffset, SEEK_SET);
	return false;
}

void clearFile(char fileName[]) {
	FILE * file;
	file = fopen(fileName, "w");
	fclose(file);
}

void setUser(user *node) {

	FILE * user_file;
	char filename[] = "../db/users.txt";
	user_file = fopen(filename, "a");

	if (user_file == NULL) {
		perror("Error");
		return;
	}

	char buffer[256];
	if (isEmptyFile(user_file))
		strcpy(buffer, "%ld\n%s\n%d\n%d\n%d\n%s\n%d\n%d\n%s\n%s");
	else 
		strcpy(buffer, "\n%ld\n%s\n%d\n%d\n%d\n%s\n%d\n%d\n%s\n%s");
	

	fprintf(user_file, buffer,
		node->id, node->name, node->level, node->porj_id, node->task_id, node->lang, node->salery, node->online, node->coments, node->due);

	fclose(user_file);
}

void addUser(int id, char name[], char lang[], char due[]) {

	// user information 
	struct user * newUser = (struct proj *)malloc(sizeof(struct user));

	newUser->id = id;
	strcpy(newUser->name, name);
	newUser->level = 1;
	newUser->porj_id = 1;
	newUser->task_id = 1;
	strcpy(newUser->lang, lang);
	newUser->salery = 1000;
	newUser->online = 0;
	strcpy(newUser->coments, "-1");
	strcpy(newUser->due, due);

	pushUser(newUser);
	setUser(newUser);

}

// This function rewrite users.txt after deleting specific node
// prototype of function delete with more functionality
void unSetUser(int id) {

	// only if previous delete from users_list
	if (deleteUser(id)) {

		user_node * new_list = users_list;
		if (!new_list) return;

		clearFile("../db/users.txt");

		// rewrite new list without deleting node
		while (new_list) {
			setUser(new_list->ptr);
			new_list = new_list->next;
		}
	}
}