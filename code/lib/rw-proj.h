void printProj(proj * proj_struct) {
	printf("ID:\t%d\n", proj_struct->id);
	printf("Users Array:\t%s\n", proj_struct->users_arr);
	printf("Tasks Array:\t%s\n", proj_struct->tasks_arr);
	printf("Categories Array:\t%s\n", proj_struct->cats_arr);
	printf("Manager ID:\t%d\n", proj_struct->manager_id);
	printf("Due:\t%s\n", proj_struct->due);
	printf("Status\t%d\n", proj_struct->status);
	printf("Cost:\t%d\n", proj_struct->cost);
	printf("-------------\n");
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
		// end line
		fgets(buffer, 256, proj_file);
		// get user arr
		fscanf(proj_file, "%s", (proj_struct->users_arr));
		// end line
		fgets(buffer, 256, proj_file);
		// get tasks_arr
		fscanf(proj_file, "%s", proj_struct->tasks_arr);
		// end line
		fgets(buffer, 256, proj_file);
		// get cats_arr
		fscanf(proj_file, "%s", proj_struct->cats_arr);
		// drop line
		fgets(buffer, 256, proj_file);
		// get manager_id
		fscanf(proj_file, "%d", &(proj_struct->manager_id));
		// drop line
		fgets(buffer, 256, proj_file);
		// get finish_date
		fscanf(proj_file, "%s", proj_struct->due);
		// drop line
		fgets(buffer, 256, proj_file);
		// get status
		fscanf(proj_file, "%d", &(proj_struct->status));
		// drop line
		fgets(buffer, 256, proj_file);
		// get cost
		fscanf(proj_file, "%d", &(proj_struct->cost));
		// drop line
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
