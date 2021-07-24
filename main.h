#include <stdlib.h>
#include  <bits/stdc++.h>
using namespace std;

ofstream tempFileOut;
ifstream inputFile, outputFile, tempOutFileIn;

// Code for testing input output
void changingInputOutputStream() {

  ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  inputFile.open ("input.txt");
  outputFile.open ("output.txt");
  tempOutFileIn.open ("tempOutputFile.txt");

  ofstream inputOut, outputOut;
  inputOut.open ("input.txt");
  outputOut.open ("output.txt", ios::trunc);
  tempFileOut.open ("tempOutputFile.txt");

  char* mySecret = getenv("input");
  char* mySecretOut = getenv("output");
  inputOut<<mySecret;
  outputOut<<mySecretOut;
  inputOut.close();
  outputOut.close();

  std::cin.rdbuf(inputFile.rdbuf());
  std::cout.rdbuf(tempFileOut.rdbuf());

}

void writeOutput(string output) {
  ofstream outputOut;
  outputOut.open("output.txt", ios::out | ios::trunc);
  outputOut<<output;
  outputOut.close();
}

void compareGeneratedOutput() {

  tempFileOut.close();
  string inLine, outLine, input;

  ofstream inputOut, outputOut;

  string output = "";
  while(getline(tempOutFileIn, inLine) && getline(outputFile, outLine)) {
    if(inLine.compare(outLine)) {
      output += "FAILED!";
      output += "\n Expected output : " + outLine + "\n Got output : " + inLine;
      writeOutput(output);
      exit(0);
    }
  }

  if (getline(tempOutFileIn, inLine)) {
    output += "FAILED!";
    output += "Found extra lines, check output";
    writeOutput(output);
    exit(0);
  }

  
  inputFile.close();
  outputFile.close();
  tempOutFileIn.close();

  output += "PASSED!!";

  inputOut.open("input.txt", ios::out | ios::trunc);
  writeOutput(output);

  inputOut.close();
  outputOut.close();

}