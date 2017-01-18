proj_node * findProjById(int id) {
	struct proj_node * temp;
	temp = projects_list;
	while (temp != NULL)
	{
		if (temp->ptr->id == id)
			return temp;
		else
			temp = temp->next;
	}
	return NULL;
}

void printProj(proj * proj_struct) {
	printf("ID:\t%d\n", proj_struct->id);
	printf("Users Array:\t%s\n", proj_struct->users_arr);
	printf("Tasks Array:\t%s\n", proj_struct->tasks_arr);
	printf("Categories Array:\t%s\n", proj_struct->cats_arr);
	printf("Manager ID:\t%d\n", proj_struct->manager_id);
	printf("Due:\t%s\n", proj_struct->due);
	printf("Status\t%d\n", proj_struct->status);
	printf("Cost:\t%d\n", proj_struct->cost);
	printf("\n\n");
}

void printProjTree() {
	proj_node * t = projects_list;
	if (!t)
		return;
	while (t)
	{
		printProj(t->ptr);
		t = t->next;
	}
}

void pushProj(proj * node)
{
	struct proj_node * temp;
	temp = (struct proj_node *)malloc(sizeof(struct proj_node));
	temp->ptr = node;
	if (projects_list == NULL)
	{
		projects_list = temp;
		projects_list->next = NULL;
	}
	else
	{
		temp->next = projects_list;
		projects_list = temp;
	}
}

bool deleteProj(int id)
{
	struct proj_node * temp, *prev = NULL;
	temp = projects_list;
	while (temp != NULL)
	{
		if (temp->ptr->id == id)
		{
			if (temp == projects_list)
			{
				projects_list = temp->next;
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

void getProjs() {

	FILE * proj_file;
	char filename[] = "../db/projects.txt";
	proj_file = fopen(filename, "r");

	if (proj_file == NULL) {
		perror("Error");
		return;
	}
	// GET DATA FROM FILE //
	char ch; // See end of loop
	do {
		struct proj * proj_struct = (struct proj *)malloc(sizeof(struct proj));

		char buffer[256];
		// get id
		fscanf(proj_file, "%d", &(proj_struct->id));
		fgets(buffer, 256, proj_file);
		// get user arr
		fscanf(proj_file, "%s", (proj_struct->users_arr));
		fgets(buffer, 256, proj_file);
		// get tasks_arr
		fscanf(proj_file, "%s", proj_struct->tasks_arr);
		fgets(buffer, 256, proj_file);
		// get cats_arr
		fscanf(proj_file, "%s", proj_struct->cats_arr);
		fgets(buffer, 256, proj_file);
		// get manager_id
		fscanf(proj_file, "%d", &(proj_struct->manager_id));
		fgets(buffer, 256, proj_file);
		// get finish_date
		fscanf(proj_file, "%s", proj_struct->due);
		fgets(buffer, 256, proj_file);
		// get status
		fscanf(proj_file, "%d", &(proj_struct->status));
		fgets(buffer, 256, proj_file);
		// get cost
		fscanf(proj_file, "%d", &(proj_struct->cost));
		fgets(buffer, 256, proj_file);

		pushProj(proj_struct);
		/*******/
		// FEOF IS BUGGED == TRUE IF END OF FILE ()
		/*******/
		// FIX
		ch = fgetc(proj_file);
		ungetc(ch, proj_file);

	} while (!feof(proj_file) && ch != EOF);

	fclose(proj_file);
}

void setProjs(proj *node) {

	FILE * proj_file;
	char filename[] = "../db/projects.txt";
	proj_file = fopen(filename, "a");

	if (proj_file == NULL) {
		perror("Error");
		return;
	}

	char buffer[256];

	fprintf(proj_file, "\n%d\n%s\n%s\n%s\n%d\n%s\n%d\n%d",
		node->id,
		node->users_arr,
		node->tasks_arr,
		node->cats_arr,
		node->manager_id,
		node->due,
		node->status,
		node->cost);

	fclose(proj_file);
}

void addProj(int id, int manager_id,int cost,char due[]) {

	// project information is empty for  new project

	struct proj * proj_struct = (struct proj *)malloc(sizeof(struct proj));

	proj_struct->id = id; // id  have to be auto generate (len(projects_list)+1)
	proj_struct->manager_id = manager_id;
	strcpy(proj_struct->due, due);
	proj_struct->cost = cost;
	strcpy(proj_struct->users_arr, "-1");
	strcpy(proj_struct->tasks_arr, "-1");
	strcpy(proj_struct->cats_arr, "-1");
	proj_struct->status = 0;

	pushProj(proj_struct);
	setProjs(proj_struct);

}

void updateProj(int id,int manager_id , char due[],bool status,int cost) {
	proj *node = findProjById(id);
	if (node != NULL) {
		printf("Proj has been find!\n");
		node->id = id;
		node->manager_id = manager_id;
		strcpy(node->users_arr, "-1");
		strcpy(node->tasks_arr, "-1");
		strcpy(node->cats_arr, "-1");
		strcpy(node->due, due);
		node->status = status;
		node->cost = cost;
	}
	else
	{
		printf("proj not find\n");
	}
	clearFile("../db/projects.txt");

	proj_node * t = projects_list;
	while (t) {
		setProjs(t->ptr);
		t = t->next;

	}
}

void unSetProj(int id) {

	// only if previous delete from users_list
	if (deleteProj(id)) {

		proj_node * new_list = projects_list;
		if (!new_list) return;

		clearFile("../db/projects.txt");

		// rewrite new list without deleting node
		while (new_list) {
			setProjs(new_list->ptr);
			new_list = new_list->next;
		}
	}
}