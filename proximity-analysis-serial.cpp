#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;





struct Location
{
	double lat;
	double longitude;

	Location(double c, double n)
	{
		lat = c;
		longitude = n;
	}


};


struct Service
{
	string name;
	int code;

	Service(int c, string n)
	{
		name = n;
		code = c;
	}

};




double pythagoreanTheorem(vector<Location> vec, double a, double b)
{
	double retVal;
	double newRet;
	double smallest = DBL_MAX;

	for(unsigned i =0; i < vec.size(); ++i)
	{
		retVal = pow(a - vec[i].lat, 2) + pow(b - vec[i].longitude, 2);

		newRet = sqrt(retVal)/1000;
		if(newRet < smallest)
		{
			smallest = newRet;
		}

	}
	

	return smallest;
}


int main(int argc, char* argv[])
{



	cout << endl;
	cout << endl;

	cout << "Proximities or Residential Addresses to Services in Toronto" << endl;
	cout << "-----------------------------------------------------------" << endl;

	vector<Service> s;

	Service fd(100001,	"Low Density Residential");

	s.push_back(fd);

	s.push_back(Service(101001,	"Hospital - Private and Public"));
	s.push_back(Service(100003,	"Subsidized Housing"));
	s.push_back(Service(101002,	"Old Age/Retirement Home"));
	s.push_back(Service(101003,	"Day Car"));
	s.push_back(Service(101004,	"Hostel"));
	s.push_back(Service(101005,	"Nursing Home - All Types"));
	s.push_back(Service(101006,	"Penal Institution"));
	s.push_back(Service(101007,	"Other Medical/Dental"));
	s.push_back(Service(102001,	"Public School – Primary"));
	s.push_back(Service(102002,	"Public School – Secondary"));
	s.push_back(Service(102003,	"Separate School – Primary"));
	s.push_back(Service(102004,	"Separate School – Secondary"));
	s.push_back(Service(102005,	"Private School"));
	s.push_back(Service(102006,	"College"));
	s.push_back(Service(102007,	"University"));
	s.push_back(Service(102008,	"Other Educational Institution"));
	s.push_back(Service(103001,	"Ambulance Station"));
	s.push_back(Service(103002,	"Fire Station"));
	s.push_back(Service(103003,	"Police Station")); 
	s.push_back(Service(103004,	"Other Emergency Service"));
	s.push_back(Service(103005,	"Fire/Ambulance Station"));
	s.push_back(Service(104001,	"Municipal City Hall"));
	s.push_back(Service(104002,	"Municipal Other"));
	s.push_back(Service(104003,	"Regional Hall"));
	s.push_back(Service(104004,	"Regional Other"));
	s.push_back(Service(104005,	"Provincial Legislature"));
	s.push_back(Service(104006,	"Provincial Other"));
	s.push_back(Service(104007,	"Federal Office Building"));
	s.push_back(Service(104008,	"Other Office Building"));
	s.push_back(Service(106001,	"Municipal Park"));
	s.push_back(Service(106002,	"Regional Park"));
	s.push_back(Service(106003,	"Provincial Park"));
	s.push_back(Service(106004,	"Federal Park"));
	s.push_back(Service(106005,	"Sport Complex"));
	s.push_back(Service(106006,	"Golf Course"));
	s.push_back(Service(106007,	"Community/Assembly Hall"));
	s.push_back(Service(106008,	"Other Recreational Facility"));
	s.push_back(Service(107001,	"Restaurant"));
	s.push_back(Service(107002,	"Concert Hall/Theatre/Cinema"));
	s.push_back(Service(107003,	"Regional Shopping Centre"));
	s.push_back(Service(107004,	"Community Shopping Centre"));
	s.push_back(Service(107005,	"Neighbourhood Shopping Centre"));
	s.push_back(Service(107006,	"Hotel"));
	s.push_back(Service(107007,	"Exhibition/Fair Ground"));
	s.push_back(Service(107008,	"Museum/Art Gallery"));
	s.push_back(Service(107009,	"Library"));
	s.push_back(Service(107010,	"Other Point of Interest"));
	s.push_back(Service(108001,	"Subway Station"));
	s.push_back(Service(108002,	"Rapid Transit Station"));
	s.push_back(Service(108003,	"GO Bus Terminal"));
	s.push_back(Service(108004, "GO Train Station"));
	s.push_back(Service(108005,	"Airport"));
	s.push_back(Service(108006,	"Parking Lot"));
	s.push_back(Service(108007,	"Railway Station"));
	s.push_back(Service(108008,	"Other Transportation Facility"));
	s.push_back(Service(109001,	"Place of Worship"));
	s.push_back(Service(109002,	"Cemetery"));
	s.push_back(Service(110001,	"Other Use"));
	s.push_back(Service(111001,	"Farm"));
	s.push_back(Service(112001,	"Commercial Location"));
	s.push_back(Service(113001,	"Industrial Location"));
	s.push_back(Service(114001,	"Vacant Location"));
	s.push_back(Service(115001,	"Unknown"));

	int input = atoi(argv[1]);
	string serviceName = "";
	//istringstream myiss(input);
	//myiss >> argv[0];


	for(unsigned i = 0; i < s.size(); ++i)
	{
		if(input == s[i].code)
		{
			serviceName = s[i].name;

		}
	}

	cout << "Service:                                        " << serviceName << endl;
	cout << "Service Code:                                   " << input << endl;

	ifstream in("services.dat");
	if(!in)
	{
		cout << "Cannot open file " << "services.dat" << endl;
		return EXIT_FAILURE;
	}
	if(in.bad())
	{
		cout << "services.dat is a bad file and cannot be opened." << endl;
	}

	// start the timer
	clock_t begin = clock();
	
	vector<Location> locationVec;
	int loops = 0;
	//char ch;
	string code = "";
	map<double,double> fads;


	while(!in.eof())
	{
		double tempLat;
		double tempLong;
		string lol;
		getline(in,lol,'\t');
		istringstream iss(lol);
		int theCode;
		iss >> theCode;

		getline(in,lol,'\t');
		istringstream isss(lol);
		isss >> tempLat;

		getline(in,lol,'\n');
		istringstream issss(lol);
		issss >> tempLong;
		if(theCode == input)
		{
			locationVec.push_back(Location(tempLat, tempLong));
		}

		loops++;

	}


	ifstream ina("residences.dat");
	if(!ina)
	{
		cout << "Cannot open file " << "residences.dat" << endl;
		return EXIT_FAILURE;
	}
	if(ina.bad())
	{
		cout << "services.dat is a bad file and cannot be opened." << endl;
	}
	double hahaha = 0;

	int zeroAndOne = 0;
	int oneAndTwo = 0;
	int twoAndFive = 0;
	int aboveFive = 0;

	while(!ina.eof())
	{
		double tempLat;
		double tempLong;
		string lol;
		getline(ina,lol,'\t');
		istringstream iss(lol);
		iss >> tempLat;

		getline(ina,lol,'\n');
		istringstream isss(lol);
		isss >> tempLong;
		hahaha++;


		// do math stuff
		double kms = pythagoreanTheorem(locationVec, tempLat, tempLong);

		if(kms > 0 && kms <= 1)
		{
			zeroAndOne++;
		}
		else if(kms > 1 && kms <= 2)
		{
			oneAndTwo++;
		}
		else if(kms > 2 && kms <= 5)
		{
			twoAndFive++;
		}
		else
		{
			// greater then 5
			 aboveFive++;
		}
	}


	// stop the timer
	clock_t end = clock();

		// report
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Number of Service Locations                     " << locationVec.size() << endl;
	cout << "Elapsed Time in Seconds:                        " << elapsed_secs << endl;
	// filestream
	cout << endl;
	cout << endl;



	cout << "Aggregate Results for all 30,000 Addresses..." << endl;
	cout << "Nearest Service ( km )   # of Addresses   % of Addresses" << endl;
	cout << "----------------------   --------------   --------------" << endl;


	cout << "                0 - 1           "  << zeroAndOne << "                " << setprecision(2) << fixed << (zeroAndOne/hahaha)*100 << endl;
	cout << "                1 - 2           " << oneAndTwo << "                " << setprecision(2) << fixed << (oneAndTwo/hahaha)*100 << endl;
	cout << "                2 - 5           " << twoAndFive << "                " << setprecision(2) << fixed << (twoAndFive/hahaha)*100 << endl;
	cout << "                > 5             " << aboveFive << "                " << setprecision(2) << fixed << (aboveFive/hahaha)*100 << endl;

}
