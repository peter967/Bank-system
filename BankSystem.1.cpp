#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    int id;
    string name;
    string password;

protected:
    // Helper function to check if a string is alphabetic
    bool isAliphatic(const string& s) const
    {
        for (char c : s)
        {
            if (!isalpha(c))
            {
                return false;
            }
        }
        return true;
    }

public:
    // Pure virtual functions to make Person an abstract class
    virtual void setId(int i) = 0;
    virtual void setName(const string& n) = 0;
    virtual void setPassword(const string& newPassword) = 0;
    virtual int getId() const = 0;
    virtual string getName() const = 0;
    virtual string getPassword() const = 0;
    virtual void display() const = 0;

    virtual ~Person() {} // Virtual destructor for proper cleanup
};

// Client class inheriting from Person
class Client : public Person
{
private:
    double balance;

public:
    void setId(int i) override
    {
        id = i;
    }

    void setName(const string& n) override
    {
        if (n.size() >= 5 && n.size() <= 20 && isAliphatic(n))
        {
            name = n;
        }
        else
        {
            cout << "The name must be alphabetic and between 5 and 20 characters." << endl;
            cout << "Please enter the name: ";
            string tempName;
            cin >> tempName;
            setName(tempName);
        }
    }

    void setPassword(const string& newPassword) override
    {
        if (newPassword.size() >= 8 && newPassword.size() <= 20)
        {
            password = newPassword;
        }
        else
        {
            cout << "Password must be between 8 and 20 characters.\n";
        }
    }

    int getId() const override
    {
        return id;
    }

    string getName() const override
    {
        return name;
    }

    string getPassword() const override
    {
        return password;
    }

    void setBalance(double b)
    {
        if (b >= 1500)
        {
            balance = b;
        }
        else
        {
            cout << "The minimum balance must be 1500. Setting balance to 1500." << endl;
            balance = 1500;
        }
    }

    double getBalance() const
    {
        return balance;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "The client balance after deposit " << amount << " = " << balance << endl;
        }
        else
        {
            cout << "Deposit’s amount should be positive (Invalid amount)." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "The client balance after withdraw " << amount << " = " << balance << endl;
        }
        else
        {
            cout << "Invalid withdraw’s amount." << endl;
        }
    }

    void transferTo(double amount, Client& recipient)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            recipient.deposit(amount);
            cout << "Transfer successful." << endl;
            cout << "Your new balance: " << balance << endl;
            cout << "Recipient's new balance: " << recipient.getBalance() << endl;
        }
        else
        {
            cout << "Invalid transfer amount." << endl;
        }
    }

    void checkBalance() const
    {
        cout << "Your current balance: " << balance << endl;
    }

    void display() const override
    {
        cout << "Client Information:" << endl;
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getId() << endl;
        cout << "Balance: " << getBalance() << endl;
        cout << "Password: " << getPassword() << endl;
    }
};

// Employee class inheriting from Person
class Employee : public Person
{
private:
    double salary;

public:
    void setId(int i) override
    {
        id = i;
    }

    void setName(const string& n) override
    {
        if (n.size() >= 5 && n.size() <= 20)
        {
            name = n;
        }
        else
        {
            cout << "The name must be between 5 and 20 characters." << endl;
        }
    }

    void setPassword(const string& newPassword) override
    {
        if (newPassword.size() >= 8 && newPassword.size() <= 20)
        {
            password = newPassword;
        }
        else
        {
            cout << "Password must be between 8 and 20 characters.\n";
        }
    }

    int getId() const override
    {
        return id;
    }

    string getName() const override
    {
        return name;
    }

    string getPassword() const override
    {
        return password;
    }

    void setSalary(double s)
    {
        if (s >= 5000)
        {
            salary = s;
        }
        else
        {
            cout << "Salary must be at least 5000." << endl;
        }
    }

    double getSalary() const
    {
        return salary;
    }

    void display() const override
    {
        cout << "Employee Information:" << endl;
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getId() << endl;
        cout << "Password: " << getPassword() << endl;
        cout << "Salary: " << getSalary() << endl;
    }
};

// Admin class inheriting from Employee
class Admin : public Employee
{
public:
    void display() const override
    {
        cout << "Admin Information:" << endl;
        cout << "Name: " << getName() << endl;
        cout << "ID: " << getId() << endl;
        cout << "Password: " << getPassword() << endl;
        cout << "Salary: " << getSalary() << endl;
    }
};

int main()
{
    Client c;
    Client ob;
    c.setName("Ali");
    c.setId(3);
    c.setPassword("123456789");
    c.setBalance(2300);
    cout << "Your balance before any actions: " << c.getBalance() << endl;
    c.deposit(500);
    c.withdraw(200);
    c.transferTo(100, ob);
    c.checkBalance();
    c.display();

    Employee f;
    f.setName("John deep"); 
    f.setId(1001);
    f.setPassword("password123");
    f.setSalary(9000);
    f.display();

    Admin a;
    a.setId(1234566879);
    a.setName("Ahmad");
    a.setPassword("14567859");
    a.setSalary(70000);
    a.display();

    return 0;
}
