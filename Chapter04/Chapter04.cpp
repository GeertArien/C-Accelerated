// Chapter04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "student_info.h"
#include "square.h"
#include "word.h"
#include "number.h"

using std::cin;           using std::setprecision;
using std::cout;          using std::sort;
using std::domain_error;  using std::streamsize;
using std::endl;          using std::string;
using std::max;           using std::vector;

int test_student_info() {
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  while (read(cin, record)) {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);

  for (vector<Student_info>::size_type i = 0; i != students.size(); i++) {
    cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

    try {
      double final_grade = grade(students[i]);
      streamsize prec = cout.precision();
      cout << setprecision(3) << final_grade << setprecision(prec);
    }
    catch (domain_error e) {
      cout << e.what();
    }
    cout << endl;
  }

  return 0;
}

void test_size_type() {
  //int max_len;
  string::size_type max_len;
  Student_info s;
  max_len = std::max(s.name.size(), max_len);
}

void test_squares(unsigned range) {
  vector<int> v = square(range);
  print_squares(cout, v);
}

void test_double_squares(unsigned range) {
  vector<double> v = square_double(range);
  print_squares(cout, v);
}

void test_word() {
  vector<string> words;
  read(cin, words);
  cout << "Number of distinct words: " << count_distinct(words) << endl;
  count_occurence(cout, words);
}

void test_number_average() {
  vector<double> numbers = { 10.2, 15.7, 18.5, 9.7, 25.2 };

  cout << average(numbers) << endl;
}

vector<double> f() {
  return{ 10.2, 17.5 };
}

int main() {
  int n = 1;
  double d = f()[n]; // f() => return vector<double> met minstens n + 1 elementen

  test_number_average();

  return 0;
}

