#include <iostream>
#include <vector>
#include <queue>
#include <iterator>
#include <algorithm>

std::vector<int> numberToSet(int n)
{
	std::vector<int> result;
	while (n)
	{
		result.push_back(n % 10);
		n = n / 10;
	}
	std::reverse(result.begin(), result.end());
	return result;
}

std::vector<int> swap(std::vector<int> set, int fP, int sP) {
	const int fV = set[fP];
	const int sV = set[sP];
	set[fP] = sV;
	set[sP] = fV;
	return set;
}

bool is_equal(std::vector<int> v1, std::vector<int> v2) {
	return std::equal(v1.begin(), v1.end(), v2.begin(), v2.end());
}

bool valid_solution(std::vector<std::vector<int>> solutions, std::vector<int> solution)
{
	for (auto found_solutions : solutions)
	{
		if (is_equal(solution, found_solutions))
			return false;
	}
	return true;
}

void permutations(std::vector<int> set) {
	std::vector<std::vector<int>> solutions = { set };
	std::queue<std::vector<int>> queue;
	queue.push(set);
	while (!queue.empty())
	{
		for (unsigned int position = 1; position < set.size(); position++)
		{
			std::vector<int> solution = swap(queue.back(), 0, position);
			if (valid_solution(solutions, solution))
			{
				solutions.push_back(solution); 
				queue.push(solution);
			}
		}
		queue.pop();
	}
	for (auto solution : solutions)
	{
		for (auto elem : solution)
		{
			std::cout << elem;
		}
		std::cout << " ";
	}
}

int main()
{
	int number;
	std::cin >> number;
	std::vector<int> set = numberToSet(number);
	permutations(set);
}
