/* voting_app.cc
* Implementations of the methods for the VotingApp class
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#include "voting_app.h"

VotingApp::VotingApp( bool test_mode ) : election_( NULL ) , test_( test_mode ), invalidBallotFileName_("") {
  this->helpMessage_ << "\n+-----------------------------------------------------------------+"
                     << "\n|                                                                 |"
                     << "\n|                                                                 |"
                     << "\n|            STV (Droop Quota)/Plurality Voting System            |"
                     << "\n|                                                                 |"
                     << "\n|                                                                 |"
                     << "\n+-----------------------------------------------------------------+"
                     << "\n"
                     << "\nInstructions:"
                     << "\nTo view this help window, please type the \"help\" command."
                     << "\n"
                     << "\nGuidelines for Election Parameter Input:"
                     << "\n1.When prompted to input the number of seats, you must enter an"
                     << "\ninteger greater than 0 and less than or equal to 10."
                     << "\n2.When prompted to input the voting algorithm for the election,"
                     << "\n enter \"Plurality\" or \"STV\"."
                     << "\n3.When prompted to input ballot files for the election, select the"
                     << "\nnames of the ballot files using the graphical"
                     << "\ninterface and press 'okay' when done."
                     << "\n4.When prompted to confirm the parameters of the election, enter"
                     << "\n\"true\" for confirmation or \"false\" otherwise."
                     << "\n*******************************************************************\n";
}

VotingApp::~VotingApp() {}

void VotingApp::run() {
  std::vector<std::string> ballot_Files;
  int seat_num;
  std::string type;
  bool shuff = true;
  bool confirmation = false;

  //display help window
  this->displayHelp();

  // ask for parameters
  while( confirmation == false ){
    seat_num = this->askForSeats();
    type = this->askForType();
    ballot_Files = this->askForFiles();

    if (!ballot_Files.empty())
      this->files_ = ballot_Files;

    if( type == "STV" && this->test_ == true ){
      shuff = this->askForShuffleTurnOff();
    }

    this->displayElectionParams( seat_num, type, shuff );

    // ask if user confirms all parameters
    confirmation =  this->askForConfirmation();
  };

  // process all ballot files
  this->processFiles(type);

  // create election object
  if( type == "STV" )  {
    election_ = new STVElection( type, seat_num, candidates_, ballots_, shuff );
  }

  else {
    election_ = new PluralityElection( type, seat_num, candidates_, ballots_ );
  }

  election_->runAlgorithm();
  if( type == "STV") {
    displayInvalidBallotFileName();
  }
  // display result and audit file path
  this->displayResults();
  this->displayAuditLocation();

  return;
}
std::vector<std::string> VotingApp::splitString(std::string str, char delim) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream token_stream(str);
  while(std::getline(token_stream, token, delim)) {
    tokens.push_back(token);
  }
  return tokens;
}

void removeDuplicates(std::vector<std::string> &v) {
  auto end = v.end();
  for(auto it = v.begin(); it != end; ++it) {
    end = std::remove(it + 1, end, *it);
  }
  v.erase(end, v.end());
}

std::vector<std::string> VotingApp::askForFiles() {
  std::vector<std::string> files;
  bool ask_user = true;
  //bool file_exists;
  std::cout << "\nSelect ballot .csv files for the election in the graphical interface and click OK when done..."<< std::endl;
  // file prompting loop
  while(ask_user) {
    sleep(1);
    std::string file_string = "";
    int status = -1;
    // open the zenity file selection GUI and put the returned list of file name into the stream variable
    FILE* stream = popen("zenity --file-selection --multiple --filename=. --file-filter=*.csv --separator=\",\" --title \"Select .csv Files Containing Ballots\" 2>/dev/null", "r");
    
    // if the user selected some files
    if(stream != NULL) {
      int buf_size = 1024;
      char buff[buf_size];
      
      while(fgets(buff, sizeof(buff), stream)) {
        file_string += buff;
      }
      status = pclose(stream);
    }
    
    // if the user selected some files and the stream was valid the whole way through
    if(status == 0) {
      // add the file names selected to the files vector
      file_string.pop_back();
      std::vector<std::string> selected_files = splitString(file_string, ',');
      files.insert(files.end(), selected_files.begin(), selected_files.end());
      removeDuplicates(files);
    }
    
    // list all of the files selected so far
    std::cout << "\nBallot files selected so far:"<< std::endl;
    
    for(int i = 0; i < (int)files.size(); i++) {
      std::cout << files[i] << std::endl;
    }
    // the user must select at least one file
    
    if(files.size() < 1) {
      std::cout << "\nYou must select at least 1 file to be able to run an election.\nSelect ballot .csv files for the election in the graphical interface and click OK when done..."<< std::endl;
    }
    else {
      std::string response;
      bool valid_response = false;
      // loop to check whether the user wants to add more files or not
      while(!valid_response) {
        std::cout << "\nWould you like to add any more ballot files for the election? Enter y or n:" << std::endl;
        std::cin >> response;

        // see if user has typed 'help"
        if(response.compare("help") == 0) {
          this->displayHelp();
        }
        else if(response.compare("n") == 0) {
          ask_user = false;
          valid_response = true;
        }
        else if(response.compare("y") == 0) {
          std::cout << "\nSelect additional ballot .csv files for the election in the graphical interface and click OK when done..."<< std::endl;
          valid_response = true;
        }
        else {
          std::cout << "\nInvalid input. Please enter a y or n."<< std::endl;
        }

      }
    }
  }
  return files;
} 

  bool is_number(const std::string& s) {
    // helper function to check if a string is a positive integer
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
  }

  int VotingApp::askForSeats() {
    std::string seats;
    int final_seat = 0;
    bool asking_user = true;
    std::string min = "";
    std::string max = "10";
    
    while( asking_user ) {
      std::cout << "How many seats are available for this election?\nPlease enter the number of seats between 1 to 10."<< std::endl;
      std::cin >> seats;

      // check if seats is a positive number
      if (is_number(seats) && 0 < seats.size() && 3 > seats.size())  {

        if( 0 < std::stoi(seats) && std::stoi(seats) <= 10 ) {
          final_seat = std::stoi(seats);
          asking_user= false;
        }
        // if the seats is not a positive number
        else {

          if (seats.compare("help") == 0) {
            this->displayHelp();
          }
          else {
            std::cout << "Please enter a valid number of seats" << std::endl;
          }

        }
      
      }
    }

  return final_seat;
}

std::string VotingApp::askForType() {
  std::string type;
  bool asking_user = true;
  
  while( asking_user ) {
    std::cout << "\nWhat type of voting algorithm would you like to run? Please type 'Plurality' or STV'"<< std::endl;
    std::cin >> type;

    if (type.compare("STV") == 0) {
      asking_user = false;
    }
    else if (type.compare("Plurality") == 0) {
      asking_user = false;
    }
    else if (type.compare("help") == 0) {
      this->displayHelp ();
    }
    else {
      std::cout << "\nPlease enter in a valid input" << std::endl;
    }
  }

  return type;
}


bool VotingApp::askForShuffleTurnOff() {
  bool shuffle_;
  std::string shuffle;
  bool asking_user = true;

  while( asking_user ) {
    std::cout << "\nDo you want to turn off shuffle?" << std::endl;
    std::cout << "Please enter 'true' or 'false'" << std::endl;
    std::cin >> shuffle;

    if (shuffle.compare("true") == 0) {
      shuffle_ = false;
      asking_user = false;
    }
    else if (shuffle.compare("false") == 0) {
      shuffle_ = true;
      asking_user = false;
    }
    else {
      std::cout <<  "\nSorry, your input must equal 'true' or 'false.'" << std::endl;
    }
  }

  return shuffle_;
}

void VotingApp::displayElectionParams( int seats, std::string type, bool shuffle) {
  std::string shuffleStatus;

  if (shuffle) {
    shuffleStatus = "on";
  }
  else {
    shuffleStatus = "off";
  }
  std::cout << "\n*******************************************************************" << std::endl;
  std::cout << "These are your input parameters: " << std::endl;
  
  if(test_ == true){
    std::cout << "Shuffle option: "  <<  shuffleStatus << std::endl;
  }

  std::cout << "Type of election: " << type << std::endl;
  std::cout << "Number of seats: " << seats << std::endl;
  for (auto it = this->files_.begin(); it != this->files_.end(); it++) {
    std::cout << "file name: " << (*it) << std::endl;

  }
  std::cout << "*******************************************************************" << std::endl;
  return;
}

bool VotingApp::askForConfirmation() {
  std::string user_input;
  bool asking_user = true;
  bool confirmation = false;

  while(asking_user) {
    std::cout << "\nAre these parameters correct?" << std::endl;
    std::cout << "Please type true, false, or help" << std::endl;
    std::cin >> user_input;

    if (user_input.compare("true") == 0) {
      confirmation = true;
      asking_user = false;
    }
    else if (user_input.compare("false") == 0) {
      confirmation = false;
      asking_user = false;
    }
    else if (user_input.compare("help") == 0) {
      this->displayHelp();
    }
    else{
      std::cout << "\nPlease type true or false, no other input will be valid." << std::endl;
    }
  }

  return confirmation;
}

// TODO Sara, possible parameter: int ballot_id
bool VotingApp::checkBallotValidity(std::string ballot){
  std::stringstream ballot_line(ballot);
  int candidateNumber = this->candidates_.size();
  int ballotVote = 0;
  int halfCandidate = 0;

  //Count the number of votes in ballot
  while( ballot_line.good() ) {
    std::string vote;
    getline( ballot_line, vote, ',' );

    if( !vote.empty() ) {
        ++ballotVote;
    }
  }

  //Calculate half the candidate number 
  halfCandidate = candidateNumber/2;

  if (candidateNumber%2 == 1) {
    halfCandidate ++;
  }

  if( ballotVote >= halfCandidate){
    return true;
  }
  else{
    return false;
  }
    
}

// TODO Yiwen; possible parameter: std::string fileName
void VotingApp::displayInvalidBallotFileName() {
 
  std::cout << "\nInvalid Ballot File location: ";
  std::cout << invalidBallotFileName_ << std::endl;
  
  return;
}

void VotingApp::writeToInvalidBallotFile(std::stringstream &invalid_text) {
  // timestamped invalid ballots file name
  invalidBallotFileName_ = "invalid_ballots" + std::to_string(std::chrono::seconds(std::time(NULL)).count()) + ".txt";
  std::ofstream invalidFile;

  // write the info to the file
  invalidFile.open(invalidBallotFileName_);
  if(!invalid_text.str().empty()) {
    invalidFile << invalid_text.str();
  }

  invalidFile.close();
}

Ballot* processLine(std::string line, std::vector<Candidate*> candidates) {
  Candidate *CA[10];
  int counter = 0;
  int i = 0;

  std::stringstream ballot_line ( line );
  // std::vector<std::string> ballot_votes;
  std::vector<Candidate*> candidatesForBallot;

  for(i = 0 ; i<10; i++ ) {
    CA[i]=NULL;
    
  }
  while( ballot_line.good() ) {
    
    std::string vote;
    getline( ballot_line, vote, ',' );

    if( !vote.empty() ) {
      int index = atoi( vote.c_str() );
      if(1<= index && index <= 10){
        CA[index-1] = ( candidates[counter] );
      }
    }
    counter++;
  }
  
  i = 0;

  while( CA[i]!= NULL ) {
    if(i == 10){
      break;
   } 
    candidatesForBallot.push_back( CA[i] );
    ++i;

  }

  Ballot *ballot = new Ballot( 1, candidatesForBallot );

  return ballot;
}

void VotingApp::processFiles(std::string type) {
  std::string line;
  std::string candidate_list;
  int ballot_id = 1;
  int candidate_id = 1;
  int invalid_ballot_count = 0;

  bool isFirstFile = true;


  for( auto it = std::begin ( files_ ); it !=std::end ( files_ ); it++ ) {
    std::ifstream ballot_file (*it);
  
    if( ballot_file.is_open () ) {
    //Assuming that the first line is candidate list and there are no errors in the file
      getline( ballot_file, candidate_list );

      if( isFirstFile ) {
        candidates_=createCandidate ( candidate_id, candidate_list );

        if (type == "STV") {
          for (int i = 0; i < (int)this->candidates_.size(); i ++) {
            if (i == 0) {
              this->invalidBallotsText_ << this->candidates_.at(i)->getName();
            }
            else {
              this->invalidBallotsText_ << "," << this->candidates_.at(i)->getName();
            }
          }
        }

        isFirstFile = false;
      }

      // process each ballot line in the file
      while( getline ( ballot_file, line ) ) {
        
        // Eve call add ballot/invalid ballot
          if (type == "STV") {
            if (this->checkBallotValidity(line)) {
              Ballot *temp = processLine(line, this->candidates_);
              temp->setId(ballot_id);
              ballots_.push_back(temp);
              ballot_id++;
            }
            else {
              this->invalidBallotsText_<< "\n" << line;
              invalid_ballot_count ++;
            }
        }
        else {
          Ballot *temp = processLine(line, this->candidates_);
          temp->setId(ballot_id);
          ballots_.push_back(temp);
          ballot_id++;
        }

      }   //end while ballot line
    
    } //ballot file is open okay
    else {
      throw "Could not open file.";
    }
  }  //for each file

  if (type == "STV") {
    this->invalidBallotsText_ << "\nThe number of invalid ballots is: " << invalid_ballot_count;
    this->writeToInvalidBallotFile(this->invalidBallotsText_);
  }

  return;
}

std::vector<Candidate*> VotingApp::createCandidate( int id, std::string candidate_string ){
  std::vector<Candidate*> candidates;

  std::stringstream candidate_line( candidate_string );

  while( candidate_line.good() ) {
    std::string candidate_name;

    getline( candidate_line , candidate_name , ',' );

    Candidate *candidate = new Candidate( id, candidate_name );
    ++id;
    candidates.push_back( candidate );

  }
  return candidates;
}

void VotingApp::displayHelp() {
  std::cout << this->helpMessage_.str() << std::endl;
}


void VotingApp::displayErrorMessage( std::string message ) {
  
  std::cout << message << std::endl;

  return;
}

void VotingApp::displayResults() {
  std::string results;

  std::cout << "\n\nThese are the election results: " << std::endl;
  sleep(1);
  std::cout << "*******************************************************************" << std::endl;
  results = election_->getResults();
  std::cout << results << std::endl;
  std::cout << "\n*******************************************************************" << std::endl;
  return;
}


void VotingApp::displayAuditLocation() {
  std::string path;

  std::cout << "\nAudit File location: ";
  path = election_->getAuditFilePath();
  std::cout << path + "\n" << std::endl;
  
  return;
}



    



