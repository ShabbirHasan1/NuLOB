#include "order.h"
#include "limit.h"

Order::Order(char* t, bool b, bool m, int s, double et) // market
    : tid(t), bidorask(b), isMarket(m), shares(s), limitPrice(-1.0), eventTime(-1.0), next(0), prev(0), parent(0) {}

Order::Order(char* t, bool b, bool m, int s, double l, double et) // limit
    : tid(t), bidorask(b), isMarket(m), shares(s), limitPrice(l), entryTime(et), eventTime(-1.0), next(0), prev(0), parent(0) {}

void Order::updateShares(int qty, int time) {
    this->parent->setVol(this->parent->getTotalVol() - (this->shares - qty));
    this->shares = qty;
}