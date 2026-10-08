#pragma once
#include "Order.hpp"
class ShippingCalculator {
public:
    double calculateShipping(int orderId);
    Order fetchOrder(int orderId);
};
