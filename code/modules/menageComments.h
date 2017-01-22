void menageComments() {
	while (1) {
		int i = 0;
		printf("-----------------------------------\n\n");
		printf("[%d] Add new comment:\n", ++i);
		printf("[%d] Edit comment:\n", ++i);
		printf("[%d] Delete comment:\n", ++i);
		printf("[%d] Back to Menu\n", ++i);
		printf("-----------------------------------\n\n");

		printf("Make your choise: ");
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
				printf("Enter ID of exist project: ");
				pId = getInt();
			}
			else {
				pId = user_ptr->porj_id;
			}

			// if project is not exist arise error
			if (findProjById(pId) == NULL)
				printf("%s\n", errors[0][0]);

			else {
				if (user_ptr->level == 3)
					tId = user_ptr->task_id;
				else {
					printf("Enter ID of exist task: ");
					tId = getInt();
				}
				
				if (findTaskById(tId) == NULL)
					printf("%s\n", errors[2][0]);
				else {
					id = ++unique_comment_key;
					printf("Enter title of new comment: ");
					getchar();  gets_s(title,256);
					printf("Enter your comment: ");
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
					printf("Enter ID of exist project: ");
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
					printf("Enter ID of exist task: ");
					tId = getInt();
				}
				task *tmpT = findTaskById(tId);


				printf("All Comments by project %s for Task [%s]:\n", tmpP->name, tmpT->title);
				comment_node * t = comments_list;
				while (t) {
					if (t->ptr->task_id == tId)
						printComment(t->ptr);
					t = t->next;
				}
				printf("Enter id of task which need to update\n");
				int id = getInt();

				comment * tmp = findcomentById(id);

				// if found comment update it
				if (tmp != NULL) {
					while (1) {
						system("cls");
						i = 0;
						printf("\n Update comment %s\n----------------------\n", tmp->title);
						printf("[%d] Change Title:\n", ++i);
						printf("[%d] Change Comment:\n", ++i);
						printf("[%d] Back to previous menu\n", ++i);
						int a = getInt();


						if (a == 1) {
							printf("Enter New title: ");
							getchar(); gets_s(newTitle,256);
							updateComment(tmp->id, newTitle, tmp->body, tmp->porj_id, tmp->task_id, tmp->user_id);
						}

						else if (a == 2) {
							printf("Enter New Comment: ");
							getchar(); gets_s(newBody,256);
							updateComment(tmp->id, tmp->title, newBody, tmp->porj_id, tmp->task_id, tmp->user_id);
						}

						else if (a == 3) { break; }

						else { break; }
					}
				}
					
				// not found comment
				else {
					printf("%s\n", errors[3][0]);
				}
			}
			// arise error no task => no comments
			else {
				printf("%s\n", errors[2][2]);
			}
		}

		// delete
		else if (x == 3) {
			int pId, tId;
			// if comment exist
			if (comments_list) {
				if (user_ptr->level == 1) {
					printf("Enter ID of exist project: ");
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
					printf("Enter ID of exist task: ");
					tId = getInt();
				}
				task *tmpT = findTaskById(tId);


				printf("All Comments by project %s in task %s:\n", tmpP->name, tmpT->title);
				comment_node * t = comments_list;
				while (t) {
					if (t->ptr->task_id == tId)
						printComment(t->ptr);
					t = t->next;
				}
				
				printf("Enter id of comment need to delete\n");
				int id = getInt();
				if (findcomentById(id) == NULL)
					printf("%s\n", errors[3][0]);
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