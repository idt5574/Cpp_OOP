#include <iostream>

class StudentMarks
{
    enum {max_length = 100};
    short marks[max_length] {0}; // массив оценок студента
    int count {0}; // количество оценок в массиве marks
public:
    StudentMarks(short* ms, int total)
    {
        count = (total > max_length) ? max_length : total;

        for(int i = 0; i < count; ++i)
            marks[i] = ms[i];
    }

    const short* get_marks() const { return marks; }
    int get_count() const { return count; }

    StudentMarks operator +(const StudentMarks& right) const
    {
        int new_total = count + right.count;
        short *new_ms = new short[new_total];

        int cur_counter = 0;

        for(int i = 0; i < count; i++, cur_counter++)
            new_ms[cur_counter] = marks[i];
        
        for(int i = 0; i < right.count; i++, cur_counter++)
            new_ms[cur_counter] = right.marks[i];

        return StudentMarks(new_ms, new_total);
    }

    StudentMarks operator +(int right) const
    {
        int new_total = count + 1;
        short *new_ms = new short[new_total];

        int cur_counter = 0;

        for(int i = 0; i < count; i++, cur_counter++)
            new_ms[cur_counter] = marks[i];
        
        new_ms[cur_counter++] = right;

        return StudentMarks(new_ms, new_total);
    }
};

int main()
{
    short m[] = {2, 2, 3, 2, 3};
    short k[] = {5, 4, 2};
    StudentMarks marks_1(m, sizeof(m)/sizeof(*m));
    StudentMarks marks_2(k, sizeof(k)/sizeof(*k));

    StudentMarks res_1 = marks_1 + marks_2; // res_1: marks = {2, 2, 3, 2, 3, 5, 4, 2}, count = 8
    StudentMarks res_2 = marks_1 + 4; // res_2: marks = {2, 2, 3, 2, 3, 4}, count = 6

    return 0;
}