void menageComments() {
	while (1) {
		int i = 0;
		printf("-----------------------------------\n\n");
		printf("[%d] %s:\n", ++i, i18("Add new comment"));
		printf("[%d] %s:\n", ++i, i18("Edit comment"));
		printf("[%d] %s:\n", ++i, i18("Delete comment"));
		printf("[%d] %s\n", ++i, i18("Back to Menu"));
		printf("-----------------------------------\n\n");

		printf("%s: ", i18("Make your choise"));
		int x = getInt();

		// add
		if (x == 1) {
			int id, pId, tId;
			char title[256];
			char body[256];

			system("cls");

			// by user level
			// director all project
			// manager and worker only current project
			if (user_ptr->level == 1) {
				printf("%s: ",i18("Enter ID of exist project"));
				pId = getInt();
			}
			else {
				pId = user_ptr->porj_id;
			}

			// if project is not exist arise error
			if (findProjById(pId) == NULL)
				printf("%s\n", i18("Not found projects with this id"));

			else {
				if (user_ptr->level == 3)
					tId = user_ptr->task_id;
				else {
					printf("%s: ", i18("Enter ID of exist task"));
					tId = getInt();
				}
				
				if (findTaskById(tId) == NULL)
					printf("%s\n", i18("Not found task with this id"));
				else {
					id = ++unique_comment_key;
					printf("%s: ", i18("Enter title of new comment"));
					getchar();  gets_s(title,256);
					printf("%s: ", i18("Enter your comment"));
					getchar();  gets_s(body,256);
					addComment(id, title, body, pId, tId, user_ptr->id);
				}
			}
		}

		// update
		else if (x == 2) {
			int pId, tId;
			char newTitle[256];
			char newBody[256];

			// it is possible update all fields except ID's
			system("cls");

			// if task exist
			if (tasks_list) {
				if (user_ptr->level == 1) {
					printf("%s: ", i18("Enter ID of exist project"));
					pId = getInt();
				}
				else {
					pId = user_ptr->porj_id;
				}
				proj *tmpP = findProjById(pId);
				
				if (user_ptr->level == 3) {
					tId = user_ptr->task_id;
				}
				else {
					printf("%s: ", i18("Enter ID of exist task"));
					tId = getInt();
				}
				task *tmpT = findTaskById(tId);


				printf("%s %s %s [%s]:\n",i18("All Comments by project"), tmpP->name, i18("for Task"), tmpT->title);
				comment_node * t = comments_list;
				while (t) {
					if (t->ptr->task_id == tId)
						printComment(t->ptr);
					t = t->next;
				}
				printf("%s\n",i18("Enter id of task which need to update"));
				int id = getInt();

				comment * tmp = findcomentById(id);

				// if found comment update it
				if (tmp != NULL) {
					while (1) {
						system("cls");
						i = 0;
						printf("\n %s %s\n----------------------\n", i18("Update comment"), tmp->title);
						printf("[%d] %s:\n", ++i, i18("Change Title"));
						printf("[%d] %s:\n", ++i, i18("Change Comment"));
						printf("[%d] %s\n", ++i, i18("Back to previous menu"));
						int a = getInt();


						if (a == 1) {
							printf("%s: ", i18("Enter New title"));
							getchar(); gets_s(newTitle,256);
							updateComment(tmp->id, newTitle, tmp->body, tmp->porj_id, tmp->task_id, tmp->user_id);
						}

						else if (a == 2) {
							printf("%s: ", i18("Enter New Comment"));
							getchar(); gets_s(newBody,256);
							updateComment(tmp->id, tmp->title, newBody, tmp->porj_id, tmp->task_id, tmp->user_id);
						}

						else if (a == 3) { break; }

						else { break; }
					}
				}
					
				// not found comment
				else {
					printf("%s\n", i18("Not found comments with this id"));
				}
			}
			// arise error no task => no comments
			else {
				printf("%s\n", i18("Task is allready exist"));
			}
		}

		// delete
		else if (x == 3) {
			int pId, tId;
			// if comment exist
			if (comments_list) {
				if (user_ptr->level == 1) {
					printf("%s: ", i18("Enter ID of exist project"));
					pId = getInt();
				}
				else {
					pId = user_ptr->porj_id;
				}
				proj *tmpP = findProjById(pId);

				if (user_ptr->level == 3) {
					tId = user_ptr->task_id;
				}
				else {
					printf("%s: ", i18("Enter ID of exist task"));
					tId = getInt();
				}
				task *tmpT = findTaskById(tId);


				printf("%s %s %s %s:\n", i18("All Comments by project"), tmpP->name, i18("in task"), tmpT->title);
				comment_node * t = comments_list;
				while (t) {
					if (t->ptr->task_id == tId)
						printComment(t->ptr);
					t = t->next;
				}
				
				printf("%s\n", i18("Enter id of comment need to delete"));
				int id = getInt();
				if (findcomentById(id) == NULL)
					printf("%s\n", i18("Not found comments with this id"));
				else {
					// delete current comment
					unSetComment(id);
				}
			}
		}

		// back to main menu
		else if (x == 4) {
			return;
		}

		// if choise is wrong back 
		else { return;  }
	}
}