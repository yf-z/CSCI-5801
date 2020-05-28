/* voting_app.cc
* Implementations of the methods for the VotingApp class
* Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

#include "voting_app.h"

VotingApp::VotingApp( bool test_mode ) : election_ ( NULL ) , test_ ( test_mode ) {
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
                     << "\n3.When prompted to input ballot files for the election, enter the"
                     << "\nnames of the files that should be used (separated by a new line"
                     << "\nif there are multiple files)."
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
    ballot_Files = this->askForFiles();

    if (!ballot_Files.empty())
      this->files_ = ballot_Files;

    seat_num = this->askForSeats();
    type = this->askForType();

    if( type == "STV" && this->test_ == true ){
      shuff = this->askForShuffleTurnOff();
    }

    this->displayElectionParams( seat_num, type, shuff );

    // ask if user confirms all parameters
    confirmation =  this->askForConfirmation();
  };



  // test only
  /*
  std::cout << "type: " << type << std::endl;
  std::cout << "seat Num: " << seat_num << std::endl;
  std::cout << "files: " << std::endl;
  for (auto it = files_.begin(); it != files_.end(); it++) {
    std::cout << "file name: " << (*it) << std::endl;
  }
  */
  // process all ballot files
  this->processFiles();
/*
  // test only
  std::cout << "candidates:\n";
  for (auto it = candidates_.begin(); it != candidates_.end(); it++) {
    std::cout << "ID: " << (*it)->getId() << std::endl;
    std::cout << "Name: " << (*it)->getName() << std::endl;
  }

  // test only
  std::cout << "ballots:\n";
  for (auto it = ballots_.begin(); it != ballots_.end(); it++) {
    std::cout << "ID: " << (*it)->getId() << std::endl;
    std::cout << "Candidate in Ballot ID " << (*it)->getId() << std::endl;
    std::vector<Candidate*> temp = (*it)->getCandidates();
    for (auto x = temp.begin(); x != temp.end(); x++){
      std::cout << (*x)->getName() <<std::endl;
    }
  }
*/
  // create election object
  if( type == "STV" )  {
    election_ = new STVElection( type, seat_num, candidates_, ballots_, shuff );
  }

  else {
    election_ = new PluralityElection( type, seat_num, candidates_, ballots_ );
  }

  election_->runAlgorithm();
  // display result and audit file path
  this->displayResults();
  this->displayAuditLocation();

  return;
}

std::vector<std::string> VotingApp::askForFiles() {
  std::vector<std::string> files;
  bool ask_user = true;
  bool file_exists;

  
  std::cout << "Please input your files one file per line."<< std::endl;
  std::cout << "enter q when done" << std::endl;

  while( ask_user ) {
    std::string file_name;
    std::cin >> file_name;

    // verify that file exists in the program directory
    file_exists = this->doesFileExist( file_name );

    // see if user has typed 'help"
    if (file_name.compare("help") == 0) {
      this->displayHelp();
      std::cout << "Please input your files one file per line."<< std::endl;
      std::cout << "enter q when done" << std::endl;
      continue;
    }

    // if the user finished entering audit file names
    if (file_name.compare("q") == 0) {
      ask_user = false;
      break;
    }

    //check if file exists
    if (!file_exists){
      std::cout << "Please enter a file that exists in the directory or enter q if done" << std::endl;
    }
    //check if file is csv file
    else if (file_name.substr(file_name.find_last_of(".") + 1) != "csv"){
      std::cout << "Please enter a csv file" << std::endl;
    }
    //add the file into files
    else{
      files.push_back(file_name);
    }
  }

  return files;
}

bool is_number(const std::string& s) {
  // helper function to check if a string is a positive integer
  return !s.empty() && std::find_if(s.begin(),
      s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}


bool VotingApp::doesFileExist( const std::string filename ) {

  if( filename == ""){
    return false;
  }
  std::ifstream infile( filename.c_str() );
  return infile.good();
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
      std::cout << "Please enter in a valid input" << std::endl;
    }
  }

  return type;
}


bool VotingApp::askForShuffleTurnOff() {
  bool shuffle_;
  std::string shuffle;
  bool asking_user = true;

  while( asking_user ) {
    std::cout << "Do you want to turn off shuffle?" << std::endl;
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
      std::cout <<  "Sorry, your input must equal 'true' or 'false.'" << std::endl;
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
  std::cout << "These are your input parameters: " << std::endl;
  
  if(test_ == true){
    std::cout << "Shuffle option: "  <<  shuffleStatus << std::endl;
  }

  std::cout << "Type of election: " << type << std::endl;
  std::cout << "Number of seats: " << seats << std::endl;
  for (auto it = this->files_.begin(); it != this->files_.end(); it++) {
    std::cout << "file name: " << (*it) << std::endl;

  }
  return;
}

bool VotingApp::askForConfirmation() {
  std::string user_input;
  bool asking_user = true;
  bool confirmation = false;

  while(asking_user) {
    std::cout << "Are these parameters correct?" << std::endl;
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
      std::cout << "Please type true or false, no other input will be valid." << std::endl;
    }
  }

  return confirmation;
}

void VotingApp::processFiles() {
  std::string line;
  std::string candidate_list;
  int ballot_id = 1;
  int candidate_id = 1;

  bool isFirstFile = true;


  for( auto it = std::begin ( files_ ); it !=std::end ( files_ ); it++ ) {
    std::ifstream ballot_file (*it);
    
  
    if( ballot_file.is_open () ) {
    //Assuming that the first line is candidate list and there are no errors in the file
      getline( ballot_file, candidate_list );


      if( isFirstFile ) {
        candidates_=createCandidate ( candidate_id, candidate_list );
        isFirstFile = false;
      }
  
 

      // process each ballot line in the file
      while( getline ( ballot_file, line ) ) {
        Candidate *CA[10];
        int counter = 0;
        int i = 0;

        std::stringstream ballot_line ( line );
        std::vector<std::string> ballot_votes;
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
              CA[index-1] = ( candidates_[counter] );
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
        

        Ballot *ballot = new Ballot( ballot_id, candidatesForBallot );
        ballots_.push_back( ballot );
        ballot_id++;
      }   //end while ballot line
    
    } //ballot file is open okay
    else{
      throw "Could not open file.";
    }
  }  //for each file

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

  std::cout << "These are the election results: " << std::endl;
  results = election_->getResults();
  std::cout << results << std::endl;

  return;
}


void VotingApp::displayAuditLocation() {
  std::string path;

  std::cout << "Audit File location: ";
  path = election_->getAuditFilePath();
  std::cout << path << std::endl;
  
  return;
}


