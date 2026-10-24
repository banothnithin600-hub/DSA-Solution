class Solution {
public:
    int convert(string date, int days[]) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int totalDays = days[month - 1] + day;

        return totalDays;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,string arriveBob, string leaveBob) {
        int count = 0;
        int days[] = {0, 31, 59, 90, 120, 151,181, 212, 243, 273, 304, 334};
                   //jan 0 to 31 , feb 32 to 59 .....
        int arrAlice = convert(arriveAlice,days);
        int levAlice = convert(leaveAlice,days);
        int arrBob = convert(arriveBob,days);
        int levBob = convert(leaveBob,days);

        for (int i = arrAlice; i <= levAlice; i++) {
            for (int j = arrBob; j <= levBob; j++) {
                if (i == j) {
                    count++;
                }
            }
        }

        return count;
    }
};