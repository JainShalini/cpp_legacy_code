#pragma once

#include "Order.hpp"
#include "IOrderProvider.hpp"

class OrderProvider : public IOrderProvider {
public:
    Order fetchOrder(int orderId) override;
};
