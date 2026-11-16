#!/usr/bin/env bash
set -euo pipefail
project_root="$(cd "$(dirname "$0")/.." && pwd)"
"$project_root/scripts/build-macos.sh"
test_dir="$(mktemp -d)"
trap 'rm -rf "$test_dir"' EXIT
INSTOCART_DATA_DIR="$test_dir" QT_QPA_PLATFORM=offscreen \
  "$project_root/build/InsToCart.app/Contents/MacOS/InsToCart" --smoke-test
