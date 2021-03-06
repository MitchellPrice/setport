// portsetter by Wyatt Sorenson

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <regex>
using namespace std;

void usage(string lang);
string getMsg(int index, string lang);

int main(int argc, char* args[]) {
	const string P = "-p";
	const string PORT = "--port";
	const string QM = "-?";
	const string H = "-h";
	const string HELP = "--help";
	const string EM = "-!";
	const string ABOUT = "--about";
	const string V = "-v";
	const string VERSION = "--version";
	const string E = "-e";
	//string port = "8080";	//UPDATED
	//CHANGED
	string port = "3114";
	string bar = "3116";
	string lang;
	string la = (string)getenv("LANG");
	string file;
	//std::regex regex_lang("^[a-z]{2}(\\_[A-Z]{2})?(\\.UTF-8)?");

	//CHANGED
	//set environment variable BAR
	setenv("BAR", bar.c_str(), 1);
	setenv("PORT", port.c_str(), 1);


	if (la == "C") {
		lang = "en";
	}
	else {
		//bool langGood == std::regex_match(la, regex_lang);
		// regex for cloud9 is unimplemented. The included regex would work.
		//if (!langGood) {
		//cout << "Bad language specification in environment variable LANG=" + la + ". Using English." << endl;
		//lang = "en";
		//break;
		//}
		lang = la.substr(0, 2); // doing only this instead
		std::ifstream infile("setport.about_" + lang + ".txt");
		if (!infile.good()) {
			cout << "Missing pl translation files. Using English." << endl;
			lang = "en";
		}
		infile.close();
	}

	//no args prints usage
	if (argc == 1) {
		usage(lang);
		return 0;
	}


	string args1 = args[1];
	string args2 = "";

	//print About
	if (args1 == EM || args1 == ABOUT) {
		if (argc > 2) {
			cout << getMsg(1, lang) << endl;
			usage(lang);
			return 5;
		}
		else {
			ifstream aboutIn;
			file = "setport.about_" + lang + ".txt";
			aboutIn.open(file.c_str());
			string line;
			getline(aboutIn, line);
			cout << line << endl;
			aboutIn.close();
			return 0;
		}
	}

	//print Version
	if (args1 == V || args1 == VERSION) {
		if (argc > 2) {
			cout << getMsg(2, lang) << endl;
			usage(lang);
			return 5;
		}
		else {
			cout << getMsg(3, lang) + "0.3" << endl;
			return 0;
		}
	}

	//print help
	if (args1 == QM || args1 == H || args1 == HELP) {
		if (argc == 2) {
			usage(lang);
			return 0;
		}
		else {
			cout << getMsg(4, lang) << endl;
			usage(lang);
			return 4;
		}

	}

	//print port listening
	if (args1 == P || args1 == PORT) {
		if (argc == 2) {
			cout << getMsg(5, lang) << endl;
			usage(lang);
			return 3;
		}
		args2 = args[2];
		if (args2 == E) {
			if (argc == 3) {
				cout << getMsg(10, lang) << port << endl;
				return 0;
			}
			if (argc == 4) {
				port = getenv(args[3]);
				cout << getMsg(10, lang) << port << endl; //comeback
				return 0;
			}
			if (argc < 4) {
				cout << getMsg(6, lang) << endl;
				usage(lang);
				return 6;
			}
		}
		if (argc > 3) {
			cout << getMsg(7, lang) << endl;
			usage(lang);
			return 4;
		}
		else {
			if (atoi(args[2]) > 0 && atoi(args[2]) < 65536) {
				cout << getMsg(10, lang) << args2 << endl;;
				return 0;
			}
			else {
				cout << getMsg(8, lang) << args2 << endl;
				usage(lang);
				return 2;
			}
		}
	}

	cout << getMsg(9, lang) << endl;
	usage(lang);
	return 1;
}

//function usage: Explains how to use program
//takes no params
//returns nothing
void usage(string lang) {
	ifstream aboutIn;
	string file = "setport.usage_" + lang + ".txt";
	aboutIn.open(file.c_str());
	string line;
	while (getline(aboutIn, line))
	{
		cout << line << endl;
	}
	aboutIn.close();
}

string getMsg(int index, string lang) {
	ifstream aboutIn;
	string file = "setport.msg_" + lang + ".txt";
	aboutIn.open(file.c_str());
	string line;
	for (int i = 0; i < index; i++) {
		getline(aboutIn, line);
	}
	aboutIn.close();
	return line;
}

/*
Everything that was updated has a //UPDATED tag
Updates:
set environment variable PORT to 3114

Everything that was changed has a //CHANGED tag
Changes:
set environment variable BAR to 3116
*/