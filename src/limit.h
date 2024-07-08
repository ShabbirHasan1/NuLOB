#pragma once
#ifndef LIMIT_H_
#define LIMIT_H_

#include "order.h"
#include <cstddef>

class Limit {
public:
    Limit(double l);

    inline void addOrder(Order* newOrder){ 
        if (this->size == 0){
            newOrder->setPrev(nullptr);
            newOrder->setNext(nullptr);
            this->headOrder = newOrder;
            this->tailOrder = newOrder;
        } else {
            newOrder->setPrev(this->tailOrder);
            newOrder->setNext(nullptr);
            this->tailOrder->setNext(newOrder);
            this->tailOrder = newOrder;
        }
        this->size += 1;
        this->totalVol += newOrder->getShares();
    }

    inline void removeOrder(Order* order){ // change to just remove the first node maybe? idk if i need the whole implementation lol
        this->size -= 1;
        this->totalVol -= order->getShares();
        if (this->size != 0){
            Order* nex = order->getNext();
            Order* pre = order->getPrev();
            if (nex->getNext() != nullptr) { 
                if (nex != nullptr) {
                    if (pre != nullptr) {
                        nex->setPrev(pre);
                        pre->setNext(nex);
                    } else {
                        nex->setPrev(nullptr);
                        this->headOrder = nex;
                    }
                } else if (pre != nullptr) {
                    pre->setNext(nullptr);
                    this->tailOrder = pre;
                }
            }
        }
    }

    inline int getSize() { return size; }

    inline Order* getHeadOrder() { return this->headOrder; }

    inline Order* getTailOrder() { return this->tailOrder; }
    inline void setTailOrder(Order* tailOrder) { this->tailOrder = tailOrder; }

    inline int getTotalVol() { return totalVol; }
    inline void setVol(int totalVol) { this->totalVol = totalVol; }
    
private:
    double limitPrice;
    int size;
    int totalVol;
    Limit* parent;
    Limit* left;
    Limit* right;
    Order* headOrder;
    Order* tailOrder;
};

#endif
