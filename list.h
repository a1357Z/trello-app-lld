#include <bits/stdc++.h>
#include <./card.h>
#include<./utility.h>
using namespace std;


class List
{
    private:
        string id;
        string name;
        Utility utility;
        unordered_map<string, Card> cards; //card cannot exist without list --> composition

    public:
        List(string id, string name, Utility u){
            this->id = id;
            this->name = name;
            this->utility = u;
        }

        //! List will manage every thing associated with cards

        //create and add a card to map
        void addCard(string cardId, string cardName, string description){
            Card c = getCard(cardId);
            if(c != NULL){
                utility.print("card already exists with this id");
                return;
            }

            //create the card with no user assigned
            Card card = Card(cardId, cardName, description);
            setCard(cardId, card);
        }

        //assign user to card and vice versa
        void assignUser(string cardId, User user){
            Card c = getCard(cardId);
            if(c == NULL){
                utility.print("card does not exist");
                return;
            }

            c.assignUser(user);
            user.assignCard(card);
        }

        //unassign user from card and vice versa
        void unAssignUser(string cardId){
            Card c = getCard(cardId);
            if(c == NULL){
                utility.print("card does not exist");
                return;
            }

            User user = c.getUser();
            if(user != NULL){
                user.unAssignCard(c);
            }
            c.unAssignUser();
        }

        //delete card
        void deleteCard(string cardId){
            Card c = getCard(cardId);
            if(c == NULL){
                utility.print("card does not exist with this id");
                return;
            }

            //unassign the card before deleting
            User user = c.getUser();
            if(user != NULL){
                user.unAssignCard(c);
            }
            this->cards.erase(cardId);
        }

        //get a card
        List getCard(string cardId){
            if(cards.count(cardId) > 0){
                return cards[cardId];
            }
            return NULL;
        }

        //set a card
        void setCard(string cardId, Card card){
            this->cards[cardId] = card;
        }
};