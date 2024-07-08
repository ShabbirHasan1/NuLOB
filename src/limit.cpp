#include "order.h"
#include "limit.h"

Limit::Limit(double l)
   : limitPrice(l), size(0), totalVol(0), parent(0), left(0), right(0), headOrder(0), tailOrder(0) {}