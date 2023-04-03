#include <iostream>
#include <string>
#include "Time.h"
using namespace std;

std::ostream& operator<<(std::ostream& stream, Time& a) {
	return stream << a.gehour() << ":" << a.gemin() << ":" << a.gesec();
}

int Time::gesec() {
	return sec;
}

int Time::gemin() {
    return min;
}

int Time::gehour() {
    return hour;
}

void Time::get() {
    cout << hour << ":" << min << ":" << sec;
}

void Time:: norm_time() {
    int tmp_sec = sec, tmp_min = min, tmp_hour = hour, count_1 = 0, count_2 = 0;

    if (tmp_sec == 60) {
        tmp_min++;
        tmp_sec = 0;
    }

    if ((tmp_sec > 59)||(tmp_min > 59)) {
        while ((tmp_sec > 59)||(tmp_min > 59)) {
            tmp_sec--;
            count_1++;
            if (tmp_sec == 60) {
                tmp_min++;
                count_2++;
                tmp_sec = count_1;
            }

            if (count_1 == 60) {
                tmp_min++;
                count_2++;
                count_1 = 0;
            }

            if (count_2 == 60) {
                tmp_hour++;
                count_2 = 0;
            }

            if (tmp_min == 60) {
                tmp_hour++;
                count_2 = 0;
                tmp_min -= 60;
            }
        }
    }

    else {
        sec = tmp_sec;
    }

    if (tmp_sec < 0)
        tmp_sec = 0;

    sec = tmp_sec;
    min = tmp_min;
    hour = tmp_hour/2;
}

void Time::set() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите секунды: ";
    cin >> sec;
    norm_time();
    cout << endl;
}

void Time::set_file(int my_hour, int my_min, int my_sec) {
    hour = my_hour;
    min = my_min;
    sec = my_sec;
}

Time operator+(Time& t1, int t2) {
    Time answer;
    answer.sec = t1.hour * 3600 + t1.min * 60 + t1.sec + t2;
    if (answer.sec > 0) {
        answer.norm_time();
        return answer;
    }
    else {
        printf("\nError\n");
        return answer;
    }
}

Time operator+=(Time& t1, int t2) {
    Time answer;
    answer.sec = t1.hour * 3600 + t1.min * 60 + t1.sec + t2;
    if (answer.sec > 0) {
        answer.sec = t1.hour * 3600 + t1.min * 60 + t1.sec + t2;
        answer.norm_time();
        return answer;
    }
    else {
        printf("\nError\n");
        return answer;
    }
}

Time operator++(Time& t1) {
    Time answer;
    answer.sec = t1.hour * 3600 + t1.min * 60 + t1.sec + 1;
    answer.norm_time();
    return answer;
}

Time operator--(Time& t1) {
    Time answer;
    answer.sec = t1.hour * 3600 + t1.min * 60 + t1.sec - 1;
    answer.norm_time();
    return answer; 
}

long long compare(const Time& t1, const Time& t2) {
        return (t1.sec - t2.sec) + 60*(t1.min - t2.min) + 3600* (t1.hour - t2.hour);
}

bool operator < (const Time& t1, const Time& t2) {
    return compare(t1, t2)<0;
}

bool operator == (const Time& t1, const Time& t2) {
    return compare(t1, t2) == 0;
}

bool operator != (const Time& t1, const Time& t2) {
    return compare(t1, t2) != 0;
}

bool operator > (const Time& t1, const Time& t2) {
    return compare(t1, t2) > 0;
}

bool operator >= (const Time& t1, const Time& t2) {
    return compare(t1, t2) >= 0;
}

bool operator <= (const Time& t1, const Time& t2) {
    return compare(t1, t2) <= 0;
}


void sort_func(FILE* Time_0, FILE* Time_Sort) { // должна быть работа с классом
    Time t[255];
    int count = 0, class_count = 0;
    char str[255];
    char err[] = { "Время указано неверно в строке: " };

    char** str_tmp = new char*[255];
    for (int w = 0; w < 255; w++)
        str_tmp[w] = new char[255];

    char my_hour[5] = { 0 }, my_min[3] = { 0 }, my_sec[3] = {0};
    while (!feof(Time_0)) {
        fgets(str, 255, Time_0);
        for (int i = 0; str[i] != 0; i++) {
            if (str[i] == ':') {
                count++;
                if (count == 2) {
                    count = 0;
                    int j = 0, q = 0;
                    while ((str[j] != ':') && (str[j] != '\0') && (str[j] != ' ')) {
                        my_hour[q] = str[j];
                        j++;
                        q++;
                    }q = 0; j++;
                    while ((str[j] != ':')&&(str[j] != ' ')) {
                        my_min[q] = str[j];
                        j++;
                        q++;
                    }q = 0; j++;
                    while ((str[j] != ':') && (str[j] != ' ')) {
                        my_sec[q] = str[j];
                        j++;
                        q++;
                    }q = 0; 
                    if ((atoi(my_min) > 59) || (atoi(my_sec) > 59)) {
                        int r = 0;
                        char err_tmp[2] = {0};
                        itoa((class_count + 1), err_tmp, 10);
                        err[31] = err_tmp[0];
                        for (r = 0; err[r] != '\0'; r++)
                            str_tmp[class_count][r] = err[r];
                        str_tmp[class_count][r] = '\0';
                    }
                    else {
                        t[class_count].set_file(atoi(my_hour), atoi(my_min), atoi(my_sec));

                        int r = 0;
                        for (r = 0; (str[r] != '\n') && (str[r] != '\0'); r++)
                            str_tmp[class_count][r] = str[r];
                        str_tmp[class_count][r] = '\0';
                    }
                    
                    class_count++;

                   
                    for (int k = 0; k < 5; k++) 
                        my_hour[k] = 0;

                    for (int k = 0; k < 3; k++)
                        my_min[k] = 0;

                    for (int k = 0; k < 3; k++)
                        my_sec[k] = 0;

                    break;
                }
            }
        }
    }
    Time t_tmp;
    char* str_tmp_2 = new char [255];
    for (int j = 0; j < class_count; j++) {
        for (int i = 0; i < class_count-1; i++) {
            if (t[i] > t[i + 1]) {
                    t_tmp = t[i];
                    t[i] = t[i + 1];
                    t[i + 1] = t_tmp;

                    str_tmp_2 = str_tmp[i];
                    str_tmp[i] = str_tmp[i + 1];
                    str_tmp[i + 1] = str_tmp_2;
            }
        }
    }


    for (int i = 0; i < class_count; i++) {
        for (int j = 0; str_tmp[i][j] != '\0'; j++) {
            cout << str_tmp[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < class_count; i++) {
        fprintf(Time_Sort, "%s\n", str_tmp[i]);
    }

    for(int i = 0; i < 255; i++)
        delete[] str_tmp[i];
    delete[] str_tmp;
}











/* 
    1) Создаётся новый класс, в него записываются данные из файлика
    2) В строке str проверка на 2 ":", проверка на секунды и минуты (не больше 59, проверка не неотриц.) ЛИБО norm_time и проверка не неотриц.
    3) Использовать оператор > 

    1) 
*/