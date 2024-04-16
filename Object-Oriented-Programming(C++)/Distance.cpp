#include <iostream>
#include <string>
#include <algorithm> //contains function to change string to all uppercase
#include <iomanip> //constains function to set precision

using namespace std;

const int city_size = 15; //number of cities
enum city_type //enum city list
{
    INVALID = -1,
    ATLANTA,
    BOSTON,
    CHICAGO,
    DALLAS,
    DENVER,
    HOUSTON,
    LOS_ANGELES,
    MEMPHIS,
    MIAMI,
    NEW_YORK,
    PHILADELPHIA,
    PHOENIX,
    SAN_FRANCISCO,
    SEATTLE,
    WASHINGTON_DC
};

const int DISTANCE_TABLE[city_size][city_size] = //const 2D distance table
    {

        {0, 1505, 944, 1157, 1945, 1126, 3108, 541, 973, 1200, 1070, 2555, 3434, 3503, 871},

        {1505, 0, 1367, 2491, 2839, 2578, 4166, 1824, 2022, 306, 435, 3691, 4330, 3997, 634},

        {944, 1366, 0, 1290, 1474, 1510, 2444, 773, 1912, 1145, 1069, 2332, 2981, 2787, 956},

        {1157, 2491, 1290, 0, 1064, 362, 1990, 675, 1785, 2204, 2086, 1422, 2380, 2701, 1900},

        {1945, 2838, 1474, 1064, 0, 1412, 1335, 1411, 2773, 2617, 2532, 942, 1524, 1640, 2395},

        {1127, 2579, 1511, 362, 1412, 0, 2205, 778, 1544, 2279, 2154, 1631, 2641, 3038, 1958},

        {3108, 4166, 2800, 1990, 1335, 2205, 0, 2573, 3755, 3933, 3918, 574, 559, 1544, 3689},

        {541, 1824, 773, 675, 1411, 778, 2573, 0, 1404, 1533, 1413, 2026, 2893, 2997, 1226},

        {973, 2022, 1912, 1785, 2773, 1544, 3755, 1404, 0, 1756, 1643, 3182, 4166, 4392, 1487},

        {1200, 306, 1145, 2204, 2617, 2279, 3933, 1533, 1756, 0, 130, 3441, 4126, 3863, 328},

        {1070, 435, 1069, 2086, 2532, 2154, 3918, 1413, 1643, 130, 0, 3342, 4047, 3816, 199},

        {2555, 3691, 2332, 1422, 942, 1631, 574, 2026, 3182, 3441, 3342, 0, 1050, 1792, 3180},

        {3434, 4330, 2981, 2380, 1524, 2641, 559, 2893, 4166, 4126, 4047, 1050, 0, 1092, 3916},

        {3503, 3997, 2787, 2701, 1640, 3038, 1544, 2997, 4392, 3863, 3816, 1792, 1092, 0, 3734},

        {871, 634, 956, 1900, 2395, 1958, 3689, 1226, 1487, 328, 199, 3180, 3916, 3734, 0},
};

int updated_distance_table[city_size][city_size];
//2D distance table array which updates distance table if there's weather alert

void build_distance_table();
//copies each row and column from const DISTANCE_TABLE and stores the values in 
//updated_distance_table array that can change data stored in array, takes no arguments
//and no return type

city_type get_enum(string city);
//precondition: takes in user inputted city as string
//postcondition: returns enum city_type value of city(ends program if city is not valid)

void get_trip_cost(string first_city, string second_city, bool weather_alert);
//precondition: takes in two strings, calls get_enum function for city indexes, finds distance
//between two cities in updated distance table and asks user for mpg and gas price
//postcondition: prints out the cost to drive, no return type

void get_average_distance(string city);
//precondtion: takes in one city string, calls get_enum function for city index, loops through
//all the columns of index row and divides by city_size - 1 (city asked isn't included)
//postcondtion: prints out average, no return type

void smallest_average();
//loops through each row and finds the average, finds the city name of row with closest distance, prints out city
//and average distance, takes no arguments and no return type

void get_closest_city(string city);
//precondition: takes in one city string, calls get_enum function for city index, loops through
//each column of index row to find smallest value (not including same city that's asked)
//postcondition: prints out closest city and the miles to that city, no return type

void get_farthest_two_cities();
//loops through each row and column to find the farthest distance, calls enum_string function
//for row and column of farthes distance which returns two cities that are farthest apart,
//prints out two cities and distance, takes no arguments and no return type

bool weather_alert_updater(string first_city, string second_city);
//precondition: two city strings arguments are passed into the function, the function calls the weather_alert function
//to check if the two cities are weather cities
//postcondition: the updated_distance_table is updated if both cities are weather cities, no return type

bool weather_alert(int city_enum);
//precondition: takes in int of city_enum and determines if the index of the city is a weather alert city
//postcondition: if index is a weather city, return true, else return false

string get_city_string(city_type enum_city);
//precondition: the enum of a city is passed as an argument in the function
//postcondition: the function returns the string of the corresponding city to the index of the argument

int main()
{
    int task; //task set to user input
    cout << "(1)Get trip cost\n"; 
    cout << "(2)Average distance\n";
    cout << "(3)Closest city\n";
    cout << "(4)City with smallest average distance\n";
    cout << "(5)Farthest two cities\n";
    cout << "Enter the number of the task you would like to perform\n" << 
            "(If your city has several words separate words by '_'): ";
    cin >> task;

    string first_city; //cit(y/ies) entered by user
    string second_city;

    if (task == 1) //gets cit(y/ies) from user depending on task, program ends if response is not 1-5
    {
        cout << "What is the first city?" << endl;
        cin >> first_city;
        cout << "What is the second city?" << endl;
        cin >> second_city;
    }
    else if (task > 1 && task < 4)
    {
        cout << "What is the city?" << endl;
        cin >> first_city;
    }
    else if (task == 4 || task == 5) //task 4 and 5 don't require a city, but still a valid response
    {}
    else
    {
        cout << "Enter a valid response." << endl;
    }
    switch (task) //switch statement executes task inputted by user
    {
        case 1:
        {
            build_distance_table();
            bool weather_alert = weather_alert_updater(first_city, second_city); //finds if two cities qualify weather alert
            get_trip_cost(first_city, second_city, weather_alert);
            break;
        }
        case 2:
            build_distance_table();
            get_average_distance(first_city);
            break;
        case 3:
            build_distance_table();
            get_closest_city(first_city);
            break;
        case 4:
            build_distance_table();
            smallest_average();
            break;
        case 5:
            build_distance_table();
            get_farthest_two_cities();
            break;
        }
}

void build_distance_table()
{
    for (int i = 0; i < city_size; i++) //transfers each value in DISTANCE_TABLE to updated_distance_table 
    {
        for(int j = 0; j < city_size; j++)
        {
            updated_distance_table[i][j] = DISTANCE_TABLE[i][j];
        }
    }
}

city_type get_enum(string city)
{
    std::transform(city.begin(), city.end(), city.begin(), ::toupper); //transforms string to all upper

    city_type enum_value;
    if (city == "ATLANTA")
    {
        enum_value = city_type::ATLANTA;
    }
    else if (city == "BOSTON")
    {
        enum_value = city_type::BOSTON;
    }
    else if (city == "CHICAGO")
    {
        enum_value = city_type::CHICAGO;
    }
    else if (city == "DALLAS")
    {
        enum_value = city_type::DALLAS;
    }
    else if (city == "DENVER")
    {
        enum_value = city_type::DENVER;
    }
    else if (city == "HOUSTON")
    {
        enum_value = city_type::HOUSTON;
    }
    else if (city == "LOS_ANGELES")
    {
        enum_value = city_type::LOS_ANGELES;
    }
    else if (city == "MEMPHIS")
    {
        enum_value = city_type::MEMPHIS;
    }
    else if (city == "MIAMI")
    {
        enum_value = city_type::MIAMI;
    }
    else if (city == "NEW_YORK")
    {
        enum_value = city_type::NEW_YORK;
    }
    else if (city == "PHILADELPHIA")
    {
        enum_value = city_type::PHILADELPHIA;
    }
    else if (city == "PHOENIX")
    {
        enum_value = city_type::PHOENIX;
    }
    else if (city == "SAN_FRANCISCO")
    {
        enum_value = city_type::SAN_FRANCISCO;
    }
    else if (city == "SEATTLE")
    {
        enum_value = city_type::SEATTLE;
    }
    else if (city == "WASHINGTON_DC")
    {
        enum_value = city_type::WASHINGTON_DC;
    }
    else
    {
        enum_value = city_type::INVALID;
        cout << "Make sure to input valid city names."; //ends program if valid cit(y/ies) not entered
        exit(0);
    }
    return enum_value; //enum number returned based on argument string city 
}

void get_trip_cost(string first_city, string second_city, bool weather_alert)
{
    double mpg;
    cout << "Enter your car's miles per gallon: ";
    cin >> mpg;

    double gas_price;
    cout << "Enter the price of gas: $";
    cin >> gas_price;


    city_type enum_value = get_enum(first_city); //get enum values of cities
    city_type enum_value2 = get_enum(second_city);

    int distance = updated_distance_table[enum_value][enum_value2]; //finds distance at index

    double total_cost = distance / mpg * gas_price;

    string city_name = get_city_string(enum_value); //gets string city names
    string city_name2 = get_city_string(enum_value2);

    if (weather_alert) //if there's weather alert
    {
        cout << "Weather alert! Your trip will add 75 miles.\n";
    }

    cout << fixed << setprecision(2) << "$" << total_cost; //sets precision to 2 decimals
}

void get_average_distance(string city)
{
    city_type enum_value = get_enum(city); //get enum value

    int total = 0;
    for (int i = 0; i < city_size; i++) //for each column in row
    {
        total += updated_distance_table[enum_value][i]; //value stored in column added to total
    }

    double average = total / (city_size - 1); //doesn't include city in argument(-1)

    cout << average << " miles";
}

void smallest_average()
{
    int lowest_average = 100000; //variable set equal to arbitrary high value that will change once table is indexed

    int index_of_lowest_average;

    for (int i = 0; i < city_size; i++) //for each row
    {
        int total_distance = 0;

        for (int k = 0; k < city_size; k++) //for each column
        {
            total_distance += updated_distance_table[i][k]; //indexed value is added to total
        }

        double current_average = (total_distance / (city_size-1)); //average not including city passed as argument

        if (current_average < lowest_average)
        {
            index_of_lowest_average = i; //index of row is stored
            lowest_average = current_average;

        }
    }
    string city_name = get_city_string(city_type(index_of_lowest_average)); //get city name

    cout << city_name << "[" << lowest_average << " miles]" << endl;
}

void get_closest_city(string city)
{
    city_type enum_value = get_enum(city); //get enum value

    int closest_city_index; //used to store index of closest city
    
    int closest_distance = 100000; //variable set equal to arbitrary high value that will change once table is indexed

    for (int i = 0; i < city_size; i++) //for column in row
    {

        if ((closest_distance > updated_distance_table[enum_value][i]) && (updated_distance_table[enum_value][i] != 0))
        //if closest distance > indexed value && indexed value != 0
        {
            closest_distance = updated_distance_table[enum_value][i]; //change closest_distance to current indexed value
            closest_city_index = i; //closest_city_index set to current index
        }
    }
    string city_name = get_city_string(city_type(closest_city_index)); //get string city_name of closest_city_index

    cout << city_name << "[" << closest_distance << " miles]";
}

void get_farthest_two_cities()
{
    int farthest_distance = 0; //value at index of two farthest cities

    int index_distance_city1; //indexes of farthest cities
    int index_distance_city2;

    for (int i = 0; i < city_size; i++)//for each row
    {
        for (int j = 0; j < city_size; j++)//for each column
        {
            if (farthest_distance < updated_distance_table[i][j]) //if value at index is > farthest_distance 
            {                                                     
                farthest_distance = updated_distance_table[i][j]; //farthest_distance is current index
                index_distance_city1 = i;
                index_distance_city2 = j;
            }
        }
    }
    string city_name1 = get_city_string(city_type(index_distance_city1)); //get city names
    string city_name2 = get_city_string(city_type(index_distance_city2));

    cout << city_name1 << "/" << city_name2 << "[" << farthest_distance << " miles]";
}

bool weather_alert_updater(string first_city, string second_city)
{
    int first_city_enum = get_enum(first_city); //get enum value
    int second_city_enum = get_enum(second_city);

    bool weather_city1 = weather_alert(first_city_enum); //checks if cities are weather cities or not
    bool weather_city2 = weather_alert(second_city_enum);

    bool weather_alert = false;

    if ((first_city_enum == 4 || second_city_enum == 4) && (weather_city1 && weather_city2)) //if both are weather cities, value at [city1][city2] increases by 75
    {     
        updated_distance_table[first_city_enum][second_city_enum] = (updated_distance_table[first_city_enum][second_city_enum])+75;
        weather_alert = true;
    }
    return weather_alert;
}

bool weather_alert(int city_enum)
{
    bool weather_cities = false; //weather cities indexes(4, 6, 12, 13)
    switch (city_enum)
    {
        case 4:
            weather_cities = true;
            break;
        case 6:
            weather_cities = true;
            break;
        case 12:
            weather_cities = true;
            break;
        case 13:
            weather_cities = true;
            break;
        
    }
    return weather_cities;
}

string get_city_string(city_type enum_city) 
{
    string city_name;

    switch (enum_city) {
        case city_type::ATLANTA :
            city_name = "Atlanta";
            break;
        case city_type::BOSTON :
            city_name ="Boston";
            break;
        case city_type::CHICAGO :
            city_name ="Chicago";
            break;
        case city_type::DALLAS :
            city_name ="Dallas";
            break;
        case city_type::DENVER :
            city_name ="Denver";
            break;
        case city_type::HOUSTON :
            city_name = "Houston";
            break;
        case city_type::LOS_ANGELES :
            city_name = "Los Angeles";
            break;
        case city_type::MEMPHIS :
            city_name = "Memphis";
            break;
        case city_type::MIAMI :
            city_name ="Miami";
            break;
        case city_type::NEW_YORK :
            city_name ="New York";
            break;
        case city_type::PHILADELPHIA :
            city_name ="Philadelphia";
            break;
        case city_type::PHOENIX :
            city_name ="Phoenix";
            break;
        case city_type::SAN_FRANCISCO :
            city_name = "San Fransisco";
            break;
        case city_type::SEATTLE :
            city_name = "Seattle";
            break;
        case city_type::WASHINGTON_DC :
            city_name ="Washington DC";
            break;
        default:
            city_name ="Invalid city";
    }
    return city_name; //city_name returned based on enum number in argument
}