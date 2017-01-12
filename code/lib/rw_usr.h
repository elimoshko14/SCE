
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
	printf("-------------\n");
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


user_node * findUserById(int id) {
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

