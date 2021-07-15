void notepad(){
	char notepadChoice = ' ';
	string notepadText = " "; // going to be used for I/O
	int loop = 0;
	do {
		cout << "Greetings, how would you wish to proceed?\n a) Create  b) Read  c) Write\n>";
		try {
			cin >> notepadChoice;
			if (notepadChoice == 'a') {
				ofstream create("notepad.txt");		// Creates file
				cout << "File Successfuly created!\n";
			}
			else if (notepadChoice == 'b') {
				ifstream read("notepad.txt");
				cout << "Notepad contents:\n\n";
				while (getline(read, notepadText)) { 		// Output the text from the file
					cout << notepadText << endl;
				} read.close();
			}
			else if (notepadChoice == 'c') {
				fstream write("notepad.txt", fstream::app);
				cout << "What would you wish to write?\n";
				cin >> notepadText;
				notepadText.append("\n");
				write << notepadText;			// Inputs into file
				write.close();
			}
			else {
				throw (notepadChoice);
			}
		}
		catch (...) {
			cout << "That's not an option!\n";
		}
		cout << "\nLoop the program? 1/0\n";
		cin >> loop;
	} while (loop == 1);
}
