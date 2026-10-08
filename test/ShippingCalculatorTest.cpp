#include "ShippingCalculator.hpp"
#include "gtest/gtest.h"

class MockOrderProvider : public IOrderProvider {
public:
    Order fetchOrder(int orderId) override {
        Order order;
        if (orderId == 1) {
            order.shippingType = "STANDARD";
            order.weightKg = 10.0;
            order.distanceKm = 100.0;
        } else if (orderId == 2) {
            order.shippingType = "EXPRESS";
            order.weightKg = 5.0;
            order.distanceKm = 50.0;
        } else if (orderId == 3) {
            order.shippingType = "OVERNIGHT";
            order.weightKg = 2.0;
            order.distanceKm = 25.0;
        }
        return order;
    }
};

class ShippingCalculatorTest : public ::testing::Test {
protected:
    MockOrderProvider mockOrderProvider;
    ShippingCalculator calculator{mockOrderProvider};
};

TEST_F(ShippingCalculatorTest, CalculatesStandardShipping) {
    double shipping = calculator.calculateShipping(1);
    EXPECT_DOUBLE_EQ(shipping, 5.0);  // 10.0 * 0.5
}

TEST_F(ShippingCalculatorTest, CalculatesExpressShipping) {
    double shipping = calculator.calculateShipping(2);
    EXPECT_DOUBLE_EQ(shipping, 9.0);  // 5.0 * 0.8 + 50.0 * 0.1
}

TEST_F(ShippingCalculatorTest, CalculatesOvernightShipping) {
    double shipping = calculator.calculateShipping(3);
    EXPECT_DOUBLE_EQ(shipping, 27.4);  // 2.0 * 1.2 + 25
}