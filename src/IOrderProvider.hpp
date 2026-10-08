#pragma once
#include "Order.hpp"

class IOrderProvider {
public:
    virtual Order fetchOrder(int orderId) = 0;
};