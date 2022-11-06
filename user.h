
class User
{
private:
    string name;
    string userId;
    unordered_map<string, Card> assignedCards;

public:
    User(string name, string userId)
    {
        this->name = name;
        this->userId = userId;
    }

    string getName()
    {
        return this->name;
    }

    string getUserId()
    {
        return this->userId;
    }

    void assignCard(Card card)
    {
        this->assignedCards[card.getId()] = card;
    }

    void unAssignCard(Card card)
    {
        if (this->assignedCards.count(card.getId()) > 0)
        {
            this->assignedCards.erase(card.getId())
        }
    }
};