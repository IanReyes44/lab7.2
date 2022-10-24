// Jacob Rice
// CPSC 120-06
// 2022-10-19
// jrice909@csu.fullerton.edu
// @JChillin808
//
// Lab 07-01
// Partners: @IanReyes44
//
// This code finds the difference between two dates
//

#include <iostream>
int JulianDay(int month, int day, int year) {
  int julian_day = day - 32075 + 1461 * (year + 4800 + (month - 14) / 12) / 4 +
                   367 * (month - 2 - (month - 14) / 12 * 12) / 12 -
                   3 * ((year + 4900 + (month - 14) / 12) / 100) / 4;
  return julian_day;
}

int DateDifference(int start_month, int start_day, int start_year,
                   int end_month, int end_day, int end_year) {
  int date_difference = JulianDay(end_month, end_day, end_year) -
                        JulianDay(start_month, start_day, start_year);
  return date_difference;
}

void PrintDate(int month, int day, int year) {
  std::cout << month << "/" << day << "/" << year;
}

int main(int argc, char* argv[]) {
  int start_day{0};
  int start_month{0};
  int start_year{0};
  int end_day{0};
  int end_month{0};
  int end_year{0};
  std::cout << "Enter a start month: ";
  std::cin >> start_month;
  std::cout << "Enter a start day: ";
  std::cin >> start_day;
  std::cout << "Enter a start year: ";
  std::cin >> start_year;
  std::cout << "Enter an end month: ";
  std::cin >> end_month;
  std::cout << "Enter an end day: ";
  std::cin >> end_day;
  std::cout << "Enter an end year: ";
  std::cin >> end_year;
  int days = DateDifference(start_month, start_day, start_year, end_month,
                            end_day, end_year);
  std::cout << "The number of days between ";
  PrintDate(start_month, start_day, start_year);
  std::cout << " and ";
  PrintDate(end_month, end_day, end_year);
  std::cout << " is " << days << " days\n";

  return 0;
}
