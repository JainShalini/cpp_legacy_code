#pragma once

#include "OrderProvider.hpp"

class ShippingCalculator {
private:
    OrderProvider orderProvider;

public:
    ShippingCalculator(OrderProvider &orderProvider);
    double calculateShipping(int orderId);
};
