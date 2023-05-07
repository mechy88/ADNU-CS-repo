#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

class Order{
private:
    string name;
    string address;
    int number_of_tickets;
public:
    bool operator == (const Order& o) const {
        return name == o.getName() && address == o.getAddress() && number_of_tickets == o.getTickets();
    }

    bool operator != (const Order& o) const {
        return !operator==(o);
    }

    Order(string n, string a, int num){
        this->name = n;
        this->address = a;
        this->number_of_tickets = num;
    }

    Order copy() const{
        return Order(this->name, this->address, this->number_of_tickets);
    }

    void display() const{
        cout << getName() << " " << getAddress() << " " << getTickets() << endl;
    }
    string getName() const{
        return name;
    }
    string getAddress() const{
        return address;
    }
    int getTickets() const{
        return number_of_tickets;
    }
};

void add(list<Order>&);
void cancel(list<Order>&);
void search(list<Order>&);
void displayAll(list<Order>&);
void save(list<Order>&);
void load(list<Order>&);


int main(){
    bool running = true;

    list<Order> orders;

    while(running){
        int command;
        cout << "Choose a command\n\t1. Add an order\n\t2. Cancel an order\n\t3. Search an order\n\t4. Display all orders\n\t5. Save orders\n\t6. Load saved orders\n\t7. Close Program\n";
        cin >> command;

        switch(command){
            case 1:
                add(orders);
                break;
            case 2:
                cancel(orders);
                break;
            case 3:
                search(orders);
                break;
            case 4:
                displayAll(orders);
                break;
            case 5:
                save(orders);
                break;
            case 6:
                load(orders);
                break;
            default:
                running = false;
                break;
        }
    }
    return 0;
}

void add(list<Order>& l){
    string n, a;
    int num;
    bool found;
    do{
        cout << "Enter Name: ";
        cin >> n;
        found = false;
        for(const auto& order : l){
            if(order.getName() == n){
                found = true;
                cout << "No duplicate orders for the same person! ";
            } 
        }
    } while(found == true);
    
    cout << "Enter Address: ";
    cin >> a;
    cout << "Enter Number of Tickets: ";
    cin >> num;
    while(num > 4){
        cout << "Only 4 tickets per person, enter up to 4: ";
        cin >> num;
    }
    l.push_back(Order(n, a, num));
    cout << "Order Added!\n";
}
void cancel(list<Order>& l){
    string n;
    cout << "Please enter name in Order: ";
    cin >> n;
    
    for(auto& order : l){
        if(order.getName() == n){
            l.remove(order.copy());
            break;
        }
    }
    cout << "Order Cancelled!\n";
}
void search(list<Order>& l){
    cout << "\t1. Search by Name\n";
    cout << "\t2. Search by Address\n";
    cout << "\t3. Search by Number of Tickets\n";

    int command;
    cin >> command;

    string command_parameter;
    switch(command){
        case 2:
            cout << "Please enter address: ";
            cin >> command_parameter;
            for(const auto& order : l){
                if(order.getAddress() == command_parameter) order.display();
            }
            break;
        case 3:
            cout << "Please enter the number of tickets: ";
            cin >> command_parameter;
            for(const auto& order : l){
                if(order.getTickets() == stoi(command_parameter)) order.display();
            }
            break;
        default:
            string name;
            cout << "Please enter name: ";
            cin >> command_parameter;
            for(const auto& order : l){
                if(order.getName() == command_parameter) order.display();
            }
            break;
    }
    cout << "Order Found!\n";
}
void displayAll(list<Order>& l){
    cout << "Displayed All Orders!\n";
    if(l.empty()){
        cout << "No Orders" << endl;
    }else{
        for(const auto& order : l){
             order.display();
        }
    }
}
void save(list<Order>& l){

    fstream save;
    save.open("PAJARILLO_E3.bin", ios::out | ios::binary);
    int size = l.size();
    save.write(reinterpret_cast<char*>(&size), sizeof(size));
    
    for(const auto& order : l){
        string name = order.getName();
        string::size_type size_name = name.length();
        save.write(reinterpret_cast<char*>(&size_name), sizeof(size_name));
        save.write(name.data(), size_name);

        string address = order.getAddress();
        string::size_type size_address = address.length();
        save.write(reinterpret_cast<char*>(&size_address), sizeof(size_address));
        save.write(address.data(), size_address);

        int tickets = order.getTickets();
        save.write(reinterpret_cast<char*>(&tickets), sizeof(tickets));
    }

}
void load(list<Order>& l){
    ifstream load;
    load.open("PAJARILLO_E3.bin", ios::binary);
    int size;
    load.read(reinterpret_cast<char*>(&size), sizeof(size));
    
    for(int i = 0; i < size; i++){
        string name;
        string::size_type size_name;
        load.read(reinterpret_cast<char*>(&size_name), sizeof(size_name));
        name.resize(size_name);
        load.read(&name[0], size_name);

        string address;
        string::size_type size_address;
        load.read(reinterpret_cast<char*>(&size_address), sizeof(size_address));
        address.resize(size_address);
        load.read(&address[0], size_address);

        int tickets;
        load.read(reinterpret_cast<char*>(&tickets), sizeof(tickets));

        l.push_back(Order(name, address, tickets));
    }

}