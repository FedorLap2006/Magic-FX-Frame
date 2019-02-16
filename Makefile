CC = g++ -std=c++14 -W
LIBDIR ?= lib 
INCDIR ?= include 
SRCDIR ?= src 
OBJDIR ?= obj
PF ?= all

ifeq ($(PF),.)
	if($(OS),Windows_NT)
		DCMD = lib_win
	else
		UNAME := $(shell uname -s)

		ifeq($(UNAME),Linux)
			DCMD = lib_linux		
		endif
		
		ifeq($(UNAME),Darwin)
			DCMD = lib_mac		
		endif
	endif
endif

ifeq ($(PLATFORM),all)
	MCOMAND = lib_win lib_linux lib_macos

all: $(DCMD)


$(OBJDIR)/Win/%.o: $(SRCDIR)/Win/%.cpp
	$(CC) -c $< -o $@

$(OBJDIR)/Linux/%.o: $(SRCDIR)/Linux/%.cpp 
	$(CC) -c $< -o $@

$(OBJDIR)/MacOS/%.o: $(SRCDIR)/Win/%.cpp 
	$(CC) -c $< -o $@

lib_win: $(OBJDIR)/Win/MFF.o
	$(CC)  -c $(SRCDIR)/*.cpp $()
	cd $(OBJDIR)/Win && ar rc libMFF.a *.o && cp libMFF.a ../libMFF.a