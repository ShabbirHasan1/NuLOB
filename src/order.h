#pragma once 
#ifndef ORDER_H_
#define ORDER_H_

class Limit;

class Order {
public:
    Order(int* t, bool b, bool m, int s, double et); // market
    Order(int* t, bool b, bool m, int s, double l, double et); // limit

    inline void updateShares(int qty, int time);

    inline bool getMarket() const { return isMarket; }

    inline bool getBidorask() const { return bidorask; }

    inline int* getTid() { return tid; }
    inline void setTid(int* tid) { this->tid = tid; }

    inline int* getQid() { return qid; }
    inline void setQid(int* qid) { this->qid = qid; }

    inline int getShares() { return shares; }
    inline void setShares(int shares) { this->shares = shares; }

    inline double getLimit() { return shares; }
    inline void setLimit(double limitPrice) { this->limitPrice = limitPrice; }

    inline double getEntryTime() { return entryTime; }
    inline void setEntryTime(double entryTime) { this->entryTime = entryTime; }
    
    inline double getEventTime() { return eventTime; }
    inline void setEventTime(double eventTime) { this->eventTime = eventTime; }

    inline Order* getNext() { return this->next; }
    inline void setNext(Order* next) { this->next = next; }

    inline Order* getPrev() { return this->prev; }
    inline void setPrev(Order* prev) { this->prev = prev; }

    inline Limit* getParent() { return parent; }
    inline void setParent(Limit* parent) { this->parent = parent; }

private:
    int *tid;
    int *qid;
    int shares;
    bool bidorask;
    bool isMarket;
    double limitPrice;
    double entryTime;
    double eventTime;
    Order* next;
    Order* prev;
    Limit* parent;
};

#endif