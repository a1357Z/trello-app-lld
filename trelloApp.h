#include <bits/stdc++.h>
#include <./user.h>
#include <./board.h>
#include<./utility.h>
using namespace std;


class TrelloApp
{
    private:
        unordered_map<string, User> users;
        unordered_map<string, Board> boards;
        Utility utility;

    public:
        TrelloApp(vector<User> users, Utility u){
            this->users = users;
            this->utility = u;
        }

        //the client directly interacts with the TrelloApp

        //get a board from boardId
        Board getBoard(string boardId){
            if(this->boards.count(boardId) > 0){
                return this->boards[boardId];
            }
            return NULL;
        }

        //create a board
        void createBoard(string id, string name, Privacy privacy, String url){
            
            //check if board with this id already exists
            Board board = getBoard(id);
            if(board != NULL){
                utility.print("board already exists");
                return;
            }
            
            //create the board
            Board b = Board(id, name, privacy, url);
            boards[id] = b;
            
        }

        //delete a board
        void deleteBoard(string boardId){
            Board b = getBoard(boardId);
            if(b != NULL){
                this->boards.erase(boardId);
            }else{
                utility.print("Board does not exist");
            }
        }


        //add a list to a board
        void addList(string boardId, string listId, string listName){
            Board b = getBoard(boardId);
            if(b != NULL){
                b.addList(listId, listName);
            }else{
                //board not found
                utility.print("Board does not exist");
            }
        }


        //delete a list from the board
        void deleteList(string boardId, string listId){
            Board b = getBoard(boardId);
            if(b != NULL){
                //delete the list
                b.deleteList(listId);
            }else{
                //board not found
                utility.print("Board does not exist");
            }
        }


        //add a card to a list
        void addCard(string boardId, string listId, string cardId, string cardName, string description){
            Board b = getBoard(boardId);
            if(b == NULL){
                utility.print("Board does not exist");
                return;   
            }
            b.addCard(listId, cardId, cardName, description);
        }


        //delete a card from a list
        void deleteCard(string boardId, string listId, string cardId){
            Board b = getBoard(boardId);
            if(b == NULL){
                utility.print("Board does not exist");
                return;   
            }
            b.deleteCard(listId, cardId);
        }

        //assign user to card
        void assignUser(string boardId, string listId, string cardId, User user){
            Board b = getBoard(boardId);
            if(b == NULL){
                utility.print("Board does not exist");
                return;   
            }
            b.assignUser(listId, cardId, user);
        }

        //unassign user from card
        void unAssignUser(string boardId, string listId, string cardId){
            Board b = getBoard(boardId);
            if(b == NULL){
                utility.print("Board does not exist");
                return;   
            }
            b.unAssignUser(listId, cardId);
        }

        //add a user to the app
        void addUser(User user){
            this->users[user.getUserId()] = user;
        }

        //move card from list1 to list2
        
        

};