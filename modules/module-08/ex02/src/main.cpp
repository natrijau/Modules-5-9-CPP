#include	"../include/MutantStack.hpp"

void	vectorContainer(void)
{
	try
	{
		std::cout << "Test with std::vector" << std::endl;
		std::vector<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
	
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		mstack.begin();
		std::vector<int>::iterator it = mstack.begin();
		std::vector<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::vector<int> s(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	listContainer(void)
{
	try
	{
		std::cout << "Test with std::list" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
	
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		mstack.begin();
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::list<int> s(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	myClass(void)
{
	try
	{
		std::cout << "Test with MutantStack class" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
	
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		mstack.begin();
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main()
{
	try
	{
		myClass();
		std::cout << std::endl;
		listContainer();
		std::cout << std::endl;
		vectorContainer();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}