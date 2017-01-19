void printCat(category * node) {
	printf("ID:\t%ld\n", node->id);
	printf("Name:\t%s\n", node->name);
	printf("Project ID:\t%d\n", node->proj_id);
	printf("Comments:\t%s\n", node->comment_arr);
	printf("\n\n");
}


void printCatTree() {
	category_node * t = categories_list;
	if (!t)
		return;
	while (t)
	{
		printCat(t->ptr);
		t = t->next;
	}
}

void pushCat(category * node)
{
	struct category_node * temp;
	temp = (struct category_node *)malloc(sizeof(struct category_node));
	temp->ptr = node;
	if (categories_list == NULL)
	{
		categories_list = temp;
		categories_list->next = NULL;
	}
	else
	{
		temp->next = categories_list;
		categories_list = temp;
	}
}

bool deleteCat(int id)
{
	struct category_node * temp, *prev = NULL;
	temp = categories_list;
	while (temp != NULL)
	{
		if (temp->ptr->id == id)
		{
			if (temp == categories_list)
			{
				categories_list = temp->next;
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


void getCategories() {

	FILE * categorys_file;
	char filename[] = "../db/categorys.txt";
	categorys_file = fopen(filename, "r");

	if (isEmptyFile(categorys_file)) return;

	// GET DATA FROM FILE //
	char ch; // See end of loop
	do {
		struct category * category_struct = (struct category *)malloc(sizeof(struct category));

		char buffer[256];
		// get id
		fscanf(categorys_file, "%ld", &(category_struct->id));
		// drop line
		fgets(buffer, 256, categorys_file);

		// get name
		fgets(category_struct->name, '256', categorys_file);
		// clear \n
		strtok(category_struct->name, "\n");
		// get proj id
		fscanf(categorys_file, "%d", &(category_struct->proj_id));
		// drop line
		fgets(buffer, 256, categorys_file);

		// get coments array (strings)
		fscanf(categorys_file, "%s", category_struct->comment_arr);
		// drop line
		fgets(buffer, 256, categorys_file);
		// clear \n
		strtok(category_struct->comment_arr, "\n");


		pushCat(category_struct);
		/*******/
		// FEOF IS BUGGED == TRUE IF END OF FILE ()
		/*******/
		// FIX
		ch = fgetc(categorys_file);
		ungetc(ch, categorys_file);

	} while (!feof(categorys_file) && ch != EOF);

	fclose(categorys_file);
}

void setCat(category *node) {

	FILE * cat_file;
	char filename[] = "../db/categorys.txt";
	cat_file = fopen(filename, "a");

	if (cat_file == NULL) {
		perror("Error");
		return;
	}


	fprintf(cat_file, "\n%d\n%s\n%d\n%s",
		node->id, node->name, node->proj_id, node->comment_arr);
}

void addCat(int id, char name[], int proj_id, char comment_arr[]) {

	// category information 
	struct category * newCat = (struct category *)malloc(sizeof(struct category));

	newCat->id = id;
	strcpy(newCat->name, name);
	newCat->proj_id = proj_id;
	strcpy(newCat->comment_arr, comment_arr);

	pushCat(newCat);
	setCat(newCat);
}

category * findCatById(long id) {
	struct category_node * temp;
	temp = categories_list;
	while (temp != NULL)
	{
		if (temp->ptr->id == id)
			return temp->ptr;
		else
			temp = temp->next;
	}
	return NULL;
}

void UpdateCat(int id, char name[], int proj_id, char comment_arr[]) {
	category *node = findCatById(id);
	if (node != NULL) {
		printf("Category has been find!\n");
		node->id = id;
		strcpy(node->name, name);
		node->proj_id = proj_id;
		strcpy(node->comment_arr, comment_arr);
	}
	else
	{
		printf("category not find!\n");
	}
	clearFile("../db/categorys.txt");

	category_node * u = categories_list;
	while (u) {
		setCat(u->ptr);
		u = u->next;
	}
}

void unSetCat(int id) {

	// only if previous delete from cat_list
	if (deleteCat(id)) {
		category_node * new_list = categories_list;
		if (!new_list) { clearFile("../db/categorys.txt"); return; }

		clearFile("../db/categorys.txt");

		// rewrite new list without deleting node
		while (new_list) {
			setCat(new_list->ptr);
			new_list = new_list->next;
		}
	}
}