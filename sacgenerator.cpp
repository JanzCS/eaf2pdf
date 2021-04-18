#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "csv.hpp"

using namespace std;

class EafSubmission
{
    public:
        friend ostream &operator<<(ostream &out, const EafSubmission &obj);
        friend istream &operator>>(istream &in, EafSubmission &obj);
        string submitterFirstName;
        string submitterLastName;
        string submitterEmail;
        string submissionDate;
        string eventName;
        string eventStartDate;
        string eventStartTime;
        string eventEndDate;
        string eventEndTime;
        string eventLocation;
        string groupName;
        string groupSacCommissioner;
        string estimatedAttendance;
        string estimatedCost;
        string SacFundingRequested;
        string RiskFactors;
        string nonGuParticipants;
        string eventDescription;
        string fundingDescription;
    
    private:

};

int main(int argc, char *argv[])
{
    vector<EafSubmission> eafs;
    if (argc < 2)
    {
        cout << "No filename entered." << endl;
        return 1;
    }
    csv::CSVReader reader(argv[1]);
    ifstream inFile(argv[1]);
    // if (reader.empty())
    // {
    //     cout << "Filed could not be found or opened. Try again." << endl;
    //     return 1;
    // }
    csv::CSVRow currentRow;
    while (reader.read_row(currentRow))
    {
        EafSubmission currentSubmission;
        currentSubmission.submitterFirstName = currentRow[1].get<>();
        currentSubmission.submitterLastName = currentRow[2].get<>();
        currentSubmission.submitterEmail = currentRow[3].get<>();
        currentSubmission.submissionDate = currentRow[7].get<>();
        currentSubmission.eventName = currentRow[13].get<>();
        currentSubmission.eventStartDate = currentRow[14].get<>();
        currentSubmission.eventStartTime = currentRow[15].get<>();
        currentSubmission.eventEndDate = currentRow[16].get<>();
        currentSubmission.eventEndTime = currentRow[17].get<>();
        currentSubmission.eventLocation = currentRow[18].get<>();
        currentSubmission.groupName = currentRow[19].get<>();
        currentSubmission.groupSacCommissioner = currentRow[21].get<>();
        currentSubmission.estimatedAttendance = currentRow[26].get<>();
        currentSubmission.estimatedCost = currentRow[27].get<>();
        currentSubmission.SacFundingRequested = currentRow[28].get<>();
        currentSubmission.RiskFactors = currentRow[29].get<>();
        currentSubmission.nonGuParticipants = currentRow[30].get<>();
        currentSubmission.eventDescription = currentRow[31].get<>();
        currentSubmission.fundingDescription = currentRow[32].get<>();

        cout << "## " << currentSubmission.eventName << endl << endl;
        cout << "### " << currentSubmission.groupName << endl << endl;
        cout << "### Submitted by " << endl << currentSubmission.submitterFirstName << " " << currentSubmission.submitterLastName << " - " << currentSubmission.submitterEmail << " on " << currentSubmission.submissionDate << endl << endl;
        cout << "### Sac Commissioner" << endl << currentSubmission.groupSacCommissioner << endl << endl;
        cout << "#### Date" << endl << currentSubmission.eventStartDate << " " << currentSubmission.eventStartTime << " - " << currentSubmission.eventEndDate << " " << currentSubmission.eventEndTime << endl << endl;
        cout << "#### Location" << endl << currentSubmission.eventLocation << endl << endl;
        cout << "#### Risk Factors" << endl << currentSubmission.RiskFactors << endl << endl;
        cout << "#### Estimated Attendance" << endl << currentSubmission.estimatedAttendance << endl << endl;
        cout << "#### Estimated Cost" << endl << currentSubmission.estimatedCost << endl << endl;
        cout << "#### SAC Funding Requested" << endl << currentSubmission.SacFundingRequested << endl << endl;
        cout << "#### Event Description" << endl << currentSubmission.eventDescription << endl << endl;
        cout << "#### Funding Explanation" << endl << currentSubmission.fundingDescription;

        cout << endl << endl << "\\pagebreak" << endl << endl;
    }
}

ostream &operator<<(ostream &out, const EafSubmission &obj)
{
    out << obj.submitterFirstName << obj.submitterLastName << endl
    << obj.submitterEmail << endl
    << obj.submissionDate << endl
    << obj.eventName << endl
    << obj.eventStartDate << endl
    << obj.eventStartTime << endl
    << obj.eventEndDate << endl
    << obj.eventEndTime << endl
    << obj.eventLocation << endl
    << obj.groupName << endl
    << obj.groupSacCommissioner << endl
    << obj.estimatedAttendance << endl
    << obj.estimatedCost << endl
    << obj.SacFundingRequested << endl
    << obj.RiskFactors << endl
    << obj.nonGuParticipants << endl
    << obj.eventDescription << endl
    << obj.fundingDescription << endl;
    return out;
}

istream &operator>>(istream &in, EafSubmission &obj)
{
    string trash;
    char trashChar;
    getline(in, trash, ',');
    getline(getline(in, trash, '"'), obj.submitterFirstName, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.submitterLastName, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.submitterEmail, '"');
    in >> trashChar;
    getline(in, trash, ',');
    getline(in, trash, ',');
    getline(in, trash, ',');
    getline(getline(in, trash, '"'), obj.submissionDate, '"');
    in >> trashChar;
    getline(in, trash, ',');
    getline(in, trash, ',');
    getline(in, trash, ',');
    getline(in, trash, ',');
    getline(in, trash, ',');
    getline(getline(in, trash, '"'), obj.eventName, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.eventStartDate, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.eventStartTime, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.eventEndDate, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.eventEndTime, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.eventLocation, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.groupName, '"');
    in >> trashChar;
    getline(in, trash, ',');
    getline(getline(in, trash, '"'), obj.groupSacCommissioner, '"');
    in >> trashChar;
    getline(in, trash, ',');
    getline(in, trash, ',');
    getline(in, trash, ',');
    getline(in, trash, ',');
    getline(getline(in, trash, '"'), obj.estimatedAttendance, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.estimatedCost, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.SacFundingRequested, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.RiskFactors, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.nonGuParticipants, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.eventDescription, '"');
    in >> trashChar;
    getline(getline(in, trash, '"'), obj.fundingDescription, '"');
    getline(in, trash);
    return in;
}