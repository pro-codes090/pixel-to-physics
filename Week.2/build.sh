#!/usr/bin/env bash
set -euo pipefail

PROJECT_NAME="$(basename "$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)")"

printf '\n\033[1;36m+-------------------------------------- +\033[0m\n'
printf '\033[1;36m|          BUILD IN PROGRESS           |\033[0m\n'
printf '\033[1;36m+-------------------------------------- +\033[0m\n'
printf '\n\033[1;33mBuilding project: %s\033[0m\n' "$PROJECT_NAME"

# Add the project-specific build steps here.

cmake -S . -B build 

cmake --build build --parallel "$(nproc)"

cd ..


printf '\033[1;32mBuild complete!\033[0m\n'
printf 'To run the example, use: \033[1;37m./run.sh\033[0m\n\n'
