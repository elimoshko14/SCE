void printComment(comment * node) {
	printf("id %ld\n", node->id);
	printf("title %s\n", node->title);
	printf("body %s\n", node->body);
	printf("project_id %d\n", node->porj_id);
	printf("task_id %d\n", node->task_id);
	printf("user_id %d\n", node->user_id);
	printf("-------------\n");
}

void printComentTree() {
	comment_node * c = comments_list;
	if (!c)
		return;
	while (c)
	{
		printComment(c->ptr);
		c = c->next;
	}
}

void pushComent(comment * node)
{
	struct comment_node * temp;
	temp = (struct comment_node *)malloc(sizeof(struct comment_node));
	temp->ptr = node;
	if (comments_list == NULL)
	{
		comments_list = temp;
		comments_list->next = NULL;
	}
	else
	{
		temp->next = comments_list;
		comments_list = temp;
	}
}

bool deleteComent(int id)
{
	struct comment_node * temp, *prev = NULL;
	temp = comments_list;
	while (temp != NULL)
	{
		if (temp->ptr->id == id)
		{
			if (temp == comments_list)
			{
				comments_list = temp->next;
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

comment_node * findcomentById(int id) {
	struct comment_node * temp;
	temp = comments_list;
	while (temp != NULL)
	{
		if (temp->ptr->id == id)
			return temp;
		else
			temp = temp->next;
	}
	return NULL;
}

void getComments() {

	FILE * coments_file;
	char filename[] = "../db/comments.txt";
	coments_file = fopen(filename, "r");

	if (coments_file == NULL) {
		perror("Error");
		return;
	}
	// GET DATA FROM FILE //
	char ch; // See end of loop
	do {
		struct comment * coment_struct = (struct comment *)malloc(sizeof(struct comment));

		char buffer[256];
		// get id
		fscanf(coments_file, "%ld", &(coment_struct->id));
		fgets(buffer, 256, coments_file);

		// get title
		fgets(coment_struct->title, '256', coments_file);
		strtok(coment_struct->title, "\n");

		// get body
		fgets(coment_struct->body, '256', coments_file);
		strtok(coment_struct->body, "\n");

		// get proj id
		fscanf(coments_file, "%d", &(coment_struct->porj_id));
		fgets(buffer, 256, coments_file);

		// get task id
		fscanf(coments_file, "%d", &(coment_struct->task_id));
		fgets(buffer, 256, coments_file);

		// get user id
		fscanf(coments_file, "%d", &(coment_struct->user_id));
		fgets(buffer, 256, coments_file);

		pushComent(coment_struct);
		/*******/
		// FEOF IS BUGGED == TRUE IF END OF FILE ()
		/*******/
		// FIX
		ch = fgetc(coments_file);
		ungetc(ch, coments_file);

	} while (!feof(coments_file) && ch != EOF);

	fclose(coments_file);
}
