#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

double xNextF(const double &x, const double &r)
{
	return 4 * r * x * (1 - x);
}

int main()
{
	double x0Step = 0.1;
	for (int x0n = 1; x0n <= 4; ++x0n)
	{
		std::fstream file;
		file.open("../results/" + std::to_string(x0n), std::ios::out);

		for (double r = 0; r <= 1; r += 0.0001)
		{
			double x = x0n * x0Step;
			double xNext = xNextF(x, r);

			bool converged = false;

			for (int n = 0; n < 1000; ++n)
			{
				x = xNext;
				xNext = xNextF(x, r);

				file << r << "\t" << xNext << std::endl;
				converged = true;

			}

			file << r << "\t" << xNext << std::endl;

//			if (!converged)
//			{
//				std::cout << "Didn't converge" << std::endl;
//			}
		}

		file.close();
	}
	return 0;
}