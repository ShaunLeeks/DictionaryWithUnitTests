#pragma once

template <typename KEY, typename DATA>
class Dictionary
{
public:
	void insert(KEY key, DATA data);
	DATA find(KEY key);
	bool present(KEY key);
private:
	using data_store = std::pair<KEY, DATA>;
	std::vector<data_store> store;

};

template<typename KEY, typename DATA>
inline void Dictionary<KEY, DATA>::insert(KEY key, DATA data)
{
	if (!present(key)) {
		store.push_back(std::pair<KEY, DATA>(key, data));
	}
}

template<typename KEY, typename DATA>
inline DATA Dictionary<KEY, DATA>::find(KEY key)
{
	for (auto pair : store) {
		if (key == std::get<0>(pair)) {
			return std::get<1>(pair);
		}
	}
	return {};
}

template<typename KEY, typename DATA>
inline bool Dictionary<KEY, DATA>::present(KEY key)
{
	for (auto pair : store) {
		if (key == std::get<0>(pair)) {
			return true;
		}
	}
	return false;
}
