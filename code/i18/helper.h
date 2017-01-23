#define LEN 1000

void pushKey(dict * node)
{
	struct dict_node * temp;
	temp = (struct dict_node *)malloc(sizeof(struct dict_node));
	temp->ptr = node;
	if (dictionary == NULL)
	{
		dictionary = temp;
		dictionary->next = NULL;
	}
	else
	{
		temp->next = dictionary;
		dictionary = temp;
	}
}

void changeLang() {

	char i18[] = "../i18/i18.txt";
	FILE * file_ptr;
	file_ptr = fopen(i18, "r");
	if (isEmptyFile(file_ptr)) return;

	// GET DATA FROM FILE //
	char ch; // See end of loop
	do {
		struct dict * trans = (struct dict *)malloc(sizeof(struct dict));

		fgets(trans->key, 256, file_ptr);
		strtok(trans->key, "\n");

		fgets(trans->value_en, LEN, file_ptr);
		strtok(trans->value_en, "\n");

		fgets(trans->value_ru, LEN, file_ptr);
		strtok(trans->value_ru, "\n");



		pushKey(trans);
		ch = fgetc(file_ptr);
		ungetc(ch, file_ptr);
	} while (!feof(file_ptr) && ch != EOF);

	fclose(file_ptr);
}

char * i18(char * key) {
	struct dict_node * temp;
	temp = dictionary;
	while (temp != NULL)
	{
		if (strcmp(temp->ptr->key, key) == 0)
			if (!user_ptr || strcmp(user_ptr->lang, "EN") == 0)
				return temp->ptr->value_en;
			else
				return temp->ptr->value_ru;
		else
			temp = temp->next;
	}
	return NULL;
}