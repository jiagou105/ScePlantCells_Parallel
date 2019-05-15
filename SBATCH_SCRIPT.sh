#!/bin/bash -l
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=24
#SBATCH --mem-per-cpu=2G
#SBATCH --time=0-00:15:00
#SBATCH --output=my16.stdout
#SBATCH --job-name="test_16"
#SBATCH -p short 

export OMP_NUM_THREADS 24
mkdir Animate_test_16
mkdir Nematic_test_1 
mkdir Locations_test_1 
./program Animate_test_16 Locations_test_1 Nematic_test_1                                  
