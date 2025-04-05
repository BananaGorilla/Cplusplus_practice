#include <iostream>
#include <iomanip>

using namespace std;

typedef struct
{
    int courseNum;
    int* coursesScore;
} courseAndScore; 

void assignCourseScore(courseAndScore* item, int courseNum, int* courseScore)
{
    item->courseNum = courseNum;
    item->coursesScore = new int[courseNum];

    for( int i = 0; i < courseNum; i++ )
    {
        item->coursesScore[i] = courseScore[i];
    }
}

float calcAvgScorePerSem(courseAndScore* item)
{
    int totalScorePerSem = 0;
    float avgScore = 0.0;
    for(int cnt = 0; cnt < item->courseNum; cnt++)
    {
        totalScorePerSem = totalScorePerSem + item->coursesScore[cnt];
    }
    
    avgScore = static_cast<float>(totalScorePerSem) / static_cast<float>(item->courseNum);

    return avgScore;
}

float calcCgpa(courseAndScore* item, int totalSemNum)
{
    float totalAvgScore = 0;
    float cgpa = 0.0;
    for(int cnt = 0; cnt < totalSemNum; cnt++)
    {
        float semAvgScore = calcAvgScorePerSem(&item[cnt]);
        totalAvgScore = totalAvgScore + semAvgScore;
    }

    totalAvgScore = totalAvgScore/static_cast<float>(totalSemNum);

    return totalAvgScore;
}

int main(int argc, char* argv[])
{
    int total_semester_num = 0;

    cout << "How many semesters have you attained? ";
    cin >> total_semester_num;

    courseAndScore* items = new courseAndScore[total_semester_num];

    for(int cnt = 0; cnt < total_semester_num; cnt++)
    {
        int numCourses = 0;
        cout << "How many courses have you attained in semester " << cnt + 1 << "? ";
        cin >> numCourses;

        int* coursesScore = new int[numCourses];
        
        for(int cnt2 = 0; cnt2 < numCourses; cnt2++)
        {
            int score;
            cout << "Course " << cnt2 + 1 << " result: ";
            cin >> score;
            coursesScore[cnt2] = score;
        }
        assignCourseScore(&items[cnt], numCourses, coursesScore);
    }

    float cgpa = calcCgpa(items, total_semester_num);
    cout << "CGPA: " << cgpa << setprecision(4);

    return 0;
}