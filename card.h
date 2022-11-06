#include <./user.h>

class Card
{
private:
    string id;
    string name;
    string description;
    User assignedUser;

public:
    Card(string id, string name, string description)
    {
        this->id = id;
        this->name = name;
        this->description = description;
        this->assignedUser = user;
    }

    string getId()
    {
        return this->id;
    }

    User getUser()
    {
        return this->assignedUser;
    }

    void assignUser(User user)
    {
        this->assignedUser = user;
    }

    void unAssignUser()
    {
        this->assignedUser = NULL;
    }

    // details of the card
    void getDetails()
    {
        cout << "Printing Card details: " << endl;
        cout << "id: " << this.id << endl;
        cout << "name: " << this.name << endl;
        cout << "description: " << this->description << endl;
        cout << "user: " << this->assignedUser.getName() << endl;
    }
};