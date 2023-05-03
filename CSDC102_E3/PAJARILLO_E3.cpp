#include <iostream>
#include <string>
#include <list>

using namespace std;

class Order{
private:
    string name;
    string address;
    int number_of_tickets;
public:
    Order(string n, string a, int num){
        this->name = n;
        this->address = a;
        this->number_of_tickets = num;
    }
};

void add();
void cancel();
void search();
void displayAll();
void save();
void load();


int main(){
    bool running = true;

    list<Order> orders;
    orders.push_back(Order("Miguel", "San Felipe", 5));

    while(running){
        int command;
        cout << "Choose a command\n\t1.) Add an order\n\t2.) Cancel an order\n\t3.) Search an order\n\t4.) Display all orders\n\t5.) Save orders\n\t6.) Load saved orders\n\t7.) Close Program\n";
        cin >> command;

        switch(command){
            case 1:
                add();
                break;
            case 2:
                cancel();
                break;
            case 3:
                search();
                break;
            case 4:
                displayAll();
                break;
            case 5:
                save();
                break;
            case 6:
                load();
                break;
            default:
                running = false;
                break;
        }
    }
    return 0;
}

void add(){
    cout << "Order Added!\n";
}
void cancel(){
    cout << "Order Cancelled!\n";
}
void search(){
    cout << "Order Found!\n";
}
void displayAll(){
    cout << "Order Displayed All!\n";
}
void save(){
    cout << "Order Save!\n";
}
void load(){
    cout << "Order Load!\n";
}