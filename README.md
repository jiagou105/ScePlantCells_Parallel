# ScePlantCells
This repository contains C++ code for modeling plant cells using the subcellular element model.


Clone this repository: git clone -b Equilibrium-SA <git link>

Commands to submit script:
(Compile program)
make all

(Compile submission helper functions)
g++ -o batchGenerator.out batchmaker.cpp
g++ CSV_interpreter.cpp -o CSV_interpreter.out

(Make subfolder in home directory)
mkdir Test_Output

(Submission)
./CSV_interpreter.out submission_test.csv

When prompted, enter an integer and press enter.

>>1

Wait for submission scripts to be submitted - this takes about 5 seconds per simulation being submitted.

You will see the output beginning to populate in Test_Output.

The CSV contains all of the information that is common to all simulations.  Note that parameters going into simulations are submitted in the form -par,-FLAGNAME,value.  The other flags -p,short,-cores,12.... etc.  are all for the SBATCH conditions that get put into ./batchGenerator.out directly.  You can see what those flags do by calling ./batchGenerator.out -help 

The flag -bigdata adds an absolute path to the shared folder in Alberlab.  You can change where that goes in batchmaker.cpp.

The parameter flags are in main.cpp. 

Please note that if you add a new global variable to the top of main.cpp you need to also list it in externs.h.
