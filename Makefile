# Makefile for CSV-COVARMAT tool.
# Felix Glas
# 2016-04-05 14:39:55

CXX = g++
CXXFLAGS = -pipe -O3 -Wextra -W -ansi -pedantic -pedantic-errors -Wmissing-braces -Wparentheses -std=c++14
CXXFLAGS += -Wall -Wold-style-cast -Wzero-as-null-pointer-constant
LDFLAGS = -static -static-libgcc -static-libstdc++
RM = rm -rf

all: covarmat.exe

covarmat.exe: covarmat.o common.o
	$(CXX) $(LDFLAGS) -o $@ $^

covarmat.o: covarmat.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

common.o: common.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	$(RM) covarmat.o
	$(RM) covarmat.exe
	$(RM) common.o

delete:
	$(RM) covarmat.o
	$(RM) covarmat.exe
	$(RM) covarmat.cc
	$(RM) common.o
	$(RM) Makefile
