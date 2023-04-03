#pragma once
class Time {
private:
	int hour = 0, min = 0, sec = 0;
public:
	void set();
	void set_file(int my_hour, int my_min, int my_sec);
	void get();
	int gesec();
	int gemin();
	int gehour();
	void norm_time();
	friend Time operator+(Time& t1, int t2);
	friend Time operator+=(Time& t1, int t2);
	friend Time operator++(Time& t1);
	friend Time operator--(Time& t1);
	friend long long compare(const Time& t1, const Time& t2);
};

std::ostream& operator<<(std::ostream& stream, Time& t);
bool operator<(const Time& t1, const Time& t2);
bool operator==(const Time& t1, const Time& t2);
bool operator!=(const Time& t1, const Time& t2);
bool operator>(const Time& t1, const Time& t2);
bool operator>=(const Time& t1, const Time& t2);
bool operator<=(const Time& t1, const Time& t2);


void sort_func(FILE* Time_0, FILE* Time_Sort);