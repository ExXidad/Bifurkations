#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

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

		for (double r = 0; r <= 1; r += 0.0005)
		{
			double xPrev = 0;
			double x = x0n * x0Step;
			double xNext = xNextF(x, r);

			double eps = x * 0.0001;
			bool converged = false;

			for (int n = 0; n < 10000; ++n)
			{
				xPrev = x;
				x = xNext;
				xNext = xNextF(x, r);
//			std::cout << xPrev << " " << x << " " << xNext << std::endl;

				if ((xNext - x) - (x - xPrev) < eps && false)
				{
					file << r << "\t" << xNext << std::endl;
					converged = true;
					break;
				}
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