#!/usr/bin/env bash
set -euo pipefail
project_root="$(cd "$(dirname "$0")/.." && pwd)"
build_dir="$project_root/build"
mkdir -p "$build_dir"
if command -v qmake >/dev/null 2>&1; then
  qmake_bin="$(command -v qmake)"
elif [[ -x /opt/homebrew/opt/qt@5/bin/qmake ]]; then
  qmake_bin=/opt/homebrew/opt/qt@5/bin/qmake
else
  printf 'Qt 5 qmake not found. Install qt@5 or put qmake on PATH.\n' >&2
  exit 1
fi
cd "$build_dir"
"$qmake_bin" "$project_root/app/InsToCart.pro"
make -j "${INSTOCART_BUILD_JOBS:-4}"
printf 'Built %s/InsToCart.app\n' "$build_dir"
