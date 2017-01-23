#define LEN 1000

char MANAG_PROJECT[LEN];






void changeLang() {

	if (!user_ptr) {
		strcpy(MANAG_PROJECT, "Manage projects");
	}
	else {
		if (strcmp(user_ptr->lang, "EN")== 0){
			strcpy(MANAG_PROJECT,"Manage projects");
		}
		else {
			strcpy(MANAG_PROJECT, "פûגפצגû ןפûגא פן ןגאûפאûג");
		}
	}
}