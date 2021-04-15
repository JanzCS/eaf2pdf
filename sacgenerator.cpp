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
    
    private:
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
            cout << currentRow[1].get<>() << currentRow[2].get<>() << endl // first and last name
            << currentRow[3].get<>() << endl //email 
            << currentRow[13].get<>() << endl // event name
            << currentRow[14].get<>() << endl // start date
            << currentRow[15].get<>() << endl // start time
            << currentRow[16].get<>() << endl // end date
            << currentRow[17].get<>() << endl // end time
            << currentRow[18].get<>() << endl // location
            << currentRow[19].get<>() << endl // group name
            << currentRow[21].get<>() << endl // sac commissioner
            << currentRow[24].get<>() << endl // event name
            << currentRow[26].get<>() << endl // estimated attendance
            << currentRow[27].get<>() << endl // est. cost
            << currentRow[28].get<>() << endl // sac request
            << currentRow[29].get<>() << endl // risk factors
            << currentRow[30].get<>() << endl // non gu participants
            << currentRow[31].get<>() << endl // event description
            << currentRow[32].get<>() << endl; // funding explanation
        cout << endl << endl << endl;
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