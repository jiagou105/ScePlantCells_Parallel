#!/bin/bash -l
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=12
#SBATCH --mem-per-cpu=2G
#SBATCH --time=0-2:00:00
#SBATCH --output=zip_log.stdout
#SBATCH --job-name="Submitting CSV..."
#SBATCH -p short
./CSV_interpreter.out FBC_high6_2.csv -begin 101
