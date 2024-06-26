#include <iostream>
#include <vector>
#include <optional>
#include <string>
#include <math.h>
#include <memory>
#include <tuple>
#include <forward_list>
#include <algorithm>
#include <string>
#include <numeric>
#include <regex>
#include <fstream>
#include <queue>

using namespace std;


struct Customer {

	int customerID;
	string name;
	double balance;

	Customer() : customerID(0), name("Ykajite imya: "), balance(0) {}

	void printinfo() { // vmesto cout
		cout << "customerID: " << customerID << endl << endl << "NameCustomer: " << name << endl << endl << "CustomerBalance: " << balance << endl << endl;
	}

	~Customer() {
	}
};


class BankQueue {
private:
	queue<Customer> clients; // o4ered klientov s danimi iz Struct


public:

	void enqueue(const Customer& human) { // function dlya dobavki clienta v o4ered

		clients.push(human); // v o4ered clientov dobavil 4eloveka
		
	}

	void dequeue() { 
		if (!clients.empty()) {
			clients.pop(); //ybral 4eloveka 
		}
		else {
			cout << "o4ered pusta " << endl;
		}
	}

	bool emptyclients() { //bez etogo metoda ne rabotala 152 stroka esli !clients.empty() pisalo 4to ne yavletsa memberom 
		return clients.empty();
	}

	Customer& frontline() { // metod front analogo4ino 58 stroke
		return clients.front();
	}

	void displayqueue() {
		queue<Customer> temp = clients; // o4ered clientov 

		while (!temp.empty()) { // poka ne pusto
			temp.front().printinfo(); // pokazivau vsex klientov 4erez front i gotovuu function dlya etogo
			temp.pop(); //zatem ydalau kajgodo poo4eredi 
		}
	}



	void inputdetails() { //Vmesto CIN. gotovya function
		Customer dataClient;

		string customerIDstr; //4tob potom preobrazit v 4islo
		string balancestr; //analogi4no 

		regex rx("^[0-9]+|[0-9.]+$"); // 4tob tip int i double rabotal
		cout << "ykajite customerID : " << endl;
		cin >> customerIDstr;
		if (!regex_match(customerIDstr, rx)) { 
			cout << "eror: ne korrektno vveden customerID" << endl;
			cin.clear();//o4ishau bufer
			cin.ignore();// ignore ne vernogo symbol
			return; //vernutsa v menu 
		}
		dataClient.customerID = stoi(customerIDstr); // zatem preobrazil v int blagodorya STOI

		cout << "ykajite Imya client: " << endl;
		cin >> dataClient.name;

		cout << "ykajite balance client: " << endl;
		cin >> balancestr;
		if (!regex_match(balancestr, rx)) { //proveryau esli sootvestvyet ysloviu 
			cout << "error: ne korrektno vveden balance" << endl;
			cin.clear(); //o4ishau bufer
			cin.ignore(); // ignore ne vernogo symbol
			return; //vernutsa v menu 
		}
		dataClient.balance = stod(balancestr); // zatem preobrazil v double blagodorya STOD
		


//esle ne regex. pri vvode symbol libo ne korrektni tip 4isla. na4inalsa beskone4nii zikl. pomoglo ispravit eto i teper vvodya symbol prosto vozvrashaet v menu


		clients.push(dataClient); // zapihnyli infy iz DataClient v quque<Customer> clients
	}




	~BankQueue() {
	}
};


int main() {
	BankQueue clients; 

	int choice; // dlya vibora deistviya


	char dw; // dlya vibora vneseniya ili snyatie deneg

	double summa; // koli4estvo deneg dlya snyatiya ili vnesenie 
	
	bool flag = true; // 4tob sdelat odno ili bolee deistvie v switch
	


	while (flag) { 
		cout << "viberite variant: " << endl
			<< "1 = Dobavit client v o4ered" << endl
			<< "2 = Obrabotat client v na4ale o4eredi(deposit ili withdrawl)" << endl
			<< "3 = Otobrazit vsex client kotorii v o4eredi" << endl
			<< "4 = exit" << endl;
		cin >> choice;
		

//eto pomoglo ispravit problemy esli pri zapuske programi kogda vivoditsa menu s viborom. vibrat ne 4islo a symbol togda na4inalsa beskone4nii zikl
		if (cin.fail()) { //esli vvel ne 4islo a symbol
			cin.clear(); //o4istit bufer
			cin.ignore(); // proignorit symbol
			continue; //prodoljit raboty v menu
		}
		
		switch (choice) { // switch dlya vibora deistviya iz menu // namnogo ydobnee 4em if/else
		case 1:
			clients.inputdetails(); // vesti dannie clienta
			break;

		case 2:
			if (!clients.emptyclients()) { // esli o4ered ne pusta
				Customer& client = clients.frontline(); // rabotaem s 4elovekom iz o4eredi
				client.printinfo(); //raspe4atat infy ob etom 4eloke
				
				cout << "viberite vashe deistvie: vlojit sredstva najmite 'd'" << endl << endl
				     << "snyat sredstva najmite 'w'" << endl << endl;
				cin >> dw; // client vibiraet svoe deistvie
				dw = tolower(dw); // pri sly4ai esli polzovatel vvel zaglavniu D 4tob ne bilo "error"
				cout << "kakoe koli4estvo money vi hotite vlojit/snyat " << endl << endl
				     << "vvedite summa: " << endl << endl;
				
				cin >> summa;
				
				if (dw == 'd') {
					client.balance += summa;

				}
				else if (dw == 'w') {
					if (client.balance >= summa) {
						client.balance -= summa;
					}
					else {
						cout << "nedostato4no sredstv na vashem s4ety" << endl;
					}
				}
				else {
					cout << "error: viberite d ili w" << endl;
				}
				
				cout << "hotite prodoljit raboty v terminale? viberite 'y' ili 'n' " << endl;
				
				char tempChar; // peremenaya esli client ho4et snova sovershit kakoe to deistvie v bankomate/na kasse
				cin >> tempChar;
				tempChar = tolower(tempChar); // pri sly4ai esli user vvel Y zaglavnuu 4tob ne bilo "error"
				if (tempChar != 'y') { 
					clients.dequeue(); // ydalili klienta iz o4eredi kak on zakon4il
				}
				
			}
			else { 
				cout << "o4ered i tak pusta" << endl;
			}
			break;

		case 3:

			clients.displayqueue();
			break;
		case 4:
			flag = false; // 4tob ne ostavasta beskon4eno v zikle/menu
			break;


		default: //srabotaet v sly4ae esli 4islo bydet 5 i bolee
			cout << "poprobyite eshe raz" << endl;
		}
	}
	return 0;
}




