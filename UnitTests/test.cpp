#include "pch.h"
#include "../Dictionary.h"

class DictionaryTestF : public ::testing::Test {
protected:
	Dictionary<int, std::string> d1_;
	Dictionary<std::string, int> d2_;
	Dictionary<int, std::string> d3_;

	void SetUp() override {
		d1_.insert(10, "test");
		d1_.insert(2646, "adfg");
		d1_.insert(12314, "data");
		d1_.insert(1099, "stuff");
		d1_.insert(-345, "things");
		d1_.insert(1, "clutter");

		d2_.insert("test", 10);
		d2_.insert("adfg", 2646);
		d2_.insert("data", 12314);
		d2_.insert("stuff", 1099);
		d2_.insert("things", -345);
		d2_.insert("clutter", 1);
	}
};

TEST_F(DictionaryTestF, FindSucceedsReturnsData) {
	EXPECT_EQ(d1_.find(-345), "things");
}

TEST_F(DictionaryTestF, FindMissingReturnsDefaltWhenKeyMissing) {
	EXPECT_EQ(d1_.find(14253), std::string{});
	EXPECT_EQ(d2_.find(""), int{});
}

TEST_F(DictionaryTestF, FindReturnsDefaltWhenSearchingEmptyDictionary) {
	EXPECT_EQ(d3_.find(2346243), std::string{});
}

TEST_F(DictionaryTestF, PresentReturnsTrueWhenKeyFound) {
	EXPECT_EQ(d1_.present(12314), true);
}

TEST_F(DictionaryTestF, PresentReturnsFalseWhenKeyMissing) {
	EXPECT_EQ(d1_.present(12426), false);
}

TEST_F(DictionaryTestF, PresentReturnsFalseWhenSearchingEmptyDictionary) {
	EXPECT_EQ(d3_.present(12426), false);
}