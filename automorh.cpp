#include <iostream>
#include <chrono>

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1>>;
	std::string m_name;
	std::chrono::time_point<clock_t> m_beg;

	double elapsed() const {
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}

public:
	Timer() : m_beg(clock_t::now()) {}
	Timer(std::string name) : m_name(name), m_beg(clock_t::now()) {}

	void start(std::string name) {
		m_name = name;
		m_beg = clock_t::now();
	}

	void print() const {
		std::cout << m_name << ":\t" << elapsed() * 1000<< " ms" << '\n';
	}
};


bool Automorphic(__int64 n) {
	__int64 m;
	bool f;
	m = n * n;
	f = true;
	while (n && f)
	{
		if ((n % 10) != (m % 10))
			f = false;
		else
		{
			n = n / 10;
			m = m / 10;
		}
	}
	return f;
}



int main() {
	

	__int64 x;
	std::cin >> x;
	if (x != NULL)
	{
		Timer timer("");
		for (__int64 i = 0; i <= x; i++)
		{

			if (Automorphic(i))
			{
				std::cout << i << std::endl;
				timer.print();
			}
		}
	}
	
	
}