void printTask(task * node) {
	printf("ID:\t%ld\n", node->id);
	printf("Title:\t%s\n", node->title);
	printf("User ID:\t%ld\n", node->user_id);
	//printf("Category ID:\t%d\n", node->category_id);
	printf("Cost:\t%d\n", node->cost);
	if (node->status == 1)
		printf("Status:\tComplete\n");
	else 
		printf("Status:\tWorking on\n");
	printf("Tags:\t%s\n", node->tags);
	printf("Due:\t%s\n", node->due);
	//printf("comments:\t%s\n", node->comments);
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

task * findTaskById(int id) {
	struct task_node * temp;
	temp = tasks_list;
	while (temp != NULL)
	{
		if (temp->ptr->id == id)
			return temp->ptr;
		else
			temp = temp->next;
	}
	return NULL;
}

void getTasks() {

	FILE * tasks_file;
	char filename[] = "../db/tasks.txt";
	tasks_file = fopen(filename, "r");

	if (isEmptyFile(tasks_file)) return;

	// GET DATA FROM FILE //
	char ch; // See end of loop
	do {
		struct task * task_struct = (struct task *)malloc(sizeof(struct task));

		char buffer[256];

		fscanf(tasks_file, "%d", &(task_struct->id));
		fgets(buffer, 256, tasks_file);

		// set unique_task_key (when we add new task unique_task_key++)
		// it has to be a maximum a value
		if (task_struct->id > unique_task_key) { unique_task_key = task_struct->id; }
		
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
	if (isEmptyFile(task_file))
		strcpy(buffer, "%d\n%s\n%ld\n%d\n%d\n%d\n%s\n%s\n%s");
	else
		strcpy(buffer, "\n%d\n%s\n%ld\n%d\n%d\n%d\n%s\n%s\n%s");

	fprintf(task_file, buffer,
		node->id, node->title, node->user_id, node->category_id, node->cost, node->status, node->tags, node->due, node->comments);
	fclose(task_file);
}

void addTask(int id, char title[], int user_id, int cat_id, int cost, int status, char tags[], char due[], char comments[]) {

	// task information 
	struct task * newTask = (struct task *)malloc(sizeof(struct task));

	newTask->id = id;
	strcpy(newTask->title, title);
	newTask->user_id = user_id;
	newTask->category_id = cat_id;
	newTask->cost = cost;
	newTask->status = status;
	strcpy(newTask->tags, tags);
	strcpy(newTask->due, due);
	strcpy(newTask->comments, comments);

	pushTask(newTask);
	setTask(newTask);

}

void updateTask(int id, char title[], int user_id, int cat_id, int cost, int status, char tags[], char due[], char comments[]) {
	task *newTask = findTaskById(id);
	if (newTask != NULL) {
		printf("Task has been find!\n");
		newTask->id = id;
		strcpy(newTask->title, title);
		newTask->user_id = user_id;
		newTask->category_id = cat_id;
		newTask->cost = cost;
		newTask->status = status;
		strcpy(newTask->tags, tags);
		strcpy(newTask->due, due);
		strcpy(newTask->comments, comments);
	}
	else
	{
		printf("task not find\n");
	}
	clearFile("../db/tasks.txt");

	task_node * u = tasks_list;
	while (u) {
		setTask(u->ptr);
		u = u->next;
	}
}

// This function rewrite tasks.txt after deleting specific node
// prototype of function delete with more functionality
void unSetTask(int id) {
	// update user task id
	task * task_ptr = findTaskById(id);
	user * user_ptr = findUserById(task_ptr->user_id);

	user_ptr->task_id = 0;
	setUser(user_ptr);

	if (deleteTask(id)) {

		task_node * new_list = tasks_list;
		if (!new_list) { clearFile("../db/tasks.txt"); return; }

		clearFile("../db/tasks.txt");

		// rewrite new list without deleting node
		while (new_list) {
			setTask(new_list->ptr);
			new_list = new_list->next;
		}
	}
}