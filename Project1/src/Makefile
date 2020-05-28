### Makefile
### Used to compile the Voting Application executable and all unit tests for the application
### Author: Sara Nelson (nels8907), Brendan Ritchie (ritch167), Yiwen Xu (xu000515), Yifan Zhang (zhan4372) **/

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
  CXX = clang++
  CXXFLAGS = -Wall -g -std=c++11 -stdlib=libc++
  CXXTESTFALGS = -Wall -std=c++11 -stdlib=libc++
else
  CXX = g++
  CXXFLAGS = -Wall -g -std=c++11
  CXXTESTFALGS = -Wall -std=c++11 -fno-access-control
endif

all: voting_app

voting_app: main.o voting_app.o election.o plurality_election.o stv_election.o candidate.o ballot.o
	$(CXX) $(CXXFLAGS) -o voting_app main.o voting_app.o election.o plurality_election.o stv_election.o candidate.o ballot.o

main.o: voting_app.h election.h ballot.h candidate.h

voting_app.o: voting_app.h election.h ballot.h candidate.h

election.o: election.h ballot.h candidate.h

plurality_election.o: plurality_election.h election.h ballot.h candidate.h

stv_election.o: stv_election.h election.h ballot.h candidate.h

candidate.o: candidate.h ballot.h

ballot.o: ballot.h candidate.h

clean:
	rm *.o voting_app

test: unit_test

unit_test:	$(ARGS).o voting_app.o election.o plurality_election.o stv_election.o candidate.o ballot.o
	$(CXX) $(CXXTESTFALGS) -o	unit_test $(ARGS).o voting_app.o election.o plurality_election.o stv_election.o candidate.o ballot.o

$(ARGS).o: voting_app.h election.h ballot.h candidate.h

voting_app.o: voting_app.h election.h ballot.h candidate.h

election.o: election.h ballot.h candidate.h

plurality_election.o: plurality_election.h election.h ballot.h candidate.h

stv_election.o: stv_election.h election.h ballot.h candidate.h

candidate.o: candidate.h ballot.h

ballot.o: ballot.h candidate.h

clean_test:
	rm *.o unit_test