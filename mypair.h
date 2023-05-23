#pragma once

template<typename T, typename U>
class my_pair {
public:
	my_pair()noexcept : first{}, second{} {};
	my_pair(const T& x, const T& y)noexcept : first(x), second(y) {};
	using first_type = T;
	using second_type = U;
	T first;
	U second;
	my_pair(const my_pair&) = default;
	my_pair(my_pair&&) = default;
	template<typename T1, typename T2>
	my_pair(const my_pair<T1, T2>& other)noexcept : first{ other.first }, second{ other.second } {};

	constexpr void swap(const my_pair& other)const noexcept
	{
		my_pair temp{ *this };
		*this = my_pair{ other };
		other(temp);
	}
};

template<typename T, typename U>
my_pair<T, U> MakePair(const T& x, const U& y)
{
	return my_pair<T, U>{x, y};
}

template<typename T, typename U, typename T1, typename U1>
constexpr bool operator<(const my_pair<T, U>& x, const my_pair<T1, U1>& y)
{
	return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
}

template<typename T, typename U, typename T1, typename U1>
constexpr bool operator==(const my_pair<T, U>& x, const my_pair<T1, U1>& y)
{
	return x.first == y.first && x.second == y.second;
}

template<typename T, typename U, typename T1, typename U1>
constexpr bool operator!=(const my_pair<T, U>& x, const my_pair<T1, U1>& y)
{
	return !(x == y);
}

template<typename T, typename U, typename T1, typename U1>
constexpr bool operator<=(const my_pair<T, U>& x, const my_pair<T1, U1>& y)
{
	return (x == y) || (x < y);
}

template<typename T, typename U, typename T1, typename U1>
constexpr bool operator>(const my_pair<T, U>& x, const my_pair<T1, U1>& y)
{
	return !(x < y);
}

template<typename T, typename U, typename T1, typename U1>
constexpr bool operator>=(const my_pair<T, U>& x, const my_pair<T1, U1>& y)
{
	return (x > y) || (x == y);
}