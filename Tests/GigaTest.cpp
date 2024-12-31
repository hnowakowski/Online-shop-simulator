#include <memory>
#include <vector>
#include "../Classes/Cart.h"
#include "../Classes/Order.h"
#include "../ExternalLibs/googletest/googletest/include/gtest/gtest.h"
#include "../Templates/LoaderSaver.h"

// Mock Serializable class for testing
class MockSerializable : public Serializable
{
  public:
    std::string data;

    MockSerializable() = default;

    explicit MockSerializable(const nlohmann::json& json) { fromJSON(json); }

    nlohmann::json toJSON() const override { return {{"data", data}}; }

    void fromJSON(const nlohmann::json& json) override
    {
        if (json.contains("data"))
        {
            data = json["data"];
        }
    }
};

// Test 1: Cart Functionality
TEST(CartTest, AddRemoveItems)
{
    Cart cart = Cart();

    auto product1 = std::make_shared<Product>(
        "1", "Product1", "Description1", "Image1", "Rating1", 1, std::make_shared<Price>(10, 50));
    auto product2 = std::make_shared<Product>(
        "2", "Product2", "Description2", "Image2", "Rating2", 2, std::make_shared<Price>(20, 25));

    EXPECT_TRUE(cart.AddBuyable(product1));
    EXPECT_TRUE(cart.AddBuyable(product2));
    EXPECT_EQ(cart.Size(), 2);

    EXPECT_FALSE(cart.RemoveBuyable(product1));
    EXPECT_EQ(cart.Size(), 1);

    EXPECT_FALSE(cart.RemoveBuyable(product2));
    EXPECT_EQ(cart.Size(), 0);
}

// Test 2: Order operations
TEST(OrderTest, CreateAndProcessOrder)
{
    auto customer =
        std::make_shared<Customer>("Customer1", "John", "Smith", "Email1", "Phone1", std::make_shared<Wallet>(30, 0));
    auto  cart = std::make_shared<Cart>();
    Order order("Order1", customer, cart);

    auto product = std::make_shared<Product>(
        "3", "TestProduct", "Description", "Image", "Rating", 1, std::make_shared<Price>(15, 0));
    cart->AddBuyable(product);

    auto total = order.GetCart()->GetTotalPrice();
    EXPECT_EQ(total.first, 15);
    EXPECT_EQ(total.second, 0);
}

// Test 3: Price Calculations
TEST(PriceTest, AddAndComparePrices)
{
    Price price1(10, 50); // $10.50
    Price price2(5, 25);  // $5.25

    Price total = price1 + price2;
    EXPECT_EQ(total.GetMainUnit(), 15); // $15
    EXPECT_EQ(total.GetSubUnit(), 75);  // 75 cents

    Price discounted = price1 - price2;
    EXPECT_EQ(discounted.GetMainUnit(), 5); // $5
    EXPECT_EQ(discounted.GetSubUnit(), 25); // 25 cents

    EXPECT_TRUE(price1 > price2);
    EXPECT_TRUE(price2 < price1);
}

// Test 4: Loading and Saving (Serializable Interface)
TEST(SerializableTest, SaveAndLoadJSON)
{
    MockSerializable mock;
    mock.data = "Test Data";

    // Serialize to JSON
    nlohmann::json serialized = mock.toJSON();
    EXPECT_EQ(serialized["data"], "Test Data");

    // Deserialize from JSON
    MockSerializable loadedMock(serialized);
    EXPECT_EQ(loadedMock.data, "Test Data");
}

// Test 5: Buyable Attribute Verification
TEST(BuyableTest, CheckAttributes)
{
    Product product("1", "Product1", "Description1", "Image1", "Rating1", 1, std::make_shared<Price>(20, 75));

    EXPECT_EQ(product.GetName(), "Product1");
    EXPECT_EQ(product.GetMainUnitPrice(), 20);
    EXPECT_EQ(product.GetSubUnitPrice(), 75);
    EXPECT_EQ(product.GetQuantity(), 1);
}

// Test 6: LoaderSaver Utility
TEST(LoaderSaverTest, SaveAndLoadList)
{
    std::vector<std::shared_ptr<Product>> products = {
        std::make_shared<Product>(
            "1", "Product1", "Description1", "Image1", "Rating1", 1, std::make_shared<Price>(10, 50)),
        std::make_shared<Product>(
            "2", "Product2", "Description2", "Image2", "Rating2", 2, std::make_shared<Price>(15, 25))};

    LoaderSaver<Product> loaderSaver;

    loaderSaver.Save("./testproducts.json", products);
    std::vector<std::shared_ptr<Product>> loadedProducts;
    loaderSaver.Load("./testproducts.json", loadedProducts);

    EXPECT_EQ(loadedProducts.size(), 2);
    EXPECT_EQ(loadedProducts[0]->GetName(), "Product1");
    EXPECT_EQ(loadedProducts[0]->GetMainUnitPrice(), 10);
    EXPECT_EQ(loadedProducts[0]->GetSubUnitPrice(), 50);
    EXPECT_EQ(loadedProducts[1]->GetMainUnitPrice(), 15);
    EXPECT_EQ(loadedProducts[1]->GetSubUnitPrice(), 25);
}