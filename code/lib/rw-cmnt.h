comment * findcomentById(int id) {
	struct comment_node * temp;
	temp = comments_list;
	while (temp != NULL)
	{
		if (temp->ptr->id == id)
			return temp->ptr;
		else
			temp = temp->next;
	}
	return NULL;
}

void printComment(comment * node) {
	printf("id %ld\n", node->id);
	printf("Title: %s\n", node->title);
	printf("%s\n", node->body);
	//printf("project_id %d\n", node->porj_id);
	//printf("task_id %d\n", node->task_id);
	//printf("user_id %d\n", node->user_id);
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

void getComments() {
	FILE * coments_file;
	char filename[] = "../db/comments.txt";
	coments_file = fopen(filename, "r");

	if (isEmptyFile(coments_file)) return;

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

void setComment(comment *node) {

	FILE * comment_file;
	char filename[] = "../db/comments.txt";
	comment_file = fopen(filename, "a");

	if (comment_file == NULL) {
		perror("Error");
		return;
	}

	char buffer[256];
	if (isEmptyFile(comment_file))
		strcpy(buffer, "%d\n%s\n%s\n%d\n%d\n%d");
	else
		strcpy(buffer, "\n%d\n%s\n%s\n%d\n%d\n%d");

	fprintf(comment_file, buffer,
		node->id, node->title, node->body, node->porj_id, node->task_id, node->user_id);
	fclose(comment_file);
}

void addComment(int id,char title[],char body[],int porj_id,int task_id ,int user_id) {

	// comment information 
	struct comment * newComment = (struct comment *)malloc(sizeof(struct category));

	newComment->id = id;
	strcpy(newComment->title, title);
	strcpy(newComment->body, body);
	newComment->porj_id = porj_id;
	newComment->task_id = task_id;
	newComment->user_id = user_id;

	pushComent(newComment);
	setComment(newComment);
}

void updateComment(int id, char title[], char body[], int porj_id, int task_id, int user_id) {
	comment *node = findcomentById(id);
	if (node != NULL) {
		printf("comment has been find!\n");
		node->id = id;
		strcpy(node->title, title);
		node->porj_id = porj_id;
		node->task_id = task_id;
		node->user_id = user_id;
	}
	else
	{
		printf("comment not find\n");
	}
	clearFile("../db/comments.txt");

	comment_node * c = comments_list;
	while (c) {
		setComment(c->ptr);
		c = c->next;
	}
}

void unSetComment(int id) {

	// only if previous delete from users_list
	if (deleteComent(id)) {

		comment_node * new_list = comments_list;
		if (!new_list) { clearFile("../db/users.txt"); return; }

		clearFile("../db/comments.txt");

		// rewrite new list without deleting node
		while (new_list) {
			setComment(new_list->ptr);
			new_list = new_list->next;
		}
	}
}
