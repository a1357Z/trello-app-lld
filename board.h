#include <bits/stdc++.h>
#include <./user.h>
#include <./list.h>
#include<./utility.h>
using namespace std;

enum Privacy
{
    /// @brief 
    PUBLIC=0, PRIVATE=1
};

class Board
{
    private:
        string id;
        string name;
        Privacy privacy;
        string url;
        vector<User> members;
        Utility utility; 
        unordered_map<string, List> lists; //composition --> list cannot exist without the board

    public:
        Board(string id, string name, Privacy privacy, string url, Utility u){
            this->id = id;
            this->name = name;
            this->privacy = privacy;
            this->url = url;
            this->utility = u;
        }

        //get a list corresponding to listId or return nullptr
        List getList(string listId){
            if(lists.count(listId) > 0){
                return lists[listId];
            }
            return NULL;
        }

        //add a list to the Board
        void addList(string listId, string listName){
            List l = this->getList(listId);
            if(l != NULL){
                //list already exists
                utility.print("List already existing for the board");
                return;
            }

            //create and add the list to the board
            List l = List(listId, listName);
            this->setList(listId, l);
            return;
        }

        //set the list corresponding to a listId
        void setList(string listId, List list){
            lists[listId] = list;
        }

        //delete the list
        void deleteList(string listId){
            List l = this->getList(listId);
            if(l == NULL){
                utility.print("List not found");
                return;
            }

            //delete the list
            this->lists.erase(listId);
        }

        //add card to list
        void addCard(string listId, string cardId, string cardName, string description){
            List l = b.getList(listId);
            if(l == NULL){
                utility.print("list does not exist");
                return;
            }

            l.addCard(cardId, cardName, description);
        }

        void assignUser(string listId, string cardId, User user){
            List l = b.getList(listId);
            if(l == NULL){
                utility.print("list does not exist");
                return;
            }

            l.assignUser(cardId, user);
        }

        void unAssignUser(string listId, string cardId){
            List l = b.getList(listId);
            if(l == NULL){
                utility.print("list does not exist");
                return;
            }

            l.unAssignUser(cardId);
        }

        //delete card
        void deleteCard(string listId, string cardId){
            List l = b.getList(listId);
            if(l == NULL){
                utility.print("list does not exist");
                return;
            }

            l.deleteCard(cardId);
        }

};