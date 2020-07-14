#include <iostream>
#include <Windows.h>
using namespace std;
COORD coord = { 0, 0 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y)	//defining/initializing to predefined objects
{
	coord.X = x;
	coord.Y = y; // X and Y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void DrawLogIn() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;
	gotoxy(51, 7);
	cout << "LOG IN " << endl;
	// Drawing for Username
	for (int i = 35; i < 75; i++) {
		gotoxy(i, 10);
		cout << "-" << endl;
	}

	for (int i = 35; i < 75; i++) {
		gotoxy(i, 12);
		cout << "-" << endl;
	}
	gotoxy(35, 11);
	cout << "|" << endl;
	gotoxy(74, 11);
	cout << "|" << endl;
	gotoxy(50, 9);
	cout << "USERNAME : " << endl;

	// Drawing for Password

	for (int i = 35; i < 75; i++) {
		gotoxy(i, 15);
		cout << "-" << endl;
	}

	for (int i = 35; i < 75; i++) {
		gotoxy(i, 17);
		cout << "-" << endl;
	}
	gotoxy(35, 16);
	cout << "|" << endl;
	gotoxy(74, 16);
	cout << "|" << endl;
	gotoxy(50, 14);
	cout << "PASSWORD : " << endl;
}

void DrawWelcome() {
	SetConsoleTextAttribute(hStdOut, 15);
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;
	for (int i = 35; i < 75; i++) {
		gotoxy(i, 10);
		cout << "-" << endl;
		gotoxy(i, 12);
		cout << "-" << endl;
	}
	gotoxy(35, 11);
	cout << "|" << endl;
	gotoxy(74, 11);
	cout << "|" << endl;
	SetConsoleTextAttribute(hStdOut, 10);
	gotoxy(52, 11);
	cout << "W";
	Sleep(500);
	gotoxy(53, 11);
	cout << "E";
	Sleep(500);
	gotoxy(54, 11);
	cout << "L";
	Sleep(500);
	gotoxy(55, 11);
	cout << "C";
	Sleep(500);
	gotoxy(56, 11);
	cout << "O";
	Sleep(500);
	gotoxy(57, 11);
	cout << "M";
	Sleep(500);
	gotoxy(58, 11);
	cout << "E";
}

void DrawMainMenu() {
	gotoxy(48, 2);
	cout << "THUNDER AVIATION 2020" << endl;
	for (int i = 29; i < 90; i++) {
		gotoxy(i, 4);
		cout << "-";
	}
	for (int i = 5; i < 12; i++) {
		gotoxy(29, i);
		cout << "|";
	}
	for (int i = 5; i < 12; i++) {
		gotoxy(89, i);
		cout << "|";
	}
	gotoxy(50, 5);
	cout << "1. View Tables ";
	gotoxy(50, 7);
	cout << "2. Make Entry ";
	gotoxy(50, 9);
	cout << "3. Go to Log In screen ";
	gotoxy(56, 14);
	cout << "INPUT : ";
	for (int i = 29; i < 90; i++) {
		gotoxy(i, 12);
		cout << "-";
	}
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 15);
		cout << "-";
	}
	gotoxy(55, 16);
	cout << "|";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 17);
		cout << "-";
	}
	gotoxy(63, 16);
	cout << "|";
	gotoxy(59, 16);
}

void DrawTables() {
	gotoxy(48, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(42, 4);
	cout << "LIST OF DATA TO BE VIEWED EXTERNALLY";

	for (int i = 29; i < 90; i++) {
		gotoxy(i, 5);
		cout << "-";
	}
	for (int i = 6; i < 35; i++) {
		gotoxy(29, i);
		cout << "|";
	}
	for (int i = 6; i < 35; i++) {
		gotoxy(89, i);
		cout << "|";
	}
	for (int i = 29; i < 90; i++) {
		gotoxy(i, 34);
		cout << "-";
	}
	gotoxy(50, 6);
	cout << "- Engines :  ";
	gotoxy(53, 7);
	cout << " -- Engines.ta";

	gotoxy(50, 9);
	cout << "- Employment : ";
	gotoxy(53, 10);
	cout << " -- Employment.ta";

	gotoxy(50, 12);
	cout << "- Parts : ";
	gotoxy(53, 13);
	cout << " -- FanBlades.ta";
	gotoxy(53, 14);
	cout << " -- Spinner.ta";
	gotoxy(53, 15);
	cout << " -- HighPressureCompressor.ta";
	gotoxy(53, 16);
	cout << " -- HighPressureTurbine.ta";
	gotoxy(53, 17);
	cout << " -- CombustionChamber.ta";
	gotoxy(53, 18);
	cout << " -- LowPressureTurbine.ta";

	gotoxy(50, 21);
	cout << "- Electronic Parts : ";
	gotoxy(53, 22);
	cout << " -- Capacitor.ta";
	gotoxy(53, 23);
	cout << " -- Resistor.ta";
	gotoxy(53, 24);
	cout << " -- SemiConductor.ta";

	gotoxy(50, 26);
	cout << "- CUs";
	gotoxy(53, 27);
	cout << " -- ControlUnits.ta";

	gotoxy(50, 29);
	cout << "- Materials";
	gotoxy(53, 30);
	cout << " -- Pipes.ta";
	gotoxy(53, 31);
	cout << " -- Rods.ta";
	gotoxy(53, 32);
	cout << " -- Sheets.ta";
	gotoxy(53, 33);
	cout << " -- SolderingWire.ta";

	gotoxy(40, 36);
	cout << "NAME OF THE FILE (INCLUDING THE EXTENSION)";

	gotoxy(39, 41);
	cout << "*Type \"MainMenu\" for going back to Main Menu";

	for (int i = 40; i < 82; i++) {
		gotoxy(i, 37);
		cout << "-";
	}
	gotoxy(40, 38);
	cout << "|";
	for (int i = 40; i < 82; i++) {
		gotoxy(i, 39);
		cout << "-";
	}
	gotoxy(81, 38);
	cout << "|";
	gotoxy(42,38);

}

void DrawMkEntry() {
	gotoxy(48, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(38, 4);
	cout << "CHOOSE FOR WHAT YOU WOULD LIKE TO MAKE ENTRY";

	for (int i = 29; i < 90; i++) {
		gotoxy(i, 5);
		cout << "-";
	}
	for (int i = 6; i < 20; i++) {
		gotoxy(29, i);
		cout << "|";
	}
	for (int i = 6; i < 20; i++) {
		gotoxy(89, i);
		cout << "|";
	}
	for (int i = 29; i < 90; i++) {
		gotoxy(i, 19);
		cout << "-";
	}

	gotoxy(50, 6);
	cout << "1. Engines ";
	gotoxy(50, 8);
	cout << "2. Employment ";
	gotoxy(50, 10);
	cout << "3. Materials";
	gotoxy(50, 12);
	cout << "4. Electronic Parts";
	gotoxy(50, 14);
	cout << "5. Control Units";
	gotoxy(50, 16);
	cout << "6. Parts";
	gotoxy(50, 18);
	cout << "0. Main Menu";

	gotoxy(56, 21);
	cout << "INPUT : ";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 22);
		cout << "-";
	}
	gotoxy(55, 23);
	cout << "|";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 24);
		cout << "-";
	}
	gotoxy(63, 23);
	cout << "|";
	gotoxy(59, 23);
}

void DrawEngineInput() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(50, 4);
	cout << "ENGINE INPUT";

	gotoxy(17, 7);
	cout << "CODE : ";
	for (int i = 10; i < 30; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 10; i < 30; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(10, 9);
	cout << "|";
	gotoxy(29, 9);
	cout << "|";

	gotoxy(50, 7);
	cout << "DESCRIPTION : ";
	for (int i = 35; i < 75; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 35; i < 75; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(35, 9);
	cout << "|";
	gotoxy(74, 9);
	cout << "|";

	gotoxy(80, 7);
	cout << "QUANTITY : ";
	for (int i = 80; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 80; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(80, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}

void DrawEmployeeEntry() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;
	
	gotoxy(41, 4);
	cout << "CHOOSE CATEGORIES FOR EMPLOYEE";

	for (int i = 29; i < 90; i++) {
		gotoxy(i, 5);
		cout << "-";
	}
	for (int i = 6; i < 20; i++) {
		gotoxy(29, i);
		cout << "|";
	}
	for (int i = 6; i < 20; i++) {
		gotoxy(89, i);
		cout << "|";
	}
	for (int i = 29; i < 90; i++) {
		gotoxy(i, 19);
		cout << "-";
	}

	gotoxy(50, 6);
	cout << "1. Engineers ";
	gotoxy(50, 8);
	cout << "2. Scientists ";
	gotoxy(50, 10);
	cout << "3. Administration ";
	gotoxy(50, 12);
	cout << "4. Artists ";
	gotoxy(50, 14);
	cout << "5. High Level Administration";
	gotoxy(50, 16);
	cout << "6. Marketing Department";
	gotoxy(50, 18);
	cout << "0. Entry Menu";
	gotoxy(56, 21);

	cout << "INPUT : ";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 22);
		cout << "-";
	}
	gotoxy(55, 23);
	cout << "|";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 24);
		cout << "-";
	}
	gotoxy(63, 23);
	cout << "|";
	gotoxy(59, 23);
}

void DrawEngineers() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(41, 4);
	cout << "ENGINEERING DEPARTMENT";

	for (int i = 29; i < 90; i++) {
		gotoxy(i, 5);
		cout << "-";
	}
	for (int i = 6; i < 17; i++) {
		gotoxy(29, i);
		cout << "|";
	}
	for (int i = 6; i < 17; i++) {
		gotoxy(89, i);
		cout << "|";
	}
	for (int i = 29; i < 90; i++) {
		gotoxy(i, 17);
		cout << "-";
	}

	gotoxy(50, 6);
	cout << "1. Mechanical Engineer ";
	gotoxy(50, 8);
	cout << "2. Electrical Engineer ";
	gotoxy(50, 10);
	cout << "3. Aero Engineer ";
	gotoxy(50, 12);
	cout << "4. Software Engineer ";
	gotoxy(50, 14);
	cout << "5. System Administrator";
	gotoxy(50, 16);
	cout << "0. Entry Menu";
	gotoxy(56, 21);

	cout << "INPUT : ";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 22);
		cout << "-";
	}
	gotoxy(55, 23);
	cout << "|";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 24);
		cout << "-";
	}
	gotoxy(63, 23);
	cout << "|";
	gotoxy(59, 23);
}

void DrawInputEngineer() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	//gotoxy(50, 4);
	//cout << "MECHANICAL ENGINEER";

	gotoxy(27, 7);
	cout << "NAME : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "SURNAME : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "WRK.HOUR: ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "EQUIP.EXP : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";

	gotoxy(79, 7);
	cout << "BONUS : ";
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(79, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}

void DrawScientists() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(41, 4);
	cout << "SCIENCE DEPARTMENT";

	for (int i = 29; i < 90; i++) {
		gotoxy(i, 5);
		cout << "-";
	}
	for (int i = 6; i < 13; i++) {
		gotoxy(29, i);
		cout << "|";
	}
	for (int i = 6; i < 13; i++) {
		gotoxy(89, i);
		cout << "|";
	}
	for (int i = 29; i < 90; i++) {
		gotoxy(i, 13);
		cout << "-";
	}

	gotoxy(50, 6);
	cout << "1. Physicist ";
	gotoxy(50, 8);
	cout << "2. Chemist ";
	gotoxy(50, 10);
	cout << "3. Mathematician ";
	gotoxy(50, 12);
	cout << "0. Entry Menu";

	gotoxy(56, 21);
	cout << "INPUT : ";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 22);
		cout << "-";
	}
	gotoxy(55, 23);
	cout << "|";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 24);
		cout << "-";
	}
	gotoxy(63, 23);
	cout << "|";
	gotoxy(59, 23);
}

void DrawInputScientist() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "NAME : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "SURNAME : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "WRK.HOUR: ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "FIELD WRK : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";

	gotoxy(79, 7);
	cout << "BONUS : ";
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(79, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}

void DrawAdministration() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(41, 4);
	cout << "ADMINISTRATION";

	for (int i = 29; i < 90; i++) {
		gotoxy(i, 5);
		cout << "-";
	}
	for (int i = 6; i < 13; i++) {
		gotoxy(29, i);
		cout << "|";
	}
	for (int i = 6; i < 13; i++) {
		gotoxy(89, i);
		cout << "|";
	}
	for (int i = 29; i < 90; i++) {
		gotoxy(i, 13);
		cout << "-";
	}

	gotoxy(50, 6);
	cout << "1. Accountant ";
	gotoxy(50, 8);
	cout << "2. Legal ";
	gotoxy(50, 10);
	cout << "3. Secretary ";
	gotoxy(50, 12);
	cout << "0. Entry Menu";

	gotoxy(56, 21);
	cout << "INPUT : ";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 22);
		cout << "-";
	}
	gotoxy(55, 23);
	cout << "|";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 24);
		cout << "-";
	}
	gotoxy(63, 23);
	cout << "|";
	gotoxy(59, 23);
}

void DrawInputAdministration() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "NAME : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "SURNAME : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "WRK.HOUR: ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "TRVL EXP. : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";

	gotoxy(79, 7);
	cout << "BONUS : ";
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(79, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}

void DrawArtist() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(41, 4);
	cout << "ARTIST SECTION";

	for (int i = 29; i < 90; i++) {
		gotoxy(i, 5);
		cout << "-";
	}
	for (int i = 6; i < 13; i++) {
		gotoxy(29, i);
		cout << "|";
	}
	for (int i = 6; i < 13; i++) {
		gotoxy(89, i);
		cout << "|";
	}
	for (int i = 29; i < 90; i++) {
		gotoxy(i, 13);
		cout << "-";
	}

	gotoxy(50, 6);
	cout << "1. Graphics Designer ";
	gotoxy(50, 8);
	cout << "2. Painter ";
	gotoxy(50, 10);
	cout << "3. UX Designer ";
	gotoxy(50, 12);
	cout << "0. Entry Menu";

	gotoxy(56, 21);
	cout << "INPUT : ";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 22);
		cout << "-";
	}
	gotoxy(55, 23);
	cout << "|";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 24);
		cout << "-";
	}
	gotoxy(63, 23);
	cout << "|";
	gotoxy(59, 23);
}

void DrawInputArtist() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "NAME : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "SURNAME : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "WRK.HOUR: ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "EX WRK. : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";

	gotoxy(79, 7);
	cout << "BONUS : ";
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(79, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}

void DrawHighLevelAdministartion() {
		gotoxy(45, 2);
		cout << "THUNDER AVIATION 2020" << endl;

		gotoxy(41, 4);
		cout << "CHOOSE CATEGORIES FOR EMPLOYEE";

		for (int i = 29; i < 90; i++) {
			gotoxy(i, 5);
			cout << "-";
		}
		for (int i = 6; i < 20; i++) {
			gotoxy(29, i);
			cout << "|";
		}
		for (int i = 6; i < 20; i++) {
			gotoxy(89, i);
			cout << "|";
		}
		for (int i = 29; i < 90; i++) {
			gotoxy(i, 19);
			cout << "-";
		}

		gotoxy(50, 6);
		cout << "1. CEO ";
		gotoxy(50, 8);
		cout << "2. Head of Engineering ";
		gotoxy(50, 10);
		cout << "3. Head of Marketing ";
		gotoxy(50, 12);
		cout << "4. Head of Design ";
		gotoxy(50, 14);
		cout << "5. Head of Administration";
		gotoxy(50, 16);
		cout << "6. Head of Science";
		gotoxy(50, 18);
		cout << "0. Entry Menu";
		gotoxy(56, 21);

		cout << "INPUT : ";
		for (int i = 55; i < 64; i++) {
			gotoxy(i, 22);
			cout << "-";
		}
		gotoxy(55, 23);
		cout << "|";
		for (int i = 55; i < 64; i++) {
			gotoxy(i, 24);
			cout << "-";
		}
		gotoxy(63, 23);
		cout << "|";
		gotoxy(59, 23);
}

void DrawInputHighLevelAdministration() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "NAME : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "SURNAME : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "WRK.HOUR: ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "TRVL EXP : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";

	gotoxy(79, 7);
	cout << "BONUS : ";
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(79, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}

void DrawMarketingDepartment() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(41, 4);
	cout << "MARKETING DEPARTMENT";

	for (int i = 29; i < 90; i++) {
		gotoxy(i, 5);
		cout << "-";
	}
	for (int i = 6; i < 13; i++) {
		gotoxy(29, i);
		cout << "|";
	}
	for (int i = 6; i < 13; i++) {
		gotoxy(89, i);
		cout << "|";
	}
	for (int i = 29; i < 90; i++) {
		gotoxy(i, 13);
		cout << "-";
	}

	gotoxy(50, 6);
	cout << "1. Marketing Manager ";
	gotoxy(50, 8);
	cout << "2. Media Handler ";
	gotoxy(50, 10);
	cout << "3. Public Representative ";
	gotoxy(50, 12);
	cout << "0. Entry Menu";

	gotoxy(56, 21);
	cout << "INPUT : ";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 22);
		cout << "-";
	}
	gotoxy(55, 23);
	cout << "|";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 24);
		cout << "-";
	}
	gotoxy(63, 23);
	cout << "|";
	gotoxy(59, 23);
}

void DrawInputMarketingDepartment() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "NAME : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "SURNAME : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "WRK.HOUR: ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "TRVL EXP : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";

	gotoxy(79, 7);
	cout << "BONUS : ";
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(79, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}

void DrawMaterials() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(41, 4);
	cout << "AVALIVABLE MATERIALS";

	for (int i = 29; i < 90; i++) {
		gotoxy(i, 5);
		cout << "-";
	}
	for (int i = 6; i < 15; i++) {
		gotoxy(29, i);
		cout << "|";
	}
	for (int i = 6; i < 15; i++) {
		gotoxy(89, i);
		cout << "|";
	}
	for (int i = 29; i < 90; i++) {
		gotoxy(i, 15);
		cout << "-";
	}

	gotoxy(50, 6);
	cout << "1. Pipes ";
	gotoxy(50, 8);
	cout << "2. Rods ";
	gotoxy(50, 10);
	cout << "3. Sheets ";
	gotoxy(50, 12);
	cout << "4. Soldering Wire";
	gotoxy(50, 14);
	cout << "0. Entry Menu";

	gotoxy(56, 21);
	cout << "INPUT : ";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 22);
		cout << "-";
	}
	gotoxy(55, 23);
	cout << "|";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 24);
		cout << "-";
	}
	gotoxy(63, 23);
	cout << "|";
	gotoxy(59, 23);
}

void DrawInputPipes() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "SUPPLIER : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "MATERIAL : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "DIAMETER : ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "LENGTH : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";

	gotoxy(79, 7);
	cout << "PRICE : ";
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(79, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}

void DrawInputSheets() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "SUPPLIER : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "MATERIAL : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "THICKN. : ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "WIDTH : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";

	gotoxy(79, 7);
	cout << "PRICE : ";
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(79, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}

void DrawInputSolderingWire() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "SUPPLIER : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "MATERIAL : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "DIAMETER : ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "LENGTH : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";

	gotoxy(79, 7);
	cout << "PRICE : ";
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(79, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}

void DrawElectronics() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(41, 4);
	cout << "SCIENCE DEPARTMENT";

	for (int i = 29; i < 90; i++) {
		gotoxy(i, 5);
		cout << "-";
	}
	for (int i = 6; i < 13; i++) {
		gotoxy(29, i);
		cout << "|";
	}
	for (int i = 6; i < 13; i++) {
		gotoxy(89, i);
		cout << "|";
	}
	for (int i = 29; i < 90; i++) {
		gotoxy(i, 13);
		cout << "-";
	}

	gotoxy(50, 6);
	cout << "1. Resistors ";
	gotoxy(50, 8);
	cout << "2. Cpacitors ";
	gotoxy(50, 10);
	cout << "3. Semi-Conductors ";
	gotoxy(50, 12);
	cout << "0. Entry Menu";

	gotoxy(56, 21);
	cout << "INPUT : ";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 22);
		cout << "-";
	}
	gotoxy(55, 23);
	cout << "|";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 24);
		cout << "-";
	}
	gotoxy(63, 23);
	cout << "|";
	gotoxy(59, 23);
}

void DrawInputElectronics() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "CODE : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "INTEGRATION : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "QUANTITY: ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "PRICE : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";
}

void DrawInputControlUnits() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "CODE : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "DESCRIPTION : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "QUANTITY: ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "PRICE : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";
}

void DrawParts() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(41, 4);
	cout << "CHOOSE PARTS";

	for (int i = 29; i < 90; i++) {
		gotoxy(i, 5);
		cout << "-";
	}
	for (int i = 6; i < 20; i++) {
		gotoxy(29, i);
		cout << "|";
	}
	for (int i = 6; i < 20; i++) {
		gotoxy(89, i);
		cout << "|";
	}
	for (int i = 29; i < 90; i++) {
		gotoxy(i, 19);
		cout << "-";
	}

	gotoxy(50, 6);
	cout << "1. Fan Blades ";
	gotoxy(50, 8);
	cout << "2. Spinner ";
	gotoxy(50, 10);
	cout << "3. High Pressure Compressor ";
	gotoxy(50, 12);
	cout << "4. Combustion Chamber ";
	gotoxy(50, 14);
	cout << "5. High Pressure Turbine ";
	gotoxy(50, 16);
	cout << "6. Low Pressure Turbinte";
	gotoxy(50, 18);
	cout << "0. Entry Menu";
	gotoxy(56, 21);

	cout << "INPUT : ";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 22);
		cout << "-";
	}
	gotoxy(55, 23);
	cout << "|";
	for (int i = 55; i < 64; i++) {
		gotoxy(i, 24);
		cout << "-";
	}
	gotoxy(63, 23);
	cout << "|";
	gotoxy(59, 23);
}

void DrawInputFanBlades() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "CODE : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "DESCRIPTION : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "QUANTITY: ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "PRICE : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";

	gotoxy(79, 7);
	cout << "ANGLE : ";
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(79, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}

void DrawInputSpinner() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "CODE : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "DESCRIPTION : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "QUANTITY: ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "PRICE : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";

	gotoxy(79, 7);
	cout << "AREA : ";
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(79, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}

void DrawInputCompressor() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "CODE : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "DESCRIPTION : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "QUANTITY: ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "PRICE : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";

	gotoxy(79, 7);
	cout << "COUNT : ";
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(79, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}

void DrawCombustionChamber() {
	gotoxy(45, 2);
	cout << "THUNDER AVIATION 2020" << endl;

	gotoxy(27, 7);
	cout << "CODE : ";
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 27; i < 38; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(27, 9);
	cout << "|";
	gotoxy(37, 9);
	cout << "|";

	gotoxy(40, 7);
	cout << "DESCRIPTION : ";
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 40; i < 51; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(40, 9);
	cout << "|";
	gotoxy(50, 9);
	cout << "|";

	gotoxy(53, 7);
	cout << "QUANTITY: ";
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 53; i < 64; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(53, 9);
	cout << "|";
	gotoxy(63, 9);
	cout << "|";

	gotoxy(66, 7);
	cout << "PRICE : ";
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 66; i < 77; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(66, 9);
	cout << "|";
	gotoxy(76, 9);
	cout << "|";

	gotoxy(79, 7);
	cout << "VOLUME : ";
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 8);
		cout << "-";
	}
	for (int i = 79; i < 90; i++) {
		gotoxy(i, 10);
		cout << "-";
	}
	gotoxy(79, 9);
	cout << "|";
	gotoxy(89, 9);
	cout << "|";
}