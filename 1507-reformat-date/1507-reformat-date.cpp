class Solution {
private:
    // Mapping of month abbreviations to their numeric values
    unordered_map<string, string> monthMap = {
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
        {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
        {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
    };
public:
    string reformatDate(string date) {
        istringstream ss(date);
        string day, month, year;
        ss >> day >> month >> year;

        // Remove "st", "nd", "rd", or "th" from the day
        day = day.substr(0, day.size() - 2);

        // Ensure day and month are zero-padded
        if(day.size() == 1) {
            day = "0" + day;
        }

        return year + "-" + monthMap[month] + "-" + day;
    }
};