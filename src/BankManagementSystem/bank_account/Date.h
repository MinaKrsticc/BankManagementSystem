#include <iostream>

using namespace std;

namespace bank_account
{
    class Date
    {
        public:
        
        int days;
        int year;
        int month;
        
        void TimeTransaction()
        {
            time_t ttime = time(0);
            tm *local_time = localtime(&ttime);
            year = 1900 + local_time->tm_year;
            month = 1 + local_time->tm_mon;
            days = local_time->tm_mday;
        }
    };
}