#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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
    ifstream inFile(argv[1]);
    if (!inFile)
    {
        cout << "Filed could not be found or opened. Try again." << endl;
        return 1;
    }
    EafSubmission submission;
    while (inFile >> submission)
    {
        eafs.push_back(submission);
    }
    for (int i = 0; i < eafs.size(); i++)
    {
        cout << eafs.at(i) << endl;
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