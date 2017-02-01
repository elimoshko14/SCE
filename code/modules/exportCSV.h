void exportCSV() {

	// lists
	 user_node * usr_runner = users_list;
	 proj_node * prj_runner = projects_list;
	 task_node * tsk_runner = tasks_list;

	 /**********************************************************/
	 /**********************************************************/
	 printf("Exporting Users List...\n");
	 while (usr_runner != NULL) {
		 FILE * csv;
		 char filename[] = "../db/users.csv";
		 clearFile("../db/users.csv");
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
	 /**********************************************************/
	 /**********************************************************/
	 printf("Exporting Projects List...\n");
	 while (prj_runner != NULL) {
		 FILE * csv;
		 char filename[] = "../db/projects.csv";
		 clearFile("../db/projects.csv");
		 csv = fopen(filename, "a");

		 if (csv == NULL) {
			 perror("Error");
			 return;
		 }

		 char buffer[256];
		 strcpy(buffer, "%d\n%s\n%s\n%s\n%s\n%d\n%s\n%d\n%d");


		 fprintf(csv, buffer,
			 prj_runner->ptr->id,
			 prj_runner->ptr->name,
			 prj_runner->ptr->users_arr,
			 prj_runner->ptr->tasks_arr,
			 prj_runner->ptr->cats_arr,
			 prj_runner->ptr->manager_id,
			 prj_runner->ptr->due,
			 prj_runner->ptr->status,
			 prj_runner->ptr->cost);

		 fclose(csv);
		 prj_runner = prj_runner->next;
	 }

	 printf("Done!\n");
	 /**********************************************************/
	 /**********************************************************/
	 printf("Exporting Tasks List...\n");
	 while (tsk_runner != NULL) {
		 FILE * csv;
		 char filename[] = "../db/tasks.csv";
		 clearFile("../db/tasks.csv");
		 csv = fopen(filename, "a");

		 if (csv == NULL) {
			 perror("Error");
			 return;
		 }

		 char buffer[256];
		 strcpy(buffer, "%d\n%s\n%ld\n%d\n%d\n%d\n%s\n%s\n%s");


		 fprintf(csv, buffer, tsk_runner->ptr->id, tsk_runner->ptr->title, tsk_runner->ptr->user_id, tsk_runner->ptr->category_id, tsk_runner->ptr->cost, tsk_runner->ptr->status, tsk_runner->ptr->tags, tsk_runner->ptr->due, tsk_runner->ptr->comments);

		 fclose(csv);
		 tsk_runner = tsk_runner->next;
	 }

	 printf("Done!\n");
	 /**********************************************************/
	 /**********************************************************/
}