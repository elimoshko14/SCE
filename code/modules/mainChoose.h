void mainChoose(int ch) {

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
	case 15: {  break; }
	case 16: {  break; }
	case 17: {  printf("\n\n Bye Bye \n\n"); exit(0); break; }


	default: break;
	}
}