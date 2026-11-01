#pragma once
namespace Biblio {


	class Date
	{
	private:
		int annee;
		int mois;
		int jour;
	public:
		Date(int, int, int);
		static bool  estBissextile(int);
		 static bool  estValide(int j, int m, int a);
		 bool operator==(const Date& d)const;
		 bool operator<(const Date& d)const;


	};
}

