#include "order.h"
#include "limit.h"

Order::Order(int* t, bool b, bool m, int s, double et) // market
    : tid(t), qid(NULL), bidorask(b), isMarket(m), shares(s), limitPrice(-1.0), eventTime(-1.0), next(nullptr), prev(nullptr), parent(nullptr) {}

Order::Order(int* t, bool b, bool m, int s, double l, double et) // limit
    : tid(t), qid(NULL), bidorask(b), isMarket(m), shares(s), limitPrice(l), entryTime(et), eventTime(-1.0), next(nullptr), prev(nullptr), parent(nullptr) {}

void Order::updateShares(int qty, int time) {
    this->parent->setVol(this->parent->getTotalVol() - (this->shares - qty));
    this->shares = qty;
}