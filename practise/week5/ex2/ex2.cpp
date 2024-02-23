#include<iostream> 
#include<vector>
using namespace std;

class customer {
private:
    string name;
    string address;
    string phone;
    string IDcustomer;
    string days;
    string months;
    string years;
    int time;
    int money;
public:
    // constructor
    customer() {};
    customer(string name, string address, string phone, string IDcustomer, string days, string months, string years, int time, int money)
        : name(name), address(address), phone(phone), IDcustomer(IDcustomer), days(days), months(months), years(years), time(time), money(money) {};

    // input
    void scan() {
        cout << "Enter customer name: ";
        cin >> name;
        cout << "Enter customer address: ";
        cin >> address;
        cout << "Enter customer phone: ";
        cin >> phone;
        cout << "Enter customer ID: ";
        cin >> IDcustomer;
        cout << "Enter customer days: ";
        cin >> days;
        cout << "Enter customer months: ";
        cin >> months;
        cout << "Enter customer years: ";
        cin >> years;
        cout << "Enter customer time: ";
        cin >> time;
        cout << "Enter customer money: ";
        cin >> money;
    }

    // print
    void print() const {
        cout << "Customer name: " << name << endl;
        cout << "Customer address: " << address << endl;
        cout << "Customer phone: " << phone << endl;
        cout << "Customer ID: " << IDcustomer << endl;
        cout << "Customer days: " << days << endl;
        cout << "Customer months: " << months << endl;
        cout << "Customer years: " << years << endl;
        cout << "Customer time: " << time << endl;
        cout << "Customer money: " << money << endl;
        cout << "Profit: " << profit(*this) << endl; // Include profit information
    }

    // friend function to calculate profit based on the time of deposit
    friend int profit(const customer& a);
    // Getter for time
    int getTime() const {
        return time;
    }

    // get money
    int getMoney() const {
        return money;
    }

    // get phone
    string getPhone() const {
        return phone;
    }
};

int profit(const customer& a) {
    int profit = 0;
    switch (a.getTime()) {
    case 1:
        profit = a.getMoney() + a.getMoney() * 0.03;
        break;
    case 2:
        profit = a.getMoney() + a.getMoney() * 0.035;
        break;
    case 3:
        profit = a.getMoney() + a.getMoney() * 0.04;
        break;
    case 4:
        profit = a.getMoney() + a.getMoney() * 0.05;
        break;
    case 5:
        profit = a.getMoney() + a.getMoney() * 0.06;
        break;
    case 6:
        profit = a.getMoney() + a.getMoney() * 0.065;
        break;
    case 7:
        profit = a.getMoney() + a.getMoney() * 0.07;
        break;
    case 8:
        profit = a.getMoney() + a.getMoney() * 0.073;
        break;
    case 9:
        profit = a.getMoney() + a.getMoney() * 0.074;
        break;
    case 10:
        profit = a.getMoney() + a.getMoney() * 0.075;
        break;
    case 11:
        profit = a.getMoney() + a.getMoney() * 0.076;
        break;
    case 12:
        profit = a.getMoney() + a.getMoney() * 0.08;
        break;
    default:
        break;
    }
    return profit;
}

class app : public customer {
private:
    vector<customer> listCustomers;
    int numberOfCustomers;

public:
    // constructor
    app() {
    }

    // input 
    void scanCustomers() {
        cout << "Enter number of customers: ";
        cin >> numberOfCustomers;
        for (int i = 0; i < numberOfCustomers; i++) {
            customer temp;
            temp.scan();
            listCustomers.push_back(temp);
        }
    }

    // Friend declarations for access to private members
    friend void listOfCustomersCloser(const app& a);
    friend void searchCustomerByPhone(const app& a);
};

void listOfCustomersCloser(const app& a) {
    vector<customer> listCustomersCloser;
    for (int i = 0; i < a.numberOfCustomers; i++) {
        if (a.listCustomers[i].getMoney() > 10000000 && a.listCustomers[i].getTime() > 6) {
            listCustomersCloser.push_back(a.listCustomers[i]);
        }
    }

    // Print loyal customers
    cout << "Loyal Customers: " << endl;
    for (const auto& c : listCustomersCloser) {
        c.print();
        cout << "-----------------------------------" << endl;
    }
}

void searchCustomerByPhone(const app& a) {
    cout << "Enter phone number: ";
    string phone;
    cin >> phone;
    int index = 0;
    for (int i = 0; i < a.numberOfCustomers; i++) {
        if (a.listCustomers[i].getPhone() == phone) {
            a.listCustomers[i].print();
            index = 1;
            break;
        }
    }
    if (index == 0) {
        cout << "Customer not found" << endl;
    }
}

int main() {
    app a;
    a.scanCustomers();
    listOfCustomersCloser(a);
    searchCustomerByPhone(a);
    return 0;
}
