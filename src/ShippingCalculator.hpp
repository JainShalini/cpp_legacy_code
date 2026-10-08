#pragma once

#include "IOrderProvider.hpp"

class ShippingCalculator {
private:
    IOrderProvider &orderProvider;

public:
    ShippingCalculator(IOrderProvider &orderProvider);
    double calculateShipping(int orderId);
};
