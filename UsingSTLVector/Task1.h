#pragma once
#include <vector>

template<typename FirstType, typename SecondType>
auto ScalarProduct(const std::vector<FirstType>& a, const std::vector<SecondType> b) -> decltype(a[0] * b[0])
{
	if (a.size() != b.size())
	{
		throw(std::runtime_error("Scalar product requires same length of vectors"));
	}
	decltype(a[0] * b[0]) result = (a[0] * b[0]);
	for (unsigned i = 1; i < a.size(); ++i)
	{
		result += (a[i] * b[i]);
	}
	return result;
}

template<typename VectorType, typename MatrixType>
auto MatrixAndVectorProd(const std::vector<VectorType>& v, const std::vector<std::vector<MatrixType>>& m)
{
	using type = decltype(v[0] * m[0][0]);
	std::vector<type> result;
	if (v.size() != m.size())
	{
		throw(std::runtime_error("Vector length must be the same as number of rows in matrix"));
	}
	for (unsigned i = 0; i < m[i].size(); ++i)
	{
		type value = type();
		for (unsigned j = 0; j < m.size(); ++j)
		{
			value += (v[j] * m[j][i]);
		}
		result.push_back(value);
	}
	return result;
}