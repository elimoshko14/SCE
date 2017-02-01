void exportCSV() {

	// lists
	 user_node * usr_runner = users_list;
	 proj_node * prj_runner = projects_list;
	 task_node * tsk_runner = tasks_list;
	 comment_node * cmnt_runner = comments_list;
	 category_node * cat_runner = categories_list;

	 printf("Exporting Users List...\n");
	 while (usr_runner != NULL) {
		 FILE * csv;
		 char filename[] = "../db/users.csv";
		 csv = fopen(filename, "a");

		 if (csv == NULL) {
			 perror("Error");
			 return;
		 }

		 char buffer[256];
		strcpy(buffer, "%ld,%s,%d,%d,%d,%s,%d,%d,%s,%s\n");


		 fprintf(csv, buffer,
			 usr_runner->ptr->id, usr_runner->ptr->name, usr_runner->ptr->level, usr_runner->ptr->porj_id, usr_runner->ptr->task_id, usr_runner->ptr->lang, usr_runner->ptr->salery, usr_runner->ptr->online, usr_runner->ptr->coments, usr_runner->ptr->password);

		 fclose(csv);
		 usr_runner = usr_runner->next;
	 }

	 printf("Done!\n");
	 printf("Exporting Projects List...\n");
	 while (prj_runner != NULL) {
		 FILE * csv;
		 char filename[] = "../db/projects.csv";
		 csv = fopen(filename, "a");

		 if (csv == NULL) {
			 perror("Error");
			 return;
		 }

		 char buffer[256];
		 strcpy(buffer, "%d\n%s\n%s\n%s\n%s\n%d\n%s\n%d\n%d");


		 fprintf(csv, buffer,
			 prj_runner->id,
			 prj_runner->name,
			 prj_runner->users_arr,
			 prj_runner->tasks_arr,
			 prj_runner->cats_arr,
			 prj_runner->manager_id,
			 prj_runner->due,
			 prj_runner->status,
			 prj_runner->cost);

		 fclose(csv);
		 prj_runner = prj_runner->next;
	 }

	 printf("Done!\n");
	 printf("Exporting Tasks List...\n");
	 while (prj_runner != NULL) {
		 FILE * csv;
		 char filename[] = "../db/projects.csv";
		 csv = fopen(filename, "a");

		 if (csv == NULL) {
			 perror("Error");
			 return;
		 }

		 char buffer[256];
		 strcpy(buffer, "%d\n%s\n%s\n%s\n%s\n%d\n%s\n%d\n%d");


		 fprintf(csv, buffer,
			 prj_runner->id,
			 prj_runner->name,
			 prj_runner->users_arr,
			 prj_runner->tasks_arr,
			 prj_runner->cats_arr,
			 prj_runner->manager_id,
			 prj_runner->due,
			 prj_runner->status,
			 prj_runner->cost);

		 fclose(csv);
		 prj_runner = prj_runner->next;
	 }

	 printf("Done!\n");
}