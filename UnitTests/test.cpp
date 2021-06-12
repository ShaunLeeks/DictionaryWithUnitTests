#include "pch.h"
#include "../Dictionary.h"

class DictionaryTest : public ::testing::Test {
protected:
	Dictionary<int, std::string> d1_;
};

TEST_F(DictionaryTest, FindPresent) {
	d1_.insert(10, "test");
	d1_.insert(2646, "adfg");
	d1_.insert(12314, "data");
	d1_.insert(1099, "stuff");
	d1_.insert(-345, "things");
	d1_.insert(1, "clutter");

	EXPECT_EQ(d1_.find(-345), "things");
}

TEST_F(DictionaryTest, FindMissing) {
	d1_.insert(10, "test");
	d1_.insert(2646, "adfg");
	d1_.insert(12314, "data");
	d1_.insert(1099, "stuff");
	d1_.insert(-345, "things");
	d1_.insert(1, "clutter");

	auto set{ d1_.find(14253) };
	EXPECT_EQ(d1_.find(14253), "");
}

TEST_F(DictionaryTest, FindEmpty) {
	EXPECT_EQ(d1_.find(0), "");
}
