class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int count = 0;
        int days[] = {0, 31, 59, 90, 120, 151,
                      181, 212, 243, 273, 304, 334};

        auto convert = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));
            return days[month - 1] + day;
        };

        int arrAlice = convert(arriveAlice);
        int levAlice = convert(leaveAlice);
        int arrBob = convert(arriveBob);
        int levBob = convert(leaveBob);

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