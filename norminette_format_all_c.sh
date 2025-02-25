#!/usr/bin/env sh
set -ex
current_dir="$(dirname "$(realpath "$0")")"
"$current_dir"/.venv/bin/c_formatter_42 $(find . -type f -name "*.c")
