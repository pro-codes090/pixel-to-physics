#!/usr/bin/env bash

set -euo pipefail

folder_name="$(basename "$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)")"
executable="./build/$folder_name"

if [[ ! -x "$executable" ]]; then
	echo "Error: '$executable' is not an executable file." >&2
	exit 1
fi

printf 'Running compiled example: %s\n' "$executable"
"$executable" "$@" 
