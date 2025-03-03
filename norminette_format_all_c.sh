#!/usr/bin/env sh
set -ex
current_dir="$(dirname "$(realpath "$0")")"

# Find directories that match the pattern "ex***"
for folder in $(find . -type d -name "ex??"); do
  "$current_dir"/.venv/bin/c_formatter_42 $(find "$folder" -type f -name "*.c")
done
