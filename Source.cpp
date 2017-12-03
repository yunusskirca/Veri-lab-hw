#include <iostream>
#include <ctime>
#include <string>
#include <conio.h>

using namespace std;

int enter_number(const string& str1 = "Enter an integer number : ")
{
	int number;
	while (1)
	{
		cout << str1;
		cin >> number;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
		}
		else
			break;
		system("cls");
		cout << "Error! Please enter an integer!" << endl;
	}
	return number;
}

struct Node {
	string name;
	bool exist = false;
};

int weight[10][10];
int node_number = 0;

Node node[10];

void first_activition() {
	for (int i = 0; i < node_number; i++)
		node[i].exist = true;
}

void set_node_names() {
	char sname[10] = { 'A','B','C','D','E','F','G','H','I','J' };
	for (int i = 0; i < 10; i++)
		node[i].name = sname[i];
}

void rand_edge() {
	for (int i = 0; i < 10; i++)
		for (int j = i; j < 10; j++) {
			weight[i][j] = rand() % 13 - 3;
			if (weight[i][j] < 0 || i == j)
				weight[i][j] = 0;
			weight[j][i] = weight[i][j];
		}

}
// string uzunluðuna karþý bug düzeltmesi yapýlýcak
void print_edge() {
	cout << "  ";
	for (int i = 0; i < 10; i++) {
		if (node[i].exist)
			cout << node[i].name << " ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		if (node[i].exist)
			cout << node[i].name << " ";
		for (int j = 0; j < 10; j++) {
			if (node[i].exist && node[j].exist)
				if(weight[i][j] != 0)
					cout << weight[i][j] << " ";
				else
					cout <<"- ";
		}
		if (node[i].exist)
			cout << endl;
	}

	cout << "Press any button to return main menu." << endl;
	_getch();
}

int find_node(string name) {
	for (int i = 0; i < 10; i++) {
		if (node[i].name == name && node[i].exist)
			return i;
	}
	cout << name << " is NOT exist! " << endl;
	return -1;
}

void change_node_name() {
	string name;
	cout << "Enter name of the node to change it : ";
	cin >> name;
	int x = find_node(name);
	if (x != -1) {
		cout << "Enter new name of the node (space character is NOT allowed) : ";
		cin >> node[x].name;
	}
}

void add_node() {
	if (node_number < 10) {
		node_number++;
		for (int i = 0; i < node_number; i++) {
			if (node[i].exist == false)
				node[i].exist = true;
		}
	}
}

void remove_node() {
	string name;
	cout << "Enter name of the node to remove it : ";
	cin >> name;
	int x = find_node(name);
	if (x != -1) {
		node_number--;
		node[x].exist = false;
	}
}

void change_edge_weight() {
	string name;
	cout << "Enter name of the first node : ";
	cin >> name;
	int x = find_node(name);
	if (x == -1) {
		cout << "Press any button to return main menu." << endl;
		_getch();
		return;
	}
	cout << "Enter name of the second node : ";
	cin >> name;
	int y = find_node(name);
	if (y == -1) {
		cout << "Press any button to return main menu." << endl;
		_getch();
		return;
	}
	system("cls");

	if (weight[x][y] == 0) {
		cout << "There isn't any edge between these nodes!" << endl;
		cout << "Press any button to return main menu." << endl;
		_getch();
		return;
	}

	int number = 0;
	while (number < 1 || number > 9)
		number = enter_number("Enter an integer to change edge weight (between 1-9) : ");

	weight[x][y] = weight[y][x] = number;
	cout << "Successful." << endl;
	cout << "Press any button to return main menu." << endl;
	_getch();
}

void add_edge() {
	string name;
	cout << "Enter name of the first node : ";
	cin >> name;
	int x = find_node(name);
	if (x == -1) {
		cout << "Press any button to return main menu." << endl;
		_getch();
		return;
	}
	cout << "Enter name of the second node : ";
	cin >> name;
	int y = find_node(name);
	if (y == -1) {
		cout << "Press any button to return main menu." << endl;
		_getch();
		return;
	}
	system("cls");

	if (weight[x][y] != 0) {
		cout << "A edge already exist between these nodes." << endl;
		cout << "Press any button to return main menu." << endl;
		_getch();
		return;
	}
	
	int number = rand() % 8 + 1;
	weight[x][y] = weight[y][x] = number;
	cout << "Random edge created between these nodes." << endl;
	cout << "Press any button to return main menu." << endl;
	_getch();
}

void remove_edge() {
	string name;
	cout << "Enter name of the first node : ";
	cin >> name;
	int x = find_node(name);
	if (x == -1) {
		cout << "Press any button to return main menu." << endl;
		_getch();
		return;
	}
	cout << "Enter name of the second node : ";
	cin >> name;
	int y = find_node(name);
	if (y == -1) {
		cout << "Press any button to return main menu." << endl;
		_getch();
		return;
	}
	system("cls");

	if (weight[x][y] == 0) {
		cout << "There isn't any edge exist between these nodes." << endl;
		cout << "Press any button to return main menu." << endl;
		_getch();
		return;
	}

	
	weight[x][y] = weight[y][x] = 0;
	cout << "Edge is removed between these nodes." << endl;
	cout << "Press any button to return main menu." << endl;
	_getch();
}

string path;
int path_value;

void recursive_part_of_finder(string path_t, int track[10], int position, int last, int counter = 0, int number = 0) {
	path_t += " => " + node[position].name;
	if (position == last) {
		if (number < path_value) {
			path = path_t;
			path_value = number;
			track[position] = 0;
			return;
		}
	}
	track[position] = 1;

	for (int i = 0; i < node_number; i++) {
		for (int j = 0; j < 10; j++) {
			if (1 == track[i])
				break;
			else if (0 == track[i] && weight[position][i] > 0)
				recursive_part_of_finder(path_t, track, i, last, counter + 1, number + weight[position][i]);
		}
	}
	track[position] = 0;
}

void find_path() {
	path = "Path is NOT exist!";
	path_value = 100000;
	string path_test;
	int track[10] = {};

	string name;
	cout << "Enter name of the first node : ";
	cin >> name;
	int x = find_node(name);
	if (x == -1) {
		cout << "Press any button to return main menu." << endl;
		_getch();
		return;
	}
	cout << "Enter name of the second node : ";
	cin >> name;
	int y = find_node(name);
	if (y == -1) {
		cout << "Press any button to return main menu." << endl;
		_getch();
		return;
	}
	system("cls");
	recursive_part_of_finder(path_test, track, x, y);

	cout << path << endl;
	cout << "Weight of the way = " << path_value << endl;
	cout << "Press any button to return main menu." << endl;
	_getch();
}

void main() {
	srand(time(NULL));

	cout << "Enter number of nodes (max 10) : ";
	cin >> node_number;
	first_activition();
	rand_edge();
	set_node_names();


	char menu;
	while (1) {
		system("cls");
		cout << "\t-MAIN MENU-" << endl << endl
			<< "\t 1- ADD NODE" << endl
			<< "\t 2- DELETE NODE" << endl
			<< "\t 3- CHANGE NODE NAME" << endl
			<< "\t 4- ADD EDGE" << endl
			<< "\t 5- REMOVE EDGE" << endl
			<< "\t 6- CHANGE EDGE WEIGHT" << endl
			<< "\t 7- EDGE TABLE (Matrix)" << endl
			<< "\t 8- FIND PATH" << endl
			<< "\t 0- Exit!";

		menu = _getch();

		if (menu == '1') {
			system("cls");
			add_node();
		}
		else if (menu == '2') {
			system("cls");
			remove_node();
		}
		else if (menu == '3') {
			system("cls");
			change_node_name();
		}
		else if (menu == '4') {
			system("cls");
			add_edge();
		}
		else if (menu == '5') {
			system("cls");
			remove_edge();
		}
		else if (menu == '6') {
			system("cls");
			change_edge_weight();
		}
		else if (menu == '7') {
			system("cls");
			print_edge();
		}
		else if (menu == '8') {
			system("cls");
			find_path();
		}

		else if (menu == '0')
			break;
	}
}
