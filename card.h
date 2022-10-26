#include <bits/stdc++.h>
#include <./user.h>
using namespace std;


class Card
{
    private:
        string id;
        string name;
        string description;
        User assignedUser;

    public:
        Card(string id, string name, string description){
            this->id = id;
            this->name = name;
            this->description = description;
            this->assignedUser = user;
        }

        string getId(){
            return this->id;
        }

        User getUser(){
            return this->assignedUser;
        }

        void assignUser(User user){
            this->assignedUser = user;
        }

        void unAssignUser(){
            this->assignedUser = NULL;
        }
        

};