#!/bin/bash -l
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --mem-per-cpu=2G
#SBATCH --time=0-2:00:00
#SBATCH --output=batch_30_batch.stdout
#SBATCH --job-name="Submitting CSV..."
#SBATCH -p short
./CSV_interpreter.out test_submission.csv -begin 1
