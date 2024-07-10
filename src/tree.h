#pragma once
#ifndef TREE_H_
#define TREE_H_

#include "order.h"
#include "limit.h"
#include <cstddef>
#include <map>
#include <unordered_map>

class Tree {
public:
    Tree() 
        : root(nullptr), vol(0), depth(0), orderCount(0) {reset();}

    void reset() {
        for (auto& pair : limitTree) {
            delete pair.second;
        }
        limitTree.clear();
        limitMap.clear();
        vol = 0;
        depth = 0;
        orderCount = 0;
    }

    inline void insertOrder(Order quote){
        int* qid = quote.getQid();
        double quotePrice = quote.getLimit();
        if (orderExists(*qid)) {
			// removeOrderByID(qid);
		}
        orderCount++;
        if (!limitExists(quotePrice)) {
			newLimit(quotePrice);
		}
        quote.setParent(getLimitList(quotePrice));
    }

    inline void newLimit(double price) {
        Limit* newList = new Limit(price); 
        limitTree[price] = newList;
        limitMap[price] = newList;
        depth++;
    }
    inline void removeLimit(double price) {
        auto mem = limitTree.find(price);
        if (mem != limitTree.end()) {
            delete mem->second; 
            limitTree.erase(mem);
            limitMap.erase(price); 
            depth--;
        }
    }

    inline Order* getOrder(int id){
        auto it = orderMap.find(id);
        if (it != orderMap.end()) {
            return it->second;
        } 
    }
    inline Limit* getLimitList(double price){
        auto it = limitMap.find(price);
        if (it != limitMap.end()) {
            return it->second;
        } 
    }

    inline bool orderExists(int id){
        orderMap.find(id) != orderMap.end();
    }
    inline bool limitExists(double price){
        limitMap.find(price) != limitMap.end();
    }

    inline int getVol() { return vol; } 
    inline int getDepth() { return depth; }
    inline int getOrderCount() { return orderCount; }
    
private:
    Limit* root;
    int vol;
    int depth;
    int orderCount;
    std::map<double, Limit*> limitTree;
    std::unordered_map<int, Order*> orderMap;
    std::unordered_map<double, Limit*> limitMap; 
};

#endif