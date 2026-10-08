#pragma once

#include "Order.hpp"

class OrderProvider {
public:
    Order fetchOrder(int orderId);
};
