#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <cctype>

void ispis(std::string s)
{
	std::cout << "\"";
	for (int i = 0; i < s.size(); i++)
	{
		if (i == 0 && s[i] != '\0')
		{
			s[0] = std::toupper(s[0]);
		}
		if (s[i] == '\0')
		{
			std::cout << "_";
		}
		else
		{
			std::cout << s[i];
		}
	}
	std::cout << "\"\n\n";
}

void gadjanjeRijeci(char unijetoSlovo, std::string trazenaR, std::string& rijec)
{
	for (int i = 0; i < trazenaR.size(); i++)
	{
		if (unijetoSlovo == trazenaR[i])
		{
			rijec[i] = unijetoSlovo;
		}
	}
}

int main()
{
	std::vector<std::string> rijeci;

	{
		std::ifstream fajlRijeci("rijeci.txt");

		for (std::string linija; std::getline(fajlRijeci, linija);)
		{
			if (linija.empty())
			{
				continue;
			}

			rijeci.push_back(linija);
		}
	}

	std::minstd_rand rng(std::random_device{}());
	std::uniform_int_distribution<int> domet(0, rijeci.size() - 1);

	std::string trazenaRijec = rijeci[domet(rng)];
	std::string unijetaRijec;

	unijetaRijec.resize(trazenaRijec.size());

	for (char& c : unijetaRijec)
	{
		c = std::tolower(c);
	}

	while (true)
	{
		std::cout << "Radi se o imenu sa " << trazenaRijec.size() << " slova.\n";
		std::cout << "Upisi neko slovo: ";
		char unijetoSlovo;
		std::cin >> unijetoSlovo;

		unijetoSlovo = std::tolower(unijetoSlovo);
		gadjanjeRijeci(unijetoSlovo, trazenaRijec, unijetaRijec);

		ispis(unijetaRijec);

		if (unijetaRijec == trazenaRijec)
		{
			std::cout << "Pogodak!? Wow, nisam ocekivao da ces pogoditi...\n";
			break;
		}
	}

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

	return 0;
}