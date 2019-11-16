#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Batsman
{
private:
	string name;
//	int    age;
	string team;
	int    matches;
	int    totalRuns;
	double average;
	double strikeRate;
	int    centunries;
	int    fifties;
	int    HS;
public:
	Batsman() : name("N/A"), /*age(0),*/ team("N/A"), 
				matches(0), totalRuns(0), average(0),
				strikeRate(0), centunries(0), fifties(0), HS(0)
	{}

	Batsman( string nm,	/*int ag,*/	string tm,	int mtch,
			 int tRuns, double avg, double stR,	int cent, int fif, int HiSc
	) : name(nm), /*age(ag),*/ team(tm),
		matches(mtch), totalRuns(tRuns), average(avg),
		strikeRate(stR), centunries(cent), fifties(fif), HS(HiSc)
	{}
	void init4mFile(ifstream& inFile);
	void printBatsman() const;
	void printInLineBatsman() const;
	static void printTitles();
	static void printBottom();
	double getAvg() const
	{
		return average;
	}
	double getStrRate() const
	{
		return strikeRate;
	}
	int getMatches() const
	{
		return matches;
	}
	string getName() const
	{
		return name;
	}
	int getRuns() const
	{
		return totalRuns;
	}

};

//--------------------------------------------------------------------
int main()
{
	
//	ifstream batsmanFile("batsmen.txt");
	ifstream batsmanFile("avg_stk_rt_combined.txt");

	string temp_str;
	getline(batsmanFile, temp_str);
	
	// Fill array from file
	Batsman topBatsmen[200];
	int n = 0;
	while (batsmanFile)
	{
		topBatsmen[n].init4mFile(batsmanFile);
		//topBatsmen[n].printInLineBatsman();
		n++;
	}
	batsmanFile.close();

/*  // Find Duplicate Entries
	for (int i = 0; i < n; i++)
	{

		for (int j = i+1; j < n; j++)
		{
			if (topBatsmen[i].getName() == topBatsmen[j].getName())
				cout << "Name: " << topBatsmen[i].getName() << "exists at " << i << " and " << j << endl;

		}
	}
*/

	// Filter results based on average strike rate and matches
	double average = 40;
	double strikeRate = 90;
	int runs = 1000;
	int matches = 25;
	cout << "Enter min Avg, min Strike rate min Runs and min Matches:\n";
	cin >> average >> strikeRate >> runs >> matches;

	Batsman::printTitles();
	for (int i = 0; i < n; i++)
	{
		if (average < topBatsmen[i].getAvg() &&
			strikeRate < topBatsmen[i].getStrRate() &&
			runs < topBatsmen[i].getRuns() && 
			matches < topBatsmen[i].getMatches())
			topBatsmen[i].printInLineBatsman();

	}
	Batsman::printBottom();





	return 0;
}

void Batsman::init4mFile(ifstream& inFile)
{
	int dummyInt;
	char dummyChar;
	inFile >> team;
	inFile >> dummyInt >> dummyChar >> dummyInt;
	inFile >> matches;
	inFile >> dummyInt >> dummyInt;
	inFile >> totalRuns;
	inFile >> HS;
	inFile >> average;
	inFile >> dummyInt;
	inFile >> strikeRate;
	inFile >> centunries;
	inFile >> fifties;
	inFile >> dummyInt >> dummyInt >> dummyInt;

	dummyChar = inFile.get();
	while (dummyChar == ' ' || dummyChar == '\t')
		dummyChar = inFile.get();

	inFile.putback(dummyChar);

	getline(inFile, name);


}

void Batsman::printBatsman() const
{
	cout << setw(20) << "Batsman Info:" << endl;
	cout << setw(20) << "-------------" << endl;
	cout << setw(20) << "Name:" << name << endl;
	//	cout << setw(20) << "Age:" << age << endl;
	cout << setw(20) << "Team:" << team << endl;
	cout << setw(20) << "Matches:" << matches << endl;
	cout << setw(20) << "Total Runs:" << totalRuns << endl;
	cout << setw(20) << "Average:" << average << endl;
	cout << setw(20) << "Strike Rate:" << strikeRate << endl;
	cout << setw(20) << "Centunries:" << centunries << endl;
	cout << setw(20) << "Fifties:" << fifties << endl;
	cout << setw(20) << "Highest Score:" << HS << endl;

}

void Batsman::printInLineBatsman() const
{
	cout << char(186);
	cout << setw(20) << name << "|";
	cout << setw(5) << team << "|";
	cout << setw(6) << matches << "|";
	cout << setw(6) << totalRuns << "|";
	cout << setw(7) << average << "|";
	cout << setw(7) << strikeRate << "|";
	cout << setw(6) << centunries << "|";
	cout << setw(6) << fifties << "|";
	cout << setw(6) << HS ;
	cout << char(186) << endl;

}
void Batsman::printTitles()
{
	char top = 205;
	char top_l = 201;
	char top_r = 187;
	char div =  186;
	cout << top_l;
	for (int i = 0; i < 77; i++)
		cout << top;
	cout << top_r << endl;;
	//cout << "\t----------------------------------------------------------------------" << endl;
	cout << div;
	cout << setw(20) << "Name" << div;
	cout << setw(5) << "Team" << div;
	cout << setw(6) << "Mat" << div;
	cout << setw(6) << "Runs" << div;
	cout << setw(7) << "Avg" << div;
	cout << setw(7) << "Str.Rt" << div;
	cout << setw(6) << "100s" << div;
	cout << setw(6) << "50s" << div;
	cout << setw(6) << "HS" << div << endl;

	cout << char(199);// top_l;
	for (int i = 0; i < 77; i++)
		cout << char(196);// top;
	cout << char(182) << endl;;

}
void Batsman::printBottom()
{
	cout << char(200);
	for (int i = 0; i < 77; i++)
		cout << char(205);
	cout << char(188) << endl;
}
