void directorChoose(int ch) {
<<<<<<< HEAD
	switch (ch) {
	case 1: { management_projets();  break; }
	case 2: { displayProjects();  break; }
	case 3: {  management_category();  break; }
	case 4: {  displayCategories();  break; }
	case 5: {  management_tasks(); break; }
	case 6: {  displayTask(1);  break; }
	case 7: {  displayTask(0); break; }
	case 8: {  menageComments(); break; }
	case 9: {  displayCommentsByTask(); break; }
	case 10: { displayCommentsByUser(); break; }
	case 11: {  management_users();  break; }
	case 12: {  displayUsersbyProject();  break; }
	case 13: {  displayWorkers(); break; }
	case 14: {  displayManagers();  break; }
	case 15: { CopyTask();  break; }
	case 16: {  CopyProj(); break; }
	case 17: {  printf("\n\n Bye Bye \n\n"); exit(0); break; }
	default: break;
	}
=======
	int i = 1;
	
	if (i == ch){ management_projets();   }i++;
	if (i == ch){  management_users();   }i++;
	if (i == ch){  management_category();   }i++;
	if (i == ch){  management_tasks();  }i++;
	if (i == ch){  menageComments();  }i++;

	if (i == ch){  /*displayProjects();*/   }i++;
	if (i == ch){  displayWorkers();  }i++;
	if (i == ch){  displayManagers();   }i++;
	
	if (i == ch){  displayCategories();   }i++;
	
	if (i == ch){  displayTask(-2);   }i++;
	if (i == ch){  displayTask(-1);   }i++;
	if (i == ch){  displayTask(0);  }i++;
	
	if (i == ch){  displayCommentsByTask();  }i++;
	if (i == ch){ displayCommentsByUser();  }i++;
	
	if (i == ch){  displayUsersbyProject();   }i++;
	
	if (i == ch){ copyTask();   }i++;
	if (i == ch){ /*Translate*/   }i++;
	if (i == ch){  printf("\n\n Bye Bye \n\n"); exit(0);  }
>>>>>>> cafb10cb39f3089646be79980f952af30946ec4b
}

void managerChoose(int ch) {
	int i = 1;
	if (i == ch){  management_users();  }i++;
	if (i == ch){  management_tasks();   }i++;
	if (i == ch){  management_category();   }i++;
	if (i == ch){  menageComments();   }i++;
	if (i == ch){  displayCategories();   }i++;
	if (i == ch){  displayTask(-2);   }i++;
	if (i == ch){  displayTask(-1);   }i++;
	if (i == ch){  displayTask(0);  }i++;
	if (i == ch){  displayCommentsByTask();  }i++;
	if (i == ch){  displayCommentsByUser();  }i++;
	
	if (i == ch){ displayUsersbyProject();  }i++;
	if (i == ch){ copyTask();   }i++;
	if (i == ch){ /* Translate */  }i++;
	if (i == ch){  printf("\n\n Bye Bye \n\n"); exit(0);  }i++;
}

void workerChoose(int ch) {
	int i = 1;
	if (i == ch){ project_info();   }i++;
	if (i == ch){ myTask();   }i++;
	if (i == ch){  completeTask();   }i++;
	if (i == ch){  menageComments();   }i++;
	if (i == ch){  displayCommentsByTask();  }i++;
	if (i == ch){  displayWorkers();   }i++;
	if (i == ch){  redueTask();   }i++;
	if (i == ch){  /*Translate*/   }i++;
	if (i == ch){  printf("\n\n Bye Bye \n\n"); exit(0);  }
}