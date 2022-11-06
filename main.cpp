#include <bits/stdc++.h>
#include <user.h>
#include <trelloApp.h>
#include <utility.h>
using namespace std;

int main()
{

    // create some users
    User u1 = User("ajay", "aj");

    // create the utility tool
    Utility utility = Utility();

    // create the trello app
    TrelloApp app = TrelloApp(utility);

    // add users to the trello app
    app.addUser(u1);

    // create board
    Privacy p = PUBLIC;
    app.createBoard("b1", "board1", p, "www.board1.com");

    // create a list in the board
    app.addList("b1", "l1", "list1");

    // create a card in the list
    app.addCard("b1", "l1", "c1", "card1", "first card buoy!!");

    // assign a user to the card
    app.assignUser("b1", "l1", "c1", u1);

    // print the entire content of the app
    app.getDetails();

    // unassign the user from the card

    // move the card to a new list

    // pending
    // edit the board, list, card
}
