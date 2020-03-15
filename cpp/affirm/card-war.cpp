两个player玩牌 牌从1到52，我们首先给他们洗牌发牌。然后每次两个player分别拿出他们的top card 比较，
大的一边可以收走小的的牌，并且得两分（用过的牌都扔掉）最后看谁分高。第二问是说这个问题变成M张牌，
N个人怎么玩（M不一定是N的倍数，如果有多的牌，需要randomly分给大家 所以大家的牌数不一定相等）

class Player {
public:
    Player(int i):id(i) {
        score=0;
    }

    int getScore() {
        return score;
    }
    void addScore(int s) {
        score+=s;
    }

    int getTopCard() {
        if (pq.empty()) return -1;
        auto res=pq.top();
        pq.pop();
        return res;
    }

    void addCard(int card) {
        cout << "player id=" << id << ", card=" << card << endl;
        pq.push(card);
    }


private:
    int id;
    int score;
    priority_queue<int> pq;
};

class CardGame {
public:
    void addPlayer(int id) {
        Player* p=new Player(id);
        players[id]=p;
    }

    void distributeCards() {
        srand (time(NULL));
        vector<int> cards(numCards);
        for (int i=0; i<numCards; ++i) cards[i]=i+1;
        int n=numCards;
        bool done=false;
        while (1) {
            for (auto& p:players) {
                if (n==0) {
                    done=true;
                    break;
                }
                int idx=rand()%n;
                p.second->addCard(cards[idx]);
                swap(cards[idx], cards[n-1]);
                n--;
            }
            if (done) break;
        }
    }

    void printScores() {
        for (auto& p:players) {
            cout << "id: " << p.first << ", score: " << p.second->getScore() << endl;
        }
    }

    void startGame() {
        bool done=false;
        while (1) {
            vector<pair<int, int>> v;
            for (auto& p:players) {
                int card=p.second->getTopCard();
                if (card==-1) {
                    done=true;
                    break;
                }
                v.push_back({p.first, card});
            }
            if (done) break;
            int maxPlayer=-1, maxCard=INT_MIN;
            for (auto i:v) {
                if (i.second>maxCard) {
                    maxCard=i.second;
                    maxPlayer=i.first;
                }
            }
            players[maxPlayer]->addScore(socrePerRound);
        }
        printScores();
    }
private:
    unordered_map<int, Player*> players;
    const int numCards=52;
    const int socrePerRound=2;
};

int main(int argc, char** argv) {
    CardGame cg;
    int players=2;
    for (int i=0; i<players; ++i) {
        cg.addPlayer(i);
    }
    cg.distributeCards();
    cg.startGame();
    return 0;
}

