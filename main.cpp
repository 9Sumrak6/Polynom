#include <iostream>
#include <vector>
#include <string>
#include "Polynom.hpp"

using namespace std;

struct Pol{
	string name;
	Polynom polynom;
};

void Print(const vector<Pol> &pols){
	if (pols.size() == 0)
		cout << "There is no pols" << endl;
	else
		for (int i = 0; i < pols.size(); i++)
			cout << pols[i].name << ": " << pols[i].polynom << endl;
}

Polynom Find(string name, const vector<Pol> &pols){
	for (int i = 0; i < pols.size(); i++)
		if (name == pols[i].name)
			return pols[i].polynom;
	
	throw "There is no mathes";
}

void Menu() {
	cout << "1. Add polynom" << endl;
	cout << "2. Print polynom" << endl;
	cout << "3. Find polynom by name" << endl;
	cout << "4. Find the derivative" << endl;
	cout << "5. To summarize 2 polynoms" << endl;
	cout << "6. To substract 2 polynoms" << endl;
	cout << "7. To multiply 2 polynoms" << endl;
    cout << "8. Quit" << endl;
}

int main() {
    int item;
    vector<Pol> pols;
    Polynom res, polynom;
    int degree;
    string name;
    string s;
    string s1;
    do {
        cout << "What do you want to do?" << endl;
        Menu();
        cout << ">";
        cin >> item;

        while(item < 1 || item > 7) {
            cout << "Incorrect item. Try again: ";
            cin >> item;
        }

        switch (item) {
            case 1:
                cout << "Enter polynom's name:";
                cin >> name;          	
            	
                cout << "Enter degree: ";
                cin >> degree;
               	polynom = Polynom(degree);

                cout << "Enter coeffs: ";
                polynom.Read();
                pols.push_back({name, polynom});
                break;

            case 2:
                Print(pols);
                break;
            case 3:
                cout << "Enter polynom's name: ";
                cin >> name;
                cout << Find(name, pols);
                break;
            case 4:
                cout << "Enter the name of the polynom, which derivative you want to find: ";
                cin >> name;
                cout << Find(name, pols).Derivative();
                break;
            case 5:
            	cout << "Enter names of polynoms: " << endl;
            	cin >> s;
            	cin >> s1;
            	res = Find(s, pols) + Find(s1, pols);
                cout << "Do you want to save this polynom? (yes/no)" << endl;
                cin >> s; 
                if (s == "yes"){
	                string name;
	                cout << "Enter polynom's name:";
	                cin >> name;
	                pols.push_back({name, res});
                }
                break;
            case 6:
           		cout << "Enter names of polynoms: " << endl;
            	cin >> s;
            	cin >> s1;
            	res = Find(s, pols) + Find(s1, pols);
                cout << "Do you want to save this polynom? (yes/no)" << endl;
                cin >> s; 
                if (s == "yes"){
	                string name;
	                cout << "Enter polynom's name:";
	                cin >> name;
	                pols.push_back({name, res});
                }
                break;  
            case 7:
            	cout << "Enter names of polynoms: " << endl;
            	cin >> s;
            	cin >> s1;
            	res = Find(s, pols) + Find(s1, pols);
                cout << "Do you want to save this polynom? (yes/no)" << endl;
                cin >> s; 
                if (s == "yes"){
	                string name;
	                cout << "Enter polynom's name:";
	                cin >> name;
	                pols.push_back({name, res});
                }
            	break;
        }
    } while (item != 8);

}