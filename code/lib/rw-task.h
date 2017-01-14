void printTask(task * node) {
	printf("ID:\t%ld\n", node->id);
	printf("Title:\t%s\n", node->title);
	printf("User ID:\t%ld\n", node->user_id);
	printf("Category ID:\t%d\n", node->category_id);
	printf("Cost:\t%d\n", node->cost);
	printf("Status:\t%d\n", node->status);
	printf("Tags:\t%s\n", node->tags);
	printf("Due:\t%s\n", node->due);
	printf("comments:\t%s\n", node->comments);
	printf("\n\n");
}

void printTaskTree() {
	task_node * t = tasks_list;
	if (!t)
		return;
	while (t)
	{
		printTask(t->ptr);
		t = t->next;
	}
}

void pushTask(task * node)
{
	struct task_node * temp;
	temp = (struct task_node *)malloc(sizeof(struct task_node));
	temp->ptr = node;
	if (tasks_list == NULL)
	{
		tasks_list = temp;
		tasks_list->next = NULL;
	}
	else
	{
		temp->next = tasks_list;
		tasks_list = temp;
	}
}

bool deleteTask(int id)
{
	struct task_node * temp, * prev = NULL;
	temp = tasks_list;
	while (temp != NULL)
	{
		if (temp->ptr->id == id)
		{
			if (temp == tasks_list)
			{
				tasks_list = temp->next;
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

task_node * findTaskById(int id) {
	struct task_node * temp;
	temp = tasks_list;
	while (temp != NULL)
	{
		if (temp->ptr->id == id)
			return temp;
		else
			temp = temp->next;
	}
	return NULL;
}

void getTasks() {

	FILE * tasks_file;
	char filename[] = "../db/tasks.txt";
	tasks_file = fopen(filename, "r");

	if (tasks_file == NULL) {
		printf("ERROR!\nCan't find file '../db/tasks.txt'!\n");
		return;
	}
	// GET DATA FROM FILE //
	char ch; // See end of loop
	do {
		struct task * task_struct = (struct task *)malloc(sizeof(struct task));

		char buffer[256];

		fscanf(tasks_file, "%d", &(task_struct->id));
		fgets(buffer, 256, tasks_file);
		
		fgets(task_struct->title, 256, tasks_file);
		strtok(task_struct->title, "\n");

		fscanf(tasks_file, "%ld", &(task_struct->user_id));
		fgets(buffer, 256, tasks_file);

		fscanf(tasks_file, "%d", &(task_struct->category_id));
		fgets(buffer, 256, tasks_file);

		fscanf(tasks_file, "%d", &(task_struct->cost));
		fgets(buffer, 256, tasks_file);

		fscanf(tasks_file, "%d", &(task_struct->status));
		fgets(buffer, 256, tasks_file);

		fscanf(tasks_file, "%s", task_struct->tags);
		fgets(buffer, 256, tasks_file);
			
		fscanf(tasks_file, "%s", task_struct->due);
		fgets(buffer, 256, tasks_file);
			
		fscanf(tasks_file, "%s", task_struct->comments);
		fgets(buffer, 256, tasks_file);

		pushTask(task_struct);
		/*******/
		// FEOF IS BUGGED == TRUE IF END OF FILE ()
		/*******/
		// FIX
		ch = fgetc(tasks_file);
		ungetc(ch, tasks_file);
	} while (!feof(tasks_file) && ch != EOF);
	fclose(tasks_file);
}

void setTask(task *node) {

	FILE * task_file;
	char filename[] = "../db/tasks.txt";
	task_file = fopen(filename, "a");

	if (task_file == NULL) {
		perror("Error");
		return;
	}

	char buffer[256];

	fprintf(task_file, "\n%d\n%s\n%ld\n%d\n%d\n%d\n%s\n%s\n%s",
		node->id, node->title, node->user_id, node->category_id, node->cost, node->status, node->tags, node->due, node->comments);
}